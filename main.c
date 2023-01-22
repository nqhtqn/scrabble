#include "header.h"

int main()
{
int nbrjoueur,i, blind=1,j,recommencer=0,k,scorefi;
char plateau [32][78],pioche[102],nomjoueur[4][30],key='a';
t_joueur tabjoueur[4];
for (i=0; i<4; i++) ///initalise le chevalet à 0 pour éviter les bugs
        {
            for(j=0; j<41; j++)
            {
                tabjoueur[i].chevalet[1][j]=0;
            }
        }
while (recommencer == 0) ///permet de pouvoir recommencer une partie
    {
        blind=1;
        Color(0,15);
        printf("Nouvelle partie\n");
        recommencer =1;
        srand(time(NULL));
        creerpioche(pioche);
        nbrjoueur=nombrejoueur();
        for (i=0; i<4 ; i++)
        {
            for(j=0;j<29;j++)
            {
                nomjoueur[i][29]=0;
            }
        }
        for (i=0; i<nbrjoueur; i++) ///nomme chaque joueur
        {
            nomjoueurf(i,nomjoueur[i]);
        }
        for(i=0; i<4; i++) ///initialisation des scores à 0
        {
            tabjoueur[i].score=0;
        }

        creationplateau(plateau);

        while (0==0)   ///début du jeu
        {
            for(i=0; i<nbrjoueur; i++) /// un tour de plateau
            {
                if(verifpioche(pioche)==1 || verifchevalet(&tabjoueur[i])==1)  ///vérifie que personne n'a encore gagné
                {
                    blind=1;

                    distribution(&tabjoueur[i],pioche);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t   Au tour de : ");
                    puts(nomjoueur[i]);
                    affichageplateau(plateau,tabjoueur[i],nomjoueur[i]);
                    printf("1-Poser des lettres\n2-Changer les lettres de son chevalet\n3-Passer son tour\n");
                    while (blind==1)   ///choix entre les 3 possibilitées
                    {
                        if(recommencer==0)
                            break;
                        fflush(stdin);
                        if(kbhit())
                        {
                            key=getch();
                            switch(key)
                            {
                            case '1' :  ///poser ses tuiles sur le plateau
                                posel(&tabjoueur[i],plateau,nbrjoueur,nomjoueur,tabjoueur);
                                blind=0;
                                break;
                            case '2' :  ///Repose ses tuiles dans la pioche
                                changel(pioche,&tabjoueur[i]);
                                blind=0;
                                break;
                            case '3' :
                                blind=0; ///passe son tour
                                break;
                            case 'm' :
                                recommencer = menu(nomjoueur,tabjoueur,nbrjoueur); ///affichage du menu
                                affichageplateau(plateau,tabjoueur[i],nomjoueur[i]);
                                break;
                            }
                        }

                    }
                    if(recommencer==0) ///permet de recommencer la partie à zéro
                        break;
                    Sleep(200); ///attente entre chaque fin de tour d'un joueur
                    system("cls");
                }
                if (verifpioche(pioche)!=1 && verifchevalet(&tabjoueur[i])!=1) ///si la partie se finie
                {
                    for(j=0;j<nbrjoueur;j++)
                    {
                        scorefi=0;
                        for(k=0;k<7;k++)
                        {
                            scorefi=scorefi+scoref(tabjoueur[j].chevalet[1][k*6+2]); ///compte le score de chaque joueur
                        }
                        tabjoueur[j].score=tabjoueur[j].score-scorefi;
                        tabjoueur[i].score=tabjoueur[i].score+scorefi;
                    }
                    printf("LE JOUEUR ");
                    if(tabjoueur[1].score>tabjoueur[2].score && tabjoueur[1].score>tabjoueur[3].score && tabjoueur[1].score>tabjoueur[4].score) ///compare les scores
                        i=1;
                    if(tabjoueur[2].score>tabjoueur[1].score && tabjoueur[2].score>tabjoueur[3].score && tabjoueur[2].score>tabjoueur[4].score)
                        i=2;
                    if(tabjoueur[3].score>tabjoueur[2].score && tabjoueur[3].score>tabjoueur[1].score && tabjoueur[3].score>tabjoueur[4].score)
                        i=3;
                    if(tabjoueur[4].score>tabjoueur[2].score && tabjoueur[4].score>tabjoueur[3].score && tabjoueur[4].score>tabjoueur[1].score)
                        i=4;
                    puts(nomjoueur[i]);
                    printf("REMPORTE LA PARTIE !!"); ///fin de partie
                    return 0;
                }
            }
            if(recommencer==0)
            {
                system("cls");
                break;
            }
        }
    }
}



