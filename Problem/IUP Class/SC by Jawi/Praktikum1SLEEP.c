#include <stdio.h>

int main(){
    //we must first declare the values to hold the values inputted by the problem
    long long int hour1, minutes1, hour2, minutes2, triptime, sleeptime;
    //Scan the value given by the problem
    scanf("%lli %lli %lli %lli %lli %lli", &hour1, &minutes1, &hour2, &minutes2, &triptime, &sleeptime);

    if(hour1>hour2){
        printf("Sleepyhead you already late smh");
    }
    else if(hour1==hour2){
        if(minutes1>minutes2){
            printf("Sleepyhead you already late smh");
        }
        else if(minutes1>minutes2-(triptime+sleeptime)){
            printf("Don't sleep again or you'll be late, Zoro");
        }
        else if(sleeptime==0){
            printf("Don't sleep again or you'll be late, Zoro");
        }
        else {
            printf("Zoro can sleep for another %lli minutes :D", (minutes2-minutes1)-triptime);
        }

    }
    else{
        minutes2 += (hour2-hour1)*60;

        if(minutes1>minutes2){
            printf("Sleepyhead you already late smh");
        }
        else if(minutes1>minutes2-(triptime+sleeptime)){
            printf("Don't sleep again or you'll be late, Zoro");
        }
        else if(sleeptime==0){
            printf("Don't sleep again or you'll be late, Zoro");
        }
        else {
            printf("Zoro can sleep for another %lli minutes :D", (minutes2-minutes1)-triptime);
        }
    }
}
