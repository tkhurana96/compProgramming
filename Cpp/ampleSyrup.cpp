#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main() {

  int t;
  std::cin >> t;

  while (t--) {
    long long int n, k;
    std::cin >> n >> k;

    std::vector<std::tuple<long long int, long long int>> radiusAndHeights(
        n, std::tuple<long long int, long long int>(0, 0));

    for (auto i = 1; i <= n; i++) {
      std::cin >> std::get<0>(radiusAndHeights[i]) >>
          std::get<0>(radiusAndHeights[i]);
    }

    // std::for_each(
    //     radiusAndHeights.begin(), radiusAndHeights.end(), [](auto &eachPair)
    //     {
    //       std::cout << eachPair.first << '>' << eachPair.second << '\n';
    //     });

    for (auto &x : radiusAndHeights) {
      std::cout << std::get<0>(x) << '-' << std::get<1>(x) << '\n';
    }
  }
  return 0;
}