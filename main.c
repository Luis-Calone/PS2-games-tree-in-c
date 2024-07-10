#include <stdio.h>
#include <stdlib.h>
#include "printAux.c"

#ifdef _WIN32
#include "inc\Node.h"
#else
#include "inc/Node.h"
#endif

int main(int argc, char **argv)
{
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

    // showTree(root);

    root = rollRIght(root);

    printf("\n");
    showTree(root);

    return EXIT_SUCCESS;
}