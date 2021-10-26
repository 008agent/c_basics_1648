#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char *optarg;
extern int optind, opterr, optopt;

#if defined DEBUG
#define DBG(x) printf("%s func: %s:%d\n", x, __func__, __LINE__)
#else
#define DBG(x) 
#endif

#ifndef __linux__
#warning Not a linux kernel
#endif


void print_help(const char *message)
{
    printf("usage: %s -s [source file] -d [destination file]\n", message);
}


int main(int argc, char **argv)
{
    // s - source
    // d - destination
    const char *f_src = NULL;
    const char *f_dst = NULL;
    /*
    DBG("initialization");
    */
    opterr = 0;
    int ret;
    while ((ret = getopt(argc, argv, "sdh")) != -1) {
        switch(ret) {
            case 's' : {
                DBG("getopt found source file");
                //printf("Found source option string %s optind %d optopt %d opterr %d\n",
                //       optarg, optind, optopt, opterr);
                f_src = argv[optind];
                break;
            }
            case 'd' : {
                DBG("getopt found destination file");
                //printf("Found destination option string %s optind %d optopt %d opterr %d\n",
                //       optarg, optind, optopt, opterr);
                f_dst = argv[optind];
                break;
            }
            case 'h' : {
                print_help(argv[0]);
                break;
            }
            case '?' : {
                //printf("Found unknown option\n");
                DBG("Found unknown option");
                break;
            }
        }

    }

    if (!f_dst || !f_src) {
        //printf("Source and destination files are not defined\n");
        return -1;
    }

    FILE *fsrc = fopen(f_src, "rb");//read binary
    FILE *fdst = fopen(f_dst, "wr");//write binary

    // промежуточный(буферный) массив
    //unsigned char array[1024];
    unsigned char *array = malloc(sizeof(char) * 1024);

    if (!fsrc || !fdst) {
        //printf("Unable to open file\n");
        DBG("Unable to open file");
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
            //printf("warning! Not all contents read/wrote\n");
            DBG("warning! Not all contents read/wrote");
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
