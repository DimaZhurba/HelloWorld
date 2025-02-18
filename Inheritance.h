#pragma once

#include<iostream>

class B
{
public:
    B() { std::cout << "Constructor B\n"; }
    ~B() { std::cout << "Destructor B\n"; }
};

class A
{
public:
    A() { std::cout << "Constructor A\n"; }
    ~A() { std::cout << "Destructor A\n"; }

    B b;
};

class C : public A
{
public:
    C() { std::cout << "Constructor C\n"; }
    ~C() { std::cout << "Destructor C\n"; }
};

class InheritanceTest
{
public:
    static void Test();
};
