#include "Span.hpp"
#include "Defines.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>

Span::Span () : _maxSize (0) {}

Span::Span (unsigned int maxSize) : _maxSize (maxSize)
{
  this->_vector.reserve (maxSize);
}

void
Span::populate (std::vector<int>::iterator begin,
                std::vector<int>::iterator end)
{
  unsigned int distance = std::distance (begin, end);

  if (distance > (_maxSize - this->_vector.size ()))
    throw Span::rangeTooHighException ();
  this->_vector.insert (this->_vector.end (), begin, end);
}

void
Span::addNumber (int n)
{
  if (this->_vector.size () == this->_maxSize)
    throw Span::isFullException ();
  this->_vector.push_back (n);
}

unsigned int
Span::shortestSpan ()
{
  if (this->_vector.size () < 2)
    throw Span::notEnoughNumbersException ();
  std::sort (this->_vector.begin (), this->_vector.end ());
  std::vector<int> diference (this->_vector.size ());
  std::adjacent_difference (this->_vector.begin (), this->_vector.end (),
                            diference.begin ());
  return *std::min_element (diference.begin () + 1, diference.end ());
}

unsigned int
Span::longestSpan ()
{
  if (this->_vector.size () < 2)
    throw Span::notEnoughNumbersException ();
  unsigned int min, max;
  min = *std::min_element (this->_vector.begin (), this->_vector.end ());
  max = *std::max_element (this->_vector.begin (), this->_vector.end ());
  return max - min;
}

Span::Span (const Span &other)
    : _maxSize (other._maxSize), _vector (other._vector)
{
}

std::ostream &
Span::operator<< (std::ostream &os)
{
  std::vector<int>::iterator it = this->_vector.begin ();
  os << YELLOW "Vector data: " RESET;
  for (; it != this->_vector.end (); it++)
    {
      os << "[" << *it << "]";
    }
  std::cout << std::endl;
  return os;
}

Span &
Span::operator= (const Span &other)
{
  if (this != &other)
    {
      unsigned int &maxSize = const_cast<unsigned int &> (this->_maxSize);
      this->_vector = other._vector;
      maxSize = other._maxSize;
    }
  return *this;
}

Span::~Span () {}

const char *
Span::isFullException::what () const throw ()
{
  return RED "The container is full" RESET;
}

const char *
Span::rangeTooHighException::what () const throw ()
{
  return RED "Range too high to fit in vector's size" RESET;
}

const char *
Span::notEnoughNumbersException::what () const throw ()
{
  return RED "Not enough numbers in Span" RESET;
}