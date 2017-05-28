#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> rows(n, std::vector<int>(n));

  for (int i = 0; i < rows.size(); i++) {
    for (int j = 0; j < rows[i].size(); j++) {
      std::cin >> rows[i][j];
    }
  }

  for (auto &eachRow : rows) {
    std::sort(eachRow.begin(), eachRow.end());
  }

  //   for (int i = 0; i < rows.size(); i++) {
  //     int ascCount = 0, descCount = 0;

  //     auto tempRow = rows[i];
  //     std::sort(tempRow.begin(), tempRow.end());

  //     // std::cout << "   tempRow after sorting: ";
  //     // for (auto temp : tempRow)
  //     //   std::cout << temp << ' ';
  //     // std::cout << '\n';

  //     for (int j = 0; j < tempRow.size(); j++)
  //       if (tempRow[j] == rows[i][j])
  //         ascCount++;

  //     auto tempRow2 = rows[i];
  //     std::sort(tempRow2.begin(), tempRow2.end(),
  //               [](int a, int b) { return b < a; });

  //     // std::cout << "   tempRow2 after sorting: ";
  //     // for (auto temp : tempRow2)
  //     //   std::cout << temp << ' ';
  //     // std::cout << '\n';

  //     for (int j = 0; j < tempRow2.size(); j++)
  //       if (tempRow2[j] == rows[i][j])
  //         descCount++;

  //     if (ascCount >= descCount)
  //       rows[i] = tempRow;
  //     else
  //       rows[i] = tempRow2;
  //   }
  // }

  for (auto &row : rows) {
    std::cout << '\n';
    for (auto &eachEle : row)
      std::cout << eachEle << ' ';
  }
  std::cout << '\n';
  return 0;
}