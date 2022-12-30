#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ukuran 20000

int main(){
    char teks[ukuran], fileinput[100], fileoutput[100];

    scanf("%123s", fileinput);
    strcat(fileinput, ".txt");
    
    FILE *fp = fopen(fileinput, "r");

    scanf("%123s", fileoutput);
    strcat(fileoutput, ".txt");

    FILE *fps = fopen(fileoutput, "w");

    if (fp == NULL)
    {
        printf("Tidak ada file dengan nama tersebut");
    }
    
    while (fgets(teks, ukuran, fp) != NULL)
    {
        int i, key = 24;

        while (key < 0)
        {
            key = key + (127 - 32);
        }

        for (i = 0; teks[i]; i++)
        {
            if (teks[i] >= 32 && teks[i] < 127)
            {
                teks[i] = 32 + (teks[i] - 32 + key) % (127 - 32);
            }
        }
        fprintf(fps, "%s", teks);
    }
    
    fclose(fp);
    fclose(fps);
    return 0;
}