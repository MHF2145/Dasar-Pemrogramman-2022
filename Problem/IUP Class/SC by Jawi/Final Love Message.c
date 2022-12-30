#include <stdio.h>
#include<string.h>

void insertionSort(char *string1) {
   int i, j;
   char key;
   int n;
   n=strlen(string1);
   for (i = 1; i < n; i++) {
      key = string1[i];
      j = i-1;

      while (j >= 0 && string1[j] > key) {
         string1[j+1] = string1[j];
         j = j-1;
      }
      string1[j+1] = key;
   }
}

void HilangkanSpasi(char *string1){
    int n, m=0;
    char temp[100];
    strcat(temp, string1);
    n=strlen(string1);
    for(int i=0; i<n;i++){
        if(temp[i]!=' '){
            printf("%c", string1[i]);
        }
    }

}

int main(){
    char input[100][100];
    int counter=0;
    for(int i=0; i>=0;i++){
        scanf("%[^\n]s", input[i]);
        getchar();
        counter++;
        if(strcmp(input[i], "exit")==0)break;
    }
    for(int i=0; i<counter-1;i++){
        insertionSort(input[i]);
        HilangkanSpasi(input[i]);
        printf("\n");
    }

}
