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

namespace tools_2D
{
    class triangle_2D
    {
        std::array<tools_2D::point,3> vertices;
    
    public:
    
        triangle_2D() = default;
        triangle_2D(const tools_2D::point& a, const tools_2D::point& b, const tools_2D::point& c);
        triangle_2D(const tools_2D::point& p, const tools_2D::edge_2D& e);
        bool containsVertex(const tools_2D::point& p) const;
        tools_2D::circle circum_circle() const;
        
    };
} // namespace tools_2D