#include <stdio.h>
#include <math.h>

//get gcd using pointers
int gcd(int *a, int *b) {
    int temp;
    while (*b != 0) {
        temp = *b;
        *b = *a % *b;
        *a = temp;
    }
    return *a;
}

int main() {
    int N = 0, M = 0, K = 0, ans = 0;
	scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++) {
        K = __gcd(i, N);
        ans += pow(M, K);
    }
    ans /= N;
    printf("%d", ans);
    return 0;
}