#include <iostream>
#include <string>
#include "iter/iter.hpp"

template <typename T>
void printTempl(T &t)
{
    std::cout << t << std::endl;
}

int main(void)
{
    {
        int arr[] = {1, 3, 4, 5, 454545};
        ::iter<>(arr, 5, printTempl<const int>);
    }
    {
        std::string arr[] = {"H", "o", "l", "a"};
        ::iter<>(arr, 4, printTempl<const std::string>);
    }
    {
        std::string arr[] = {"H", "o", "l", "s"};
        ::iter<>(arr, 4, printTempl<std::string>);
    }
    return 0;
}
