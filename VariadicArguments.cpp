#include <iostream>
#include <cstdarg>
#include "VariadicArguments.h"

void VariadicArguments::Variadic(size_t size, ...)
{
    va_list arguments;
    
    va_start(arguments, size);

    for (size_t i = 0; i < size; ++i)
    {
        int element = va_arg(arguments, int);
        std::cout << element << " ";
    }
    std::cout << std::endl;

    va_end(arguments);
}

void VariadicArgumentsTest::Test()
{
    const size_t size = 5;
    VariadicArguments::Variadic(5, 1, 2, 3, 4, 5);
}