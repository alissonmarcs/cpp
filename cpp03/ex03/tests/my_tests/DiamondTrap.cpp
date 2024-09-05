#include "gtest/gtest.h"
#include "DiamondTrap.hpp"

TEST (DiamondTrap, default_constructor)
{
  DiamondTrap d;

  EXPECT_EQ (d.DiamondTrap::getName(), "guest");
  EXPECT_EQ (d.getHitPoints (), 100);
  EXPECT_EQ (d.getEnergyPoints (), 50);
  EXPECT_EQ (d.getAttackDamage (), 30);
  EXPECT_EQ (d.ClapTrap::getName() , d.DiamondTrap::getName () + "_clap_name");
}

TEST (DiamondTrap, name_constructor)
{
  DiamondTrap d("carla_123_9");

  EXPECT_EQ (d.DiamondTrap::getName(), "carla_123_9");
  EXPECT_EQ (d.getHitPoints (), 100);
  EXPECT_EQ (d.getEnergyPoints (), 50);
  EXPECT_EQ (d.getAttackDamage (), 30);
  EXPECT_EQ (d.ClapTrap::getName() , d.DiamondTrap::getName () + "_clap_name");
}

TEST (DiamondTrap, copy_constructor)
{
  DiamondTrap src("eu sou 157");

  src.setHitPoints(667);
  src.setEnergyPoints(666);
  src.setAttackDamage(665);
  src.DiamondTrap::setName("any name here");
  
  DiamondTrap dest(src);

  EXPECT_EQ (dest.DiamondTrap::getName (), "any name here");
  EXPECT_EQ (dest.getHitPoints (), 667);
  EXPECT_EQ (dest.getEnergyPoints (), 666);
  EXPECT_EQ (dest.getAttackDamage (), 665);
  EXPECT_EQ (dest.ClapTrap::getName () , dest.DiamondTrap::getName () + "_clap_name");
}

TEST (DiamondTrap, assigment_operator)
{
  DiamondTrap src("ninguem");
  DiamondTrap dest("carla abraao de souza");

  src.setHitPoints(10291);
  src.setEnergyPoints(2);
  src.setAttackDamage(0);
  src.DiamondTrap::setName("qualquer nome aqui");

  dest = src;

  EXPECT_EQ (dest.DiamondTrap::getName (), "qualquer nome aqui");
  EXPECT_EQ (dest.getHitPoints (), 10291);
  EXPECT_EQ (dest.getEnergyPoints (), 2);
  EXPECT_EQ (dest.getAttackDamage (), 0);
  EXPECT_EQ (dest.ClapTrap::getName () , dest.DiamondTrap::getName () + "_clap_name");
}
