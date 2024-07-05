#ifndef NODE_H
#define NODE_H

#include "../inc/Node.h"

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

int getImgPath(struct node *node, char *imgPath)
{
    if (node == NULL)
        return 0;

    if (!(strcpy(node->imgPath, imgPath)))
        return -1;

    return 1;
}

#endif