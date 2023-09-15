#include<stdio.h>
struct Date
{
    
 int day;
 int month;
 int year;
};
void accept(struct Date *d){
    printf("Enter the Day-Month-Year");
    scanf("%d %d %d",&d->day,&d->month,&d->year);
}
void printt(struct Date d){
    printf(" Date is %d-%d-%d",d.day,d.month,d.year);
}

int main(){
struct Date d;
accept(&d);
printt(d);


    return 0;
}