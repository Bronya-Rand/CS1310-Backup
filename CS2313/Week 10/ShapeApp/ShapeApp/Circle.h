#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    string objectID = "ID: DEFAULT CIRCLE SHAPE";
    void draw() override;
    Circle();
    ~Circle();
};

