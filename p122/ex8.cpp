#include <cstddef>
#include <iostream>
#include <stdexcept>
/*
input: size n1 n2 ... n[size]
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
    reset(new T[m_size], m_size);
    for (std::size_t i = 0; i < m_size; ++i) {
      in >> m_data[i];
    }
  }

  void to(std::ostream& out) {
    out << m_size;
    for (std::size_t i = 0; i < m_size; ++i) {
      out << ' ' << m_data[i];
    }
  }
};

template <typename T>
bool contains(T* begin, T* end, const T& t) noexcept {
  for (; begin != end; ++begin) {
    if (*begin == t) {
      return true;
    }
  }
  return false;
}

int main() try {
  dynarray<int> data{};
  data.from(std::cin);

  auto write_it = data.begin();
  for (auto b = data.begin(); b != data.end(); ++b) {
    if (!contains(data.begin(), b, *b)) {
      *write_it = *b;
      ++write_it;
    }
  }

  if (data.begin() != write_it) {
    auto bg = data.begin();
    std::cout << *bg;
    ++bg;
    for (; bg != write_it; ++bg) {
      std::cout << ' ' << *bg;
    }
  }
} catch (std::exception& e) {
  std::cout << e.what();
}
