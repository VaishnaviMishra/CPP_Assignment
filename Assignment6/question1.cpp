#include<iostream>
using namespace std;
int Factorial(int n){
   
    
    if( n<0){
    throw 1;}
int result = n;
if(n==0){
 return 1;}
else
for(int i = n;i>1;i--){
    result = result * ( n-1);
    n--; }
    cout << result<<endl;
return result;
    


}


int main(){
    int result;
    int number;
    try{
    
    cout<<"Enter number"<<endl;
    cin>>number;
    result = Factorial(number);
    }
    catch(int error){
    cout<<"Factorial of negative number cannot be calculated"<<endl;
}
    cout<<"Factorial of "<<number<< " is "<<result;
    


return 0;
}