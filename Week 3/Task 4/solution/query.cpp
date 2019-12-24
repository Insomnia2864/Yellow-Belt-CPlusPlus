#include "query.h"

std::istream& operator >> (std::istream& is, Query& q)
{
    std::string tmp;
    is >> tmp;

    if (tmp == "NEW_BUS")
    {
        q.stops.clear();
        size_t counter;
        q.type = QueryType::NewBus;
        is >> q.bus;
        is >> counter;
        for (size_t i = 0; i < counter; i++)
        {
            is >> tmp;
            q.stops.push_back(tmp);
        }
    }
    else if (tmp == "BUSES_FOR_STOP")
    {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (tmp == "STOPS_FOR_BUS")
    {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else if (tmp == "ALL_BUSES")
    {
        q.type = QueryType::AllBuses;
    }

    return is;
}