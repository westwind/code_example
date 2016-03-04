#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);

    switch (x){
        case 1:
            printf("1: %d\n",x);
        case 2:
            printf("2: %d\n",x);
        case 3:
            printf("3: %d\n",x);
        case 4:
            printf("4: %d\n",x);
        default:
            printf("default %d\n",x);
    }
}
