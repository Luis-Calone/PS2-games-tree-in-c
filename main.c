#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include "inc\Node.h"
#else
#include "inc/Node.h"
#endif

#define MAX_LINE_LENGTH 255

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    FILE *tab1, *gphviz;
    char line[MAX_LINE_LENGTH];
    char title[255];

    struct node *root = createNode();
    root = setData(root, "ROOT");

    if (!(gphviz = fopen("grphviz.txt", "w+")))
    {
        perror("ERRO AO CRIAR ARQUIVO");
        return EXIT_FAILURE;
    }

    if (!(tab1 = fopen(argv[1], "r")))
    {
        perror("ERRO AO ABRIR O ARQUIVO");
        return EXIT_FAILURE;
    }

    int i; // pegando linha por linha e colocando os titulos na arvore
    while (fgets(line, sizeof(line), tab1))
    {
        i = 0; // verificando caso ',' ou '\n'
        while (line[i] != ',' && line[i] != '\n')
        {
            if (line[i] == '\"')
                title[i] = ' ';
            else
                title[i] = line[i];
            i++;
        }
        title[i] = '\0';

        struct node *nd = createNode();
        nd = setData(nd, title); // colocando os titulos

        root = includeNode(root, nd);

        fbCalc(root);

        root = rotation(root);

        memset(title, 0, sizeof(title));
    }

    fgraphviz(root, gphviz);
    graphviz(root);
    // showTree(root, 0); // funcao para mostrar a arvore no terminal
    // nao recomendada para vizualizacao de uma arvore grande, somente pra teste

    fclose(tab1);
    fclose(gphviz);
    return EXIT_SUCCESS;
}