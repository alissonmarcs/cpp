#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <vector>

// int
// main (void)
// {
//   ScavTrap scavTrap ("carla");
//   ClapTrap clapTrap ("simone");

//   print ("ClapTrap name: " << clapTrap.getName ());
//   print ("ScavTrap name: " << scavTrap.getName ());

//   print ("ClapTrap hit points: " << clapTrap.getHitPoints ());
//   print ("ScavTrap hit points: " << scavTrap.getHitPoints ());

//   print ("ClapTrap energy points: " << clapTrap.getEnergyPoints ());
//   print ("ScavTrap energy points: " << scavTrap.getEnergyPoints ());

//   print ("ClapTrap attack damage: " << clapTrap.getAttackDamage ());
//   print ("ScavTrap attack damage: " << scavTrap.getAttackDamage ());

//   clapTrap.attack ("enemy");
//   scavTrap.attack ("enemy");

//   scavTrap.guardGate ();
// }

// namespace Tests
// {
//   void TestCopyConstructor()
//   {
//     ClapTrap clap("carla");
//     ScavTrap scav(clap);


//     print("Scav Name: " << scav.getName());
//     print("Scav Hit Points: " << scav.getHitPoints());
//     print("Scav Energy Points: " << scav.getEnergyPoints());
//     print("Scav Attack Damage: " << scav.getAttackDamage());
//   }

// }

class Base
{
protected:
  std::string _name;

public:
  Base(std::string name) : _name(name) {}
  std::string get_name()
  {
    return  _name;
  }
};

class Circle: public Base
{
public:
  Circle(std::string name) : Base(name) {}
  void print_form()
  {
    std::cout << "Circle named: " << get_name() << std::endl;
  }
};

class Triangle: public Base
{
public:
  Triangle(std::string name) : Base(name) {}
  void print_form()
  {
    std::cout << "Triangle named: " << get_name() << std::endl;
  }
};

int main()
{
  std::vector<Base *> vect;
  Circle circle("circle");
  Triangle triangle("triangle");

  vect.push_back(&circle);
  vect.push_back(&triangle);

  ((Circle *)vect[0])->print_form();
  ((Triangle *)vect[1])->print_form();
  return 0;
}

// int main()
// {
//   ScavTrap scavTrap("carla");
//   ClapTrap tmp(scavTrap);

//   print(tmp.getAttackDamage());
//   return 0;
// }
