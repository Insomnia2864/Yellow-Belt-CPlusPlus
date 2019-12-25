#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	if ((range_end - range_begin) < 2)
	{
		return;
	}

	std::vector<typename RandomIt::value_type> elems(range_begin, range_end);

	MergeSort(elems.begin(), elems.begin() + (elems.end() - elems.begin()) / 2);
	MergeSort(elems.begin() + (elems.end() - elems.begin()) / 2, elems.end());

	std::merge(elems.begin(), elems.begin() + (elems.end() - elems.begin()) / 2,
		elems.begin() + (elems.end() - elems.begin()) / 2, elems.end(),
		range_begin);
}