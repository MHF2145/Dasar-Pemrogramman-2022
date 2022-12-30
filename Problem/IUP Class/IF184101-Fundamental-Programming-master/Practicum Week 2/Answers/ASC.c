#include <stdio.h>

int main() {
    /*
    design n rooms
    all needs to be same color
    1 to 9 colors
    */
    int amount_of_rooms;
    scanf("%d", &amount_of_rooms);

    int colors[amount_of_rooms];
    for (int i = 0; i < amount_of_rooms; i++) {
        scanf("%d", &colors[i]);
    }

    // loop through all the colors
    int maxElem, count;
    for (int i = 0; i < amount_of_rooms; i++) {
        count = 1;
        for (int color = i; color < amount_of_rooms; color++) {
            if (colors[i] == colors[color]) {
                count++;
                if (count > 0) {
                    maxElem = colors[color];
                }
            }
        }
    }

    int maxCounter = 0;
    for (int i = 0; i < amount_of_rooms; i++) {
        if (colors[i] == maxElem) {
            maxCounter++;
        }
    }
    int changes = amount_of_rooms - maxCounter;

    printf("%d", changes);
    return 0;
}