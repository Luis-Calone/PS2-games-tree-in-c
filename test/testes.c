#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#ifdef _WIN32
#include "..\inc\Node.h"
#define CSVPATH_A "..\\csv\\ListOfPs2GamesAK.csv"
#define CSVPATH_B "..\\csv\\ListOfPs2GamesLZ.csv"
#else
#include "../inc/Node.h"
#define CSVPATH_A "../csv/ListOfPs2GamesAK.csv"
#define CSVPATH_B "../csv/ListOfPs2GamesLZ.csv"
#endif

#define MAX_LINE_LENGTH 255

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    FILE *tab1 = fopen(CSVPATH_A, "r");
    FILE *tab2 = fopen(CSVPATH_B, "r");

    if (!(tab1 = fopen(CSVPATH_A, "r")) || !(tab2 = fopen(CSVPATH_B, "r")))
    {
        perror("ERROR AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    char c;
    char title[100];
    char developer[30];
    char publisher[35];
    char released[25];

    bool var = true;
    int it;
    int i = 0;

    while (var)
    {

        i = 0;
        while ((c = fgetc(tab1)) != ',')
        {
            title[i] = c;
            i++;
        }
        title[i] = '\0';
        printf("%s, ", title);

        i = 0;
        while ((c = fgetc(tab1)) != ',')
        {
            developer[i] = c;
            i++;
        }
        developer[i] = '\0';
        printf("%s, ", developer);

        i = 0;
        while ((c = fgetc(tab1)) != ',')
        {
            publisher[i] = c;
            i++;
        }
        publisher[i] = '\0';
        printf("%s, ", publisher);

        i = 0;
        while ((c = fgetc(tab1)) != ',')
        {
            released[i] = c;
            i++;
        }
        released[i] = '\0';
        printf("%s", released);

        while (c = fgetc(tab1) != '\n')
        {
            if (c==EOF)
                break;
        }
        printf("\n");
 
        if (c == EOF)
            var = false;
    }
    fclose(tab1);
    fclose(tab2);
    return EXIT_SUCCESS;
}