#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) 
{
    string tmp;
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

struct BusesForStopResponse 
{
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) 
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

struct StopsForBusResponse
{
    string bus;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) 
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
        os << endl;
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r)
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
        os << endl;
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) 
    {
        bool flag;
        buses_[bus] = stops;
        for (const auto& i : stops)
        {
            flag = true;
            for (const auto& j : stops_[i])
            {
                if (j == bus)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                stops_[i].push_back(bus);
            }
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const
    {
        if (stops_.count(stop) == 0)
        {
            return{};
        }
        return { stop,stops_.at(stop) };
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const 
    {
        return { bus, buses_, stops_ };;
    }

    AllBusesResponse GetAllBuses() const {
        return { buses_ };
    }
private:
    map<string, vector<string>> buses_;
    map<string, vector<string>> stops_;
};


int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}