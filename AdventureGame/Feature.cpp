#include "Feature.h"
#include <iostream>

void Feature::PrintFeature()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << " " << std::endl;
}
