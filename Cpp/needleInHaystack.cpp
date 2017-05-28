#include <iostream>

int main() {
  std::string haystack("hello there how are you ?");
  std::string needle("how");

  auto result = haystack.find(needle);
  if (result != std::string::npos) {
    std::cout << "  needle found in haystack \n";
  } else {
    std::cout << "  needle not found\n";
  }
}