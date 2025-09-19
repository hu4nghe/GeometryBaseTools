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

namespace tools_2D 
{
    class edge_2D
    {
        std::pair<tools_2D::point, tools_2D::point> endpoints;
    public:
        edge_2D() = default;
        edge_2D(const tools_2D::point&, const tools_2D::point&);
        bool operator==(const edge_2D&) const;
        bool operator<(const edge_2D&) const;
        auto get_points() const ->std::pair<tools_2D::point, tools_2D::point>;
    };
} // namespace tools_2D