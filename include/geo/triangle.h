#pragma once 
struct triangle
{
    public:
        point a, b, c;

        triangle() = default;
        triangle(point a, point b, point c) : 
            a(a), 
            b(b), 
            c(c) 
        {
            if (a == b || a == c || b == c) 
                throw std::invalid_argument("Invalid triangle");
        }
        triangle(const point& a, const edge& e) : 
            a(a), 
            b(e.a), 
            c(e.b) 
        {
            if (a == b || a == c || b == c) 
                throw std::invalid_argument("Invalid triangle");
        }
            
        bool containsVertex(const point& p) const 
        { 
            return a == p || b == p || c == p; 
        }

        circle circum_circle() const
        {
            double  a1 = b.x - a.x, 
                    b1 = b.y - a.y, 
                    c1 = (a1 * a1 + b1 * b1) / 2,
                    a2 = c.x - a.x, 
                    b2 = c.y - a.y, 
                    c2 = (a2 * a2 + b2 * b2) / 2,
                    d  = a1 * b2 - a2 * b1;

            point center;
            center.x = a.x + (c1 * b2 - c2 * b1) / d;
            center.y = a.y + (a1 * c2 - a2 * c1) / d;

            return circle(center, center.distance(a));
        }
    };