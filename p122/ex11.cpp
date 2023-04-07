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

#include <fstream>

int main() try {
  dynarray<int> hs1, hs2;
  {
    std::ifstream in1{"klase.txt"};
    std::ifstream in2{"naujokai.txt"};
    hs1.from(in1);
    hs2.from(in2);
  }
  {
    std::ofstream out{"nauja.txt"};
    out << (hs1.size() + hs2.size()) << '\n';
    auto b1 = hs1.begin();
    auto b2 = hs2.begin();
    while(b1 != hs1.end() && b2 != hs2.end()) {
        if(*b1 > *b2) {
            std::cout << *b1++ << ' ';
        }
        else {
            std::cout << *b2++ << ' ';
        }
    }
    for(;b1 != hs1.end(); ++b1) {
        std::cout << *b1 << ' ';
    }
    for(;b2 != hs2.end(); ++b2) {
        std::cout << *b2 << ' ';
    }
  }
} catch (std::exception& e) {
  std::cerr << e.what();
}
