#include<iostream>
using namespace std;
class Date
{
private:
    int Day;
    int Month;
    int Year;
public:
    Date(){
      this->Day = 1;
      this->Month = 1;
      this-> Year = 1000;

    };
     void isLeapYear(){
         if(Year%4==0){
             cout<<Year<<" is a leap year"<<endl;
         }
         else{
             cout<<Year<<" is not a leap year"<<endl;
         }
     }
   
    void accept(){
        cout<<"Enter Day - Month - Year"<<endl;
        cin>>Day>>Month>>Year;
    }
    void printdate(){
        cout<<"Date is :"<<Day<<"-"<<Month<<"-"<<Year<<endl;
    }
};
int menu(){
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"0 - Exit  "<<endl;
    cout<<"1 - Accept"<<endl;
    cout<<"2 - Print "<<endl;
    cout<<"3 - Leap Year"<<endl;
    
    cin>>choice;
    return choice;

}


int main(){
    Date d;
    int choice;
    while ((choice = menu())!=0)
    {
        switch (choice)
        {
        case 1:
        d.accept();
            break;
        case 2:
        d.printdate();
        break;
         
        case 3:
        d.isLeapYear();
        break;
        
        default:
        cout<<"Wrong choice";
            break;
        }
    
    }
    


return 0;
}