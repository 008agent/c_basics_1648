#include <stdio.h>


// 1.Считать строку и заменить в ней все строчные английские буквы на заглавные.
void str_replace_to_upper(void);
// 2.Дана строка состоящая из английских букв и цифр. Посчитать сумму цифр в ней.
void summ_of_digits(void);
// 3.Дана строка состоящая из английских букв и цифр. 
// Составить из цифр в данной строке одно число и поместить его в целочисленную переменную.
// 123abc456 => 123456
void str_as_number(void);
// 4.Дана строка состоящая из английских букв и пробелов, в конце строки символ точка. 
// Необходимо удалить из нее все лишние пробелы.
void remove_spaces(void);
// получить со стандартного потока ввода через getchar unsigned int
unsigned int get_uint(void);

// 1. Составить функцию, модуль числа и привести пример ее использования.
int my_abs(int arg);
// 2. Составить функцию возведения числа n в степень p.
unsigned int my_pow_u32(unsigned int arg, unsigned int p);
// 3. Описать функцию, которая проверяет, является ли целое неотрицательное число n степенью 3. 
// В случае положительного ответа функция возвращает значение 1 и 0 в противном случае.
unsigned int is_pow_of_3(unsigned int arg);
// 4. Пусть n – целое неотрицательное число.
// Описать функцию от параметра n, которая находит максимальную цифру в числе.
unsigned int get_max_digit(unsigned int arg);
// 5. Пусть n – целое неотрицательное число. Описать функцию от параметра n, 
// которая находит количество четных цифр в числе
unsigned int get_n_plural(unsigned int arg);


int main(void)
{
    unsigned int test = 0;
    //int input;

    test = get_uint();
    //printf("my_pow result %u\n", my_pow_u32(test, 4));
    //printf("Is pow of 3 %s\n", is_pow_of_3(test) ? "YES" : "NO"); 
    //printf("get_max_digit result %u\n", get_max_digit(test));
    printf("get_n_plural %d\n", get_n_plural(test));

    //printf("got %u\n", test);
    //printf("my_abs = %d\n", my_abs(input));

    //str_replace_to_upper();
    //summ_of_digits();
    //str_as_number();
    //remove_spaces();

    return 0;
}


void str_replace_to_upper(void)
{
    char c;

    while((c = getchar()) != '\n') {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        putchar(c);
    }
}


void summ_of_digits(void)
{
    char c;
    int summ = 0;

    while((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            summ += c - '0';
        }
    }

    printf("Summ of digits %d\n", summ);
}


void str_as_number(void)
{
    char c;
    int summ = 0;

    while((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            summ *= 10;
            summ += c - '0';
        }
    }

    printf("result %d\n", summ);
}


void remove_spaces(void)
{
    char c;

    while((c = getchar()) != '.') {
        if (c != ' ') {
            putchar(c);
        }
    }
}


unsigned int get_uint(void)
{
    char c;
    unsigned int summ = 0;

    while((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            summ *= 10;
            summ += c - '0';
        }
    }

    return summ;
}


int my_abs(int arg)
{
    return (arg < 0) ? -arg : arg;
}


unsigned int my_pow_u32(unsigned int arg, unsigned int p)
{
    unsigned int result = 1;
    for (int i = p; i > 0; i--)
        result *= arg;

    return result;
}


unsigned int is_pow_of_3(unsigned int arg)
{
    unsigned int base = 3;
    while (base <= arg) {
        if (base == arg) {
            return 1;
        }
        base *= 3;
    }
    return 0;
}


unsigned int get_max_digit(unsigned int arg)
{
    unsigned int max = arg % 10;

    while (arg) {
        if ((arg % 10) > max) max = arg % 10;
        arg /= 10;
    }

    return max;
}


unsigned int get_n_plural(unsigned int arg)
{
    unsigned int count = 0;

    while (arg) {
        if ((arg % 10) & 0x1) {
            arg /= 10;
            continue;
        }
        arg /= 10;
        count++;
    }

    return count;
}