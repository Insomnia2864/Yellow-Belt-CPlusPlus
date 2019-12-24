#pragma once
#include <string>
#include <vector>
#include <map>
#include <ostream>

struct BusesForStopResponse
{
    std::string stop;
    std::vector<std::string> buses;
};

struct StopsForBusResponse
{
    std::string bus;
    std::map<std::string, std::vector<std::string>> buses;
    std::map<std::string, std::vector<std::string>> stops;
};

struct AllBusesResponse {
    std::map<std::string, std::vector<std::string>> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);