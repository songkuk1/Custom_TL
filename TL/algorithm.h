#pragma once

namespace JTL 
{
    template <typename Iterator, typename T>
    Iterator find(Iterator first, Iterator last, const T& value) 
    {

        for (; first != last; ++first) 
        {

            if (*first == value) 
            {
                return first; 
            }
        }
        return last;
    }
}