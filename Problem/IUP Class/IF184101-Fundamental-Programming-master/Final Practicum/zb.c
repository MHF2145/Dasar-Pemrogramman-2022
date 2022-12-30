#include <stdio.h>
#include <math.h>
#define lld long long

lld gcd(lld a, lld b) {
    for (lld i = 1; i < b; i++) {
        if (((a % b) * (i % b)) % b == 1) {
            return i;
        }
    } 
}

int main() {
    const int r = 1000000007;
    lld N, M;
    scanf(" %lld %lld", &N, &M);
    lld ans = 0;
    for (lld i = 0; i < N; i++) {
        lld tot = 1, temp, max = i;
        for (lld j = N; j != 0; j = temp) {
            temp = (max % j) % r;
            max = j;
        }
        for (int j = 0; j < max; j++) {
            tot = (tot * M) % r;
        }
        ans = (ans + tot) % r;
    }
    ans = (ans * gcd(N, r)) % r;
    printf("%lld", ans);
    return 0;
}