#include<iostream>
using namespace std;
struct Date
{
private:
    int Day = 1;
    int month = 1;
    int year = 1000;
public:
void accept(){
    cout<<"Enter Day-Month-Year"<<endl;
    cin>>Day>>month>>year;
}
void printt(){
    cout<<" Entered date is "<<Day<<"-"<<month<<"-"<<year<<endl;
}
};
int menu (){
    int choice;
    cout<<"\nEnter your choice"<<endl;
    cout<<"  0  - Exit"<<endl;
    cout<<"  1  - Accept Date "<<endl;
    cout<<"  2  - Display Date "<<endl;
    cin>>choice;
    return choice;

}

int main(){
struct Date d;
int choice;
while ((choice = menu())!=0)
{
    switch (choice)
    {
    case 1:
    d.accept();
        break;
    case 2:
    d.printt();
    break;
    
    default:
        cout<<"Wrong Input";
        break;
    }
}

return 0;
}