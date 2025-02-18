#include "String.h"

#include <iostream>
#include <cstring>

// destination - enough
// source is valid c string
char* String::strcpy(char* destination, const char* source)
{
    const char* sourceIter = source;
    char* destIter = destination;
    do
    {
        *(destIter++) = *sourceIter;
    } while (*(sourceIter++) != '\0');
    return destination;
}

void StringTest::Test()
{
    const char* source = "Hello World!";
    char destination[13] = { 'f' };
    //std::memset(destination, 'f');
    String::strcpy(destination, source);
    std::cout << destination;
}