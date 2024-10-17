#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "defines.hpp"

Base * generate(void)
{
	static int is_first = true;
	int random_number;
	Base *base = NULL;

	if (is_first)
	{
		is_first = false;
		std::srand(std::time(0));
	}
	random_number = std::rand() % 3;
	switch (random_number)
	{
		case 0:
			base = new A();
			break;
		case 1:
			base = new B();
			break;
		case 2:
			base = new C();
			break;
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		print (GREEN "A" RESET);
	else if (dynamic_cast<B*>(p))
		print (GREEN "B" RESET);
	else if (dynamic_cast<C*>(p))
		print (GREEN "C" RESET);
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		print (GREEN "A" RESET);
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			print (GREEN "B" RESET);
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				print (GREEN "C" RESET);
				(void)c;
			}
			catch (std::exception &e)
			{
				print (RED "Error: bad casing" RESET);
			}
		}
	}
}

Base::~Base()
{
}
