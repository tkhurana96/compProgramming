#include <iostream>
#include <vector>
#include <string>

class Cross
{
public:
	std::string exist(std::vector<std::string> board)
	{
		bool found{false};
		for (int i = 1; i <= board.size() - 2; i++)
		{
			for (int j = 1; j <= board[i].size() - 2; j++)
			{
				if ((board[i][j] == '#') && (board[i-1][j] == '#') && (board[i+1][j] == '#') && (board[i][j-1] == '#') && (board[i][j+1] == '#'))
				{
					found = true;
					return "Exist";
				}
			}
		}
		return "Does not exist";
	}
	
};

int main()
{
	Cross obj1;
	std::cout << obj1.exist(std::vector<std::string> {".##", "###", "##."}) << '\n';
	std::cout << obj1.exist(std::vector<std::string> {".##", "###", "#.."}) << '\n';
	std::cout << obj1.exist(std::vector<std::string> {"######", "######", "######", "######", "######", "######", "######"}) << '\n';
	std::cout << obj1.exist(std::vector<std::string> {".#.#", "#.#.", ".#.#", "#.#."}) << '\n';
	std::cout << obj1.exist(std::vector<std::string> {".#.#", "###.", ".###", "#.#."}) << '\n';
	std::cout << obj1.exist(std::vector<std::string> {"###","###", "###"}) << '\n';
	return 0;
}