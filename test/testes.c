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

    struct node *teste = createNode("jteste", 7);
    struct node *teste1 = createNode("dteste", 7);
    struct node *teste2 = createNode("xteste", 7);
    struct node *teste3 = createNode("ateste", 7);
    struct node *teste4 = createNode("cteste", 7);

    teste = includeNode(teste, teste1);
    teste = includeNode(teste, teste2);
    teste = includeNode(teste, teste3);
    teste = includeNode(teste, teste4);

    showTree(teste, 0);

    printf("\n\n%d\n", heightTree(teste));
    // FILE *tab1 = fopen(CSVPATH_A, "r");
    // FILE *tab2 = fopen(CSVPATH_B, "r");

    // if (!(tab1 = fopen(CSVPATH_A, "r")) || !(tab2 = fopen(CSVPATH_B, "r")))
    // {
    //     perror("ERROR AO ABRIR O ARQUIVO");
    //     return EXIT_FAILURE;
    // }

    // char line[MAX_LINE_LENGTH];
    // char c = '\0';
    // char title[125];
    // char developer[30];
    // char publisher[35];
    // char released[25];

    // bool quota = false;
    // int it;
    // int i, j;

    // while (fgets(line, sizeof(line), tab1))
    // {
    //     // printf("%s\n", line);

    //     i = 0;
    //     j = 0;
    //     if (line[0] == '\"')
    //     {
    //         while (line[i] != '\n')
    //         {
    //             title[i] = line[i];
    //             i++;
    //         }
    //         quota = true;
    //         title[i] = ' ';
    //         continue;
    //     }

    //     if (quota)
    //     {
    //         i = strlen(title);
    //         quota = false;
    //     }

    //     while (line[j] != ',')
    //     {
    //         title[i] = line[j];
    //         i++;
    //         j++;
    //     }
    //     title[i] = '\0';
    //     printf("%s, ", title);

    //     j += 1;
    //     i = 0;
    //     while (line[j] != ',')
    //     {
    //         developer[i] = line[j];
    //         i++;
    //         j++;
    //     }
    //     developer[i] = '\0';
    //     printf("%s, ", developer);

    //     j += 1;
    //     i = 0;
    //     while (line[j] != ',')
    //     {
    //         publisher[i] = line[j];
    //         i++;
    //         j++;
    //     }
    //     publisher[i] = '\0';
    //     printf("%s, ", publisher);

    //     j += 1;
    //     i = 0;
    //     while (line[j] != ',')
    //     {
    //         released[i] = line[j];
    //         i++;
    //         j++;
    //     }
    //     released[i] = '\0';
    //     printf("%s\n", released);

    //     memset(title,0,sizeof(title));
    //     memset(publisher,0,sizeof(publisher));
    //     memset(developer,0,sizeof(developer));
    //     memset(released,0,sizeof(released));
    // }
    return EXIT_SUCCESS;
}