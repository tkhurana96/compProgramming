#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    std::cin >> t;
    while(t-- > 0)
        {
        std::string a,b;
        long long int k;
        std::cin >> a >> k;
        int i = 0, n = a.size();
        while (i < n && k > 0)
        {
            char temp = a[i];
            if (a[i] != 'a')
            {
                temp = 'a';
                k--;
            }
            b = b + temp;
            i++;
            std::cout << k << b << " \n";
        }
        std::cout << k << b << " \n";
        if ( k > 0)
        {
            for (int j = a.size(); j > 0 ; j--)
            {
                if (a[i] == 'a')
                {
                    b[i] = 'b';
                    k--;
                }
            }
        }
        std::cout<< a << "\t" << b << "\n";
    }
    return 0;
}
