#include "bus_manager.h"

BusManager::BusManager()
{
    stops_ = std::map<std::string, std::vector<std::string>>();
    buses_ = std::map<std::string, std::vector<std::string>>();
}

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops)
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

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const
{
    if (stops_.count(stop) == 0)
    {
        return{};
    }
    return { stop,stops_.at(stop) };
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const
{
    return { bus, buses_, stops_ };;
}

AllBusesResponse BusManager::GetAllBuses() const {
    return { buses_ };
}