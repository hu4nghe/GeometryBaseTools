#pragma once

#include "point_2D.h"
#include <tuple>

class vector_2D 
{
    double a;
    double b;
    
public :
    
    vector_2D()                             = default;
    vector_2D(const vector_2D &)            = default;
    vector_2D(vector_2D &&)                 = default;
    vector_2D &operator=(const vector_2D &) = default;
    vector_2D &operator=(vector_2D &&)      = default;
   ~vector_2D()                             = default;

    vector_2D(double a, double b) : a(a), b(b) {}
    
    vector_2D(const point_2D& p)
    {
        std::tie(a,b) = p.get_coordinates();
    }

    vector_2D operator+(const vector_2D &other) 
    const { return {a + other.a, b + other.b}; }

    vector_2D operator-(const vector_2D& other) 
    const { return {a - other.a, b - other.b}; }

    vector_2D operator*(double t) 
    const { return {a * t, b * t}; }

    double 
    dot(const vector_2D& other) 
    const { return a*other.a + b*other.b; }

    double 
    cross(const vector_2D& other) 
    const { return a*other.b - b*other.a; }

    double 
    length_sq() 
    const { return a*a + b*b; }
};