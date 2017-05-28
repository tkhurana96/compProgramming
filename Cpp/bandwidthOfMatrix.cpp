#include <cmath>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;

  while (t-- > 0) {
    int n, temp, numZeros = 0;
    std::cin >> n;

    for (auto i = 1; i <= n * n; i++) {
      std::cin >> temp;
      if (temp == 0)
        numZeros++;
    }

    auto x = std::floor((-1 + std::pow(1 + (4 * numZeros), (0.5))) / 2);
    std::cout << n - x - 1 << '\n';
  }
  return 0;
}