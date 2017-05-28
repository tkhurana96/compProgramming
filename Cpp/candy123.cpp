#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int t;
  std::cin >> t;

  while (t--) {
    long long int a, b;
    std::cin >> a >> b;

    for (auto i = 1;; i++) {
      if (i & 1) {
        a -= i;
      } else {
        b -= i;
      }

      if (a < 0) {
        std::cout << "Bob\n";
        break;
      }
      if (b < 0) {
        std::cout << "Limak\n";
        break;
      }
    }
  }

  return 0;
}