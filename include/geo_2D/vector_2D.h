#pragma once

#include "point_2D.h"

class vector_2D 
{

    geotools::point_2D cord;
    
public :
    
    vector_2D()                             = default;
    vector_2D(const vector_2D &)            = default;
    vector_2D(vector_2D &&)                 = default;
    vector_2D &operator=(const vector_2D &) = default;
    vector_2D &operator=(vector_2D &&)      = default;
   ~vector_2D()                             = default;

    
    vector_2D(const geotools::point_2D& p) : cord(p) {}
    vector_2D(const geotools::point_2D& p1, const geotools::point_2D& p2) : cord(p2 - p1) {}

    vector_2D operator+(const vector_2D &other) 
    const { return {cord + other.cord}; }

    vector_2D operator-(const vector_2D& other) 
    const { return {cord - other.cord}; }

    vector_2D operator*(double t) 
    const { return {cord * t }; }

    double 
    dot(const vector_2D& other) 
    const 
    { 
        const auto& [x, y] = cord.get_coordinates();
        const auto& [other_x, other_y] = other.cord.get_coordinates();
        return x * other_x + y * other_y;
        
    }

    double 
    cross(const vector_2D& other) 
    const 
    {
        const auto& [x, y] = cord.get_coordinates();
        const auto& [other_x, other_y] = other.cord.get_coordinates();
        return x * other_y - y * other_x; 
    }

    double 
    length_sq() 
    const 
    {
        const auto& [x, y] = cord.get_coordinates();
        return x * x + y * y; 
    }

    const auto
    get_coordinates()
    const { return cord.get_coordinates(); }
};