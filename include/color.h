#pragma once
#include"vec3.h"
#include"interval.h"
#include<iostream>
using color = vec3;
double linear_to_gamma(double linear_component){
    if(linear_component>0)return std::sqrt(linear_component);
    return 0;
}
void write_color(std::ostream& out,const color& pixel_color){
    auto r=pixel_color.x();
    auto g=pixel_color.y();
    auto b=pixel_color.z();

    r=linear_to_gamma(r);
    g=linear_to_gamma(g);
    b=linear_to_gamma(b);
    
    static const interval intensity(0.000,0.999);
    int rbyte=int(intensity.clamp(r)*255.999);
    int gbyte=int(intensity.clamp(g)*255.999);
    int bbyte=int(intensity.clamp(b)*255.999);
    out<<rbyte<<' '<<gbyte<<' '<<bbyte<<'\n';
}
