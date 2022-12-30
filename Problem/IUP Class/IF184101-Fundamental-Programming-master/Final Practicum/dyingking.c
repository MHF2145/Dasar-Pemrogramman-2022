#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPrime(int n) {
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

struct City {
    char name[1000];
    char longitude[1000];
    char latitude[1000];
};

int main() {
    int places = 0, check = 0;
    scanf("%d %d", &places, &check);
    
    struct City city[places];
    for (int i = 0; i < places; i++) {
        scanf(" %s", city[i].name);
        scanf(" %s", city[i].longitude);
        scanf(" %s", city[i].latitude);
    }
    char places_to_check[1000][1000];
    for (int i = 0; i < check; i++) {
        scanf(" %s", places_to_check[i]);
    }

    for (int i = 0; i < check; i++) {
        for (int j = 0; j < places; j++) {
            if (strcmp(places_to_check[i], city[j].name) == 0) {
                int north = atoi(city[j].longitude);
                int east = atoi(city[j].latitude);
                if (isPrime(north) && isPrime(east)) {
                    printf("%s aman! Bangunlah Kesatria!\n", places_to_check[i]);
                    break;
                } else {
                    printf("%s tidak aman! Ini pasti ulah Gorgom!\n", places_to_check[i]);
                    break;
                }
            }
            if (strcmp(places_to_check[i], city[j].name) != 0) {
                if (j == places - 1) {
                    printf("Tempat apa itu? Kotaro tidak tahu!\n");
                    break;
                }
                continue;
            }
        }
    }
}