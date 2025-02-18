#pragma once
struct Vector
{
    int* data;
    int size;

    Vector();
    Vector(std::initializer_list<int> list);
    Vector(const Vector& other);
    Vector& operator=(Vector other) noexcept;
    ~Vector();
    void Swap(Vector& other) noexcept;
    void Print() const;
};

class VectorTest
{
public:
    static void Test();
};