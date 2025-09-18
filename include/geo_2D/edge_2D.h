/**
 * @file edge_2D.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief 2D edge class
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "point_2D.h"

namespace geotools 
{
    class edge
    {
        std::pair<geotools::point_2D, geotools::point_2D> endpoints;

    public:
        edge() = default;

        edge(const geotools::point_2D& a, const geotools::point_2D& b) : endpoints{a > b ? a : b, a > b ? b : a} {}

        bool
        operator==(const edge& other) 
        const { return endpoints == other.endpoints; }

        bool 
        operator<(const edge& other) 
        const { return endpoints <  other.endpoints; }

        const auto&
        get_points()
        const { return endpoints; }
    };
} // namespace geotools