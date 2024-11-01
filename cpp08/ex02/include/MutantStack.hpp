#include <deque>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
  typedef typename std::stack<T, C>::container_type::iterator iterator;

  MutantStack<T, C> () : std::stack<T, C> (){};
  MutantStack<T, C> (const MutantStack<T, C> &rhs) : std::stack<T, C> (rhs){};
  MutantStack<T, C> &
  operator= (const MutantStack<T, C> &rhs)
  {
    if (this != &rhs)
      this->c.operator= (rhs.c);
    return (*this);
  };
  ~MutantStack<T, C> (){};

  iterator
  begin ()
  {
    return (this->c.begin ());
  };

  iterator
  end ()
  {
    return (this->c.end ());
  };
};