#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a;
    std::vector< std::vector<int>> v;
    a.reserve(n);
    for ( int i = 0 ; i < n ; i++ )
        std::cin >> a[i];
    
    // v.push_back(static_cast<std::vector<int>>(a[0]));
    v.push_back( std::vector<int>{a[0]});

    // for ( std::vector<int> innerVec:v)
    // {
    //     for (int element : innerVec)
    //         std::cout << element;
    // }

    
    for (int i = 1 ; i < n ; i++)
    {
        for ( std::vector<int> innerVec:v)
        {
            v.push_back( std::vector<int>{innerVec.push_back(a[i])} );
        }
        v.push_back( std::vector<int>{a[i]} );
    }
    // for (int k = 0 ; k < v.size() ; k++)
    // {
    //     for ( int l = 0 ; l < v[k].size() ; l++)
    //     {
    //         std::cout<< v[k][l] << " ";
    //     }
    //     std::cout << "\n";
    // }
    return 0;
}
