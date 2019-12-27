#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <cmath>

const double pi = 3.14;

class Figure
{
public:
	Figure() = default;

	Figure(const std::string& name) :
		name_(name)
	{}

	std::string Name() const
	{
		return name_;
	}

	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;

private:
	std::string name_;
};

class Triangle : public Figure
{
public:
	Triangle() :
		Figure("TRIANGLE")
	{}

	Triangle(double a, double b, double c) :
		Figure("TRIANGLE"),
		a_(a),
		b_(b),
		c_(c)
	{}

	double Perimeter() const override
	{
		return a_ + b_ + c_;
	}

	double Area() const override
	{
		double p = Perimeter() / 2;

		return std::sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}

private:
	double a_, b_, c_;
};

class Rect : public Figure
{
public:
	Rect() :
		Figure("RECT")
	{}

	Rect(double a, double b) :
		Figure("RECT"),
		a_(a),
		b_(b)
	{}

	double Perimeter() const override
	{
		return 2 * a_ + 2 * b_;
	}

	double Area() const override
	{
		return a_ * b_;
	}

private:
	double a_, b_;
};

class Circle : public Figure
{
public:
	Circle() :
		Figure("CIRCLE")
	{}

	Circle(double r) :
		Figure("CIRCLE"),
		r_(r)
	{}

	double Perimeter() const override
	{
		return 2 * pi * r_;
	}

	double Area() const override
	{
		return pi * r_ * r_;
	}

private:
	double r_;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is)
{
	double a, b, c;

	std::string tmp;

	is >> tmp;
	
	if (tmp == "RECT")
	{
		is >> a >> b;
		return std::make_shared<Rect>(a, b);
	}
	else if (tmp == "TRIANGLE")
	{
		is >> a >> b >> c;
		return std::make_shared<Triangle>(a, b, c);
	}
	else if (tmp == "CIRCLE")
	{
		is >> a;
		return std::make_shared<Circle>(a);
	}
	throw std::invalid_argument(tmp);
}

int main()
{
	std::vector<std::shared_ptr<Figure>> figures;
	for (std::string line; std::getline(std::cin, line); ) 
	{
		std::istringstream is(line);

		std::string command;
		is >> command;
		if (command == "ADD")
		{
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") 
		{
			for (const auto& current_figure : figures) 
			{
				std::cout << std::fixed << std::setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << std::endl;
			}
		}
	}
	return 0;
}