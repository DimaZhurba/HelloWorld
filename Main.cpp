#include <iostream>
#include <cassert>

#include "Templates.h"
#include "Search.h"
#include "Sorter.h"


int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    /*
    // Templates
    const int val = MaxValue(1, 2, 3, 4, 8, 9, 10);
    assert(val == 10, "error");
    assert(MaxValue(1.3, 2.0, 3., 14.1, 8.9, 9.2, 1.0) == 14.1, "error");
    assert(MaxValue('a', 'v', 'c', 'b') == 'v', "error");
    std::cout << "Hello World\n";

    //auto result = Search({ 2, 7, 11, 15 }, 9);
    auto result = Search({ 3, 2, 4 }, 6);
    for (auto item : result)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    unsigned int x = -1; std::cout << x;*/

    for (size_t i = 10; i <= 10; ++i)
    {
        auto unsortedVector = Sorter<char>::GenerateVector(i);
        auto sortedVector = Sorter<char>::MergeSort(unsortedVector, true);

        for (auto& item : unsortedVector)
            std::cout << item << " ";
        std::cout << std::endl;
        for (auto& item : sortedVector)
            std::cout << item << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return 0;
}