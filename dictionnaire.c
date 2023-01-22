#include"header.h"

int dico(char MOT[16])
{

    int verifier =0,i=0,existee=0,blind=0,j=0;
    char mot[20],mot2[20];
    FILE*dico=NULL;
    dico =fopen("dictionnaire.txt","r"); ///ouvre le premier dictionnaire
    if(dico==NULL)
    {
        printf("\nerreur d'ouverture du fichier\n");
    }
    while(existee==0 && i<11999) ///scan le disctionnaire pour trouver un mot
    {
        fscanf(dico,"%s",mot);
        verifier=strcmp(mot,MOT);
        if (verifier==0)
        {
            existee=1;
        }
        i++;
    }

    FILE*dico2=NULL;
    dico2=fopen("dictionnaire2.txt","r"); ///ouvre le deuxième dictionnaire (parce que ca ne marchait sur l'ordinateur d'un des eleve du groupe, le scan s'arrêtait à environ la moitié du dictionnaire)
    if(dico2==NULL)
    {
        printf("\nerreur d'ouverture du fichier\n");
    }
    while(existee==0 && j<11000) ///scan le deuxième dictionnaire
    {
        fscanf(dico2,"%s",mot2);
        verifier=strcmp(mot2,MOT);
        if (verifier==0)
        {
            existee=1;
        }
        j++;
    }

    if (existee==1) ///le mot existe dans le dictionnaire
    {
        blind=1;
        printf("\nle mot est dans le dictionnaire\n");
    }
    else ///le mot n'existe pas dans le dictionnaire
        {
            printf("\nle mot n est pas dans le dictionnaire\n");
        }
    return blind;
}
