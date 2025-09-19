#include "geo_2D/edge_2D.h"

geotools::edge_2D::edge_2D(const geotools::point_2D& a, const geotools::point_2D& b) : endpoints{a > b ? a : b, a > b ? b : a} {}

bool
geotools::edge_2D::operator==(const edge_2D& other) 
const { return endpoints == other.endpoints; }

bool 
geotools::edge_2D::operator<(const edge_2D& other) 
const { return endpoints <  other.endpoints; }

std::pair<geotools::point_2D, geotools::point_2D>
geotools::edge_2D::get_points() 
const { return endpoints; }