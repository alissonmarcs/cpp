#include "utils.hpp"

#include "gtest/gtest.h"

namespace
{
	TEST(replace, cornCases)
	{
		std::string		ret;

		ret = replace("ALISSON MARCOS SERAFIM DE SOUZA", "DE", "de");
		EXPECT_STREQ(ret.c_str(), "ALISSON MARCOS SERAFIM de SOUZA");
		ret = replace("ALISSON MARCOS SERAFIM DEDE SOUZA", "DE", "de");
		EXPECT_STREQ(ret.c_str(), "ALISSON MARCOS SERAFIM dede SOUZA");
		ret = replace("DE", "DE", "de");
		EXPECT_STREQ(ret.c_str(), "de");
		ret = replace("does not have target", "any", "LOL");
		EXPECT_STREQ(ret.c_str(), "does not have target");
		ret = replace("does not have target", "", "LOL");
		EXPECT_TRUE(ret.empty());
	}
}
