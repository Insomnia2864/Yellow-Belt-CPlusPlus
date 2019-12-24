#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception & e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void test()
{
    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(6, "qqq");
        AssertEqual(person.GetFullName(3), "Incognito");
    }

    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(6, "qqq");
        AssertEqual(person.GetFullName(4), "qwe with unknown last name");
    }

    {
        Person person;
        person.ChangeFirstName(5, "qwe");
        person.ChangeLastName(4, "ewq");
        person.ChangeFirstName(6, "qqq");
        AssertEqual(person.GetFullName(4), "ewq with unknown first name");
    }

    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(6, "qqq");
        AssertEqual(person.GetFullName(8), "qqq ewq");
    }

    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(6, "qqq");
        person.ChangeLastName(9, "ewq1");
        AssertEqual(person.GetFullName(9), "qqq ewq1");
    }

    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(8, "qqq");
        person.ChangeLastName(9, "ewq1");
        AssertEqual(person.GetFullName(5), "qwe ewq");
    }

    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(9, "qqq");
        person.ChangeLastName(8, "ewq1");
        AssertEqual(person.GetFullName(8), "qwe ewq1");
    }

    {
        Person person;
        person.ChangeFirstName(4, "qwe");
        person.ChangeLastName(5, "ewq");
        person.ChangeFirstName(6, "qqq");
        AssertEqual(person.GetFullName(22), "qqq ewq");
    }
}
/*
class Person {
public:
    void ChangeFirstName(int year, const string& first_name);
    void ChangeLastName(int year, const string& last_name);
    string GetFullName(int year);
};*/

int main() {
    TestRunner runner;
    runner.RunTest(test, "");
    return 0;
}