#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* compile me with following:
    gcc -o main main.c -lm
*/

int get_user_input(void);
void menu_ifelse(int arg);
void menu_switch(int arg);

/* 1while - Ввести целое число и определить количество цифр в нем. 12345 = 5 */
void print_digits_num(int arg);
/* 2while - Ввести целое число и определить сумму цифр в нем. */
void print_digits_summ(int arg);
/* 3while - Дано натуральное число n. Получить все его натуральные делители. 9 */
void print_natur_dividers(int arg);

/* 1for - Напечатать квадраты целых чисел от 1 до 10.*/
void print_n_squares(int N);
/* 2for - Дано натуральное число n. Получить наименьшее число вида 2^k, 
    превосходящее n. (Используйте побитовые операции). 30 */
void print_n_2k_for(int N);
void print_n_2k_while(int N);

/* Определяем что число простое */
bool is_prime(int arg);


int main(void)
{
    int from_user = get_user_input();
    printf("number %d is prime %s\n", from_user, is_prime(from_user) ? "TRUE" : "FALSE");
    //print_digits_num(from_user);
    //print_digits_summ(from_user);
    //print_natur_dividers(from_user);
    //menu_ifelse(from_user);
    //menu_switch(from_user);
    //print_n_squares(from_user);
    //print_n_2k_for(from_user);
    //print_n_2k_while(from_user);

    return 0;
}


int get_user_input(void)
{
    int input;
    int rc;

    printf("Please enter int number:\n");
    rc = scanf("%d", &input);
    if (rc != 1) {
        printf("error!\n");
    }

    return input;
}


void menu_ifelse(int arg)
{
    if (arg == 1) {
        printf("ONE\n");
    } else if (arg == 2) {
        printf("TWO\n");
    } else if (arg == 3) {
        printf("THREE\n");
    } else {
        printf("UNKNOWN!\n");
    }

    return;
}


void menu_switch(int arg)
{
    switch (arg) {
        case 1 : {
            printf("ONE\n");
            break;
        }
        case 2 : {
            printf("TWO\n");
            break;
        }
        case 3 : {
            printf("THREE\n");
            break;
        }
        default : {
            printf("UNKNOWN!\n");
            break;
        }
    }

    return;
}


void print_digits_num(int arg)
{
    int counter = 0;

    while (arg != 0) {
        arg /= 10;
        counter++;
    }

    printf("Digits num %d\n", counter);
}


void print_digits_summ(int arg)
{
    int counter = 0;

    while (arg != 0) {
        counter += arg % 10;
        arg /= 10;
    }

    printf("Digits summ %d\n", counter);
}


void print_natur_dividers(int arg)
{
    int counter = 0;
    int current = 1;

    while (current != (arg + 1)) {
        if ((arg % current) == 0) {
            counter++;
            printf("%d ", current);
        }
        current++;
    }
    printf("\nNum of dividers %d\n", counter);
}


void print_n_squares(int N)
{
    for (int i = 1; i <= N; i++) {
        //printf("%d ", i*i);
        printf("%d ", (int)pow((double)i, 2.0));
    }
    printf("\n");
}


void print_n_2k_for(int N)
{
    int counter;
    for (counter = 1; counter <= N; counter <<= 1);
    printf("%d\n", counter);
}


void print_n_2k_while(int N)
{
    int counter = 1;
    while (counter <= N) {
        counter <<= 1;
    }

    printf("%d\n", counter);
}


bool is_prime(int arg)
{
    bool prime = true;

    for (int i = 2; i < arg; i++) {
        if ((arg % i) == 0) {
            return false;
        }
    }

    return prime;
}
