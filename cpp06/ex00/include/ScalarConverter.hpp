#pragma once

#include <exception>
#include <string>
#include <cstdlib>

class ScalarConverter
{
	private:

		/* Canonical form */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
	class ImpossibleException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

