#include <stdio.h>
#include <string.h>

void subStringPalindrome(char str[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int k = i;
        while (j >= 0 && k < n && str[j] == str[k]) {
            count++;
            j--;
            k++;
        }
        j = i;
        k = i + 1;
        while (j >= 0 && k < n && str[j] == str[k]) {
            count++;
            j--;
            k++;
        }
    }
    printf("%d", count);
}

int main() {
    char str[100000];
    scanf("%s", str);
    subStringPalindrome(str, strlen(str));
    return 0;
}
