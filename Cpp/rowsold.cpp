#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        std::string s;
        std::cin >> s;

        auto currentPickingTime = 0;
        auto totalPickingTime = 0;

        for (auto currentVal = s.rbegin() + 1; currentVal != s.rend(); currentVal++)
        {
            if (*currentVal == '1' && *(currentVal - 1) == '0')
            {
                // std::cout << " incrementing current from: " << currentPickingTime << " to: " << currentPickingTime + 1 << '\n';
                currentPickingTime++;
            }
            if (*currentVal == '1')
            {
                // std::cout << " adding to totalPickingTime: " << totalPickingTime << " " << currentPickingTime << '\n';
                totalPickingTime += currentPickingTime;
            }
        }
        // std::cout << "  s is: " << s << '\n';
        // std::cout << "  currentPickingTime is: " << currentPickingTime << '\n';
        // std::cout << "  totalPickingTime is: " << totalPickingTime << '\n';

        auto totalNumOfOnes = 0;
        for (auto &eachChar : s)
            if (eachChar == '1')
                totalNumOfOnes++;

        auto numOfOnesOnLeft = 0;
        auto totalMovingTime = 0;
        for (auto index = 0; index <= s.size(); index++)
        {
            if (s[index] == '1')
            {
                numOfOnesOnLeft++;
                // std::cout << "  totalNumOfOnes is: " << totalNumOfOnes << '\n';
                // std::cout << "  numOfOnesOnLeft is: " << numOfOnesOnLeft << '\n';
                // std::cout << "  adding to totalMovingTime: " << totalMovingTime << '\n';
                auto totalOnesOnRight = totalNumOfOnes - numOfOnesOnLeft;
                totalMovingTime += ((s.size() - 1 - totalOnesOnRight) - index);
                // std::cout << "  totalMovingTime now is: " << totalMovingTime << "\n\n";
            }
        }

        // std::cout << "  numOfOnesOnLeft: " << numOfOnesOnLeft << '\n';
        // std::cout << "  totalMovingTime: " << totalMovingTime << '\n';

        std::cout << totalMovingTime + totalPickingTime << '\n';
    }
    return 0;
}