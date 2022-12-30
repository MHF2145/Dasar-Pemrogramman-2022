#include <stdio.h>

int main() {
    /*
        - wakeHH, wakeMM = time when zoro wakes up by alarm
        - classHH, classMM = the time when the class starts
        - tripTime = time he needs to go to classroom
        - minSleepTime = minimum time in minutes zoro wants to sleep
    */
    int wakeHH, wakeMM, classHH, classMM, tripTime = 0, minSleepTime;
    scanf("%d %d", &wakeHH, &wakeMM);
    scanf("%d %d", &classHH, &classMM);
    scanf("%d %d", &tripTime, &minSleepTime);

    int wakeHH_mm = wakeHH * 60;
    int classHH_mm = classHH * 60;
    
    // get difference between class starts and time he wakes up
    int class_starts_in = (classHH_mm + classMM) - (wakeHH_mm + wakeMM);

    int time_to_sleep = class_starts_in - tripTime;
    if (time_to_sleep >= minSleepTime) {
        printf("Zoro can sleep for another %d minutes :D", time_to_sleep);
    } else {
        if (class_starts_in <= 0) {
            printf("Sleepyhead you already late smh");
        } else {
            printf("Don't sleep again or you'll be late, Zoro");
        }
    }

    return 0;
}