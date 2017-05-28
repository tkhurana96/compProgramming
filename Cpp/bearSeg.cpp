#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {

  int t;
  std::cin >> t;

  while (t--) {
    long long int n, p;
    std::cin >> n >> p;

    std::vector<long long int> v(n, 0);
    for (auto &ele : v) {
      std::cin >> ele;
    }

    std::vector<std::vector<long long int>> sums(
        n, std::vector<long long int>(n, 0));

    std::for_each(v.begin(), v.end(),
                  [&](long long int &eachNum) { eachNum = eachNum % p; });

    for (auto row = 0; row < sums.size(); row++) {
      sums[row][row] = v[row];
    }

    // std::partial_sum(v.begin(), v.end(), v.begin());
    for (int i = 1; i < v.size(); i++) {
      //   std::cout << "v[i] is: " << v[i] << '\n';
      //   std::cout << "v[i-1] is: " << v[i - 1] << '\n';
      v[i] = (v[i - 1] + v[i]) % p;
      //   std::cout << '\n';
    }

    // for (auto &x : v) {
    //   std::cout << x << ' ';
    // }
    // std::cout << '\n';

    for (auto row = 0; row < sums.size(); row++) {
      for (auto col = row + 1; col < sums[row].size(); col++) {

        // std::cout << "col is: " << col << '\n';
        // std::cout << "v[col] is: " << v[col] << '\n';

        long long int sumToBe = v[col];
        if (row != 0) {
          sumToBe = (sumToBe - v[row - 1]);
          //   std::cout << "v[row -1] is: " << v[row - 1] << '\n';
          //   std::cout << "row is: " << row << '\n';
        }
        sums[row][col] = sumToBe;
        // std::cout << "\n\n";
      }
    }

    for (auto &v : sums) {
      for (auto &e : v) {
        std::cout << e << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';

    long long int maxNum = -1;
    long long int maxNumOcc = 0;

    for (auto row = 0; row < sums.size(); row++) {
      for (auto col = row; col < sums[row].size(); col++) {
        // maxNumOcc = sums[row][col] > maxNum ? 0 : maxNumOcc + 1;
        if (maxNum < sums[row][col]) {
          maxNum = sums[row][col];
          maxNumOcc = 1;
        } else if (maxNum == sums[row][col]) {
          maxNumOcc++;
        }
      }
    }

    std::cout << "ans is: " << maxNum << " " << maxNumOcc << '\n';
  }

  return 0;
}