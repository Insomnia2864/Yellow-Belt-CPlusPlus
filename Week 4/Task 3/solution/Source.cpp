#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> SplitIntoWords(const std::string& s)
{
	std::stringstream ss;
	ss << s;
	std::string tmp;
	std::vector<std::string> result;

	while (ss)
	{
		ss >> tmp;
		result.push_back(tmp);

	}

    result.pop_back();

	return result;
}

int main() {
    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}