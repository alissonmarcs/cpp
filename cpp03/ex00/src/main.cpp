#include "ClapTrap.hpp"

int
main (void)
{
  Fixed a;
  Fixed const b (10);
  Fixed const c (42.42f);
  Fixed const d (b);
  a = Fixed (1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  std::cout << "a is " << a.toInt () << " as integer" << std::endl;
  std::cout << "b is " << b.toInt () << " as integer" << std::endl;
  std::cout << "c is " << c.toInt () << " as integer" << std::endl;
  std::cout << "d is " << d.toInt () << " as integer" << std::endl;

  return 0;
}

int
main (void)
{
  // ClapTrap claptrap("alisson");
  // std::cout << claptrap.getHitPoints() << std::endl;
  // std::cout << claptrap.getEnergyPoints() << std::endl;
  // std::cout << claptrap.getAttackDamage() << std::endl;

  // claptrap.attack("carla");
  // claptrap.setAtackDamage(3);
  // claptrap.attack("carla");
  // claptrap.takeDamage(5);
  // std::cout << claptrap.getHitPoints() << std::endl;

  ClapTrap tmp ("alisson");

  print (tmp.getName ());
}
