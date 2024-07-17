#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "inc\Node.h"
#else
#include "inc/Node.h"
#endif

int main(int argc, char **argv)
{
    FILE *tab;
    if (!(tab = fopen(argv[1], "r")))
    {
        perror("FALHA AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}