#include <algorithm>
#include <iostream>
// #include <iterator>
#include <vector>

int main() {
  int t, totalCases;
  std::cin >> t;

  totalCases = t;
  while (t--) {
    int r, c;
    std::cin >> r >> c;
    std::vector<std::vector<char>> cake(r, std::vector<char>(c, '?'));

    for (auto i = 0; i < r; i++) {
      for (auto j = 0; j < c; j++) {
        std::cin >> cake[i][j];
      }
    }

    for (auto &eachRow : cake) {
      auto res = std::find_if(eachRow.begin(), eachRow.end(),
                              [](const char &c) { return c != '?'; });

      if (res != eachRow.end()) {
        char temp = *res;
        for (auto &eachChar : eachRow) {
          if (eachChar == '?')
            eachChar = temp;
          else
            temp = eachChar;
        }
      }
    }

    auto firstNonEmptyRow =
        std::find_if(cake.begin(), cake.end(), [](const std::vector<char> &v) {
          return std::find(v.begin(), v.end(), '?') == v.end() ? true : false;
        });

    auto tempRow = *firstNonEmptyRow;
    for (auto &eachRow : cake) {
      if (std::find(eachRow.begin(), eachRow.end(), '?') != eachRow.end())
        eachRow = tempRow;
      else
        tempRow = eachRow;
    }

    std::cout << "Case #" << totalCases - t << ":\n";
    for (auto &eachRow : cake) {
      for (auto &eachChar : eachRow) {
        std::cout << eachChar;
      }
      std::cout << '\n';
    }
  }
  return 0;
}