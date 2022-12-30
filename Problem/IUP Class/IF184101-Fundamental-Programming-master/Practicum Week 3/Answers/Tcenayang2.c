#include <stdio.h>
#include <string.h>

char encrypt(char text, int key) {
    if(text >= 'a' && text <= 'z') {
        text = (text - 'a' + key) % 26 + 'a';
    }
    else if(text >= 'A' && text <= 'Z') {
        text = (text - 'A' + key) % 26 + 'A';
    }
    return text;
}

// decryption algorithm
char decrypt(char text, int key) {
    if (text >= 'a' && text <= 'z') {
        key = key % 26;
        text = text - key;
        if (text < 'a') {
            text = text + 26;
        }
    }
    else if (text >= 'A' && text <= 'Z') {
        //text = (((text - 'A') + (26 - key)) % 26) + 'A';
        key = key % 26;
        text = text - key;
        if (text < 'A') {
            text = text + 26;
        }
    }
    return text;
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int add_fib(int n) {
    return n + fib(n);
}

int main() {
    int t, process[10000], key[10000];
    // encrypting = 0, decrypting = 1
    char message[1000][1000];
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &process[i]);
        if (process[i] > 1) {
            printf("Mode is not valid!");
            return 0;
        }

        scanf("%d", &key[i]);
        getchar();
        scanf(" %[^\n]", message[i]);
    }

    for (int i = 0; i < t; i++) {
        // get the fibonnaci number of the key
        int fib_key = fib(key[i]);

        // encrypt and decrypt the message
        if (process[i] == 0) {
            for (int j = 0; j < strlen(message[i]); j++) {
                message[i][j] = encrypt(message[i][j], fib_key);
            }
        }
        else if (process[i] == 1) {
            for (int j = 0; j < strlen(message[i]); j++) {
                message[i][j] = decrypt(message[i][j], fib_key);
            }
        } else {
            printf("Mode is not valid!");
        }
        printf("%s\n", message[i]); 
    }
    return 0;
}

/*
    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
    65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90
    a  b  c  d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z
    97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122
*/