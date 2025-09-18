#include "point_2D.h"

class line
{
    point_2D a;
    point_2D b;

    public:
       

        line() = default;
        line(point_2D a, point_2D b) : 
            a(a > b ? a : b), 
            b(a > b ? b : a) {}

        bool operator==(const line& p) const 
        { 
            return a == p.a && b == p.b; 
        }

        bool operator< (const line& p) const 
        { 
            return a == p.a ? b < p.b : a < p.a; 
        }
};