#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human
{
public:
    Human() = default;

    Human(const string& name) :
        Name(name)
    {}

    virtual void Walk(const string& destination) const = 0;

    string getName() const
    {
        return Name;
    }

 protected:
    const string Name;
};


class Student : public Human
{
public:
    
    Student() = default;

    Student(const string& name, const string& favouriteSong) :
        Human(name),
        FavouriteSong(favouriteSong)
    {}

    void Learn() const
    {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(const string& destination) const override
    {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const
    {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human
{
public:

    Teacher() = default;

    Teacher(const string& name, const string& subject) :
        Human(name),
        Subject(subject)
    {}

    void Teach() const
    {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override
    {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human 
{
public:

    Policeman() = default;

    Policeman(const string& name) :
        Human(name)
    {}

    void Check(const Human& h) const
    {
        cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << h.getName() << endl;
    }

    void Walk(const string& destination) const override
    {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }
};


void VisitPlaces(const Human& h, const vector<string>& places) 
{
    for (const auto& p : places) {
        h.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}
