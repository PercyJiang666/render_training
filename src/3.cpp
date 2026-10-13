#include<iostream>
class vec3{
public:
    double e[3];
    vec3():e{0,0,0}{}
    vec3(double e1,double e2,double e3):e{e1,e2,e3}{};
    double x(){return e[0];}
    double y(){return e[1];}
    double z(){return e[2];}
    vec3 operator-(){return vec3({-e[0],-e[1],-e[2]});}
    vec3 operator-(vec3 v){return vec3({v.x()-e[0],v.y()-e[1],v.z()-e[2]});}
    double& operator[](int i){return e[i];}
    double& operator[](int i)const{return e[i];}
    vec3& operator+=(const vec3& v){
        e[0]+=v[0];
        e[1]+=v[1];
        e[2]+=v[2];
        return (*this);
    }
    vec3& operator*=(const vec3& v){
        e[0]*=v[0];
        e[1]*=v[1];
        e[2]*=v[2];
        return (*this);
    }
    vec3& operator-=(const vec3& v){
        e[0]-=v[0];
        e[1]-=v[1];
        e[2]-=v[2];
        return (*this);
    }
    
};

int main(){


}