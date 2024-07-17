#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    FILE *arq;
    char line[255],
        title[125],
        developer[30],
        publisher[35],
        released[25];
    int i, j, flag = 0;

    if (!(arq = fopen(argv[1], "r")))
    {
        perror("ERRO AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), arq))
    {
        i = j = flag = 0;
        while (line[j] != ',')
        {
            if (line[j] == '\n')
            {
                flag = 1;
                break;
            }

            title[i] = line[j];
            j++;
            i++;
        }
        if (flag == 1)
            continue;
    }

    return EXIT_SUCCESS;
}