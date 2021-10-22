#include <stdio.h>
#include <string.h>

void print_operations(char *ops, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%c ", ops[i]);
    }
    printf("\n");
}

void print_operands(int *ops, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", ops[i]);
    }
    printf("\n");
}

int main(void)
{
    const char *str = "100+200-50*20*10/100";

    int operands[100] = { 0 };
    int n_operands = 0;

    char operations[100] = { 0 };
    int n_operations = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            operands[n_operands] *= 10;
            operands[n_operands] += str[i] - '0';
        }

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            n_operands++;
            operations[n_operations++] = str[i];
        }
    }

    n_operands++;

    print_operands(operands, n_operands);
    print_operations(operations, n_operations);

    int result = operands[0];

    for (int i = 0; i < n_operations; i++) {
        switch (operations[i]) {
            case '+': {
                result += operands[i+1];
                break;
            }
            case '-': {
                result -= operands[i+1];
                break;
            }
            case '*': {
                result *= operands[i+1];
                break;
            }
            case '/': {
                result /= operands[i+1];
                break;
            }
        }
    }

    printf("result %d\n", result);

    return 0;
}