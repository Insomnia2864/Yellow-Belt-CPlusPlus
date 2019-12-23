#include <iostream>
#include <cstdint>

int main()
{
	std::size_t N;
	std::size_t R, W, H, D;
	std::uint64_t result = 0;

	std::cin >> N >> R;

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> W >> H >> D;

		result += static_cast<uint64_t>(R * W * H * D);
	}

	std::cout << result;

	return 0;
}