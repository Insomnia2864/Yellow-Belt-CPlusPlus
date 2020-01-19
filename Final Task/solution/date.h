#pragma once
#include <ostream>
#include <istream>

class Date
{
public:
	Date() = delete;

	Date(int year_, int month_, int day_);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

private:
	int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& out, const Date& date);

Date ParseDate(std::istream& in);