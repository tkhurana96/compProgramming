#include <algorithm>
#include <iostream>
#include <string>

enum class lastSeen { None, Head };

int main() {

  std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int r;
  std::cin >> r;

  while (r--) {
    int l;
    std::cin >> l;

    std::string s;
    std::cin >> s;

    s.erase(std::remove(s.begin(), s.end(), '.'), s.end());

    lastSeen seen{lastSeen::None};
    bool invalid(false);

    for (auto &x : s) {
      if (seen == lastSeen::None && x == 'H') {
        seen = lastSeen::Head;
      } else if (seen == lastSeen::Head && x == 'T') {
        seen = lastSeen::None;
      } else {
        invalid = true;
        break;
      }
    }

    if (invalid || seen != lastSeen::None) {
      std::cout << "Invalid\n";
    } else {
      std::cout << "Valid\n";
    }
  }

  return 0;
}