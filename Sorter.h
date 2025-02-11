#pragma once

#include <vector>

template<typename T>
class Sorter
{
public:
    static std::vector<T> GenerateVector(const size_t size);

    static std::vector<T> MergeSort(const std::vector<T>& range, const bool log = false);

private:
    static void MergeSortImpl(T range[], T buffer[], const size_t start, const size_t end,
        const size_t depth = 0, const bool log = false);
};

template<typename T>
std::vector<T> Sorter<T>::GenerateVector(const size_t size)
{
    std::vector<T> result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result[i] = rand() % 100;
    }
    return result;
}

template<>
std::vector<char> Sorter<char>::GenerateVector(const size_t size)
{
    std::vector<char> result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result[i] = rand() % ('Z' - 'A' + 1) + 'A';
    }
    return result;
}


template<typename T>
std::vector<T> Sorter<T>::MergeSort(const std::vector<T>& range, const bool log)
{
    const size_t num = range.size();
    T* arr = new T[num] {};
    T* buffer = new T[num] {};

    for (size_t i = 0; i < num; ++i)
    {
        arr[i] = range[i];
    }

    MergeSortImpl(arr, buffer, 0, num - 1, 0, log);
    std::vector<T> result(arr, arr + num);

    delete[] buffer;
    delete[] arr;

    return result;
}

template<typename T>
void Sorter<T>::MergeSortImpl(T range[], T buffer[], const size_t start, const size_t end,
    const size_t depth, const bool log)
{
    if (log)
    {
        for (size_t i = 0; i < depth; ++i)
        {
            std::cout << " ";
        }
        std::cout << "range [" << start << ", " << end << "]" << std::endl;
    }

    if (start >= end)
        return;

    const size_t middle = (start + end) / 2;
    MergeSortImpl(range, buffer, start, middle, depth + 1, log);
    MergeSortImpl(range, buffer, middle + 1, end, depth + 1, log);

    size_t bufId = start;
    size_t leftId = start;
    const size_t leftEnd = middle;
    size_t rightId = middle + 1;
    const size_t rightEnd = end;

    while (leftId <= leftEnd && rightId <= rightEnd)
    {
        buffer[bufId++] = (range[leftId] < range[rightId]) ?
            range[leftId++] : range[rightId++];
    }
    while (leftId <= leftEnd)
    {
        buffer[bufId++] = range[leftId++];
    }
    while (rightId <= rightEnd)
    {
        buffer[bufId++] = range[rightId++];
    }
    for (size_t i = start; i <= end; ++i)
    {
        range[i] = buffer[i];
    }
}