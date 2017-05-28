#include <bits/stdc++.h>

class SuperUserDo
{
public:
	int install(std::vector<int> A, std::vector<int> B)
	{
		// int maxOfA = *std::max_element(A.begin(), A.end());
		// int maxOfB = *std::max_element(B.begin(), B.end());
		// std::cout << maxOfA << maxOfB << '\n';
		// auto size = std::max(maxOfA, maxOfB);
		auto size = std::max(*std::max_element(A.begin(), A.end()), *std::max_element(B.begin(), B.end()));
		std::cout << "calulated size for final array is : " << size << '\n';
		std::vector<int> final(size);
		final.resize(size);
		std::cout << "final array size : " << final.size() << '\n';
		std::cout << "final array capacity : " << final.capacity() << '\n';
		for (int i = 0, j = 0; i < A.size(), j < B.size(); i++, j++)
		{
			// std::cout << "loop running from k = " << A[i] << " to k = " <<B[j] << '\n';
			for (int k = A[i]; k <= B[j]; k++)
				final[k] |= 1;
		}
		int sum = std::accumulate(final.begin(), final.end(),0);
		return sum;
	}	
};

int main()
{
	SuperUserDo obj;
	std::cout << obj.install(std::vector<int>{1}, std::vector<int>{10}) << '\n';
	std::cout << obj.install(std::vector<int>{1}, std::vector<int>{1}) << '\n';
	std::cout << obj.install(std::vector<int>{1, 101}, std::vector<int>{10, 110}) << '\n';
	std::cout << obj.install(std::vector<int>{1}, std::vector<int>{1000}) << '\n';
	std::cout << obj.install(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{6, 7, 8, 9, 10}) << '\n';
	std::cout << obj.install(std::vector<int>{1, 1}, std::vector<int>{1, 1}) << '\n';
	return 0;
}
