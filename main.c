#include <stdio.h>
#include <stdlib.h>
#include "inc/Node.h"

int main(int argc, char **argv)
{
    char *name = (char *)malloc(10);
    char *name2 = (char *)malloc(10);
    strcpy(name, "GTA3");
    strcpy(name2, "GTASA");
    struct node *root = createNode(name, 10);
    struct node *leaf = createNode(name2, 10);

    includeNode(&root, leaf);

    printf("%s\n", root->right->title);

    showTree(root);
    return EXIT_SUCCESS;
}