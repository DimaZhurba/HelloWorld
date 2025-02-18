#include <algorithm>
#include <iostream>

#include "Vector.h"

Vector::Vector()
    : data{ nullptr }
    , size{ 0 }
{}

Vector::Vector(std::initializer_list<int> list)
{
    size = list.size();
    data = new int[size];
    int i = 0;
    for (auto item : list)
    {
        data[i++] = item;
    }
}

Vector::Vector(const Vector& other)
    : data{ nullptr }
    , size{ 0 }
{
    if (other.data)
    {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
}

Vector& Vector::operator=(Vector other) noexcept
{
    other.Swap(*this);
    return *this;
}

Vector::~Vector()
{
    if (data != nullptr)
    {
        delete[] data;
    }
}

void Vector::Swap(Vector& other) noexcept
{
    std::swap(data, other.data);
    std::swap(size, other.size);
}

void Vector::Print() const
{
    if (data)
    {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
}

void VectorTest::Test()
{
    Vector v1({ 1,2,3,4,5 });
    Vector v2 = v1;
    Vector v3({ 3,2,1 });
    v2 = v3;

    v1.Print();
    v2.Print();
    v3.Print();
}