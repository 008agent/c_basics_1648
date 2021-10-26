#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return -1;
    }

    const char *f_src = argv[1];
    const char *f_dst = argv[2];

    FILE *fsrc = fopen(f_src, "rb");//read binary
    FILE *fdst = fopen(f_dst, "wr");//write binary

    // промежуточный(буферный) массив
    //unsigned char array[1024];

    //динамически выделяем память под массив
    unsigned char *array = malloc(sizeof(char) * 1024);

    if (!fsrc || !fdst) {
        printf("Unable to open file\n");
        return -1;
    }

    while(1) {
/*
       size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

       size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);
*/
        size_t rd = fread(array, 1, 1024, fsrc);
        size_t wr = fwrite(array, 1, rd, fdst);

        if (rd != wr) {
            printf("warning! Not all contents read/wrote\n");
        }
        if (feof(fsrc))
            break;
    }

    // высвобождаем память выделенную через malloc()
    free(array);
    fclose(fsrc);
    fclose(fdst);

    // cp <f1> => <f2>
    return 0;
}