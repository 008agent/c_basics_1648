#include <stdio.h>
#include "dirops.h"
#include <unistd.h>


/*
//способ с getcwd
int main(void)
{
    //получить текущий рабочий каталог
    char cwd[255] = { 255 };
    getcwd(cwd, 254);
    cwd[254] = 0;

    dirls(cwd, false);
    return 0;
}
*/

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Введите аргумент(путь к директории)\n");
        return 0;
    }

    if (argc == 3 && argv[2][0] == 'y')
        dirls(argv[1], true);
    else
        dirls(argv[1], false);

}