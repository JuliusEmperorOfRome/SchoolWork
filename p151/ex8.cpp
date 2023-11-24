#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>

struct person {
  char name[16];
  double average, percentage10;

  //Rust's influence
  static person from(const char (&name)[16], const std::vector<int>& points) {
    person ret{};
    memcpy(&ret.name, name, sizeof(name));

    int sum = 0;
    int count10 = 0;
    for (const int& p : points) {
        sum += p;
        count10 += (p == 10);
    }

    // avoid division by 0
    double len = points.size() ? points.size() : 1.0;

    ret.average = sum / len;
    ret.percentage10 = 100.0 * (count10 / len);

    return ret;
  }
};

void process(std::istream& in, std::ostream& out) {
  person* ppl = nullptr;
  int ppl_count;
  in >> ppl_count;
  ppl = new person[ppl_count];

  std::vector<int> points;
  for(int i = 0; i < ppl_count; ++i) {
    points.clear();
    char name[16];
    in >> std::setw(16) >> name;
    for(;;) {
        int p;
        if(!(in >> p)) {
            break;
        }
        points.push_back(p);
    }
    in.clear();
    ppl[i] = person::from(name, points);
  }
  
  int best_avg_index = 0;
  int best_p10_index = 0;
  for(int i = 1; i < ppl_count; ++i) {
    const person& me = ppl[i];
    if(ppl[best_avg_index].average < me.average) {
        best_avg_index = i;
    }
    if(ppl[best_p10_index].percentage10 < me.percentage10) {
        best_p10_index = i;
    }
  }

  const auto& best_avg = ppl[best_avg_index];
  const auto& best_p10 = ppl[best_p10_index];
  out << std::setprecision(1) << std::fixed;
  out << "Taikliausias — " << best_avg.name << ' ' << best_avg.average << '\n';
  out << "Daug. deš. % — " << best_p10.name << ' ' << best_p10.percentage10 << std::flush;
  delete[] ppl;
}

int main() {
    process(std::cin, std::cout);
}
