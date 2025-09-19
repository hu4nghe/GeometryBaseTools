#include "geo_2D/edge_2D.h"

tools_2D::edge_2D::edge_2D(const tools_2D::point& a, const tools_2D::point& b) : endpoints{a > b ? a : b, a > b ? b : a} {}

bool
tools_2D::edge_2D::operator==(const edge_2D& other) 
const { return endpoints == other.endpoints; }

bool 
tools_2D::edge_2D::operator<(const edge_2D& other) 
const { return endpoints <  other.endpoints; }

std::pair<tools_2D::point, tools_2D::point>
tools_2D::edge_2D::get_points() 
const { return endpoints; }