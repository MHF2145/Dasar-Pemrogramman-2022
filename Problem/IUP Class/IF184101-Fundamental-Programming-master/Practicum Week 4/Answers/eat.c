#include <stdio.h>
#include <string.h>

struct Team {
    char firstMember[1000];
    char secondMember[1000];
    long long score;
};

struct TeamMember {
    char name[1000];
    long long eatPerMin;
};

void checkWinner(struct Team *teams, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (teams[i].score > max) {
            max = teams[i].score;
        }
    }
    for (int i = 0; i < n; i++) {
        if (teams[i].score == max) {
            printf("%s & %s Win!\nTotal Eaten: %d", 
                teams[i].firstMember, 
                teams[i].secondMember, 
                teams[i].score
            );
        }
    }
}

int main()
{
    long long n, min;
    scanf(" %lli %lli", &n, &min);

    struct TeamMember member[n];
    struct Team team[n];
    
    for (long long i = 0; i < n; i++){
        scanf(" %s %lli", member[i].name, &member[i].eatPerMin);
    }
    for (long long i = 0; i < n/2; i++) {
        team[i].score = 0;
        scanf(" %s %s", team[i].firstMember, team[i].secondMember);
        for (long long j = 0; j < n; j++) {
            if (strcmp(team[i].firstMember, member[j].name) == 0) {
                team[i].score += member[j].eatPerMin * min;
            }
            if (strcmp(team[i].secondMember, member[j].name) == 0)
            {
                team[i].score += member[j].eatPerMin * min;
            }
        }
    }

    checkWinner(team, n/2);
    return 0;
}