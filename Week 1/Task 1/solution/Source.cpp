#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
	std::int64_t N;
	int64_t tmp;
	std::int64_t avg = 0;
	std::vector<int64_t> tempVector;
	
	std::cin >> N;
	tempVector.reserve(N);
	
	for (int64_t i = 0; i < N; i++)
	{
		std::cin >> tmp;
		avg += tmp;
		tempVector.push_back(tmp);
	}

	avg /= N;

	std::vector<int64_t> days;
	
	for (int64_t i = 0; i < N; i++)
	{
		if (tempVector[i] > avg)
		{
			days.push_back(i);
		}
	}

	std::cout << days.size() << std::endl;

	for (int64_t i = 0; i < days.size(); i++)
	{
		std::cout << days[i] << " ";
	}


	return 0;
}