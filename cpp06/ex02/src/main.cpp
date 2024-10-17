#include "defines.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main ()
{
	print (YELLOW TITTLE << "CPP Module 06 - Ex02\n" RESET);
	print (GREEN SUB_TITTLE << "identify and generate functions" RESET);
	Base *base = generate ();
	identify (base);
	delete base;
	base = generate ();
	identify (*base);
	delete base;
}
