#ifndef NODE_H
#define NODE_H

#ifdef _WIN32
#include "..\inc\Node.h"
#else
#include "../inc/Node.h"
#endif

struct node *createNode()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->fb = 0;
    temp->title = (char *)malloc(sizeof(char) * 100);
    temp->left = NULL;
    temp->right = NULL;
    temp->imgPath = NULL;

    return temp;
}

struct node *setData(struct node *root,
                     const char *title)
{
    if (title == NULL)
        return root;

    strcpy(root->title, title);

    return root;
}

int setImgPath(struct node *node, char *imgPath)
{
    if (node == NULL)
        return 0;

    if (!(strcpy(node->imgPath, imgPath)))
        return -1;

    return 1;
}

int cmpChar(char a, char b)
{
    return ((int)a < (int)b) ? LEFT : RIGHT;
}

struct node *includeNode(struct node *root, struct node *node_include)
{
    if (node_include == NULL)
        return NULL;

    if (root == NULL)
    {
        root = node_include;
        return root;
    }

    if (cmpChar(node_include->title[0], root->title[0]) == LEFT)
    {
        root->left = includeNode(root->left, node_include);
    }
    else
    {
        root->right = includeNode(root->right, node_include);
    }

    return root;
}

void showElements(struct node *root)
{
    if (root == NULL)
        return;

    showElements(root->left);
    printf("%s\n", root->title);
    showElements(root->right);
}

// A função showTree faz um desenho esquerda-direita-raiz
// da árvore x. O desenho terá uma margem esquerda de
// 2b espaços.
void showTree(struct node *a, int b)
{
    if (a == NULL)
    {
        printNum("*", b);
        return;
    }
    showTree(a->right, b + 1);
    printNum(a->title, b);
    showTree(a->left, b + 1);
}

// A função auxiliar printNum imprime o caracter
// c precedido de 3b espaços e seguido de uma mudança
// de linha.
void printNum(char *c, int b)
{
    int i;
    for (i = 0; i < b; i++)
        printf("    ");
    printf("%s\n", c);
}

struct node *rollRight(struct node *root)
{
    if (root == NULL)
        return root;

    struct node *temp;
    if ((temp = root->right) == NULL)
        return root;

    root->right = temp->left;
    temp->left = root;
    return temp;
}

struct node *rollLeft(struct node *root)
{
    if (root == NULL)
        return root;

    struct node *temp;
    if ((temp = root->left) == NULL)
        return root;

    root->left = temp->right;
    temp->right = root;
    return temp;
}

int heightTree(struct node *root)
{
    if (root == NULL)
        return -1;

    int left = heightTree(root->left);
    int right = heightTree(root->right);

    if (left > right)
        return left + 1;

    return right + 1;
}

int fbCalc(struct node *root)
{
    if (root == NULL)
        return 0;

    int right, left;

    right = heightTree(root->right);
    left = heightTree(root->left);
    root->fb = right - left;

    return 1;
}

struct node *rotation(struct node *root)
{
    if (root->fb == 2 && root->right->fb == 1)
    {
        return rollLeft(root);
    }
    else if (root->fb == -2 && root->left->fb == -1)
    {
        return rollRight(root);
    }
    else if (root->fb == 2 && root->right->fb == -1)
    {
        root->right = rollLeft(root->right);
        return rollRight(root);
    }
    else if (root->fb == -2 && root->left->fb == 1)
    {
        root->left = rollRight(root->left);
        return rollLeft(root);
    }

    return root;
}

void fgraphviz(struct node *root, FILE *txt) // Faz a recursao nos nodes imprimindo o conteudo dele e do filho, caso houver.
{
    if (root != NULL && txt != NULL)
    {
        if (root->left != NULL)
            fprintf(txt, "\"%s\" -- \"%s\"\n", root->title, root->left->title);
        if (root->right != NULL)
            fprintf(txt, "\"%s\" -- \"%s\"\n", root->title, root->right->title);

        fgraphviz(root->left, txt);
        fgraphviz(root->right, txt);
    }
}

void graphviz(struct node *root) // Faz a recursao nos nodes imprimindo o conteudo dele e do filho, caso houver.
{
    if (root != NULL)
    {
        if (root->left != NULL)
            printf("\"%s\" -- \"%s\"\n", root->title, root->left->title);
        if (root->right != NULL)
            printf("\"%s\" -- \"%s\"\n", root->title, root->right->title);

        graphviz(root->left);
        graphviz(root->right);
    }
}

#endif