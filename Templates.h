#pragma once


template<typename T>
constexpr decltype(auto) MaxValue(T arg)
{
    return arg;
}

template<typename T, typename... Ts>
constexpr decltype(auto) MaxValue(T arg, Ts... args)
{
    const auto rest = MaxValue(args...);
    return arg > rest ? arg : rest;
}

class TemplateTest
{
public:
    static void Test();
};

void TemplateTest::Test()
{
    // Templates
    const int val = MaxValue(1, 2, 3, 4, 8, 9, 10);
    assert(val == 10, "error");
    assert(MaxValue(1.3, 2.0, 3., 14.1, 8.9, 9.2, 1.0) == 14.1, "error");
    assert(MaxValue('a', 'v', 'c', 'b') == 'v', "error");
    std::cout << "Hello World\n";
}