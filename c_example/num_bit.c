#include <stdio.h>

int main(int argc, char *argv[])
{
    int integer = atoi(argv[1]);
    int num = 0;

    while(integer != 0)
    {
        if (integer%2 == 1)
        {
            num++;
        }
        integer = integer >> 1;
    }
    printf("%s has %d  1-bit\n", argv[1], num);
}
