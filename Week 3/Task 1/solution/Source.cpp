#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y)
{
	return x + y;
}

std::string Reverse(std::string s)
{
	std::string result = std::string();

	if (s.empty())
	{
		return result;
	}

	for (size_t i = s.size() - 1; i != 0; i--)
	{
		result.push_back(s[i]);
	}
	result.push_back(s[0]);

	return result;
}

void Sort(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
}