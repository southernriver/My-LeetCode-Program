#include<stdlib.h>
#include<stdio.h>

void main()
{
    char *endptr;
    char a[] = "12345.6789";
    char b[] = "1234.567qwer";
    char c[] = "-232.23e4";
    double x = strtod(a,NULL);
    printf("x=%lf\n",x);
    
    printf("a=%lf\n", strtod(a, NULL));
    printf("b=%lf\n", strtod(b, &endptr));
    printf("endptr=%s\n", endptr);
    printf("c=%lf\n", strtod(c, NULL));
    system("pause");
}