// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <vector>

// std::map<int, char> colorCode{{1, 'R'}, {2, 'O'}, {3, 'Y'},
//                               {4, 'G'}, {5, 'B'}, {6, 'V'}};
// int main() {

//   int t;
//   std::cin >> t;

//   while (t--) {
//     int n;
//     std::vector<int> colors(7, 0);

//     for (auto &color : colors) {
//       std::cin >> color;
//     }

//     std::vector<char> answer(colors[0], ' ');
//     for (auto index = 0; index <= answer.size();) {
//       if (index != ' ')
//         break;
//       auto maxIter = std::max_element(colors.begin(), colors.end());
//       auto maxIndex = std::distance(maxIter, colors.begin());
//       auto res = colorCode.find(maxIndex);
//       std::cout << res->second << ' ';

//       answer[index] = res->second;
//       if (*maxIter == 1) {
//         index++;
//       } else {
//         index = (index + 2) % n;
//       }

//       *maxIter = *maxIter - 1;
//     }
//   }
//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

auto simpleArrange(std::map<char, long long int> numHorses,
                   std::vector<char> &arrangement) {

  numHorses['O'] = numHorses['V'] = numHorses['Y'] = 0;

  auto maxIter = std::max_element(
      numHorses.begin(), numHorses.end(),
      [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

  if (maxIter->second > std::floor(arrangement.size() / 2)) {
    return 0;
  } else {

    auto i = 0;
    for (; i < arrangement.size(); i = ((i + 2) % arrangement.size())) {
      arrangement[i] = 'R';
      maxIter->second--;
    }
    std::cout << "placed reds\n\n";

    maxIter = std::max_element(
        numHorses.begin(), numHorses.end(),
        [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

    while (maxIter->second > 0) {
      // for (i = i + 1; i < arrangement.size();)
      i = i + 1;
      while (maxIter->second > 0) {
        if (arrangement[i] == ' ') {
          arrangement[i] = maxIter->first;
          maxIter->second--;
        }
        i = ((i + 1) % arrangement.size());
      }
      maxIter = std::max_element(
          numHorses.begin(), numHorses.end(),
          [](const auto &p1, const auto &p2) { return p1.second < p2.second; });
    }

    return 1;
  }
}

int main() {

  int t;
  std::cin >> t;

  while (t--) {
    std::map<char, long long int> numHorses{{'R', 0}, {'O', 0}, {'Y', 0},
                                            {'G', 0}, {'B', 0}, {'V', 0}};

    long long int n;
    std::cin >> n;

    std::for_each(numHorses.begin(), numHorses.end(),
                  [](auto &eachPair) { std::cin >> eachPair.second; });

    std::for_each(numHorses.begin(), numHorses.end(), [](auto &eachPair) {
      std::cout << eachPair.first << " -> " << eachPair.second << '\n';
    });

    std::vector<char> arrangement(n, ' ');

    auto res = simpleArrange(numHorses, arrangement);

    if (!res) {
      std::cout << "IMPOSSIBLE\n";
    } else {

      for (auto &horse : arrangement) {
        std::cout << horse << ' ';
      }
      std::cout << '\n';
    }
  }
  return 0;
}