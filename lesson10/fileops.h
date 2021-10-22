#ifndef FILEOPS_H
#define FILEOPS_H


int get_file_size(const char *filename);
/*
1. Дан текстовый файл in.txt, содержащий целые числа. Посчитать сумму чисел.
2. Ввести имя файла и напечатать его размер.
3. Дан текстовый файл in.txt. Необходимо посчитать количество цифр 
в файле и дописать это число в конец данного файла.

*/
int get_file_numbers_summ(const char *filename);

void file_append_digits_amount(const char *filename);


void save_binary_file(const void *ptr, int bytescount, const char *filename);
void load_binary_file(void *ptr, int bytescount, const char *filename);

#endif