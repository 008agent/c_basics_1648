#include "fileops.h"
#include <stdio.h>

int get_file_size(const char *filename)
{
    FILE *f;
    long sz;

    f = fopen(filename, "r");
    if (!f) {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    sz = ftell(f);
    fclose(f);

    return sz;
}


int get_file_numbers_summ(const char *filename)
{
    FILE *f;
    int tmp;
    int summ = 0;

    f = fopen(filename, "r");
    if (!f) {
        return -1;
    }

    while (fscanf(f, "%d", &tmp) == 1) {
        summ += tmp;
    }

    fclose(f);

    return summ;
}


void file_append_digits_amount(const char *filename)
{
    FILE *f;
    char c;
    int digits = 0;

    f = fopen(filename, "r+");
    if (!f) {
        return;
    }

    while ((c = fgetc(f)) != EOF) {
        if (c >= '0' && c <= '9') {
            digits++;
        }
    }

    fprintf(f, " %d", digits);

    fclose(f);
}

/*

       size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

       size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);

*/


void save_binary_file(const void *ptr, int bytescount, const char *filename)
{
    FILE *f;
    // b - binary
    f = fopen(filename, "wb");
    if (!f) {
        printf("Error save_binary_file\n");
        return;
    }

    size_t wr = fwrite(ptr, 1, bytescount, f);

    printf("write %lu bytes\n", wr);

    fclose(f);
}


void load_binary_file(void *ptr, int bytescount, const char *filename)
{
    FILE *f;
    // b - binary
    f = fopen(filename, "rb");
    if (!f) {
        printf("Error load_binary_file\n");
        return;
    }

    size_t rd = fread(ptr, 1, bytescount, f);

    printf("read %lu bytes\n", rd);

    fclose(f);
}