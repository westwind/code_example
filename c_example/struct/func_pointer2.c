#include <stdio.h>

struct sample
{
    int (*method)(int, int);
};

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
    struct sample s1;
    s1.method = Add;
    printf("%d\n", s1.method(5, 3) );
}
