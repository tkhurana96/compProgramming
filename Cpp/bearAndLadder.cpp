#include <cmath>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int q;
  std::cin >> q;
  while (q--) {
    long long int a, b;
    std::cin >> a >> b;

    if (std::abs(a - b) == 2) {
      std::cout << "YES\n";
    } else if (std::ceil(a / 2.0) == std::ceil(b / 2.0)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}