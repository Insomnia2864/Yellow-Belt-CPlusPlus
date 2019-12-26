#include <iostream>
#include <string>
#include <sstream>

int main()
{
	int num, counter;
	std::cin >> num;
	std::string target;
	std::stringstream ss;
	ss << num;

	std::cin >> counter;

	int qwe = counter;

	while (counter != 0)
	{
		char operation;
		std::cin >> operation >> num;
		ss << ") " << operation << " " << num;
		counter--;
	}

	for (int i = 0; i < qwe; i++)
	{
		std::cout << '(';
	}
	std::cout << ss.str();

	return 0;
}