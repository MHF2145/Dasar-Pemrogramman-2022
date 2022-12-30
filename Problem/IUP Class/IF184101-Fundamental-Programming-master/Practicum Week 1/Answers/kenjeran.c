#include <stdio.h>

int main() {
    int m, n, t;
    scanf("%d %d %d", &m, &n, &t);
    
    // total cars in line
    int total_cars = m + n + 1;
    // how many cars will go out within t seconds
    int cars_out = t / 85 * 12;
    // check if time contains remainder seconds less than 85
    if (t % 85 > 25) {
        cars_out += ((t % 85) - 25) / 5;
    }

    // how many cars left in line
    int cars_left = total_cars - cars_out;

    // check if we also passed the green light
    if (cars_out > m) {
        printf("YES!");
    } else {
        printf("NO!");
    }

    // check if all cars passed
    if (total_cars > cars_out) {
        printf(" %d", cars_left);
    } else {
        printf(" 0");
    }

    return 0;
}