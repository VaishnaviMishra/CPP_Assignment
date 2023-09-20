#include<iostream>
using namespace std;
class Distance
{
    private:
    int feet;
    int inch;
    public:
    Distance()
    {
        this->feet = 0;
        this->inch = 0;
    }
    Distance(int feet, int inch): feet(feet), inch(inch)
    {
    }
    void accept()
    {
        cout << "Please enter feet: ";
        cin >> this->feet;
        cout << "Please enter inches: ";
        cin >> this->inch;
    }
    void display()
    {
        cout << "Distane: " << this->feet << " feet and " <<this->inch << " inches" << endl;
    }
    Distance operator+(Distance &obj)
    {
        Distance d;
        d.inch = this->inch + obj.inch;
        if(d.inch >= 12)
        {
            d.feet = this->feet + obj.feet + 1;
            d.inch = d.inch % 12;
        }
        else
        {
            d.feet = this->feet +  obj.feet;
        }
        return d;

    }
    void operator++()
    {
        this->inch++;
        if(this->inch >= 12)
        {
            this->feet++;
            this->inch = this->inch % 12;
        }
    }
    friend bool operator ==(Distance &obj1, Distance &obj2);
    friend void operator>>(istream &in, Distance &obj);
    friend void operator<<(ostream &out, Distance &obj);
    friend void operator--(Distance &obj);
};
bool operator ==(Distance &obj1, Distance &obj2)
{
    if(obj1.feet == obj2.feet && obj1.inch == obj2.inch)
    return true;
    return false;
}
void operator>>(istream &in, Distance &obj)
{
    cout << "Feet : ";
    in >> obj.feet;
    cout << "Inches: ";
    in >> obj.inch;
}
void operator<<(ostream &out, Distance &obj)
{
    out << "-----------------------" << endl;
    out << "Feet : " << obj.feet << endl;
    out << "Inches: " << obj.inch << endl;
    out << "-----------------------" << endl;
}
void operator--(Distance &obj)
{
    if(obj.inch == 0)
    {
        obj.feet--;
        obj.inch = 11;
    }
    else
    {
        obj.inch--;
    }
}
int main()
{
    Distance D1, D2, D3;
    cin >> D1;
    cin >> D2;
    D3 = D1 + D2;
    cout << D3;
    Distance D4(5, 0), D5(5, 11);
    --D4;
    cout << D4;
    ++D5;
    cout << D5;
    return 0;
}