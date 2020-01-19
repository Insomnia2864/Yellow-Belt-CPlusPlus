#pragma once

#include "date.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <ostream>
#include <utility>
#include <future>
#include <algorithm>

struct Data
{
	std::set<std::string> st_;
	std::vector<std::string> vec_;
};

class Database
{
public:
	void Add(const Date& date, const std::string& event);
	void Print(std::ostream& out) const;

	template <typename L>
	int RemoveIf(const L predicate);

	template <typename L>
	std::vector<std::pair<Date, std::string>> FindIf(const L predicate) const;

	std::string Last(const Date& date) const;

private:
	std::map<Date, Data> storage;
};

template <typename L>
int Database::RemoveIf(const L predicate)
{
	int counter = 0;
	std::map<Date, Data> new_map;
	for (auto& [key, value] : storage)
	{
		for (auto& i : value.vec_)
		{
			if (!predicate(key, i))
			{
				Data& tmp = new_map[key];
				tmp.st_.insert(i);
				tmp.vec_.push_back(std::move(i));
			}
			else
			{
				counter++;
			}
		}
	}

	storage = std::move(new_map);

	return counter;
}

template <typename L>
std::vector<std::pair<Date, std::string>> Database::FindIf(const L predicate) const
{
	std::vector<std::pair<Date, std::string>> result;

	for (auto& [key, value] : storage)
	{
		for (std::size_t i = 0; i < value.vec_.size(); i++)
		{
			if (predicate(key, value.vec_[i]))
			{
				result.push_back(std::make_pair(key, value.vec_[i]));
			}
		}
	}

	return result;
}