#include <stdio.h>

int main(int argc, char *argv[])
{
    //int a[3]={123456, 234567, 34567};
    char a[3]={'a', 'b', 'c'};
    int i;

    for(i=0;i<3;i++)
    {
        printf("0x%x ",a[i]);
    }
    printf("\n");

    a[0] = a[0]>>5;
    for(i=0;i<3;i++)
    {
        printf("0x%x ",a[i]);
    }
    printf("\n");
}
