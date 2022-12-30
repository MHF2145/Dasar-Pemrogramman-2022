#include <stdio.h>
#define lld long long

void swap(lld *a, lld *b) {
    lld a_t = *b;
    lld b_t = *a;
    *a = a_t;
    *b = b_t;
}

void get_swap_count(lld *arr, lld size, lld *swap_count) {
    for (lld i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
            *swap_count += 1;
            i = -1;
        }
    }
}

int main() {
    lld n = 0;
    for (int i = 0; 1; i++) {
        scanf(" %lld", &n);
        lld arr[n];
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }
        // sort the array
        lld count = 0;
        get_swap_count(arr, n, &count);

        // count the minimal changes
        printf("Minimal lakukan %lld pertukaran\n", count);

        // print out the array
        for (int i = 0; i < n; i++) {
            if (arr[i] % 10 == 0) {
                printf("Yeay Lulus Dasprog\n");
            } else if (arr[i] % 5 == 0) {
                printf("Lulus\n");
            } else if (arr[i] % 2 == 0) {
                printf("Yeay\n");
            } else {
                printf("%lld\n", arr[i]);
            }
        }
    }
    return 0;
}

/*
int sort_array_using_pointers(int *arr, int n) {
    // sort the array using pointers and count the number of swaps
    int temp;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                count++;
            }
        }
    }
    return count;
}

int main() {
    // input format
    // first row is n (the amount of glass)
    // second row is n amount of glass
    // if n = 0, then stop the program
    int n = 0;
    for (int i = 0; 1; i++) {
        scanf("%d", &n);
        int arr[n];
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        // sort the array
        int count = sort_array_using_pointers(arr, n);

        // count the minimal changes
        printf("Minimal lakukan %d pertukaran\n", count);

        // print out the array
        int yeay = 0, lulus = 0, dasprog = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 10 == 0 && dasprog == 0) {
                printf("Yeay Lulus Dasprog\n");
                dasprog++;
            } else if (arr[i] % 5 == 0 && lulus == 0) {
                printf("Lulus\n");
                lulus++;
            } else if (arr[i] % 2 == 0 && yeay == 0) {
                printf("Yeay\n");
                yeay++;
            } else {
                printf("%d\n", arr[i]);
            }
        }
    }
    return 0;
}
*/