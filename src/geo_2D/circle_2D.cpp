#include "geo_2D/circle_2D.h"
namespace geotools 
{
    geotools::circle_2D::circle_2D(geotools::point_2D center, double radius) : center(center), radius(radius) {}

    bool 
    geotools::circle_2D::contains(const geotools::point_2D& p) const
    { return center.distance(p) <= radius; }
} // namespace geotools