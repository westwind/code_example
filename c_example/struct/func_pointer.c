#include <stdio.h>

int Add(int a, int b)
{
    return a+b;
}

int Sub(int a, int b)
{
    return a-b;
}

int main(int argc, char *argv[])
{
    int (*method)(int, int);
    method = Add;
    printf("%d\n", (*method)(5, 3) );
}
