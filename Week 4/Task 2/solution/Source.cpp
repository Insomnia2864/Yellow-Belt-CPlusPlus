#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border)
{
	std::vector<T> result;

	auto iter = elements.upper_bound(border);

	for (auto it = iter; it != elements.end(); it++)
	{
		result.push_back(*it);
	}

	return result;
}

int main() {
    for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
		std::cout << x << " ";
    }
	std::cout << std::endl;

	std::string to_find = "Python";
	std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
    return 0;
}