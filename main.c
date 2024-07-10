#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "inc\Node.h"
#else
#include "inc/Node.h"
#endif

// A função mostraArvore faz um desenho esquerda-direita-raiz
// da árvore x. O desenho terá uma margem esquerda de
// 2b espaços.
void mostraArvore(struct node *a, int b)
{
    if (a == NULL)
    {
        imprimeNo('*', b);
        return;
    }
    mostraArvore(a->right, b + 1);
    imprimeNo(a->title[0], b);
    mostraArvore(a->left, b + 1);
}

// A função auxiliar imprimeNo imprime o caracter
// c precedido de 3b espaços e seguido de uma mudança
// de linha.
void imprimeNo(char c, int b)
{
    int i;
    for (i = 0; i < b; i++)
        printf("  ");
    printf("%c\n", c);
}

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

    mostraArvore(root, 0);

    root = rollRIght(root);

    printf("\n");
    printf("\n");
    printf("\n");
    mostraArvore(root, 0);
    // showTree(root);

    return EXIT_SUCCESS;
}