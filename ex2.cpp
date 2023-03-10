#include <cstddef>
#include <iostream>
#include <stdexcept>
/*
input: p size: price1 price2 ... price[size]
output: size: np1 np2 ... np[size]
*/

template <typename T>
class dynarray {
  T* m_data;
  std::size_t m_size;

 public:
  dynarray(T* new_data, std::size_t new_size) noexcept
      : m_data{new_data}, m_size{new_size} {}
  dynarray() noexcept : dynarray(nullptr, 0) {}
  dynarray(std::size_t new_size) : dynarray(new T[new_size], new_size) {}
  ~dynarray() noexcept { reset(); }

  T* begin() noexcept { return m_data; }
  const T* begin() const noexcept { return m_data; }

  T* end() noexcept { return m_data + m_size; }
  const T* end() const noexcept { return m_data + m_size; }

  T* data() noexcept { return begin(); }
  const T* data() const noexcept { return begin(); }
  std::size_t size() const noexcept { return m_size; }

  T& operator[](std::size_t n) noexcept { return m_data[n]; }
  const T& operator[](std::size_t n) const noexcept { return m_data[n]; }

  void reset(T* new_data = nullptr, std::size_t new_size = 0) {
    if (m_data) {
      delete[] m_data;
    }
    m_data = new_data;
    m_size = new_size;
  }

  void from(std::istream& in) {
    in >> m_size;
    if (in.get() != ':') {
      throw std::runtime_error("size must be followed by ':'");
    }
    reset(new T[m_size], m_size);
    for (std::size_t i = 0; i < m_size; ++i) {
      in >> m_data[i];
    }
  }

  void to(std::ostream& out) {
    out << m_size << ':';
    for (std::size_t i = 0; i < m_size; ++i) {
      out << ' ' << m_data[i];
    }
  }
};

double average(const dynarray<double>& xs) noexcept {
  double cummulator = 0;
  for (double x : xs) {
    cummulator += x;
  }
  return cummulator / xs.size();
}

int main() try {
  double p;
  dynarray<double> prices{};
  std::cin >> p;
  p = (p + 100) / 100;
  prices.from(std::cin);
  double avg = average(prices);
  for (double& pr : prices) {
    if (pr < avg) {
      pr *= p;
    }
  }

  prices.to(std::cerr);
} catch (std::exception& e) {
  std::cerr << e.what();
}