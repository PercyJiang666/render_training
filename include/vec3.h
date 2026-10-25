#pragma once

#include<cmath>
#include<iostream>
class vec3{
public:
    double e[3];
    vec3(double e0 = 0,double e1 = 0,double e2 = 0):e{e0,e1,e2}{};
    double x()const{return e[0];}
    double y()const{return e[1];}
    double z()const{return e[2];}
    vec3 operator-()const{return vec3(-e[0],-e[1],-e[2]);}
    double& operator[](int i){return e[i];}
    double operator[](int i)const{return e[i];}
    bool near_zero()const{
        auto s = 1e-8;
        return (std::fabs(e[0])<s)&&(std::fabs(e[1])<s)&&(std::fabs(e[2])<s);
    }
    vec3& operator+=(const vec3& v){
        e[0]+=v[0];
        e[1]+=v[1];
        e[2]+=v[2];
        return (*this);
    }
    vec3& operator*=(double c){
        e[0]*=c;
        e[1]*=c;
        e[2]*=c;
        return (*this);
    }
    vec3& operator-=(const vec3& v){
        e[0]-=v[0];
        e[1]-=v[1];
        e[2]-=v[2];
        return (*this);
    }
    vec3& operator/=(double c){
        return (*this)*=1/c;
    }
    double length_square()const{
        return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
    }
    double length()const{
        return std::sqrt(length_square());
    }
    static vec3 random(){
        return vec3(random_double(),random_double(),random_double());
    }
    static vec3 random(double min,double max){
        return vec3(random_double(min,max),random_double(min,max),random_double(min,max));
    }
    
};
/*
<<
+
-
*
/
dot 
cross
unit_vector
*/
using point3 = vec3;
inline std::ostream& operator<<(std::ostream& out, const vec3& v);
inline vec3 operator+(const vec3& v1,const vec3& v2);
inline vec3 operator-(const vec3& v1,const vec3& v2);
inline vec3 operator*(const vec3& v,double c);
inline vec3 operator*(double c,const vec3& v);
inline vec3 operator*(const vec3& v1,const vec3& v2);
inline vec3 operator/(const vec3& v,double c);
inline vec3 operator/(const vec3& v1,const vec3& v2);
inline double dot(const vec3& v1,const vec3& v2);
inline double det2D(double a,double b,double c,double d);
inline vec3 cross(const vec3& v1,const vec3& v2);
inline vec3 unit_vector(const vec3& v);

inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out <<v[0]<<' '<<v[1]<<' '<<v[2];
}
inline vec3 operator+(const vec3& v1,const vec3& v2){
    return vec3(v1[0]+v2[0],v1[1]+v2[1],v1[2]+v2[2]);
}
inline vec3 operator-(const vec3& v1,const vec3& v2){
    return vec3(v1[0]-v2[0],v1[1]-v2[1],v1[2]-v2[2]);
}
inline vec3 operator*(const vec3& v,double c){
    return vec3(v[0]*c,v[1]*c,v[2]*c);
}
inline vec3 operator*(double c,const vec3& v){
    return v*c;
}
inline vec3 operator*(const vec3& v1,const vec3& v2){
    return vec3(v1[0]*v2[0],v1[1]*v2[1],v1[2]*v2[2]);
}
inline vec3 operator/(const vec3& v,double c){
    return v*(1/c);
}
inline vec3 operator/(const vec3& v1,const vec3& v2){
    return vec3(v1[0]/v2[0],v1[1]/v2[1],v1[2]/v2[2]);
}
inline double dot(const vec3& v1,const vec3& v2){
    return v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
}
inline double det2D(double a,double b,double c,double d){
    return a*d-b*c;
}
inline vec3 cross(const vec3& v1,const vec3& v2){
    return vec3(det2D(v1[1],v1[2],v2[1],v2[2]),
                -det2D(v1[0],v1[2],v2[0],v2[2]),
                det2D(v1[0],v1[1],v2[0],v2[1]));
}
inline vec3 unit_vector(const vec3& v){
    return v/v.length();
}
inline vec3 random_unit_vector(){
    while(true){
        auto p = vec3::random(-1,1);
        auto lensq = p.length_square();
        if(1e-160<lensq&&lensq<=1)return p/sqrt(lensq);
    }
}

inline vec3 random_on_hemisphere(const vec3& normal){
    vec3 on_unit_sphere = random_unit_vector();
    if(dot(on_unit_sphere,normal)>0.0)return on_unit_sphere;
    return -on_unit_sphere;

}

inline vec3 reflect(const vec3& v,const vec3& n){
    return v-(2*dot(v,n)*n);
}