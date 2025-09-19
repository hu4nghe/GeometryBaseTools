/**
 * @file triangle_2D.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief 2D triangle class
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once 

#include <array>

#include "geo_2D/edge_2D.h"
#include "geo_2D/circle_2D.h"

namespace geotools
{
    class triangle_2D
    {
        std::array<geotools::point_2D,3> vertices;
    
    public:
    
        triangle_2D() = default;
        triangle_2D(const geotools::point_2D& a, const geotools::point_2D& b, const geotools::point_2D& c);
        triangle_2D(const geotools::point_2D& p, const geotools::edge_2D& e);
        bool containsVertex(const geotools::point_2D& p) const;
        geotools::circle_2D circum_circle() const;
        
    };
} // namespace geotools