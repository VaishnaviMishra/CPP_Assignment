#include<iostream>
#include<string>
#include<limits>
using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;
    public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year) : day(day), month(month), year(year)
    {
    }
    int get_day()
    {
        return this->day;
    }
    void set_day(int day)
    {
        this->day = day;
    }
    int get_month()
    {
        return this->month;
    }
    void set_month(int month)
    {
        this->month = month;
    }
    int get_year()
    {
        return this->year;
    }
    void set_year(int year)
    {
        this->year = year;
    }
    void accept()
    {
        cout << "Please enter date in dd mm yyyy format: " << endl;
        cin >> this->day >> this->month >> this->year;
    }
    void display()
    {
        cout << "Date: " << this->day << " - " << this->month << " - " << this->year << endl;
        cout << "-------------------" << endl;
    }
    bool isLeapYear()
    {
        if((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0))
        return true;
        else
        return false;
    }
};
class Person
{
    private:
    string name;
    string address;
    Date dob;
    public:
    Person(): dob() // way 1
    {
        this->name = "";
        this->address = "";
        // way 2
        // this->dob.set_day(0);
        // this->dob.set_month(0);
        // this->dob.set_year(0);
    }
    Person(string name, string address, int day, int month, int year) : dob(day, month, year) // way1
    {
        this->name = name;
        this->address = address;
        // way 2
        // this->dob.set_day(day);
        // this->dob.set_month(month);
        // this->dob.set_year(year);
    }
    string get_name()
    {
        return this->name;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    string get_address()
    {
        return this->address;
    }
    void set_address(string address)
    {
        this->address = address;
    }
    Date get_dob()
    {
        return this->dob;
    }
    void set_dob(int day, int month, int year)
    {
        this->dob.set_day(day);
        this->dob.set_month(month);
        this->dob.set_year(year);
    }
    void display()
    {
        cout << "-------------------" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Address: " << this->address << endl;
        this->dob.display();
    }
    void accept() {
        cout << "Please enter name: ";
        cin >> this->name;
        // Clear the input buffer to consume the newline character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter address: ";
        getline(cin, this->address);
        cout << "Please enter date of birth: " << endl;
        this->dob.accept();
    }
};
class Employee
{
    private:
    int id;
    float salary;
    string dept;
    Date doj;
    public:
    Employee():doj()
    {
        this->id = 0;
        this->salary = 0;
        this->dept = "";
    }
    Employee(int id, float salary, string dept, int day, int month, int year): doj(day, month, year)
    {
        this->id = id;
        this->salary = salary;
        this->dept = dept;
    }
    int get_id()
    {
        return this->id;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    float get_salary()
    {
        return this->salary;
    }
    void set_salary(float salary)
    {
        this->salary = salary;
    }
    string get_dept()
    {
        return this->dept;
    }
    void set_dept(string dept)
    {
        this->dept = dept;
    }
    Date get_doj()
    {
        return this->doj;
    }
    void set_doj(Date doj)
    {
        this->doj = doj;
        // Assignment operator is not provided, default one will be used.
        // Since there are no pointers in Date class, shallow copy is safe to use here.
    }
    void display()
    {
        cout << "-------------------" << endl;
        cout << "Id: " << this->id << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "Department: " << this->dept << endl;
        cout << "Joining date: ";
        this->doj.display();
    }
    void accept()
    {
        cout << "Please enter employee ID: ";
        cin >> this->id;
        cout << "Please enter salary: ";
        cin >> this->salary;
        // Clear the input buffer to consume the newline character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter department: ";
        getline(cin, this->dept);
        // cout << "Please enter department: ";
        // cin >> this->dept;
        cout << "Please enter date of joining: "<< endl;
        this->doj.accept();
    }
};
int main()
{
    Employee e1;
    e1.accept();
    e1.display();
    Person P1;
    P1.accept();
    P1.display();
    return 0;
}