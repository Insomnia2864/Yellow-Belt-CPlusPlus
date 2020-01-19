#pragma once

#include "date.h"

#include <string>
#include <memory>

enum class LogicalOperation
{
	And,
	Or
};

enum class Comparison
{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class Node
{
public:
	virtual bool Evaluate(const Date& date, const std::string& event) = 0;
};

class EmptyNode : public Node
{
public:
	EmptyNode() = default;
	bool Evaluate(const Date& date, const std::string& event) override;
};

class LogicalOperationNode : public Node
{
public:
	LogicalOperationNode() = default;
	LogicalOperationNode(const LogicalOperation& op, const std::shared_ptr<Node>& node_ptr1, const std::shared_ptr<Node>& node_ptr2);

	bool Evaluate(const Date& date, const std::string& event) override;
private:
	LogicalOperation operation_;
	std::shared_ptr<Node> node_ptr1_, node_ptr2_;
};

class DateComparisonNode : public Node
{
public:
	DateComparisonNode() = default;
	DateComparisonNode(const Comparison& op, const Date& date);

	bool Evaluate(const Date& date, const std::string& event) override;
private:
	Comparison operation_;
	Date date_;
};

class EventComparisonNode : public Node
{
public:
	EventComparisonNode() = default;
	EventComparisonNode(const Comparison& comp, const std::string& event);

	bool Evaluate(const Date& date, const std::string& event) override;

private:
	Comparison operation_;
	std::string event_;
};