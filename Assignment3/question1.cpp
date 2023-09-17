#include<iostream>
using namespace std;
class cylinder{
 const double pi;
 double radius;
 double height;
 double volm;
 public:
 cylinder():pi(3.14){
    this->radius = 0.0;
    this->height = 0.0;
    this->volm = 0.0;
 }
 cylinder(double radius,double height):pi(3.14){
    this->radius = radius;
    this->height = height;

 }
 double getradius(){
     return this->radius;
 }

 void setradius(double radius){
    this->radius = radius;
 }

 double getheight(){
    return this->height;
}

 void setheight(double height){
    this->height = height;
}

double getvolm(){
     return volm = pi * radius * radius * height;
}
void printvolm() {
    cout<<"Volume is "<< getvolm()<<endl;
    
    
}
};



int main(){
cylinder c(10.0,10.0);
c.getheight();
c.printvolm();


return 0;
}
