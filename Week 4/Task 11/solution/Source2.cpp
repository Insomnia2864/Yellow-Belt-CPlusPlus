#include <iostream>
#include <string>
#include <sstream>

bool ifNeeded(char a, char b)
{
	if (((b == '/') || (b == '*')) && ((a == '+') || (a == '-')))
	{
		return true;
	}

	return false;
}

int main()
{
	int num, counter;
	std::cin >> num;
	std::string target;
	std::stringstream ss;
	ss << num;

	std::cin >> counter;

	int qwe = 0;
	char prev_op = '*';

	while (counter != 0)
	{
		char operation;
		std::cin >> operation >> num;
		if (ifNeeded(prev_op, operation))
		{
			qwe++;
			ss << ')';
		}
		
		ss << ' ' << operation << ' ' << num;

		prev_op = operation;
		counter--;
	}

	for (int i = 0; i < qwe ; i++)
	{
		std::cout << '(';
	}
	std::cout << ss.str();

	return 0;
}