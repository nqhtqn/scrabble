#include "header.h"

void distribution(t_joueur *joueur,char pioche[102])
{

    int a=0,j=2,i=1,k=102,p=1,v=1;
    for (i=0; i<7; i++)
        {
            while((k>101 || k<0) || pioche[k]==0 ||a==0) ///tant que on a pas une carte valide dans le chevalet
            {
                v=verifpioche(pioche);
                if (v==0)
                {
                    printf("il y a plus de jetons dans la pioche");
                    i=8;
                    break;
                }
                k=rand()%(102); ///prend une carte aléatoirement et continu que si cette carte est encore dans la pioche
                a=1;
            }
            if(joueur->chevalet[p][j]==0)
            {
                joueur->chevalet[p][j]=pioche[k]; ///met la carte dans le chevalet du joueur
                pioche[k]=0;
            }
        j=j+6;
        k=102;
        }
}

int verifpioche(char pioche[102]) ///vérifie que la pioche n'est pas vide
{
    int i,v=0;
    for (i=0;i<102;i++)
    {
        if (pioche[i]!=0)
        {
            v=1;
        }
    }
    return v;
}

int verifchevalet(t_joueur *joueur)  ///vérifie que le chevalet du joueur n'est pas vide
{
    int i,v=0;
    for (i=0;i<7;i++)
    {
        if (joueur->chevalet[1][i*6+2]!=0)
        {
            v=1;
        }
    }
    return v;
}
