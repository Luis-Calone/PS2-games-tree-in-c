#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "..\inc\Node.h"
#define CSVPATH_A "..\\csv\\List_of_PlayStation(A-K).csv"
#define CSVPATH_B "..\\csv\\List_of_PlayStation(L-Z).csv"
#else
#include "../inc/Node.h"
#define CSVPATH_A "../csv/List_of_PlayStation(A-K).csv"
#define CSVPATH_B "../csv/List_of_PlayStation(L-Z).csv"
#endif

int main(int argc, char **argv)
{
    FILE *tab1 = fopen(CSVPATH_A, "r");
    FILE *tab2 = fopen(CSVPATH_B, "r");

    if (!(tab1 = fopen(CSVPATH_A, "r")) || !(tab2 = fopen(CSVPATH_B, "r")))
    {
        perror("ERRO AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    /*
    char *name0 = (char *)malloc(10);
    char *name1 = (char *)malloc(10);
    char *name2 = (char *)malloc(10);
    char *name3 = (char *)malloc(10);
    char *name4 = (char *)malloc(10);
    char *name5 = (char *)malloc(10);

    strcpy(name0, "GTA3");
    strcpy(name1, "GTASA");
    strcpy(name2, "A.C.E");
    strcpy(name3, "G.C.E");
    strcpy(name4, "J.C.E");
    strcpy(name5, "Z.C.E");

    struct node *root = createNode(name0, 10);
    struct node *NODE0 = createNode(name1, 10);
    struct node *NODE1 = createNode(name2, 10);
    struct node *NODE2 = createNode(name3, 10);
    struct node *NODE3 = createNode(name4, 10);
    struct node *NODE4 = createNode(name5, 10);

    root = includeNode(root, NODE0);
    root = includeNode(root, NODE1);
    root = includeNode(root, NODE2);
    root = includeNode(root, NODE3);
    root = includeNode(root, NODE4);

    // showElements(root);

    showTree(root, 0);

    root = rollLeft(root);

    printf("\n");
    printf("\n");
    printf("\n");
    showTree(root, 0);

    root = rollRight(root);

    printf("\n");
    printf("\n");
    printf("\n");
    showTree(root, 0);

    root = rollRight(root);

    printf("\n");
    printf("\n");
    printf("\n");
    showTree(root, 0);

    // showElements(root);
    */

    return EXIT_SUCCESS;
}