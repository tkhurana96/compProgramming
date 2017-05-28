#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int t;
  std::cin >> t;

  while (t--) {
    double ds, dt, d;
    std::cin >> ds >> dt >> d;

    std::cout.precision(6);

    if (ds + dt >= d)
      std::cout << "0.0\n";
    else
      std::cout << std::fixed << d - ds - dt << '\n';
  }

  return 0;
}