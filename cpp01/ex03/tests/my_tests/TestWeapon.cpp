#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include "gtest/gtest.h"

namespace
{
	TEST(WeaponTest, setTypegetTypeTest)
	{
		Weapon w("shot");

		EXPECT_STREQ(w.getType().c_str(), "shot");
		w.setType("");
		EXPECT_TRUE(w.getType().empty());
		w.setType("a");
		EXPECT_STREQ(w.getType().c_str(), "a");
	}

	TEST(HumanATest, common)
	{
		Weapon w("shot");
		HumanA h("carla", w);

		h.attack();
		w.setType("shot2");
		h.attack();
	}

	TEST(HumanBTest, common)
	{
		HumanB h("carla");
		Weapon w("shot");

		h.setWeapon(&w);
		h.attack();
		w.setType("shot2");
		h.attack();
	}
}
