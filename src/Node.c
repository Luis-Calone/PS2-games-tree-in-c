#ifndef NODE_H
#define NODE_H

#include "..\inc\Node.h"

struct node *createNode(char *title, size_t sizeChar)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->title = (char *)malloc(sizeof(char) * sizeChar);
    strcpy(temp->title, title);
    temp->left = NULL;
    temp->right = NULL;
    temp->imgPath = NULL;

    return temp;
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

void showTree(struct node *root)
{
    if (root == NULL)
        return;

    showTree(root->right);
    printf("%s\n", root->title);
    showTree(root->left);
}

#endif