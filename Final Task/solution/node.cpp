#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const std::string& event)
{
	return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const std::shared_ptr<Node>& node_ptr1, const std::shared_ptr<Node>& node_ptr2) :
	operation_(op),
	node_ptr1_(node_ptr1),
	node_ptr2_(node_ptr2)
{}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event)
{
	if (operation_ == LogicalOperation::And)
	{
		return node_ptr1_->Evaluate(date, event) && node_ptr2_->Evaluate(date, event);
	}
	
	return node_ptr1_->Evaluate(date, event) || node_ptr2_->Evaluate(date, event);
}

DateComparisonNode::DateComparisonNode(const Comparison& op, const Date& date) :
	operation_(op),
	date_(date)
{}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event)
{
	if (operation_ == Comparison::Equal)
	{
		return date_ == date;
	}
	else if (operation_ == Comparison::Greater)
	{
		return date_ < date;
	}
	else if (operation_ == Comparison::GreaterOrEqual)
	{
		return date_ <= date;
	}
	else if (operation_ == Comparison::Less)
	{
		return date_ > date;
	}
	else if (operation_ == Comparison::LessOrEqual)
	{
		return date_ >= date;
	}
	else
	{
		return date_ != date;
	}
}

EventComparisonNode::EventComparisonNode(const Comparison& comp, const std::string& event) :
	operation_(comp),
	event_(event)
{}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event)
{
	if (operation_ == Comparison::Equal)
	{
		return event_ == event;
	}
	else if (operation_ == Comparison::Greater)
	{
		return event_ < event;
	}
	else if (operation_ == Comparison::GreaterOrEqual)
	{
		return event_ <= event;
	}
	else if (operation_ == Comparison::Less)
	{
		return event_ > event;
	}
	else if (operation_ == Comparison::LessOrEqual)
	{
		return event_ >= event;
	}
	else
	{
		return event_ != event;
	}
}