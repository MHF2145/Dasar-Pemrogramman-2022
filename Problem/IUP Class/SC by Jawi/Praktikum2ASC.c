#include<stdio.h>

int main(){

    long long int n, maxCount=0, numers[100000], out;;


    scanf("%lli", &n);

    long long int size[n];

    for(long long int i=0; i<n;i++){
        scanf("%lli", &numers[i]);
    }

    for (long long int i = 0; i < n; i++) {
      long long int count = 0;

      for (long long int j = 0; j < n; j++) {
         if (numers[j] == numers[i])
         count++;
      }

      if (count > maxCount) {
         maxCount = count;
      }
   }
   out= n-maxCount;
   printf("%lli", out);

}
