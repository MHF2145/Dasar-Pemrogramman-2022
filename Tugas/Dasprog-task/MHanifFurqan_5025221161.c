#include <stdio.h>

int main(){
    int a, b;
    char operator;
    
    scanf("%d %c %d", &a, &operator, &b);

    if(operator == '+'){
        printf("%d", a + b);
    } else if(operator == '-'){
        printf("%d", a - b);
    } else if(operator == '*'){
        printf("%d", a * b);
    } else if(operator == '/'){
        printf("%d", a / b);
    } else if(operator == '%'){
        printf("%d", a % b);
    } else{
        printf("tolong masukin operator  + - * / %");
    }

    return 0;
}