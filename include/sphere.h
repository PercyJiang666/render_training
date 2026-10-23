#include"hittable.h"
class sphere : public hittable{
private:
    point3 center;
    double radius;
public:
    sphere(point3 o,double r):center(o),radius(r){}
    bool hit(const ray& r,double ray_tmin,double ray_tmax,hit_record& rec)const override{
        vec3 oc=(center-r.origin());
        auto a=r.direction().length_square();
        auto h=dot(r.direction(),oc);
        auto c=oc.length_square()-radius*radius;
        auto d=h*h-a*c;
        if(d<0)return false;
        auto sqrtd=std::sqrt(d);
        auto root = (h-sqrtd)/a;
        if(root<=ray_tmin||ray_tmax<=root){
            root = (h+sqrtd)/a;
                if(root<=ray_tmin||ray_tmax<=root)return false;
        }
        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p-center)/radius;
        rec.set_face_normal(r,outward_normal);
        return true;
    }
};