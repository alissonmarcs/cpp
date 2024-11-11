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
	void executeOperator (std::stack<int> &stk, int first, std::string token, int second);
	bool isOperator (std::string str);
};
