#include <iostream>
#include <string>
#include <vector>

int main() {
  //   std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int t;
  std::cin >> t;

  while (t--) {
    long long int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<long long int> countsOfB;
    countsOfB.resize(s.size(), 0);

    // std::cout << s;

    std::cout << " this is: " << s[s.size() - 1] << '\n';
    auto lastChar = s[s.size() - 1];
    if (lastChar == 'b') {
      std::cout << "inside if";
      countsOfB[s.size() - 1] = 1;
    }

    for (auto index = s.size() - 2; index >= 0; index--) {
      countsOfB[index] = countsOfB[index + 1];
      if (s[index] == 'b') {
        countsOfB[index]++;
      }
    }

    for (auto &eachCount : countsOfB) {
      eachCount *= k;
    }

    long long int totalPairs = 0;
    for (auto index = 0; index <= s.size(); index++) {
      if (s[index] == 'a') {
        totalPairs += (countsOfB[index]);
      }
    }

    std::cout << totalPairs << '\n';
  }

  return 0;
}