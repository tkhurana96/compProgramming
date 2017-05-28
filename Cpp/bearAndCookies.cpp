#include <iostream>
#include <vector>

int main(){
	int t;
	std::cin >> t;
	while (t > 0){
		int n;
		std::cin >> n;
		std::vector<std::string> minutes(n);
		for (auto &eachMinute: minutes)
			std::cin >> eachMinute;
		bool followed(true);
		for (int i = 0; i < minutes.size() - 1; i++){
			if (minutes[i] == "cookie" && minutes[i + 1] != "milk"){
				followed = false;
				break;
			}
		}
		if (minutes[minutes.size() - 1] == "cookie")
			followed = false;
		if (followed)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
		t--;
	}
	return 0;
}