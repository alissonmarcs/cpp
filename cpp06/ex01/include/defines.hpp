#pragma once

#include <iostream>

#define print(s) std::cout << s << std::endl

#define YELLOW_BOLD "\001\033[1;33m\002"
#define GREEN_BOLD "\001\033[1;32m\002"
#define RED_BOLD "\001\033[1;31m\002"
#define BLUE_BOLD "\001\033[1;94m\002"
#define PURPLE_BOLD "\001\033[1;35m\002"
#define CYAN_BOLD "\001\033[1;36m\002"
#define WHITE_BOLD "\001\033[1;37m\002"

#define YELLOW "\001\033[33m\002"
#define GREEN "\001\033[32m\002"
#define RED "\001\033[31m\002"
#define BLUE "\001\033[94m\002"
#define PURPLE "\001\033[35m\002"
#define CYAN "\001\033[36m\002"
#define WHITE "\001\033[37m\002"

#define RESET "\001\033[0m\002"
#define TITTLE "\n\t\t"
#define SUB_TITTLE "\n\t"

typedef unsigned long long uintptr_t;
