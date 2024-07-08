#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1

struct node
{
    struct node *left;
    struct node *right;
    char *title;
    char *imgPath;
};

void showTree(struct node *root);
struct node *createNode(char *title, size_t sizeChar);
int setImgPath(struct node *node, char *imgPath);
int cmpChar(char a, char b);
int includeNode(struct node *root, struct node *node_include);