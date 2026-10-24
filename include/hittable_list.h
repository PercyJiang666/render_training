#pragma once
#include "hittable.h"

#include<memory>
#include<vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable{
public:
    std::vector<shared_ptr<hittable>> objects;
    
    hittable_list(){}
    hittable_list(const shared_ptr<hittable>& object){add(object);};

    void clear(){objects.clear();}

    void add(const shared_ptr<hittable>& object){
        objects.push_back(object);
    }

    bool hit(const ray& r,const interval& ray_t,hit_record& rec)const override{
        hit_record temp_rec;
        bool hit_something = false;
        interval closest_so_far = ray_t;
        for(const auto& object : objects){
            if(object->hit(r,closest_so_far,temp_rec)){
                hit_something = true;
                rec = temp_rec;
                closest_so_far.max = temp_rec.t;
            }
        }
        return hit_something;
    }
};