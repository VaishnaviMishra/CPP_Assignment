#include<iostream>
using namespace std;
class Fraction
{private:
int numerator;
int denominator;
public:

int common_factor(int n,int d){
    
   
    while(d!=0){
        int temp =d;
   
    d = n % d;
    n = temp;}
   
return n;}

    Fraction(){
    this->numerator = 1;
    this->denominator = 1;
}

Fraction(int numerator,int denominator){
    if(denominator == 0)
    throw 2;
else
this->numerator = numerator;
this->denominator = denominator;
}

void set_numerator(int numerator){
    this->numerator = numerator;
}

void set_denominator(int denominator){
    if(denominator == 0)
    throw 1;
else
this->denominator = denominator;
}

int get_numerator(){
    cout<<this->numerator<<endl;
    return this->numerator;
}

int get_denominator(){
    cout<<this->denominator<<endl;
    return this->denominator;
}

void lowestform(){
    int commonfactor = common_factor(numerator,denominator);
    
   this->numerator = this->numerator/commonfactor;
   this->denominator = this->denominator/commonfactor;
   cout<<"lowest form is "<<this->numerator<<" / "<<this->denominator<<endl;

 }

void decimalValue() {
        cout<< "Decimal form is "<<static_cast<double> (numerator) / denominator<<endl;
    }

Fraction operator+( Fraction &other){
    Fraction f1;
    f1.numerator = this->numerator+other.numerator;
    f1.denominator = this->numerator + other.numerator;
    return f1;
}

};






int main(){
    try{
    Fraction f1;
    f1.set_numerator(18);
    f1.set_denominator(36);
    f1.lowestform();
   
    f1.decimalValue();
    
    Fraction f2(25,5);
    Fraction f3= f1 + f2;
    
    f3.get_numerator();
    f3.get_denominator();
    f3.lowestform();}

    catch (int error){
        cout<<"Error : Denominator can't be zero"<<endl;
    }
    


}