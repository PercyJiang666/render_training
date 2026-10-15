#include"color.h"
#include"ray.h"
#include<iostream>
bool hitsphere(const point3& center, double radius,const ray& r){
    vec3 ca=(r.origin()-center);
    double a=r.direction().length_square();
    double b=2*dot(r.direction(),ca);
    double c=ca.length_square()-radius*radius;
    if(b*b-4*a*c<0)return false;
    return true;
    /*if(-b>0){
        double t=(-b-D)/2.0/a;
        r.at(t)
    }*/
}
color ray_color(const ray& r){
    if(hitsphere(point3(0,0,-1), 0.5, r))return color(1,0,0);
    vec3 v=unit_vector(r.direction());
    auto a=(v.y()+1.0)*0.5;
    //return color(1,1,1);
    return (1.0-a)*color(1.0,1.0,1.0)+a*color(0.5,0.7,1.0);
}
int main(){
    //image settings
    auto aspect_ratio = 16.0/9.0;
    int image_width = 400;

    //calculate image height
    int image_height=  int(image_width/aspect_ratio);
    image_height = (image_height<1)?1:image_height;
    //camera settings
    auto viewport_height = 2.0;
    auto focal_length=1.0;
    auto camera_center=point3(0,0,0);
    auto viewport_width = viewport_height*(double(image_width)/image_height);
    
    //calculate the absolute position
    auto viewport_u=vec3(viewport_width,0,0);
    auto viewport_v=vec3(0,-viewport_height,0);
    auto pixel_delta_u=viewport_u/image_width;
    auto pixel_delta_v=viewport_v/image_height;
    auto view_port_upper_left=camera_center-vec3(0,0,focal_length)-viewport_u/2-viewport_v/2;
    auto pixel00_loc=view_port_upper_left+(pixel_delta_u+pixel_delta_v)*0.5;
    
    //setting sphere
    auto radius=0.5;
    auto center=point3(0,0,-1);
    std::cout<<"P3\n"<<image_width<<' '<<image_height<<"\n255\n";
    for(int j=0;j<image_height;j++){
        std::clog<<"\rscan line remaining:"<<image_height-j<<' '<<std::flush;
        for(int i=0;i<image_width;i++){
            auto pixel_center = pixel00_loc + i*pixel_delta_u + j*pixel_delta_v;
            auto ray_direction = pixel_center-camera_center;
            ray r(camera_center,ray_direction);
            color pixel_color = ray_color(r);
            write_color(std::cout,pixel_color);
        }
    }
    std::clog<<"\rDone.                 \n";
}