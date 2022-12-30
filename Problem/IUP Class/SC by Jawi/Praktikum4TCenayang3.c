#include <stdio.h>
#include <string.h>

struct Database{
    char input[100];
};

void Encrypt(char *string1);

int main(){

    struct Database x[100];
    for(int i=0; i>=0;i++){
        scanf("%s", x[i].input);
        if(strcmp(x[i].input, "exit")==0){
            return 0;
        }
        else{
            Encrypt(x[i].input);
            printf("%s\n", x[i].input);
        }
    }
}

void Encrypt(char *string1)
{
    int i, n, temp;
    n = strlen(string1);
    for (i = 0; i < n/2; i++){
        temp = string1[i];
        string1[i] = string1[n-i-1];
        string1[n-i-1] = temp;
    }

}
