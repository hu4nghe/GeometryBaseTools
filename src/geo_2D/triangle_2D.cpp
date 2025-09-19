#include "geo_2D/triangle_2D.h"

#include <stdexcept>
#include <cmath>

#include "geo_2D/vector_2D.h"

namespace geotools 
{
    geotools::triangle_2D::triangle_2D(const geotools::point_2D& a, const geotools::point_2D& b, const geotools::point_2D& c)
    {
        auto cross = geotools::vector_2D{a,b}.cross(geotools::vector_2D{b,c});

        if (cross > 0) 
                    vertices = {a, b, c};
        else if (cross < 0) 
                    vertices = {a, c, b};
        else 
            throw std::invalid_argument("Triangle vertices are collinear");
    }


    geotools::triangle_2D::triangle_2D(const geotools::point_2D& p, const geotools::edge_2D& e) 
        : vertices{p, e.get_points().first, e.get_points().second }{}
            

    bool 
    geotools::triangle_2D::containsVertex(const geotools::point_2D& p) 
    const 
    { 
        return std::ranges::find(vertices, p) != vertices.end(); 
    }     

    geotools::circle_2D 
    geotools::triangle_2D::circum_circle() 
    const
    { 
        geotools::vector_2D ab(vertices[0], vertices[1]);
        geotools::vector_2D ac(vertices[0], vertices[2]);

        double ab_len2 = ab.length_sq() * 0.5;
        double ac_len2 = ac.length_sq() * 0.5;
        double d       = ab.cross(ac);

        geotools::point_2D center(
        vertices[0].get_coordinates().first  + (ab_len2 * ac.get_coordinates().second - ac_len2 * ab.get_coordinates().second) / d,
        vertices[0].get_coordinates().second + (ac_len2 * ab.get_coordinates().first  - ab_len2 * ac.get_coordinates().first ) / d);

        return geotools::circle_2D(center, std::sqrt(geotools::vector_2D(center, vertices[0]).length_sq())); 
    }     
}