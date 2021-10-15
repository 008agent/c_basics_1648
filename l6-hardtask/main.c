#if 0
Задание со звездочкой(необязательное):
Реализовать через getchar() функционал для считывания строки в переменную типа float или double. И продемонстрировать работу алгоритма(функции)

например 
float get_float(void)
{
	float result;
// магия с getchar() и result
	return result;
}
#endif


#include <stdio.h>
#include <stdbool.h>

bool is_num(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}

float get_float(void)
{
    float result;
    char ch;
    bool negative = false;
    bool divider = false; // признак точки или запятой
    float first = 0, second = 0;// first - целая часть, second - дробная часть

    while ( (ch = getchar()) != '\n') {

        if (ch == '-') {
            negative = true;
            continue;
        }

        if (ch == '.' || ch == ',') {
            divider = true;
            continue;
        }


        if (is_num(ch)) {
            if (divider) {
                second *= 10;
                second += ch - '0';
            } else {
                first *= 10;
                first += ch - '0';
            }
        }
    }

    int tmp;

    while (tmp = second) {
        second /= 10;
    }

    result = first + second;
    if (negative) {
        result *= -1;
    }

    return result;
}

int main(void)
{
    float test = get_float();

    printf("you've entered %f\n", test);
    return 0;
}