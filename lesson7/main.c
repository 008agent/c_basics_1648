#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b);
bool get_user_input_int(int *a, int *b);

unsigned int my_factorial(unsigned int n);
unsigned int my_factorial_for(unsigned int n);
void recursive_for(int i, int n);
unsigned int float_as_int(float arg);

//fact(3) = 3 * 2 * 1
//fact(5) = 5 * 4 * 3 * 2 * 1

// Задачи на рекурсию:
// 1. На стандартном потоке ввода задан текст оканчивающаяся точкой, 
// точка в текст не входит. На стандартный поток вывода вывести 
// этот текст в обратном порядке
void print_rev(void);
// 2. Написать рекурсивную функцию перевод числа в двоичную систему счисления
void to_bin(unsigned int n);
// 3. Дано натуральное число N. Вычислите сумму его цифр
unsigned int digit_summ(unsigned int n);
// 4. Дано натуральное число N. Выведите все его цифры по одной, 
// в обратном порядке, разделяя их пробелами или новыми строками
void print_digit_reverse(unsigned int n);
// 5. Дано натуральное число N. Выведите все его цифры по одной, 
// в прямом порядке, разделяя их пробелами или новыми строками
void print_digit_straight(unsigned int n);
// 6. Дана последовательность натуральных чисел, завершающаяся числом 0. Найдите максимум
unsigned int get_max(void);

int main(void)
{
    unsigned int arg;
    scanf("%u", &arg);
    //printf("result recursive %u\n", my_factorial(arg));
    //printf("result for %u\n", my_factorial_for(arg));

    //printf("result %u\n", digit_summ(arg));
    //print_digit_reverse(arg);
    //print_digit_straight(arg);

    unsigned int max = get_max();
    printf("max %u\n", max);
    //print_rev();

    //to_bin(float_as_int(-1.5)); //IEEE754

    //printf("\n");
    /*
    int a = 5, b = 10;
    int *p_a = &a;
    int *p_b = &b;
    */

    /*float f_val = 123.456f;
    int f_as_int = f_val;
    int f_as_int = *(int *)&f_val;

    printf("%d\n", f_as_int);
    */
    /*
    bool ret = get_user_input_int(&a, &b);
    if (ret == false) {
        printf("Error!\n");
        return -1;
    }

    printf("%d %d\n", a, b);
    swap(p_a, p_b);
    printf("%d %d\n", a, b);
    */
    return 0;
}


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


bool get_user_input_int(int *a, int *b)
{
    int retcode;

    retcode = scanf("%d%d", a, b);
    if (retcode == 2) {
        return true;
    } else {
        return false;
    }
}

//хвостовая
unsigned int my_factorial(unsigned int n)
{
    // условие остановки
    if (n <= 1) {
        return 1;
    }
    //шаг рекурсии
    return n * my_factorial(n-1);
}


unsigned int my_factorial_for(unsigned int n)
{
    int result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


void recursive_for(int i, int n)
{
    if (i == n) {
        return;
    }
    printf("%d ", i);
    recursive_for(i+1, n);
}


void print_rev(void)
{
    char ch;
    scanf("%c", &ch);

    if (ch != '.') {
        print_rev();
        printf("%c", ch);
    }

}


void to_bin(unsigned int n)
{
    if (n <= 1) {
        putchar('0' + n);
        return;
    }

    to_bin(n>>1);
    putchar('0' + (0x1 & n));
}


unsigned int float_as_int(float arg)
{
    return *(unsigned int*)&arg;
}


unsigned int digit_summ(unsigned int n)
{
    if (n <= 9) {
        return n;
    }

    return (n % 10) + digit_summ(n / 10);
}


void print_digit_reverse(unsigned int n)
{
    if (n <= 9) {
        printf("%d ", n);
        return;
    }

    printf("%d ", n % 10);
    print_digit_reverse(n / 10);
}


void print_digit_straight(unsigned int n)
{
    if (n <= 9) {
        printf("%d ", n);
        return;
    }

    print_digit_straight(n / 10);
    printf("%d ", n % 10);
}


unsigned int get_max(void)
{
    unsigned int number, max;
    scanf("%u", &number);

    if (number == 0) {
        return 0;
    }

    max = get_max();

    if (max < number)
        max = number;
    return max;
}
