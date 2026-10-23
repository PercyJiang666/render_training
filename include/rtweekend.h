#pragma once

#include<cmath>
#include<memory>
#include<limits>
#include<iostream>

using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degree_to_radius(double degrees){
    return degrees*pi/180.0;
}

#include"color.h"
#include"ray.h"
#include"vec3.h"