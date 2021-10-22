#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>


/* 
Описать структуру для представления информации о человеке: 
фамилия (не более 30 символов), имя (не более 30 символов), 
возраст. Описать функцию, которая для заданного массива из описанных структур определяет: 
1. возраст самого старшего человека; 
2. количество людей с заданным именем (имя также является параметром функции); 
*/
struct user {
    char surname[30];
    char name[30];
    int age;
};


void print_user(struct user u);
void print_users(struct user *u, int N);
//возраст самого старшего человека; 
int get_max_user_age(struct user *u, int N);
//количество людей с заданным именем (имя также является параметром функции);
int get_users_for_name(struct user *u, int N, const char *name);

void sort_users_by_age(struct user *u, int N);


/*Описать структурный тип для представления сбора информации с датчика температуры, 
необходимые поля: дата (день, месяц, год) и температура. 
Используя этот тип, описать функцию, принимающую на вход массив 
таких данных и упорядочивающую его по неубыванию, по дате. */

struct measurements {
    int day;
    int month;
    int year;
    int temp;
};

struct bitset {
    char bit0:1;
    char bit1:1;
    char bit2:1;
    char bit3:1;
    char bit4:1;
    char bit5:1;
    char bit6:1;
    char bit7:1;
};

union num {
    float f;
    int i;
};

union u_test {
    unsigned int as_u32;
    unsigned char as_u8[4];
    struct bitset b;
};

int read_measurements_from_file(struct measurements *meas, const char *file);
void print_measurements(struct measurements *meas, int N);

#endif
