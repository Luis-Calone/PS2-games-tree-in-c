#ifdef _WIN32
#include "inc\Node.h"
#else
#include "inc/Node.h"
#endif

#include <stdio.h>

// A função mostraArvore faz um desenho esquerda-direita-raiz
// da árvore x. O desenho terá uma margem esquerda de
// 3b espaços.
void mostraArvore(struct node *a, int b)
{
    if (a == NULL)
    {
        imprimeNo('*', b);
        return;
    }
    mostraArvore(a->right, b + 1);
    imprimeNo(a->title, b);
    mostraArvore(a->left, b + 1);
}

// A função auxiliar imprimeNo imprime o caracter
// c precedido de 3b espaços e seguido de uma mudança
// de linha.
void imprimeNo(char c, int b)
{
    int i;
    for (i = 0; i < b; i++)
        printf("   ");
    printf("%c\n", c);
}