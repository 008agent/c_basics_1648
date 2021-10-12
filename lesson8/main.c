#include <stdio.h>
#include <stdint.h>//uint32_t
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Как будет хранится число 0,625 тип float
//0,625(10) = 0,101(2) => 1,01 * 2^(-1)
//0 01111110 010000000000000000

//Как будет хранится число 3,875 тип float
//3,875(10) = ?(2) = 11,111
//1,1111 * 2^1
//0 10000000 1111000000000000

//Как будет хранится число 64 тип float
//64(10) = 1000000(2)
//1, *2^6
//0 10000101 0000000000000000
// денормализация, вычисление порядка 1000 0101 = 133(порядок 6)
// 0000000000000000 => (1),0000000000000000
//1,000 * 2^6 = 1000000 = 64(10)

//Самостоятельно 7,625(10) 
// 7,625(10) => 111,101
//(1),11101 * 2^2
//0 129(10) 11101

uint32_t float_as_u32(float arg);
void print_u32(uint32_t arg);

void enter_array(int array[], int N);
void print_array(int array[], int N);
void print_array_simple(int array[], int N);
void fill_array_random(int array[], int N);

// 1. Ввести с клавиатуры массив из 5 элементов и умножить 
// все его элементы на число 3. Распечатать полученный массив.
void mul_array(int array[], int N, int mult);
// 2. Найти минимальный элемент в массиве.
int get_min_element(int array[], int N);
// 3. Найти максимальный элемент в массиве.
int get_max_element(int array[], int N);
// 4. Поменять местами максимальный и минимальный элемент в массиве.
void swap_min_max(int array[], int N);
// 5. На стандартном потоке ввода задан текст, 
// состоящий из латинских букв и цифр и оканчивающийся точкой. 
// На стандартный поток вывода вывести цифру, наиболее часто встречающуюся 
// в тексте (если таких цифр несколько, вывести любую из них).
void task5_print_max_freq_digit(void);
// 6. Циклически сдвинуть массив влево на 1 элемент.
// 1 2 3 4 5 => 2 3 4 5 1
void shift_left_array(int array[], int N);
void shift_right_array(int array[], int N);
// 7. Сделать реверс массива
void swap(int *a, int *b);
void reverse_array(int array[], int N);

int main(void)
{
    int array[5] = { 0 };
    // task 1
    /*
    fill_array_random(array, 5);
    print_array(array, 5);
    mul_array(array, 5, 3);
    print_array(array, 5);
    */

    // task 2,3,4
    /*fill_array_random(array, 5);
    print_array(array, 5);
    printf("Minimum %d\n", get_min_element(array, 5));
    printf("Minimum %d\n", get_max_element(array, 5));
    swap_min_max(array, 5);
    print_array(array, 5);
    */

    // task 5
    //task5_print_max_freq_digit();

    //task 6,7
    fill_array_random(array, 5);
    print_array_simple(array, 5);
    shift_left_array(array, 5);
    print_array_simple(array, 5);
    shift_right_array(array, 5);
    print_array_simple(array, 5);
    reverse_array(array, 5);
    print_array_simple(array, 5);

    /* К 1 части урока
    float x = 0.1f;

    for (int i = 0; i < 10; i++) {
        print_u32(float_as_u32(x));
        // так делать не рекоммендуется
        if (x == 1.f) {
            printf("Equils 1.F\n");
        }

        if (fabs(x - 1.f) <= 0.00001f) {
            printf("Equils DELTA 1.F\n");
        }

        x += 0.1f;
    }
    */

    return 0;
}


uint32_t float_as_u32(float arg)
{
    uint32_t result = 0;

    memcpy(&result, &arg, 4);

    printf("%f = ", arg);

    return result;
}


void print_u32(uint32_t arg)
{
    for (int i=31; i>=0; i--) {

        if (i == 30 || i == 22) {
            putchar(' ');
        }

        if ((arg>>i) & 0x1) {
            putchar('1');
        }
        else {
            putchar('0');
        }
    }
    printf("\n");
}


void enter_array(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
}


void print_array(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("ptr %p array[%d] = %d\n", &array[i], i, array[i]);
    }
}


void print_array_simple(int array[], int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}



void mul_array(int array[], int N, int mult)
{
    for (int i = 0; i < N; i++) {
        array[i] *= mult;
    }
}


int get_min_element(int array[], int N)
{
    int min = array[0];

    for (int i = 1; i < N; i++) {
        if (array[i] < min)
            min = array[i];
    }

    return min;
}


int get_max_element(int array[], int N)
{
    int max = array[0];

    for (int i = 1; i < N; i++) {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}


void fill_array_random(int array[], int N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100 - 50;
    }
}


void swap_min_max(int array[], int N)
{
    // минимальное и максимальное значение
    int min = array[0], max = array[0];
    int min_index = 0, max_index = 0;
    int tmp;

    for (int i = 0; i < N; i++) {
        if (array[i] < min) {
            min = array[i];
            min_index = i;
        }
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }

    tmp = array[max_index];
    array[max_index] = array[min_index];
    array[min_index] = tmp; 
}


void task5_print_max_freq_digit(void)
{
    char ch;
    int array[10] = { 0 };

    while ((ch = getchar()) != '.') {
        if (ch >= '0' && ch <= '9') {
            array[ch - '0']++;
        }
    }

    int max_index = 0;
    int max = array[0];

    for (int i = 0; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }

    printf("Max digit is %d\n", max_index);
}


void shift_left_array(int array[], int N)
{
    int tmp = array[0];

    for (int i = 1; i < N; i++) {
        array[i-1] = array[i];
    }

    array[N - 1] = tmp;
}


void shift_right_array(int array[], int N)
{
    int tmp = array[N - 1];

    for (int i = (N - 1); i > 0; i--) {
        array[i] = array[i - 1]; 
    }

    array[0] = tmp;
}


void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}


void reverse_array(int array[], int N)
{
    for (int i = 0; i < (N/2); i++) {
        swap(&array[i], &array[N-i-1]);
    }
}
