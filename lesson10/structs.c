#include "structs.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print_user(struct user u)
{
    printf("%s %s age:%d\n", u.name, u.surname, u.age);
}

void print_users(struct user *u, int N)
{
    for (int i = 0; i < N; i++) {
        print_user(u[i]);
    }
}


int get_max_user_age(struct user *u, int N)
{
    int max = u[0].age;

    for (int i = 1; i < N; i++) {
        if (u[i].age > max) {
            max = u[i].age;
        }
    }

    return max;
}


int get_users_for_name(struct user *u, int N, const char *name)
{
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(u[i].name, name) == 0) {
            count++;
        }
    }

    return count;
}


int comparer(const void *v1, const void *v2)
{   
    struct user u1 = *(struct user*)v1;
    struct user u2 = *(struct user*)v2;

    return u1.age - u2.age;
}


void sort_users_by_age(struct user *u, int N)
{
    qsort(u, N, sizeof(struct user), comparer);
/*       void qsort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));*/
}


int read_measurements_from_file(struct measurements *meas, const char *file)
{
    FILE *f;
    int counter = 0;

    f = fopen(file, "r");
    if (!f) {
        return -1;
    }

    while (!feof(f)) {
        int scans = fscanf(f, "%d;%d;%d;%d", 
                           &meas[counter].day,
                           &meas[counter].month,
                           &meas[counter].year,
                           &meas[counter].temp
                            );
        if (scans != 4) {
            break;
        }
        counter++;
    }

    fclose(f);
    return counter;
}

void print_measurements(struct measurements *meas, int N)
{
    for (int i = 0; i < N; i++) {
        printf("D:%d M:%d Y:%d TEMP:%d\n", 
               meas[i].day,
               meas[i].month,
               meas[i].year,
               meas[i].temp);
    }
}
