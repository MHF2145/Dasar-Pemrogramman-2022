#include <stdio.h>
#include <math.h>

int main() {
    // number cards (1 - 9) are given in random order
    // we should choose two cards (starting from the right to the left)
    // same card cant be chosen twice

    int cards, c1, c2, num1, num2;
    scanf("%d", &cards);
    scanf("%d %d", &c1, &c2);

    // we know cards are 1 - 9
    // get digit from index
    num1 = cards / pow(10, c1 - 1);
    num1 = num1 % 10;
    num2 = cards / pow(10, c2 - 1);
    num2 = num2 % 10;

    if (num1 == num2) {
        // both cards have the same value
        printf("Win 100$!");
    } else if (num1 % 2 == 0 && num2 % 2 != 0) {
        // both are even and odd
        printf("Win 50$!");
    } else if (num1 % 2 != 0 && num2 % 2 == 0) {
        // both are odd and even
        printf("Win 50$!");
    } else if (num1 % 2 != 0 && num2 % 2 != 0) {
        // both cards are even
        printf("Lose!");
    } else if (num1 % 2 == 0 && num2 % 2 == 0) {
        // both cards are odd
        printf("Lose!");
    } else {
        // lmao
        printf("idk");
    }

    return 0;
}