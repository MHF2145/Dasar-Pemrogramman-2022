#include <stdio.h>

int main() {
    int n, m;
    int a;
    scanf("%d %d", &n, &m);

    //memakai rumus kombinatorika, untuk menghitung kemungkinan dari berapa banyak garis yang dibuat dengan jumlah titik yang diketahui
    a = ((n-2)*(n-1)) / 2; // 2 karena satu garis harus tepat 2 titik
    if (m > a) //gamungkin kalo misal garis lebih banyak daripada titik yang ada
    {
        printf("mana bisa bang");
    }
    else
    {
        printf("bisa dong");
    }

return 0;
}