#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Database{
    char name[10];
    int movement[10];
};


int main() {
    struct Database pemain[4];
    char seeker_name[10];
    int  index_of_seeker;
  	for (int i=0; i<4;i++){
        scanf("%s", pemain[i].name);
        for(int j=0; j<10;j++){
            scanf("%d", &pemain[i].movement[j]);
        }
    }
    scanf("%s", seeker_name);
    for(int i=0;i<4;i++){
        if(strcmp(seeker_name, pemain[i].name)==0){
            index_of_seeker=i;
            break;
        }
    }
    int index_caught[3], counter=0;

    for(int i=0; i<4;i++){
        if(i==index_of_seeker)continue;
        for(int j=0;j<10;j++){
            if(pemain[i].movement[j]==pemain[index_of_seeker].movement[j]){
                index_caught[counter]=i;
                counter++;
                break;
            }
        }
    }

    switch(counter){
        case 0: printf("%s seeks again", pemain[index_of_seeker].name);break;
        case 1: printf("%s is caught by %s", pemain[index_caught[0]].name, pemain[index_of_seeker].name);break;
        case 2: printf("%s and %s are caught by %s", pemain[index_caught[0]].name, pemain[index_caught[1]].name, pemain[index_of_seeker].name);break;
        case 3: printf("%s, %s, and %s are all caught, %s wins", pemain[index_caught[0]].name, pemain[index_caught[1]].name,pemain[index_caught[2]].name, pemain[index_of_seeker].name);break;
    }

    return 0;
}


