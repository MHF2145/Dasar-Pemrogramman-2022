#include <stdio.h>
#include <string.h>

struct player {
    char name[11];
    int movements[10];
};

int main() {
    struct player players[4];
    char seeker[11];
    int found = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%s", players[i].name);
        for (int j = 0; j < 10; j++) {
            scanf("%d", &players[i].movements[j]);
        }
    }
    scanf("%s", seeker);
    for (int i = 0; i < 4; i++) {
        if (strcmp(players[i].name, seeker) == 0) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 4; k++) {
                    if (players[i].movements[j] == players[k].movements[j]) {
                        found++;
                    }
                }
            }
        }
    }
    if (found == 4) {
        printf("%s, %s and %s are all caught, %s wins", players[0].name, players[1].name, players[2].name, seeker);
    } else if (found == 3) {
        printf("%s is caught by %s", players[0].name, seeker);
    } else if (found == 2) {
        printf("%s and %s are caught by %s", players[0].name, players[1].name, seeker);
    } else {
        printf("%s seeks again", seeker);
    }
}