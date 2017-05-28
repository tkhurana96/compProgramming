#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int t;
  std::cin >> t;

  while (t-- > 0) {
    long int n;
    long long int temp;
    std::vector<long long int> sequence;

    std::cin >> n;
    sequence.reserve(n);

    for (auto i = 1; i <= n; i++) {
      std::cin >> temp;
      sequence.push_back(temp);
    }

    std::sort(sequence.begin(), sequence.end());

    if (sequence[1] - sequence[0] != 1)
      std::cout << sequence[0] << '\n';
    else if (sequence[sequence.size() - 1] - sequence[sequence.size() - 2] != 1)
      std::cout << sequence[sequence.size() - 1] << '\n';
    else {
      long long int i;
      for (i = 1; i < sequence.size(); i++)
        if (sequence[i] - sequence[i - 1] == 0)
          break;
      std::cout << sequence[i] << '\n';
    }
  }
  return 0;
}