#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r)
{
    if (r.buses.empty())
    {
        return os << "No stop";
    }

    for (const auto& i : r.buses)
    {
        os << i << " ";
    }

    return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r)
{
    if (r.buses.count(r.bus) == 0)
    {
        return os << "No bus";
    }

    for (const auto& i : r.buses.at(r.bus))
    {
        os << "Stop " << i << ":";
        bool flag = false;
        for (const auto& j : r.stops.at(i))
        {
            if (j != r.bus)
            {
                flag = true;
                os << " " << j;
            }
        }
        if (!flag)
        {
            os << " no interchange";
        }
        os << std::endl;
    }
    return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r)
{
    if (r.buses.empty())
    {
        return os << "No buses";
    }
    for (const auto& i : r.buses)
    {
        os << "Bus " << i.first << ":";
        for (const auto& j : i.second)
        {
            os << " " << j;
        }
        os << std::endl;
    }
    return os;
}