#include "phone_number.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>

PhoneNumber::PhoneNumber(const std::string& international_number)
{
	if (international_number.empty())
	{
		throw std::invalid_argument("empty string");
	}

	if (*international_number.begin() != '+')
	{
		throw std::invalid_argument("1st char isnt +");
	}

	std::stringstream ss;
	ss << international_number;
	ss.ignore(1);
	std::getline(ss, country_code_, '-');
	std::getline(ss, city_code_, '-');
	std::getline(ss, local_number_);

	if (country_code_.empty() || city_code_.empty() || local_number_.empty())
	{
		throw std::invalid_argument("smth is missing");
	}
	/*
	std::string::iterator iter = std::remove_if(local_number_.begin(), local_number_.end(), [](char t) {
		return t == '-';
		});

	local_number_.erase(iter, local_number_.end());*/
}

std::string PhoneNumber::GetCountryCode() const
{
	return country_code_;
}
std::string PhoneNumber::GetCityCode() const
{
	return city_code_;
}
std::string PhoneNumber::GetLocalNumber() const
{
	return local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const
{
	std::stringstream ss;

	ss << "+" << country_code_ << "-" << city_code_ << "-" << local_number_;
	return ss.str();
}