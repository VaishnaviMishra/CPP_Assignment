#include<iostream>
using namespace std;
class Marks{
private:
    float Eng;
    float Chem;
    float Phy;

public:
Marks(){
    this->Eng = 0;
    this->Chem = 0;
    this->Phy = 0;
}
Marks(int e, int c, int p){
    this->Eng = e;
    this->Chem = c;
    this->Phy = p;

}
void accept_marks(){
    cout<<"Enter your obtained marks in Eng out of 100"<<endl;
    cin>>this->Eng;
    cout<<"Enter your obtained marks in phy out of 100"<<endl;
    cin>>this->Phy;
    cout<<"Enter your obtained marks in chem out of 100"<<endl;
    cin>>this->Chem;
}
float percentage(){
float percent = ((this->Eng+this->Chem+this->Phy) / 300)*100;
return percent;
}
};

class Student{
private:
string Name;
char Gender;
int Roll_No;
Marks m;
public:
void accept(){
    cout<<"Enter your name"<<endl;
    cin>>Name;
    cout<<"Enter Your gender , F - Female , M - Male"<<endl;
    cin>>Gender;
    cout<<"Enter your Roll No"<<endl;
    cin>>Roll_No;
    m.accept_marks();
}

void display(){
    cout<<"Name = "<<Name<<endl;
    cout<<"Gender = "<<Gender<<endl;
    cout<<"Roll No = "<<Roll_No<<endl;
    cout<<"Your Percentage = "<<m.percentage()<<"%"<<endl;
}




};




int main(){
    Student s[3];
    for(int i = 0;i<3;i++){
    s[i].accept();
    s[i].display();
    }
}