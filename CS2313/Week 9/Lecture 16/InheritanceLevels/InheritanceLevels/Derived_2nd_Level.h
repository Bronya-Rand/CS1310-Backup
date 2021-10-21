#pragma once
#include "Derived1.h"
#include "Derived2.h"
#include "Derived3.h"

class Derived_2nd_Level :
    public Derived1
{
public:
    Derived_2nd_Level();
    ~Derived_2nd_Level();
};

