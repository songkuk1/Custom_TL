#pragma once
#include <iostream>

namespace JTL
{
    template<typename Iterator>
    void iter_swap(Iterator a, Iterator b)
    {
        auto tmp = std::move(*a);
        *a = std::move(*b);
        *b = std::move(tmp);
    }

    template <typename Iterator, typename T>
    Iterator find(Iterator first, Iterator last, const T& value)
    {
        for (; first != last; ++first)
            if (*first == value)
                return first;
        return last;
    }

    template<typename Iterator>
    Iterator partition(Iterator begin, Iterator end)
    {

        auto pivot = *(begin + (end - begin) / 2);

        Iterator low = begin;
        Iterator high = end - 1;      

        while (true)
        {
            while (low < end && *low < pivot) ++low;  
            while (high >= begin && *high > pivot) --high;

            if (low >= high)
                return high; 

            iter_swap(low, high);
            ++low;
            --high;
        }
    }

    template<typename Iterator>
    void sort(Iterator begin, Iterator end)
    {
        if ((end - 1) - begin <= 1) return;

        Iterator q = partition(begin, end);

        sort(begin, q + 1);
        sort(q + 1, end);  
    }
}