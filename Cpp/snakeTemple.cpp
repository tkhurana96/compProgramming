#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int t;
    std::cin >> t;

    while(t--){

        long long int n;
        std::cin >> n;

        std::vector<long long int> heights(n, 0);
        for (auto &h: heights){
            std::cin >> h;
        }

        std::cout << "heights are: ";
        for (auto &h: heights){
            std::cout << h << ' ';
        }
        std::cout << '\n';


        std::vector<long long int> specialPointIndexes;

        if (heights[0] < heights[1]) {
            specialPointIndexes.push_back(0);
        }

        for (auto i = 1; i < heights.size()- 1; i++){
            if ( heights[i-1] >= heights[i] && heights[i] <= heights[i+1]){
                specialPointIndexes.push_back(i);
            }
        }

        specialPointIndexes.push_back(heights.size() - 1);
        std::cout << "specialPointIndexes are: ";
        for (auto &s: specialPointIndexes){
            std::cout << s << ' ';
        }
        std::cout << '\n';

        std::vector<long long int> cumulativeHeights(heights);
        for (auto i = 1; i <= cumulativeHeights.size() -1; i++ ){
            cumulativeHeights[i] += cumulativeHeights[i-1];
        }

        std::cout << "cumulative heights are: ";
        for (auto &h: cumulativeHeights){
            std::cout << h << ' ';
        }
        std::cout << '\n';

        long long int minOperations = 1000000000000000;

        for (auto i = 0; i < specialPointIndexes.size() -1 ; i++){
            auto intervalLength = specialPointIndexes[i+1] - specialPointIndexes[i] + 1;
            std::cout << "  intervalLength before updating: " << intervalLength << '\n';
            if ( intervalLength & 1){
                intervalLength++;
                auto n = (intervalLength / 2) - 1;
                std::cout << "  intervalLength after updating: " << intervalLength << '\n';
                auto intervalSumWouldHaveBeen = 2* ((n * (n+1)) / 2) + (intervalLength / 2);
                std::cout << "  intervalSumWouldHaveBeen: " << intervalSumWouldHaveBeen << '\n';
                auto intervalActualSum = cumulativeHeights[specialPointIndexes[i+1]] - cumulativeHeights[specialPointIndexes[i-1]];
                std::cout << "  intervalActualSum: "<< intervalActualSum << '\n';
                if (intervalActualSum >= intervalSumWouldHaveBeen){
                    auto sumToBeMadeZero = cumulativeHeights[specialPointIndexes[i-1]] + (cumulativeHeights[cumulativeHeights.size()-1] - cumulativeHeights[specialPointIndexes[i+1]]);
                    sumToBeMadeZero += intervalActualSum - intervalSumWouldHaveBeen;
                    std::cout << "  sumToBeMadeZero is: " << sumToBeMadeZero << '\n';
                    minOperations = std::min(sumToBeMadeZero, minOperations);
                }
            }
            else {
                auto peakIndex = std::distance(heights.begin(), std::max_element(heights.begin() + specialPointIndexes[i], heights.begin() + specialPointIndexes[i+1]));
                for (auto eachPossibleIndex = specialPointIndexes[i]; eachPossibleIndex < peakIndex; eachPossibleIndex++){
                    for (auto eachOddLengthInc = 2; eachPossibleIndex + eachOddLengthInc <= intervalLength; eachOddLengthInc += 2){
                        auto n = eachOddLengthInc / 2;
                        auto intervalSumWouldHaveBeen = 2* ((n * (n+1)) / 2) + n + 1;
                        std::cout << "  intervalSumWouldHaveBeen: " << intervalSumWouldHaveBeen << '\n';
                        auto intervalActualSum = cumulativeHeights[eachPossibleIndex + eachOddLengthInc] - cumulativeHeights[eachPossibleIndex - 1];
                        std::cout << "  intervalActualSum: "<< intervalActualSum << '\n';
                        if (intervalActualSum >= intervalSumWouldHaveBeen){
                            auto sumToBeMadeZero = cumulativeHeights[eachPossibleIndex] + (cumulativeHeights[cumulativeHeights.size()-1] - cumulativeHeights[eachPossibleIndex+eachOddLengthInc]);
                            sumToBeMadeZero += intervalActualSum - intervalSumWouldHaveBeen;
                            std::cout << "  sumToBeMadeZero is: " << sumToBeMadeZero << '\n';
                            minOperations = std::min(sumToBeMadeZero, minOperations);
                        }
                    }
                }

                
            }
        }

        std::cout << minOperations << '\n';
    }

    return 0;
}