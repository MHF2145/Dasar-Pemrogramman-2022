#include <stdio.h>

int main() {
    /*
    win = 2 * bet
    jackpot = 5 * bet
    lose = -bet
    */

    long long digits = 0, prize[10000];
    char bet[100], result;
    char status[3][1000] = {
        "Lose! you're no longer a quadrillionaire now :\"(",
        "Jackpot!\nPrize: $",
        "Win!\nPrize: $"
    };

    scanf("%lli", &digits);
    scanf("%s", bet);
    scanf(" %c", &result);

    // if lose, then prize = -bet
    if (result == 'L') {
        printf("%s", status[0]);
    }
    else {
        // decrement loop through the array of all digits
        /*
            5 10 15 20 25 30, carry = 0
            5 10 15 20 55, carry = 0
            5 10 15 75, carry = 0
            5 10 80, carry = 10
            5 90, carry = 10
            15 90, carry = 0
            105
        */
        int carry = 0;
        for (int i = digits - 1; i >= 0; i--) {
            // convert char to int
            long long val =  (long long) bet[i] - '0';
            
            // if win then multiply by 2 else multiply by 5
            val = (result == 'W') ? val * 2 : val * 5;

            // add carry to val and store in prize array
            if (i > 0) {
                prize[i] = (val + carry) % 10;
                carry = (val + carry) / 10;
            }
            else {
                prize[i] = val + carry;
            }
        }
        
        // if win then print status[2] else print status[1]
        printf("%s", status[result == 'W' ? 2 : 1]);
        for (int i = 0; i < digits; i++) {
            printf("%lli", prize[i]);
        }
    }
    
    return 0;
}