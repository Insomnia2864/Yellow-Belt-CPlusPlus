#include <iostream>
#include <vector>
#include <algorithm>

/*
 *  на 3 части
 */

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    size_t one_to_third = (range_end - range_begin) / 3;
    if ((range_end - range_begin) < 2)
    {
        return;
    }

    std::vector<typename RandomIt::value_type> vec(range_begin, range_end);

    RandomIt first_p = vec.begin() + (vec.end() - vec.begin()) / 3;
    RandomIt second_p = vec.begin() + (vec.end() - vec.begin()) * 2 / 3;

    MergeSort(vec.begin(), first_p);
    MergeSort(first_p, second_p);
    MergeSort(second_p, vec.end());

    std::vector<typename RandomIt::value_type> tmp_res;

    std::merge(vec.begin(), first_p,
        first_p, second_p,
        std::back_inserter(tmp_res));

    std::merge(tmp_res.begin(), tmp_res.end(),
        second_p, vec.end(),
        range_begin);
}