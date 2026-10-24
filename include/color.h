#pragma once
#include"vec3.h"
#include"interval.h"
#include<iostream>
using color = vec3;
void write_color(std::ostream& out,const color& pixel_color){
    auto r=pixel_color.x();
    auto g=pixel_color.y();
    auto b=pixel_color.z();

    static const interval intensity(0.000,0.999);
    int rbyte=int(intensity.clamp(r)*255.999);
    int gbyte=int(intensity.clamp(g)*255.999);
    int bbyte=int(intensity.clamp(b)*255.999);
    out<<rbyte<<' '<<gbyte<<' '<<bbyte<<'\n';
}
