#include <stdio.h>

void moo(int a, int *b);

int main()
{
    int x;
    int *y;

    x = 1;
    y = &x;

    printf("Address of x = %p, value of x = %d\n", &x, x);
    printf("Address of y = %p, value of y = %p, value of *y = %d\n", &y, y, *y);
    moo(9, &x);
    //  moo(9, y);
}

void moo(int a, int *b)
{
    printf("\n");
    printf("Address of a = %p, value of a = %d\n", &a, a);
    printf("Address of b = %p, value of b = %p, value of *b = %d\n", &b, b, *b);
}