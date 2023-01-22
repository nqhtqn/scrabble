#include "header.h"

void nomjoueurf(int i,char nom [30]) ///rentre le nom du joueur pour la partie
{
    if(i+1==1)
    {
       printf("\nentrez le nom du 1er joueur\n");
    }
    else
    {
        printf("entrez le nom du %deme joueur\n",i+1); ///distinction entre le 1er joueur et les autres pour l'orthographe
    }
    fflush(stdin);
    gets(nom);
}
