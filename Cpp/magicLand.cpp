#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));

    auto colBest = 1, rowBest = 1, counter = 1;

    // calculating rowBest while taking input
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < m; j++) {
        std::cin >> matrix[i][j];
        if (j != 0) {
          if (matrix[i][j - 1] == matrix[i][j]) {
            counter++;
          } else {
            rowBest = std::max(rowBest, counter);
            counter = 1;
          }
        }
      }
    }

    counter = 1;
    // calculating colBest
    for (auto col = 0; col < m; col++) {
      for (auto row = 1; row < n; row++) {
        if (matrix[row][col] == matrix[row - 1][col]) {
          counter++;
        } else {
          colBest = std::max(colBest, counter);
          counter = 1;
        }
      }
    }

    std::cout << rowBest * colBest << '\n';
  }
  return 0;
}
