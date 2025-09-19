/**
 * @file edge_2D.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief 2D edge_2D class
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "geo_2D/point_2D.h"
#include "point_2D.h"

namespace geotools 
{
    class edge_2D
    {
        std::pair<geotools::point_2D, geotools::point_2D> endpoints;
    public:
        edge_2D() = default;
        edge_2D(const geotools::point_2D&, const geotools::point_2D&);
        bool operator==(const edge_2D&) const;
        bool operator<(const edge_2D&) const;
        auto get_points() const ->std::pair<geotools::point_2D, geotools::point_2D>;
    };
} // namespace geotools