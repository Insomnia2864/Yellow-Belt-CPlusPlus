#include <set>
#include <string>
#include <utility>
#include <optional>

std::optional<std::string> findStr(const std::set<std::pair<int, std::string>>& set_, int year)
{
    if (set_.empty())
    {
        return std::optional<std::string>();
    }
    auto a = set_.lower_bound(std::make_pair(year, ""));

    if (a == set_.end())
    {
        return std::optional<std::string>(std::prev(a)->second);
    }

    if (a == set_.begin())
    {
        return (a->first > year) ? std::optional<std::string>() : std::optional<std::string>(a->second);
    }

    return (a->first > year) ? std::optional<std::string>(std::prev(a)->second) : std::optional<std::string>(a->second);
}

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) 
    {
        frst.insert(std::make_pair(year, first_name));
    }
    void ChangeLastName(int year, const std::string& last_name) 
    {
        scnd.insert(std::make_pair(year, last_name));
    }
    std::string GetFullName(int year) 
    {
        auto first_ = findStr(frst, year),
            second_ = findStr(scnd, year);

        if (!first_ && !second_)
        {
            return "Incognito";
        }

        if (!first_)
        {
            return second_.value() + " with unknown first name";
        }

        if (!second_)
        {
            return first_.value() + " with unknown last name";
        }

        return first_.value() + " " + second_.value();
    }
private:
    std::set<std::pair<int, std::string>> frst;
    std::set<std::pair<int, std::string>> scnd;
};