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
#include <stdexcept>

#include "edge_2D.h"
#include "vector_2D.h"
#include "circle_2D.h"

class triangle_2D
{
    std::array<geotools::point_2D,3> vertices;
    
    public:

        triangle_2D() = default;

        triangle_2D(const geotools::point_2D& a, const geotools::point_2D& b, const geotools::point_2D& c)
        {
            auto cross = vector_2D{a,b}.cross(vector_2D{b,c});

            if (cross > 0) 
                vertices = {a, b, c};
            else if (cross < 0) 
                vertices = {a, c, b};
            else 
                throw std::invalid_argument("Triangle vertices are collinear");
        }

        triangle_2D(const geotools::point_2D& p, const geotools::edge& e) : vertices{p, e.get_points().first, e.get_points().second }{}
            
        bool 
        containsVertex(const geotools::point_2D& p) 
        const { return std::ranges::find(vertices, p) != vertices.end(); }

        geotools::circle_2D circum_circle() const
        {
            
            const auto& a = vertices[0];
            const auto& b = vertices[1];
            const auto& c = vertices[2];

            vector_2D ab(a, b);
            vector_2D ac(a, c);

            double ab_len2 = ab.length_sq() * 0.5;
            double ac_len2 = ac.length_sq() * 0.5;

            double d = ab.cross(ac);

            geotools::point_2D center(
                a.get_coordinates().first  + (ab_len2 * ac.get_coordinates().second - ac_len2 * ab.get_coordinates().second) / d,
                a.get_coordinates().second + (ac_len2 * ab.get_coordinates().first  - ab_len2 * ac.get_coordinates().first ) / d
            );

            double radius = std::sqrt(vector_2D(center, a).length_sq());

            return geotools::circle_2D(center, radius);
        }
    };