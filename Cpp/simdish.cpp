#include <iostream>
#include <set>

auto fun()
{
    return 32 & (1 << 5);
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // // std::cin.tie(NULL);

    // int t;
    // std::cin >> t;

    // while (t--)
    // {
    //     std::set<std::string> ingredients;
    //     std::string eachIngredient;
    //     for (auto i = 1; i <= 8; i++)
    //     {
    //         std::cin >> eachIngredient;
    //         ingredients.insert(eachIngredient);
    //     }

    //     if (ingredients.size() == 4 || ingredients.size() == 5 || ingredients.size() == 6)
    //     {
    //         std::cout << "similar\n";
    //     }
    //     else
    //     {
    //         std::cout << "dissimilar\n";
    //     }
    // }

    auto y = 72;
    auto x = 1 << 5;
    auto res = fun();
    std::cout << res;
    return 0;
}