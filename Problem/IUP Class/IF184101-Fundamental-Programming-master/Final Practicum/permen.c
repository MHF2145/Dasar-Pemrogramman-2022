/*
a wants candy from b.
a gives a formula to b, and b will give x candies from the formula.
the formula is:

candy = sigma(i=0 to n-1) (a^i * i^b) % m

if the gcd of m and a-1 is 1, then output the amount of candies b will give to a.

input: a b n m
output: x

e.g.
input: 4 2 6 10
output: 0

input: 10 3 8 7
output: 4

input: 20 4 10 100
output: 20
*/
#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // first line of input is n (number of cases)
    int n;
    scanf("%d", &n);
    int cases[n][4];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &cases[i][0], &cases[i][1], &cases[i][2], &cases[i][3]);
    }
    for (int i = 0; i < n; i++) {
        int a = cases[i][0];
        int b = cases[i][1];
        int n = cases[i][2];
        int m = cases[i][3];
        int x = 0;
        for (int j = 0; j <= n - 1; j++) {
            x += (int)(pow(a, j) * pow(j, b)) % m;
        }
        // if gcd of m and a-1 is 1, then output the amount of candies b will give to a
        if (gcd(m, a-1) == 1) {
            printf("%d", x);
        } else {
            printf("0");
        }
    }
}