#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t t;
    struct tm lt;
    char res[32];
    t = 1452849871;
    t = (time_t) atoi(argv[1]);
    localtime_r(&t, &lt);

    if (strftime(res, sizeof(res), "%H", &lt) == 0)
    {
        printf("error\n");
        return 1;
    }
    printf("%u -> %d\n", t, atoi(res));
}
