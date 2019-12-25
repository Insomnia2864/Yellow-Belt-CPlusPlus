#include <iostream>
#include <set>

std::set<int>::const_iterator FindNearestElement(
    const std::set<int>& numbers,
    int border)
{
    if (numbers.empty())
    {
        return numbers.cend();
    }

    auto a = numbers.lower_bound(border);

    if (a == numbers.cbegin())
    {
        return a;
    }
    
    if (a == numbers.cend())
    {
        return std::prev(a);
    }

    auto b = std::prev(a);

    return ((*a) - border) < (border - (*b)) ? a : b;

}