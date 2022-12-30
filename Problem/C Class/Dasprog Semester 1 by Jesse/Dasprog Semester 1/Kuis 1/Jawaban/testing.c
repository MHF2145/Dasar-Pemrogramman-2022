#include<stdio.h>
	#include<conio.h>
		
	//PROGRAM OF REVERS THREE DIGIT NUMBER WITHOUT LOOP
	void main()
	{
    int a, last, rev=0;

    printf("enter 4 digit number");
    scanf("%d",&a);

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    last=a%10;
    rev=rev*10+last;
    a=a/10;

    rev=rev*10+a;

printf("reverse number is %d",rev);
}