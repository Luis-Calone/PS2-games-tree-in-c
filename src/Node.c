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
    temp->title = NULL;
    // temp->developer = NULL;
    // temp->publisher = NULL;
    // temp->released = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->imgPath = NULL;

    return temp;
}

struct node *setData(struct node *root,
                     char *title)
// char *developer,
// char *publisher,
// char *released)
{
    if (title == NULL)
        // developer == NULL ||
        // publisher == NULL ||
        //  released == NULL)
        return root;

    strcpy(root->title, title);
    // strcpy(root->developer, developer);
    // strcpy(root->publisher, publisher);
    // strcpy(root->released, released);

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
    struct node *aux = root;
}

#endif