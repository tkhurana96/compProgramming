#include <iostream>

enum class seen { START, END, NONE };

int main() {

  std::ios_base::sync_with_stdio(false);
  //   std::cin.tie(NULL);

  int t;
  std::cin >> t;

  while (t--) {
    std::string s;
    std::cin >> s;

    s = s + '0';

    seen lastSeen{seen::NONE};
    bool badString{false};

    for (auto i = 0; i < s.size(); i++) {
      if (s[i] == '1' && lastSeen == seen::NONE) {
        lastSeen = seen::START;
      } else if (s[i] == '0' && lastSeen == seen::START) {
        lastSeen = seen::END;
      } else if (s[i] == '1' && lastSeen == seen::END) {
        badString = true;
        break;
      }
    }
    if (lastSeen == seen::NONE) {
      std::cout << "NO\n";
    } else if (!badString) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }

  return 0;
}