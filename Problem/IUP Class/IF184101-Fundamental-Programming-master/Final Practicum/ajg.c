#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define lld long long

int prime[100000];
int isPrime(lld n) {
    if (n == 0 || n == 1)
        return 0;
    for (int i = 2; i <= (lld)sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    lld Q, N;
    scanf("%lld", &Q);
    for (int i = 0; i < Q; i++) {
        lld noErrors = 0;
        scanf("%lld", &N);
        for (int j = 0; j < N; j++) {
            lld num = 0;
            scanf("%lld", &num);
            if (prime[num] == 0) {
                if (isPrime(num) == 1)
                    prime[num] = 1;
                else
                    prime[num] = -1;
            }
            if (prime[num] == 1) {
                printf("%lld ", num);
                noErrors = 1;
            }
        }
        if (noErrors == 0) {
            printf("Unable to send Fever Slot Buckle.");
        }
        printf("\n");
    }
}