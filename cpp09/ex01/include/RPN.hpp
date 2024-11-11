#pragma once

#include <string>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	RPN(std::string expression);
};
