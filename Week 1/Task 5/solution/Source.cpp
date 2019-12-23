#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <sstream>

template <typename T>
T Sqr(T value);

template <typename T>
std::vector<T> operator*(const std::vector<T>& lhs, const std::vector<T>& rhs);

template <typename Key, typename Value>
std::map<Key, Value> operator*(const std::map<Key, Value>& lhs, const std::map<Key, Value>& rhs);

template <typename First, typename Second>
std::pair<First, Second> operator*(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs);

int main()
{
	std::vector<int> v = { 1, 2, 3 };
	std::cout << "vector:";
	for (int x : Sqr(v)) {
		std::cout << ' ' << x;
	}
	std::cout << std::endl;

	std::map<int, std::pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	std::cout << "map of pairs:" << std::endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
	}
}

template <typename T>
T Sqr(T value)
{
	return value * value;
}


template <typename T>
std::vector<T> operator*(const std::vector<T>& lhs, const std::vector<T>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		std::stringstream ss;
		ss << lhs.size() << "!=" << rhs.size();
		throw std::invalid_argument(ss.str());
	}

	std::vector<T> result;
	result.reserve(lhs.size());

	for (size_t i = 0; i < lhs.size(); i++)
	{
		result.push_back(lhs.at(i) * rhs.at(i));
	}

	return result;
}

template <typename Key, typename Value>
std::map<Key, Value> operator*(const std::map<Key, Value>& lhs, const std::map<Key, Value>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		std::stringstream ss;
		ss << lhs.size() << "!=" << rhs.size();
		throw std::invalid_argument(ss.str());
	}

	std::map<Key, Value> result;

	for (const auto& pr : lhs)
	{
		result[pr.first] = lhs.at(pr.first) * rhs.at(pr.first);
	}

	return result;
}

template <typename First, typename Second>
std::pair<First, Second> operator*(const std::pair<First, Second>& lhs, const std::pair<First, Second>& rhs)
{
	return std::make_pair(lhs.first * rhs.first, lhs.second * rhs.second);
}