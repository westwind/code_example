#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned int integer = atoi(argv[1]);
    int num = 0;

    for(num=0; integer; num++)
    {
        integer &= integer-1;
    }
    printf("%s has %d  1-bit\n", argv[1], num);
}
