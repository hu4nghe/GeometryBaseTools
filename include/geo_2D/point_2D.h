/**
 * @file point_2D.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief 2D point class
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <utility>

namespace geotools
{
    class point_2D
    {
        static inline std::size_t next_ID{1};
        double      x;
        double      y;
        std::size_t ID;
    public :
        point_2D();  
        point_2D(double x, double y);
        point_2D(const point_2D& other);
        point_2D(point_2D&& other) noexcept;
        ~point_2D() = default;
        point_2D& operator=(const point_2D& other);  
        point_2D& operator=(point_2D&& other) noexcept;
        bool operator==(const point_2D& other) const;
        bool operator!=(const point_2D& other) const;
        bool operator<(const point_2D& other) const; 
        bool operator>(const point_2D& other) const;
        point_2D operator+(const point_2D& other) const;
        point_2D operator-(const point_2D& other) const;
        point_2D operator*(double t) const;
        point_2D operator/(double t) const;
        double distance(const point_2D& other) const;
        double slope(const point_2D& other) const;
        const int get_ID() const;
        const std::pair<double, double> get_coordinates() const; 
        void set_coordinate(double new_x, double new_y);
    };

} // namespace geotools