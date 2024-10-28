#include "defines.hpp"
#include "whatever.hpp"

int main(int argc, char const *argv[])
{
    int a = 2, b = 30;

    print(YELLOW_BOLD "Before swap: " RESET);
    print("a = " << a);
    print("b = " << b);
    ::swap <int>(a, b);
    print(GREEN_BOLD "After swap: " RESET);
    print("a = " << a);
    print("b = " << b);
    return 0;
}
