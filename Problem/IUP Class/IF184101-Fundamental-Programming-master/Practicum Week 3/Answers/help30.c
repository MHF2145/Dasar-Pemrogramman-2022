#include <stdio.h>

long long fib(long long n) {
   // 0 0 1 1 2 4 7...68 112 180 292
   //  _ _ _ _ _ _      _   _   _
   //  0 1 0 1 2 3     44  68  112
   // pattern from n = 1 to n = 10 is the sum of the previous 3 fib numbers
   // pattern after n = 10 is the sum of the previous 2 fib numbers
   if (n == 1 || n == 2) return 0;
   else if (n == 3 || n == 4) return 1;
   else if (n == 5) return (fib(2) + fib(3) + fib(4));
   else if (n == 6) return (fib(3) + fib(4) + fib(5));
   else if (n == 7) return (fib(4) + fib(5) + fib(6));
   else if (n == 8) return (fib(5) + fib(6) + fib(7));
   else if (n == 9) return (fib(6) + fib(7) + fib(8));
   else if (n == 10) return (fib(7) + fib(8) + fib(9));
   else return (fib(n-1) + fib(n-2));
   // switch cases cannot be used because n is not constant
   // n should be evaluated at compile time for that
}

int main() {
   long long t, n, result[10000];
   scanf("%lld", &t);
   
   for (int i = 0; i < t; i++) {
      scanf("%lld", &n);
      result[i] = fib(n);
   }
   for (int i = 0; i < t; i++) {
      printf("%lld\n", result[i]);
   }

   return 0;
}