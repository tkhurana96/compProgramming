#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  std::cin >> t;

  while (t--) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> dishAndIslands(k, 0);
    for (auto i = 1; i <= n; i++) {
      int pi, ki;
      std::cin >> pi;

      for (auto j = 1; j <= pi; j++) {
        std::cin >> ki;
        if (dishAndIslands[ki - 1] == 0) {
          dishAndIslands[ki - 1] = i;
        } else if (dishAndIslands[ki - 1] > 0) {
          dishAndIslands[ki - 1] = -1;
        }
      }
    }

    auto res = std::find_if(dishAndIslands.begin(), dishAndIslands.end(),
                            [](const int &currVal) { return currVal == 0; });

    if (res == dishAndIslands.end()) {

      auto newEnd = std::unique(dishAndIslands.begin(), dishAndIslands.end());
      dishAndIslands.erase(newEnd, dishAndIslands.end());

      newEnd = std::remove(dishAndIslands.begin(), dishAndIslands.end(), -1);
      dishAndIslands.erase(newEnd, dishAndIslands.end());

      if (dishAndIslands.size() == n) {
        std::cout << "all\n";
      } else {
        std::cout << "some\n";
      }
    } else {
      std::cout << "sad\n";
    }
  }
  return 0;
}