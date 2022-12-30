#include <stdio.h>

//make a function to analyze how many vowels in a string
int vowel(char *str){
    int i=0;
    int count=0;
    while(str[i]!='\0'){
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
        str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
            count++;
        }
        i++;
    }
    return count;
}

//B, C, D, F, G, J, K, L, M, N, P, Q, S, T, V, X, Z and often H, R, W, Y.
int consonants(char *str) {
    int i = 0;
    int count = 0;
    char cons[1000]={'b','c','d','f','g','j','k','l','m','n','p','q','s','t','v','x','z','h','r','w','y',
    'B','C','D','F','G','J','K','L','M','N','P','Q','S','T','V','X','Z','H','R','W','Y'};
    while(str[i]!='\0'){
        for (int j = 0; j < 42; j++){
            if (str[i] == cons[j]){
                count++;
            }
        }
        i++;
    }
    return count;
}

// make a function to return the number of uppercase in a string
int uppercase(char *str){
    int i=0;
    int count=0;
    while(str[i]!='\0'){
        if (str[i]>='A'&&str[i]<='Z'){
            count++;
        }
        i++;
    }
    return count;
}

int lowercase(char *str){
    int i=0;
    int count=0;
    while(str[i]!='\0'){
        if (str[i]>='a'&&str[i]<='z'){
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    char str[1000][1000];
    scanf("%[^\n]", str[0]);
    printf("Vowel Number: %d\n", vowel(str[0]));
    printf("Number of Consonants: %d\n", consonants(str[0]));
    printf("Total Uppercase: %d\n", uppercase(str[0]));
    printf("Total Smallcase: %d", lowercase(str[0]));
    return 0;
}