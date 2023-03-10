#include <cstddef>
#include <iostream>
#include <stdexcept>
/*
input: size: n1 n2 ... n[size]
output: (Taip|Ne)
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

int main() try {
  dynarray<int> data{};
  data.from(std::cin);
  std::size_t half = data.size() / 2;
  for (std::size_t i = 0; i < half; ++i) {
    if (data[i] != data[data.size() - i - 1]) {
      std::cout << "Ne";
      return 0;
    }
  }

  std::cout << "Taip";
} catch (std::exception& e) {
  std::cerr << e.what();
}