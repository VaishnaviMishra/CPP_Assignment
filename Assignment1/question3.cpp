
#include<iostream>
using namespace std;

struct student {
    char name[30];
    int rollNo;
    float marks;

  void  initStudent( student* std){
    std->name;
    std->rollNo=0;
    std->marks=0.0;
}
void acceptStudentFromConsole( student* std)
{
    cout<<"enter rollNo"<<endl;
    cin>>std->rollNo;
    cout<<"enter name"<<endl;
    cin>>std->name;
    cout<<"enter marks"<<endl;
    cin>>std->marks;
}
void printStudentOnConsole( student* std){
    cout<<"Roll No : "<<std->rollNo<<"\nName : "<<std->name<<"\nMarks : "<<std->marks<<endl;
}
};

int main(){
     student* std;
       std=new student();
    int choice;
do{
cout<<"0.Exit\n1. initStudent\n2. acceptStudentFromConsole \n3.printStudentOnConsole"<<endl;

cin>>choice;
switch(choice){
    case 1:
        std->initStudent(std);
    break;
    case 2:
        std->acceptStudentFromConsole(std);
     break;
    case 3: 
        std->printStudentOnConsole(std);
    break;
    default:
    cout<<"Enter correct Choice!!!";
    break;
    
}
}while(choice!=0);
return 0;
}
