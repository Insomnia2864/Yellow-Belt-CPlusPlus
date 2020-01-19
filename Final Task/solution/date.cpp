#include "date.h"

#include <iomanip>
#include <sstream>

Date::Date(int year_, int month_, int day_) :
	year(year_),
	month(month_),
	day(day_)
{}

int Date::GetYear() const
{
	return year;
}

int Date::GetMonth() const
{
	return month;
}
int Date::GetDay() const
{
	return day;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() < rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() <= rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay();
}

bool operator>(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() > rhs.GetDay();
		}

		return lhs.GetMonth() > rhs.GetMonth();
	}

	return lhs.GetYear() > rhs.GetYear();
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() >= rhs.GetDay();
		}

		return lhs.GetMonth() > rhs.GetMonth();
	}

	return lhs.GetYear() > rhs.GetYear();
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	return out << std::setw(4) << std::setfill('0') << date.GetYear() << '-'
			   << std::setw(2) << std::setfill('0') << date.GetMonth() << '-'
			   << std::setw(2) << std::setfill('0') << date.GetDay();
}

Date ParseDate(std::istream& in)
{
	int year, month, day;
	std::string tmp;
	in >> tmp;
	std::stringstream ss(tmp);

	ss >> year;
	ss.ignore(1);
	ss >> month;
	ss.ignore(1);
	ss >> day;

	return Date(year, month, day);
}