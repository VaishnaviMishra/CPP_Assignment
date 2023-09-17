# include<iostream>
using namespace std;

class Time
{
private:
    int h, m, s;
public:
   Time(){}
    Time(int h,int m,int s){
        this->h=h;
        this->m=m;
        this->s=s;
    }   
    void setHour(int h){
        this->h=h;
    }
    void setMinute(int m){
        this->m=m;
    }
    void setSeconds(int s){
        this->s=s;
    }
    int getHour(){
        return this->h;
    }
    int getMinute(){
        return this->m;
    }
    int getSeconds(){
        return this->s;
    }
    void printTime(){
        cout<<getHour()<<" : "<<getMinute()<<" : "<<getSeconds()<<endl;
    }
    
};

int main(){

Time* timeArray = new Time[3];

    // Set and print the times for each object
    for (int i = 0; i < 3; ++i) {
        int h, m, s;
        cout << "Enter the time (hh mm ss) for object " << i + 1 << ": ";
        cin >> h >> m >> s;
        timeArray[i] = Time(h, m, s);
        timeArray[i].printTime();
    }

    // Deallocate the dynamically allocated memory
    delete[] timeArray;

return 0;

}