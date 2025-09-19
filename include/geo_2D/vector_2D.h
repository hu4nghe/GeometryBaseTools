#pragma once

#include "geo_2D/point_2D.h"

namespace geotools
{
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
        
        vector_2D(const geotools::point_2D& p);
        vector_2D(const geotools::point_2D& p1, const geotools::point_2D& p2);
        vector_2D operator+(const vector_2D &other) const;
        vector_2D operator-(const vector_2D& other) const;
        vector_2D operator*(double t) const;

        double dot(const vector_2D& other) const;
        double cross(const vector_2D& other) const;
        double length_sq() const;

        auto get_coordinates() const -> std::pair<double, double>; 
    };
}