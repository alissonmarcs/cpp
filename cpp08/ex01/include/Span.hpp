#pragma once

#include <iostream>
#include <vector>

class Span
{
private:
  const unsigned int _maxSize;
  std::vector<int> _vector;

public:
  Span ();
  Span (const Span &other);
  Span &operator= (const Span &other);
  ~Span ();

  Span (unsigned int n);
  void addNumber (int n);
  void populate (std::vector<int>::iterator beg,
                 std::vector<int>::iterator end);
  unsigned int shortestSpan ();
  unsigned int longestSpan ();

  class isFullException : public std::exception
  {
    virtual const char *what () const throw ();
  };

  class rangeTooHighException : public std::exception
  {
    virtual const char *what () const throw ();
  };

  class notEnoughNumbersException : public std::exception
  {
    virtual const char *what () const throw ();
  };

  std::ostream &operator<< (std::ostream &os);
};
