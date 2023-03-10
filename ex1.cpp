#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
/*
input: size: number1 number2 ... number[size]
output: size: number[size] number[size-1] ... number1
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

int main(/*int argc, char** argv*/) try {
  dynarray<int> data{};
  //   std::ifstream in((argc == 3) ? argv[1] : "in1.txt");
  //   std::ofstream out((argc == 3) ? argv[2] : "out1.txt");
  //   data.from(in);
  data.from(std::cin);

  std::size_t bound = data.size() / 2;
  for (std::size_t i = 0; i < bound; ++i) {
    std::swap(data[i], data[data.size() - i - 1]);
  }

  data.to(std::cout);
  //   data.to(out);
} catch (std::exception& e) {
  std::cerr << e.what();
}