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
/*
class Rational {
public:

    Rational();
    Rational(int numerator, int denominator);

    int Numerator() const;
    int Denominator() const;
};
*/
void test()
{
    {
        Rational r = Rational();
        AssertEqual(r.Numerator(), 0);
        AssertEqual(r.Denominator(), 1);
    }

    {
        Rational r = Rational(2, 4);
        AssertEqual(r.Numerator(), 1);
        AssertEqual(r.Denominator(), 2);
    }

    {
        Rational r = Rational(-3, -2);
        AssertEqual(r.Numerator(), 3);
        AssertEqual(r.Denominator(), 2);
    }

    {
        Rational r = Rational(-5,25);
        AssertEqual(r.Numerator(), -1);
        AssertEqual(r.Denominator(), 5);
    }

    {
        Rational r = Rational(-4, -36);
        AssertEqual(r.Numerator(), 1);
        AssertEqual(r.Denominator(), 9);
    }

    {
        Rational r = Rational(8, -64);
        AssertEqual(r.Numerator(), -1);
        AssertEqual(r.Denominator(), 8);
    }   

    {
        Rational r = Rational(0, -666);
        AssertEqual(r.Numerator(), 0);
        AssertEqual(r.Denominator(), 1);
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(test, "");
    return 0;
}