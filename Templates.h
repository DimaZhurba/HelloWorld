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