#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *left;
    struct node *right;
    char *title;
    char *imgPath;
};

struct node *createNode(char *title, size_t sizeChar);
int getImgPath(struct node *node, char *imgPath);
