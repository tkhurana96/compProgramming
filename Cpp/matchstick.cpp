#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	long long int n, c, bi, mi;
	std::vector<long long int> matchStickVector;
	std::cin >> n >> c;
	for (int i = 1; i <= c; i++)
	{
		std::cin >> bi >> mi;
		std::vector<long long int> tempVector(bi, mi);
		matchStickVector.insert(matchStickVector.end(), tempVector.begin(), tempVector.end());
	}
	std::sort(matchStickVector.begin(), matchStickVector.end(), [](int a, int b) {return b < a;});
	long long int i = 0, totalMatchSticks = 0;
	while (n && i < matchStickVector.size())
	{
		totalMatchSticks += matchStickVector[i];
		i++;
		n--;
	}
	std::cout << totalMatchSticks << '\n';
	return 0;
}