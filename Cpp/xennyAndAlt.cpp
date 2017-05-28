#include <iostream>

int main() {
  int t;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::cin >> t;
  while (t-- > 0) {
    long long int n, temp;
    long long int xOddSum(0), xEvenSum(0), yOddSum(0), yEvenSum(0);

    std::cin >> n;

    for (auto i = 1; i <= n; i++) {
      std::cin >> temp;
      if (i & 1)
        xOddSum += temp;
      else
        xEvenSum += temp;
    }

    for (auto i = 1; i <= n; i++) {
      std::cin >> temp;
      if (i & 1)
        yOddSum += temp;
      else
        yEvenSum += temp;
    }

    auto minSum = ((xOddSum + yEvenSum) <= (xEvenSum + yOddSum))
                      ? (xOddSum + yEvenSum)
                      : (xEvenSum + yOddSum);
    std::cout << minSum << '\n';
  }
  return 0;
}