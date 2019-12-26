#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const std::string& prefix)
{
    std::string prefix_1 = std::string(prefix);
    std::string prefix_2 = std::string(prefix);

    prefix_2[prefix_2.size() - 1]++;

    return std::make_pair(std::lower_bound(range_begin, range_end, prefix_1),
        std::lower_bound(range_begin, range_end, prefix_2));
}