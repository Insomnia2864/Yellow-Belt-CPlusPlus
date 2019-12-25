#include <iostream>
#include <vector>
#include <algorithm>
/*
enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};*/

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);

void PrintStats(std::vector<Person> persons);

int main()
{
    return 0;
}

void PrintStats(std::vector<Person> persons)
{
    std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;

    std::cout << "Median age for females = " << ComputeMedianAge(
        persons.begin(),
        std::partition(persons.begin(), persons.end(), [](const Person& prs)
            {
                return prs.gender == Gender::FEMALE;
            })
    ) << std::endl;

    std::cout << "Median age for males = " << ComputeMedianAge(
        persons.begin(),
        std::partition(persons.begin(), persons.end(), [](const Person& prs)
            {
                return prs.gender == Gender::MALE;
            })
    ) << std::endl;

    std::cout << "Median age for employed females = " << ComputeMedianAge(
        persons.begin(),
        std::partition(persons.begin(), persons.end(), [](const Person& prs)
            {
                return prs.gender == Gender::FEMALE && prs.is_employed;
            })
    ) << std::endl;

    std::cout << "Median age for unemployed females = " << ComputeMedianAge(
        persons.begin(),
        std::partition(persons.begin(), persons.end(), [](const Person& prs)
            {
                return prs.gender == Gender::FEMALE && !prs.is_employed;
            })
    ) << std::endl;

    std::cout << "Median age for employed males = " << ComputeMedianAge(
        persons.begin(),
        std::partition(persons.begin(), persons.end(), [](const Person& prs)
            {
                return prs.gender == Gender::MALE && prs.is_employed;
            })
    ) << std::endl;

    std::cout << "Median age for unemployed males = " << ComputeMedianAge(
        persons.begin(),
        std::partition(persons.begin(), persons.end(), [](const Person& prs)
            {
                return prs.gender == Gender::MALE && !prs.is_employed;
            })
    ) << std::endl;
}