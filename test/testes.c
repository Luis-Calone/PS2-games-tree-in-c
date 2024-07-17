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

// int separateValues(char *line, char **data)
// {
//     int i = 0;
//     int j = 0;
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
//         data[0][i] = line[j];
//         i++;
//         j++;
//     }
//     data[0][i] = '\0';
//     printf("%s, ", data[0]);

//     j += 1;
//     i = 0;
//     while (line[j] != ',')
//     {
//         data[1][i] = line[j];
//         i++;
//         j++;
//     }
//     data[1][i] = '\0';
//     printf("%s, ", data[1]);

//     j += 1;
//     i = 0;
//     while (line[j] != ',')
//     {
//         data[2][i] = line[j];
//         i++;
//         j++;
//     }
//     data[2][i] = '\0';
//     printf("%s, ", data[2]);

//     j += 1;
//     i = 0;
//     while (line[j] != ',')
//     {
//         data[3][i] = line[j];
//         i++;
//         j++;
//     }
//     data[3][i] = '\0';
//     printf("%s\n", data[3]);
// }

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    FILE *tab1;
    // char **data = (char **)malloc(sizeof(char *) * 4);
    char line[MAX_LINE_LENGTH];
    char title[255];

    // int i;
    // for (i = 0; i < 4; i++)
    // {
    //     data[i] = (char *)malloc(sizeof(char) * 50);
    // }

    struct node *root = createNode();
    root = setData(root, "Title");
        printf("tA\n");

    if (!(tab1 = fopen(argv[1], "r")))
    {
        perror("ERRO AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    int i;
    while (fgets(line, sizeof(line), tab1))
    {
        i = 0;
        while (line[i] != ',' || line[i] != '\n')
        {
            title[i] = line[i];
            i++;
        }
        title[i] = '\0';

        printf("tA\n");

        struct node *nd = createNode();
        nd = setData(nd, title);
        
        printf("tA\n");

        root = includeNode(root, nd);
        printf("tA\n");

        memset(title, 0, sizeof(title));
    }

    // fgets(line, sizeof(line), tab1);

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

    fclose(tab1);
    return EXIT_SUCCESS;
}