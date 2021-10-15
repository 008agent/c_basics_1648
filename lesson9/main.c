#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void fill_array(int *array, int N);
void print_array(int *array, int N);
/* 1.1 Написать функцию вычисления скалярного произведения двух вещественных массивов. */
void print_array_f(const float *array, int N);
void scalar_mult2(const float array1[], const float array2[], float result[], int N);
void scalar_mult2_ptrs(const float *array1, const float *array2, float *result, int N);
/* 1.2 Составить функцию которая определяет в массиве, состоящем из положительных и 
   отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент. 
   Показать пример ее работы на массиве из 10 элементов. */
int int_module(int arg);
int get_module_max_amount(int *array, int N);

/* 2.1 Реализовать строковую функцию strlen(const char *cs) */
int my_strlen(const char *str);
int get_string(char *str);

/* 2.2 Реализовать строковую функцию strcpy(char *dst, const char *src)
    Копирования строки src (включая '\0') в строку dst . 
    Функция возвращает указатель на первый символ строки dst. 
 */
char *my_strcpy(char *dst, const char *src);

/* 2.3 Реализовать строковую функцию strcmp(const char *cs, const char *ct)
Функция сравнивает в лексикографическом порядке строку cs со строкой ct. 
Если строка cs меньше строки ct, возвращается значение < 0, если строка cs 
больше строки ct, возвращается значение > 0, в случае равенства строк возвращается значение 0. 
 */

/*
 2.4 Посчитать количество слов в тексте, слова разделены одним или несколькими пробелами.
*/
int get_words_count(const char *text);

/* 2.5 Реализовать функцию, которая возвращает сумму цифр 
   в переданной ей строке. str_sum_digits(const char *cs)
*/
int str_sum_digits(const char *cs);

int my_strcmp(const char *cs, const char *ct);

int main(void)
{
    /* task 1.1
    float array1[5] = { 0.f, 10.f, 20.f, 30.f, 50.f };
    float array2[5] = { 40.f, -2.f, 0.f, -10.f, 11.f };
    float array3[5] = { 0.f };

    print_array_f(array1, 5);
    print_array_f(array2, 5);
    scalar_mult2_ptrs(array1, array2, array3, 5);
    print_array_f(array3, 5);
    */

    /*
    task 1.2
    int array[10];
    fill_array(array, 10);
    print_array(array, 10);
    printf("get_module_max_amount = %d\n", get_module_max_amount(array, 10));
    */

/* tasks 2.1-2.3
    char str[100] = { 0 };
    char str2[100] = { 0 };

    get_string(str);
    get_string(str2);

    printf("my_strcmp result %d\n", my_strcmp(str2, str));
*/

/* task 2.4
    char str1[100] = { 0 };
    get_string(str1);

    printf("WC %d\n", get_words_count(str1));
*/
/* task 2.5
    char str1[100] = { 0 };
    get_string(str1);

    printf("str_sum_digits %d\n", str_sum_digits(str1));
*/

    return 0;
}


void fill_array(int *array, int N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        // [-50:50)
        *(array + i) = rand() % 100 - 50;
    }
}


void print_array(int *array, int N)
{
    for (int i = 0; i < N; i++) {
        printf("[%d] = %d ptr=%p\n", i, *(array + i), (array + i));
    }
}


void scalar_mult2(const float array1[], const float array2[], float result[], int N)
{
    for (int i = 0; i < N; i++) {
        result[i] = array1[i] * array2[i];
    }
}


void scalar_mult2_ptrs(const float *array1, const float *array2, float *result, int N)
{
    for (int i = 0; i < N; i++) {
        *(result + i) = *(array1 + i) * *(array2 + i);
    }
}


void print_array_f(const float *array, int N)
{
    for (int i = 0; i < N; i++) {
        printf("[%d] = %f ptr=%p\n", i, *(array + i), (array + i));
    }
}


int int_module(int arg)
{
    return (arg < 0) ? -arg : arg;
}


int get_module_max_amount(int *array, int N)
{
    // ищем максимальный элемент
    int max_module_amount = 0;
    int max = array[0];

    for (int i = 1; i < N; i++) {
        if (array[i] > max)
            max = array[i];
    }
    printf("max element %d\n", max);

    for (int i = 0; i < N; i++) {
        if (int_module(array[i]) > max)
            max_module_amount++;
    }

    return max_module_amount;
}


int my_strlen(const char *str)
{
    int size = 0;
    while (*str++) {
        size++;
    }
    return size;
}


int get_string(char *str)
{
    int ctr = 0;
    char ch;

    while( (ch = getchar()) != '\n') {
        *str++ = ch;
        ctr++;
    }
}


char *my_strcpy(char *dst, const char *src)
{
    char *tmp = dst;
    while (*dst++ = *src++);

    return tmp;
}


int my_strcmp(const char *cs, const char *ct)
{
    int tmp1 = 0, tmp2 = 0;

    while(*cs++) {
        tmp2 += *cs;
    }

    while(*ct++) {
        tmp1 += *ct;
    }

    return tmp2 - tmp1;
}


int get_words_count(const char *text)
{
    int wc = 1;
    while (*text++) {
        if (*text == ' ') {
            wc++;
        }
    }
    return wc;
}


int str_sum_digits(const char *cs)
{
    int tmp = 0;
    while (*cs) {
        if (*cs >= '0' && *cs <= '9') {
            tmp += *cs - '0';
        }
        cs++;
    }

    return tmp;
}