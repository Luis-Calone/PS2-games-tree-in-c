#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "inc\Node.h"
#else
#include "inc/Node.h"
#endif

int main(int argc, char **argv)
{
    char *name = (char *)malloc(10);
    char *name2 = (char *)malloc(10);
    char *name3 = (char *)malloc(10);

    strcpy(name, "GTA3");
    strcpy(name2, "GTASA");
    strcpy(name3, "A.C.E");

    struct node *root = createNode(name, 10);
    struct node *leafR = createNode(name2, 10);
    struct node *leafL = createNode(name3, 10);

    root = includeNode(root, leafR);
    root = includeNode(root, leafL);

    showTree(root);
    return EXIT_SUCCESS;
}