#include<iostream>
#include<iomanip>


struct person {
  char name[16];
  unsigned height;
};

struct people {
  unsigned count;
  person people[30];
};

void read(std::istream& in, people& out) {
  for(int i = out.count;in && i < 30; i = ++out.count) {
    in >> std::setw(16) >> out.people[i].name;
    in >> out.people[i].height;
  }
}
