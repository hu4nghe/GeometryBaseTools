 /**
 * @file circle_2D.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief 2D Circle class
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "geo_2D/point_2D.h"

namespace geotools
{
    class circle_2D
    {
        geotools::point_2D center;
        double   radius;
    public:
        circle_2D() = default; 
        circle_2D(geotools::point_2D center, double radius);
        bool contains(const geotools::point_2D& p) const;
    };
} // namespace geotools