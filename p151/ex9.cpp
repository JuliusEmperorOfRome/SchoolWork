#include<iostream>
#include<iomanip>


struct person {
  char name[16];
  int height;
  friend bool operator<(const person& a, const person& b) {
    return a.height < b.height;
  }
};

struct people {
  int count;
  person people[30];
};

void read(std::istream& in, people& out) {
  for(int i = out.count;i < 30; i = ++out.count) {
    in >> std::setw(16) >> out.people[i].name;
    in >> out.people[i].height;
    if(!in) { break; }
  }
}

void write(std::ostream& out, people& in) {
  for(int i = 0; i < in.count; ++i) {
    person& p = in.people[i];
    out << p.name << ' ' <<  p.height << '\n';
  }
}

void sort(people& in) {
  person* ps = in.people;
  int n = in.count;
  for(int i = 1; i < n; ++i) {
    for(int j = i; j > 0; --j) {
      if(ps[j - 1] < ps[j]) {
        person copy = ps[j];
        ps[j] = ps[j - 1];
        ps[j - 1] = copy;
      }
      else break;
    }
  }
}

int main() {
  people ppl{};
  read(std::cin, ppl);
  sort(ppl);
  write(std::cout, ppl);
}
