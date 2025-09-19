#pragma once

#include "geo_2D/point_2D.h"

namespace tools_2D
{
    class vector_2D 
    {
        tools_2D::point cord;
    public :
        
        vector_2D()                             = default;
        vector_2D(const vector_2D &)            = default;
        vector_2D(vector_2D &&)                 = default;
        vector_2D &operator=(const vector_2D &) = default;
        vector_2D &operator=(vector_2D &&)      = default;
       ~vector_2D()                             = default;
        
        vector_2D(const tools_2D::point& p);
        vector_2D(const tools_2D::point& p1, const tools_2D::point& p2);
        vector_2D operator+(const vector_2D &other) const;
        vector_2D operator-(const vector_2D& other) const;
        vector_2D operator*(double t) const;

        double dot(const vector_2D& other) const;
        double cross(const vector_2D& other) const;
        double length_sq() const;

        auto get_coordinates() const -> std::pair<double, double>; 
    };
}