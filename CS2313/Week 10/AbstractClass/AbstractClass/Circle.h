#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle();
    double area() override;
    ~Circle();
};

