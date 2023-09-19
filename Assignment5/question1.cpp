#include<iostream>

using namespace std;
class Distance
{
private:
    int feet;
    int inches;
public:
Distance(){
    cout<<" inside parameterless"<<endl;
};
    Distance(int feet, int inches){
        this->feet = feet;
        this->inches = inches;
    };


    void display(){

cout<<"Distance = "<<this->feet<<"."<<this->inches<< endl;
    }
Distance operator+(Distance &other){
     Distance d;
     d.feet = this->feet + other.feet;
     d.inches = this->inches + other.inches;
return d;
}   
};
void operator==()



int main(){
 Distance d1(5,2);
 d1.display();
 Distance d2(6,2);
 d2.display();
Distance d3;
d3 = d1+d2;
d3.display();

return 0;
}