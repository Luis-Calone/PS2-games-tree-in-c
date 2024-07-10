#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// setting the values for cmpChar() //
#define LEFT 0
#define RIGHT 1

// the base node struct //
struct node
{
    struct node *left;
    struct node *right;
    char *title;
    char *imgPath;
};

typedef struct tree
{
    struct node *root;
    size_t hight;
    int FB;
} Tree;

/* createNode() is the method that create each node */
struct node *createNode(char *title, size_t sizeChar);

/* setImgPath() gets the created node and set the image path in the
project files */
int setImgPath(struct node *node, char *imgPath);

/* cmpChar() is just an auxiliar method to compare the titles in nodes */
int cmpChar(char a, char b);

/* includeNode() gets the root node of the tree and the node to be added
and returns the root with the new node included */
struct node *includeNode(struct node *root, struct node *node_include);

/* showTree() is a function that runs all the tree and
print itself in order */
void showTree(struct node *root);

/* rollRight() rolls the tree to the right side for balancing */
struct node *rollRIght(struct node *root);

struct node *rollLeft(struct node *root);