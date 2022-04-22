#include <iostream>
int main()
{
    int some_number;
    std::cout << "[STANDARD OUPUT] Please input a number bigger than 100" << std::endl;
    std::cin >> some_number;
    if (some_number < 100)
    {
        std::cerr << "[STANDARD ERROR] Number is not bigger than 100 =" << some_number << std::endl;
        return 1;
    }
    std::cout << "[STANDARD OUTPUT] Number is = " << some_number << std::endl;
    return 0;
}