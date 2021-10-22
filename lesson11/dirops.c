#include "dirops.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void print_type(const struct stat *st)
{
    switch (st->st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
}


void dirls(const char *path, bool hidden)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Error: opendir %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && !hidden)
            continue;

        char fullname[255] = { 0 };
        snprintf(fullname, 254, "%s/%s", path, entry->d_name);

        struct stat st = { 0 };
        int statret = stat(fullname, &st);
        if (statret != 0) {
            fprintf(stderr, "Error: stat %s\n", fullname);
            continue;
        }

        printf("%s\t %lu ", fullname, st.st_size);
        print_type(&st);

    }

    closedir(dir);
}