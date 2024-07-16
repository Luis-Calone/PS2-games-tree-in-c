#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "inc\Node.h"
// #define CSVPATH_A "..\\csv\\ListOfPs2GamesAK.csv"
// #define CSVPATH_B "..\\csv\\ListOfPs2GamesLZ.csv"
#else
#include "inc/Node.h"
// #define CSVPATH_A "../csv/ListOfPs2GamesAK.csv"
// #define CSVPATH_B "../csv/ListOfPs2GamesLZ.csv"
#endif

int main(int argc, char **argv)
{
    FILE *tab;
    if (!(tab = fopen(argv[1],"r")))
    {
        perror("FALHA AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}