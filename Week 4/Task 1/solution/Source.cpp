#include <iostream>
#include <vector>
#include <algorithm>

void PrintVectorPart(const std::vector<int>& numbers)
{
	std::vector<int>::const_iterator iter = find_if(numbers.begin(), numbers.end(), [](int num)
		{
			return num < 0;
		});

	while (iter != numbers.begin())
	{
		iter--;
		std::cout << *iter << " ";
	}
}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	std::cout << std::endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });
	std::cout << std::endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	std::cout << std::endl;
	return 0;
}