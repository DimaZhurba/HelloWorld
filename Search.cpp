#include <iostream>
#include <algorithm>
#include <map>
#include "Search.h"

std::vector<int> Search(std::vector<int> nums, int target)
{
    std::map<int, int> numMap;
    for (size_t i = 0; i < nums.size(); ++i) // O(N*LogN)
        numMap[nums[i]] = i;

    int firstIndex = -1, secondIndex = -1;

    for (auto& pair : numMap) // O(N*LogN)
    {
        int firstOper = pair.first;
        auto iter = numMap.find(target - firstOper);
        if (iter != numMap.end())
        {
            firstIndex = pair.second;
            secondIndex = iter->second;
            break;
        }
    }

    return { firstIndex, secondIndex };
}

void SearchTest::Test()
{
    //auto result = Search({ 2, 7, 11, 15 }, 9);
    auto result = Search({ 3, 2, 4 }, 6);
    for (auto item : result)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}