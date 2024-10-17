#include "defines.hpp"
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data batman = {"Bruce", "Wayne", 42};

	print (TITTLE YELLOW_BOLD "Data members before serialization\n" RESET);
	print (YELLOW "Name: " RESET << batman.name);
	print (YELLOW "Second name: " RESET << batman.second_name);
	print (YELLOW "Age: " RESET << batman.age);

	print (TITTLE YELLOW_BOLD "Serializing\n" RESET);
	uintptr_t raw = Serializer::serialize(&batman);
	print (YELLOW "Data pointer serialized: " RESET << raw);

	print (TITTLE YELLOW_BOLD "Deserializing\n" RESET);
	Data *batman_ptr = Serializer::deserialize(raw);
	print (YELLOW "Data pointer deserialized: " RESET << batman_ptr);

	print (TITTLE YELLOW_BOLD "Checking data members by deserialized pointer\n" RESET);
	print (YELLOW "Name: " RESET << batman_ptr->name);
	print (YELLOW "Second name: " RESET << batman_ptr->second_name);
	print (YELLOW "Age: " RESET << batman_ptr->age);
}
