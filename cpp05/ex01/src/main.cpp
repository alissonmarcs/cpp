#include "print.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

namespace Tests
{
	void defaultConstructor()
	{
		Bureaucrat b1;

		print(b1.getName());
	}

	void tooHigh()
	{
		try
		{
			Bureaucrat b("Mister", 0);
		}
		catch (const std::exception &e)
		{
			print(e.what());
		}
	}

	void tooLow()
	{
		try
		{
			Bureaucrat b("Melvin", 200);
		}
		catch (const std::exception &e)
		{
			print(e.what());
		}
	}

	void incrementGrade()
	{
		Bureaucrat b("Alisson", 1);

		try
		{
			b.incrementGrade();
		}
		catch (const std::exception &e)
		{
			print(e.what());
		}
	}

	void decrementGrade()
	{
		Bureaucrat b("Thor", 150);

		try
		{
			b.decrementGrade();
		}
		catch (const std::exception &e)
		{
			print(e.what());
		}
	}

	void printOperator()
	{
		Form awesome(42, 90, "Alisson");

		std::cout << awesome << std::endl;
	}
}

int main(void)
{
}
