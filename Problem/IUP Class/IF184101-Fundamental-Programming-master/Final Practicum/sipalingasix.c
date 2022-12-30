/*
a will pay 6 coins to b on the first day
a will pay 66 coins to b on the second day
a will pay 666 coins to b on the third day
and so on
calculate all possible days b has worked for a from a number n (the sum of all the coins a has paid to b)

e.g.
input: 6
output: 1

input: 18
output: 3, 5
explanation: 6 + 66 + 666 = 738 => 7+3+8 = 18
             6 + 66 + 666 + 6666 + 66666 = 74070 => 7+4+0+7+0 = 18

input: 2022
output: -1
explanation: there is no way to get 2022 from the sum of coins a has paid to b
*/
#include <stdio.h>

int main() {
    // first line of input is n (number of cases)
    int n;
    scanf("%d", &n);
    int cases[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cases[i]);
    }
    for (int i = 0; i < n; i++) {
        int days[1000];
        // find all possible days
        
    }
}