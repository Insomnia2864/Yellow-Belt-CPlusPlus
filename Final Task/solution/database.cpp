#include "database.h"

#include <sstream>
#include <algorithm>

void Database::Add(const Date& date, const std::string& event)
{
	Data& tmp = storage[date];

	if (tmp.st_.count(event) == 0)
	{
		tmp.st_.insert(event);
		tmp.vec_.push_back(event);
	}
}

void Database::Print(std::ostream& out) const
{
	for (const auto& [key, value] : storage)
	{
		for (const auto& j : value.vec_)
		{
			out << key << ' ' << j << '\n';
		}
	}
}

std::string Database::Last(const Date& date) const
{
	auto it = storage.upper_bound(date);
	
	if (it == storage.begin())
	{
		return "No entries";
	}

	std::stringstream ss;

	ss << (--it)->first << ' ' << it->second.vec_.back();

	return ss.str();
}