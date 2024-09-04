#include "gtest/gtest.h"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

TEST (FragTrap, default_constructor)
{
  FragTrap fragtrap;

  EXPECT_EQ (fragtrap.getName (), "guest");
  EXPECT_EQ (fragtrap.getHitPoints (), 100);
  EXPECT_EQ (fragtrap.getEnergyPoints (), 100);
  EXPECT_EQ (fragtrap.getAttackDamage (), 30);
}

TEST (FragTrap, name_constructor)
{
  FragTrap fragtrap ("fragtrap");

  EXPECT_EQ (fragtrap.getName (), "fragtrap");
  EXPECT_EQ (fragtrap.getHitPoints (), 100);
  EXPECT_EQ (fragtrap.getEnergyPoints (), 100);
  EXPECT_EQ (fragtrap.getAttackDamage (), 30);
}

TEST (FragTrap, name_constructor_empty_string)
{
  FragTrap fragtrap ("");

  EXPECT_EQ (fragtrap.getName (), "");
  EXPECT_EQ (fragtrap.getHitPoints (), 100);
  EXPECT_EQ (fragtrap.getEnergyPoints (), 100);
  EXPECT_EQ (fragtrap.getAttackDamage (), 30);
}

TEST (FragTrap, assigment_operator)
{
  FragTrap fragtrap1 ("rose and jack");
  FragTrap copy;

  fragtrap1.setHitPoints (200);
  fragtrap1.setEnergyPoints (1);
  fragtrap1.setAttackDamage (42);
  copy = fragtrap1;
  EXPECT_EQ (copy.getName (), "rose and jack");
  EXPECT_EQ (copy.getHitPoints (), 200);
  EXPECT_EQ (copy.getEnergyPoints (), 1);
  EXPECT_EQ (copy.getAttackDamage (), 42);
}

TEST (FragTrap, copy_constructor)
{
  FragTrap fragtrap1 ("any name here");

  fragtrap1.setHitPoints (9102);
  fragtrap1.setEnergyPoints (12);
  fragtrap1.setAttackDamage (199);

  FragTrap copy(fragtrap1);

  EXPECT_EQ (copy.getName (), "any name here");
  EXPECT_EQ (copy.getHitPoints (), 9102);
  EXPECT_EQ (copy.getEnergyPoints (), 12);
  EXPECT_EQ (copy.getAttackDamage (), 199);
}

TEST (FragTrap, high_fives_guys_messages)
{
  FragTrap fragtrap ("fragtrap");

  testing::internal::CaptureStdout ();
  fragtrap.highFivesGuys ();
  std::string output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "FragTrap fragtrap requests a high five!\n");

  fragtrap.setHitPoints (0);
  testing::internal::CaptureStdout ();
  fragtrap.highFivesGuys ();
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "FragTrap fragtrap is dead and can't request a high five!\n");
  fragtrap.setHitPoints (42);
  fragtrap.setEnergyPoints (0);
  testing::internal::CaptureStdout ();
  fragtrap.highFivesGuys ();
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "FragTrap fragtrap is out of energy and can't request a high five!\n");
}

TEST (FragTrap, decrement_energy_points)
{
  FragTrap fragtrap ("fragtrap");

  fragtrap.setEnergyPoints (42);
  fragtrap.attack ("target");
  EXPECT_EQ (fragtrap.getEnergyPoints (), 41);
}

TEST (FragTrap, set_negative_values)
{
  FragTrap fragtrap ("fragtrap");
  std::string output;

  testing::internal::CaptureStdout ();
  fragtrap.setHitPoints (-42);
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "ClapTrap hit points can't be negative! Previous value kept.\n");
  testing::internal::CaptureStdout ();
  fragtrap.setEnergyPoints (-42);
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "ClapTrap energy points can't be negative! Previous value kept.\n");
  testing::internal::CaptureStdout ();
  fragtrap.setAttackDamage (-42);
  output = testing::internal::GetCapturedStdout ();
  EXPECT_EQ (output, "ClapTrap attack damage can't be negative! Previous value kept.\n");
}
