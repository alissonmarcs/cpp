#pragma once

#include <cstddef>
#include <exception>

template <typename T> class Array
{
private:
  T *_array;
  size_t _size;

public:
  Array ();
  Array (const Array &other);
  Array<T> &operator= (const Array<T> &rhs);
  ~Array ();

  Array (size_t n);
  size_t size () const;
  T &operator[] (size_t i);
  const T &operator[] (size_t i) const;
  ;

  class OutOfLimitsException : public std::exception
  {
    virtual const char *what () const throw ();
  };

  class InvalidArraySize : public std::exception
  {
    virtual const char *what () const throw ();
  };

  class EmptyArray : public std::exception
  {
    virtual const char *what () const throw ();
  };
};

#define MAX_SIZE 1000

#include "../src/Array.tpp"