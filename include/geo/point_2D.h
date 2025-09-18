/**
 * @file point_2D.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief A 2D point class
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "dbl_compare.h"

class point_2D
{
    static inline std::size_t next_ID{1};

    double  x;
    double  y;
    int     ID;

public :

        point_2D()                      : x(0)      , y(0)      , ID(next_ID++) {}
        point_2D(double x, double y)    : x(x)      , y(y)      , ID(next_ID++) {}
        point_2D(const point_2D& other) : x(other.x), y(other.y), ID(next_ID++) {}
        
        point_2D(point_2D&& other) noexcept 
            :   x (std::exchange(other.x , 0.0)),
                y (std::exchange(other.y , 0.0)),
                ID(std::exchange(other.ID, 0)) {}
       
       ~point_2D() = default;

        point_2D& 
        operator=(const point_2D& other)     
        { 
            if (this != &other)
            {
                x = other.x; 
                y = other.y; 
                ID = next_ID++; 
            } 
            return *this; 
        }
    
        point_2D& 
        operator=(point_2D&& other) noexcept 
        { 
            if (this != &other)
            {
                x = other.x; 
                y = other.y; 
                ID = other.ID; 
                other.ID = 0; //original object is moved
            } 
            return *this; 
        } 

        bool
        operator==(const point_2D& other)   
        const { return ID == other.ID && geotools::dbl_eq(x, other.x) && geotools::dbl_eq(y, other.y); }

        bool
        operator!=(const point_2D& other)   
        const { return !(*this == other); }

        bool
        operator<(const point_2D& other)    
        const { return geotools::dbl_eq(x, other.x) ? geotools::dbl_inf(y, other.y) : geotools::dbl_inf(x, other.x); }

        bool
        operator>(const point_2D& other)    
        const { return (*this != other) && !(*this < other); }

        double
        distance(const point_2D& other)     
        const { return std::hypot(x - other.x, y - other.y); }
        
        double
        slope(const point_2D& other)        
        const { return geotools::dbl_eq(x, other.x) ? std::numeric_limits<double>::infinity() : (y - other.y) / (x - other.x); }
        
        const auto
        get_ID() 
        const { return ID;}

        const std::pair<double, double>
        get_coordinates() 
        const { return {x, y}; }

        void
        set_coordinate(double new_x, double new_y) 
        { x = new_x; y = new_y; }
};