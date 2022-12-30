#include <stdio.h>
#include <string.h>

char string[100000];
int oho = 0, left = 0, right = 0;

int nguli(char *dayum){
    int length = strlen(dayum);
    for (int i = 0; i <= length; i++)
    {
        left = right = i;
        while ((left >= 0) && (right < length) && (dayum[left] == dayum[right]))
        {
            oho += 1;
            left--;
            right++;
        }

        right = i + 1;
        left = i;

        while ((left >= 0) && (right <= length) && (dayum[left] == dayum[right]))
        {
            oho += 1;
            left--;
            right++;
        }
    }
    return oho;
}

int main(){
    scanf("%s", string);
    oho = nguli(string);
    printf("%d", oho);
    
    return 0;
}