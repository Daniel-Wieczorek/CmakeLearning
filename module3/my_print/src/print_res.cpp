#include <iostream>
#include "my_print/print_res.h"

void print_result(std::string result_type, float result_value)
{
    std::cout << result_type << " result: " << result_value << std::endl;
}