#include <iostream>
#include <cassert>

#include "Templates.h"
#include "Search.h"
#include "Sorter.h"
#include "VariadicArguments.h"
#include "String.h"
#include "Vector.h"
#include "Inheritance.h"


int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    TemplateTest::Test();
    SorterTest::Test();
    VariadicArgumentsTest::Test();
    StringTest::Test();
    SearchTest::Test();
    VectorTest::Test();
    InheritanceTest::Test();


    unsigned int x = -1; std::cout << x;

    return 0;
}