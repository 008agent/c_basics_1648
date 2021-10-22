#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "help.h"
#include "structs.h"
#include "fileops.h"


int main(void)
{
    /*
    tasks with structs part 1
    struct user people[10];
    for (int i = 0; i < 10; i++) {
        people[i].age = rand() % 50;
        snprintf(people[i].surname, 30, "surname%d", rand() % 100);
        snprintf(people[i].name, 30, "name%d", rand() % 100);
    }

    print_users(people, 10);
    printf("Max age %d\n", get_max_user_age(people, 10));
    printf("People with name name27 %d\n", get_users_for_name(people, 10, "name27"));
    sort_users_by_age(people, 10);
    print_users(people, 10);
    */
    // fileops task 1
    //char filename[50] = { 0 };
    //scanf("%s", filename);
    //printf("File test.txt size %d\n", get_file_size(filename));
    // fileops task 2
    //printf("File summ %d\n", get_file_numbers_summ("in.txt"));
    //fileops task 3
    //file_append_digits_amount("in.txt");

    struct measurements meas[100];
    int count = read_measurements_from_file(meas, "measurements.txt");
    if (count != -1) {
        print_measurements(meas, count);
    }

    save_binary_file(meas, 100* sizeof(struct measurements), "structs.bin");

    memset(meas, 0, 100* sizeof(struct measurements));
    print_measurements(meas, 10);

    load_binary_file(meas, 100* sizeof(struct measurements), "structs.bin");
    print_measurements(meas, 10);

    return 0;
}