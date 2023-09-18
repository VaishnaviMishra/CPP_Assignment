#include<iostream>
using namespace std;
class Employee{
    private:
    int id;
    float salary;
    public:
    Employee(){
        this->id=0;
        this->salary=0.00;   
    }
    Employee(int id,float salary){
this->id=id;
this->salary=salary;
    }
    void accept(){
cout<<"Enter your id "<<endl;
cin>>this->id;
cout<<"Enter your salary"<<endl;
cin>>this->salary;
    }
int get_id(){
    return this->id;
}


float get_salary(){
    return this->salary;
}


void display(){
cout<<"Id = "<<get_id()<<endl;
cout<<"Salary = "<<get_salary()<<endl;
}


};
int main(){
Employee e1(5,5000);
e1.display();
Employee e2;
e2.accept();
e2.display();


}