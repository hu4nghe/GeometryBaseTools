#include "geo_2D/point_2D.h"
#include "base/dbl_compare.h"

namespace geotools
{
    geotools::point_2D::point_2D()                          : x(0)      , y(0)      , ID(next_ID++) {}
    geotools::point_2D::point_2D(double x, double y)        : x(x)      , y(y)      , ID(next_ID++) {}
    geotools::point_2D::point_2D(const point_2D& other)     : x(other.x), y(other.y), ID(next_ID++) {}
    geotools::point_2D::point_2D(point_2D&& other) noexcept : x(other.x), y(other.y), ID(std::exchange(other.ID, 0)) {}
        

    point_2D& 
    geotools::point_2D::operator=(const point_2D& other)     
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
    geotools::point_2D::operator=(point_2D&& other) 
    noexcept 
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
    geotools::point_2D::operator==(const point_2D& other)
    const 
    { 
        return ID == other.ID && geotools::dbl_eq(x, other.x) && geotools::dbl_eq(y, other.y); 
    }

    bool
    geotools::point_2D::operator!=(const point_2D& other)   
    const 
    { 
        return !(*this == other); 
    }
    bool
    geotools::point_2D::operator<(const point_2D& other) 
    const 
    { 
        return geotools::dbl_eq(x, other.x) ? geotools::dbl_inf(y, other.y) : geotools::dbl_inf(x, other.x); 
    }
    bool
    geotools::point_2D::operator>(const point_2D& other)   
    const
    { 
        return (*this != other) && !(*this < other); 
    }
    
    point_2D 
    geotools::point_2D::operator+(const point_2D& other) 
    const 
    { 
        return {x + other.x, y + other.y}; 
    }
    
    point_2D 
    geotools::point_2D::operator-(const point_2D& other) 
    const 
    { 
        return {x - other.x, y - other.y}; 
    }
    
    point_2D 
    geotools::point_2D::operator*(double t) 
    const 
    { 
        return {x * t, y * t}; 
    }
    point_2D 
    geotools::point_2D::operator/(double t) 
    const 
    { 
        return {x / t, y / t}; 
    }
    
    double
    geotools::point_2D::distance(const point_2D& other)  
    
    const 
    { 
        return std::hypot(x - other.x, y - other.y); 
    }
    
    double
    geotools::point_2D::slope(const point_2D& other)   
    const 
    { 
        return geotools::dbl_eq(x, other.x) ? std::numeric_limits<double>::infinity() : (y - other.y) / (x - other.x); 
    }
    
    const int
    geotools::point_2D::get_ID() 
    const 
    { 
        return ID;
    }
    
    const std::pair<double, double>
    geotools::point_2D::get_coordinates() 
    const 
    { 
        return {x, y}; 
    }
    
    void
    geotools::point_2D::set_coordinate(double new_x, double new_y) 
    { 
        x = new_x; y = new_y; 
    }           
} // namespace geotools