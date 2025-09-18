/**
 * @file dbl_compare.h
 * @author HUANG He (he.hu4ng@outlook.com)
 * @brief define float number compare functions
 * @version 0.1
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <cmath>
#include <utility>
#include <limits>

namespace geotools 
{
    template<std::floating_point T>
    inline std::pair<T, T>
    dbl_delta(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        T diff = a - b;
        T rel_eps = std::max(std::fabs(a), std::fabs(b)) * epsilon;
        return { diff, rel_eps };
    }

    template<std::floating_point T>
    inline bool 
    dbl_inf(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        auto [diff, rel_eps] = dbl_delta(a, b, epsilon);
        return -diff > rel_eps;
    }

    template<std::floating_point T>
    inline bool 
    dbl_sup(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        auto [diff, rel_eps] = dbl_delta(a, b, epsilon);
        return diff > rel_eps;
    }

    template<std::floating_point T>
    inline bool 
    dbl_eq(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        return !dbl_inf(a, b, epsilon) && !dbl_sup(a, b, epsilon);
    }

    template<std::floating_point T>
    inline bool 
    dbl_neq(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        return !dbl_eq(a, b, epsilon);
    }

    template<std::floating_point T>
    inline bool 
    dbl_infeq(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        return dbl_inf(a, b, epsilon) || dbl_eq(a, b, epsilon);
    }

    template<std::floating_point T>
    inline bool 
    dbl_supeq(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
    {
        return dbl_sup(a, b, epsilon) || dbl_eq(a, b, epsilon);
    }
} // namespace geotools
