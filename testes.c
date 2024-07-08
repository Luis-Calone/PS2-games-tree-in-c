#include <stdio.h>
#include <string.h>

int cmpChar(char a, char b)
{
    return ((int)a < (int)b) ? (int)a : (int)b;
}

int main()
{
    char var = '.';
    char var1 = 'A';

    printf("%d\n", var);
    printf("%d\n", var1);
    printf("%c\n", cmpChar(var1, var));

    return 0;
}