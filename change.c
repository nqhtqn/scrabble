#include"header.h"

void change(char chevalet[7], char pioche[102], int nbrLettre)
{
    int i, j, k, l;
    char z[1], stock[1];
    for (i=0; i<=nbrLettre; i++)
    {
        printf("Quelle lettre voulez-vous changer?\n");
        scanf("%s", &z[1]);

        for (j=0; j<=7; j++)
        {
            if (chevalet[j] == z[1])
            {
                k=rand()%(102+1);
                chevalet[j] = stock;
                chevalet[j] = pioche[k];

                printf("\nvous avez pioche la carte : ");
                if(pioche[k]=='A'||pioche[k]=='E'||pioche[k]=='I'||pioche[k]=='L'||pioche[k]=='N'||pioche[k]=='O'||pioche[k]=='R'||pioche[k]=='S'||pioche[k]=='T'||pioche[k]=='U')
                {
                    Color(0,15);
                    printf(" %c 1pt \n",pioche[k]);
                }
                Color(15,0);

                if(pioche[k]=='D'||pioche[k]=='G'||pioche[k]=='M')
                {
                    Color(0,15);
                    printf(" %c 2pt \n",pioche[k]);
                }

                if(pioche[k]=='C'||pioche[k]=='B'||pioche[k]=='P')
                {
                    Color(0,15);
                    printf(" %c 3pt \n",pioche[k]);
                }

                if(pioche[k]=='F'||pioche[k]=='H'||pioche[k]=='V')
                {
                    Color(0,15);
                    printf(" %c 4pt \n",pioche[k]);
                }

                if(pioche[k]=='J'||pioche[k]=='Q')
                {
                    Color(5,14);
                    printf(" %c 8pt \n",pioche[k]);
                }
                if(pioche[k]=='K'||pioche[k]=='W'||pioche[k]=='X'||pioche[k]=='Y'||pioche[k]=='Z')
                {
                    Color(0,15);
                    printf(" %c 10pt \n",pioche[k]);
                }
                Color(15,0);
                if(pioche[k]=='?')
                {
                    Color(0,15);
                    printf(" %c 0pt \n",pioche[k]);
                }

                for (l=0; l<=102; l++)
                {
                    if (pioche[l] == 0)
                    {
                        pioche[l] = stock[1];
                        l = 103;
                    }
                }
                j=8;
            }
        }
    }
}
