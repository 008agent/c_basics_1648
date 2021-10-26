//day;month;year;temp

#include <stdio.h>
#include <stdlib.h>

struct measurement {
    int day;
    int month;
    int year;
    int temp;
};

int main(int argc, char **argv)
{
    const char *fname = "output.txt";

    FILE *f = fopen(fname, "w");
    if (!f) {
        printf("Error!\n");
        return -1;
    }

    struct measurement meas[31];//0-30

    for (int i = 0; i < 31; i++) {
        meas[i].day = i+1;
        meas[i].month = 1;
        meas[i].year = 2000;
        meas[i].temp = rand() % 100 - 50;
    }

    for (int i = 0; i < 31; i++) {
        fprintf(f, "%d;%d;%d;%d\n", 
           meas[i].day,
           meas[i].month,
           meas[i].year,
           meas[i].temp );
    }

    fclose(f);
    return 0;
}