#include<iostream>
using namespace std;
class Employee{
    protected:
    int id;
    float salary;
    public:

    Employee(){
        this->id=0;
        this->salary=0.00;  
        cout<<"Inside employee class" <<endl;
    }

    Employee(int id,float salary){
this->id=id;
this->salary=salary;
    }

 virtual void accept(){
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


virtual void display(){
cout<<"Id = " <<get_id()<<endl;
cout<<"Salary = " <<get_salary()<<endl;
}
};

class manager :virtual public Employee
{
    protected:
    float bonus;
    public:
    manager(){
        this ->bonus = 0;
        cout<<"Inside manager class" <<endl;
    }

    manager(int id,float salary,float bonus){
        this->id = id;
        this->salary = salary;
        this ->bonus=bonus;
    }

float get_bonus(){
        return this->bonus;
    }

    void accept(){
        Employee::accept();
        cout<<"Enter bonus ="<<endl;
        cin>>bonus;
}

    void display(){
        Employee::display();
        cout<<"Bonus is "<<get_bonus()<<endl;
    }

};
class salesman :virtual public Employee
{
    protected:
    float commision;
    public:
    salesman(){
        this->commision = 0;
        cout<<"Inside salesman class" <<endl;
    }

    salesman(int id, float salary,float commision){
        this->id =id;
        this->salary = salary;
           this->commision = commision;
    }

    float get_commision(){
        return this->commision;
    }

    void accept(){
        Employee::accept();
        cout<<"Enter commision "<<endl;
        cin>>this->commision;
    }
    void display(){
        Employee::display();
        cout<<"Commision is "<<get_commision()<<endl;
    }

};

class sales_manager  : public manager , public salesman
{
public:
sales_manager(){
    this->id =0;
    this->salary=0;
    this->bonus = 0;
    this->commision = 0;
    cout<<"inside salesmanager"<<endl;
}

sales_manager(int id,float salary,float bonus,float commision){
    this->id = id;
    this->salary = salary;
    this->bonus = bonus;
    this->commision = commision;
}

void accept()
{ manager::accept();
  salesman::accept();
  manager::display();
  salesman::display();
} 

void display(){
}
};
int main(){
// Employee e1(5,5000);
// e1.display();
//Employee e2;
// e2.accept();
// e2.display();
//manager m1;
// m1.accept();
// m1.display();

//salesman s1;
// s1.accept();
// s1.display();
sales_manager sm;
sm.accept();
sm.display();

return 0;
}