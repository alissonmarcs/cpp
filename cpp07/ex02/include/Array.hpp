#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
private:
	T *_array;
	size_t _size;

public:
	Array();
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	Array(size_t n);

	class OutOfLimitsException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidArraySize : public std::exception
	{
		virtual const char *what() const throw();
	};

	class EmptyArray : public std::exception
	{
		virtual const char *what() const throw();
	};
};
