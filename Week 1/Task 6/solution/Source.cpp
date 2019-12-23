#include <iostream>
#include <map>
#include <stdexcept>

template <typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, Key key)
{
	if (m.count(key) == 0)
	{
		throw std::runtime_error("there is no such key");
	}

	return m.at(key);
}

int main()
{
	std::map<int, std::string> m = { {0, "value"} };
	std::string& item = GetRefStrict(m, 0);
	item = "newvalue";
	std::cout << m[0] << std::endl; // выведет newvalue
}