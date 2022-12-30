#include <stdio.h>
#include <string.h>

char num[20];

void bubelsort(char erey[], int n){
int i, j, swapped;        
        for (i = 0; i < n - 1; i++) {
            swapped = 0;
            for (j = 0; j < n - i - 1; j++) {
                if (erey[j] < erey[j+1]) {
                    int temp1 = erey[j];
                    erey[j] = erey[j + 1];
                    erey[j + 1] = temp1;
                    swapped = 1;
                }
            }
            if (swapped == 0)
                break;
        }
}

int main() {
   int digits;

   scanf("%s", num);
   scanf("%d", &digits);

   int i, j;
   char hehe[digits], temp2[digits];

   for (i = 0; i < digits; i++)
   {
        temp2[i] = '0';
        hehe[i] = '0';
   }
   
   int nyaho = strlen(num);
   for (i = 0; i < nyaho - digits + 1; i++)
   {
        int susu = i;

        for (j = 0; j < digits; j++)
        {
            temp2[j] = num[j + susu];
        }

        bubelsort(temp2, digits);

        if (strcmp(temp2, hehe) > 0)
        {
            strcpy(hehe, temp2);
        }
   }

   for (i = 0; i < digits; i++)
   {
        printf("%c", hehe[i]);
   }
}