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
    int fb;
    char *title;
    char *imgPath;
};

/* createNode() is the method that create each node */
struct node *createNode();

struct node *setData(struct node *root,
                     const char *title);

/* setImgPath() gets the created node and set the image path in the
project files */
int setImgPath(struct node *node, char *imgPath);

/* cmpChar() is just an auxiliar method to compare the titles in nodes */
int cmpChar(char a, char b);

/* includeNode() gets the root node of the tree and the node to be added
and returns the root with the new node included */
struct node *includeNode(struct node *root, struct node *node_include);

/* showElements() is a function that runs all the tree and
print itself in order */
void showElements(struct node *root);

/* showTree() its a method tha shows the tree horizontally
in the terminal */
void showTree(struct node *a, int b);

/* printNum() is an auxiliar method*/
void printNum(char *c, int b);

/* rollRight() rolls the tree to the right side for balancing */
struct node *rollRight(struct node *root);

/* rollLeft() rolls the tree to the left side for balancing */
struct node *rollLeft(struct node *root);

int heightTree(struct node *root);

int fbCalc(struct node *root); 

struct node *rotation(struct node *root);