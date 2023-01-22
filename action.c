#include "header.h"

void posel(t_joueur *joueur,char plateau [32][78],int nbrjoueur,char nomjoueur[4][30],t_joueur tabjoueur[4])
{
    int ordonnee=20,sensh=0,sensv=0,blind=0,blind2=0,i,j,compteur,mult,debug,existe,compt,jj;
    char mot[16],sens='a',abscisse='Z',test[16],chevalet2[7],motV[16];
    while(blind==0) ///tant que le joueur n'a pas mis un mot valide
    {
        for(i=0; i<7; i++) ///copie le chevalet
        {
            chevalet2[i]=joueur->chevalet[1][i*6+2];
        }
        compt=0;
        test[0]='\0';
        mult=1;
        ordonnee=20;
        blind2=0;
        compteur=0;
        sensv=0;
        sensh=0;
        ordonnee = 20;
        abscisse='Z';
        sens = 'a';
        debug=0;
        printf("Ecrire le mot\n");
        fflush(stdin);
        scanf("%s",mot);
        while(sens!='V' && sens !='H') ///entre le sens du mot
            while(sens!='V' && sens !='H')
            {
                printf("Ecrire le sens \nH-horizontale \nV-verticale\n");
                fflush(stdin);
                scanf("%c",&sens);
                if(sens=='V')
                {
                    sensv=1;
                    sensh=0;
                }

                if(sens=='H')
                {
                    sensv=0;
                    sensh=1;
                }

                if(sens!='H' && sens !='V')
                    printf("veuillez saisir un H ou V\n");
            }
        while((abscisse>'O' || abscisse<'A') || (ordonnee>15 || ordonnee <1)) ///entre les coordonnées de la première lettre du mot
        {
            printf("Ecrire les coordonnees de la case de depart(lettre puis nombre)\n");
            fflush(stdin);
            scanf("%c",&abscisse);
            scanf("%d",&ordonnee);
            if((abscisse>'P' || abscisse<64) || (ordonnee>16 || ordonnee <0))
                printf("veuillez saisir des coordonnees correctes\n");
        }
        for(i=0; i<strlen(mot); i++)
        {
            test[i]=plateau[ordonnee*2-1+i*2*sensv][((abscisse-64)*5-2)+i*5*sensh]; ///copie une chaine de caractere equivalente a l'emplacement futur du mot pour pouvoir tester si le mot correspond au plateau
        }
        for(i=0; i<strlen(mot); i++)
        {
            if(abscisse=='H' && ordonnee==8)
                break;
            if(test[i]==0)
                blind2++;
            if(blind2==strlen(mot))
            {
                printf("votre mot doit etre attache a une lettre deja presente\n"); ///blindage d'un mot hors jeu
                blind2=5;
            }
        }
        for(i=0; i<strlen(mot); i++)
        {
            for(j=0; j<2; j++)
            {
                if(test[i]=='?')
                {
                    if(mot[i+1]=='\0')
                    {
                        debug=1;    ///debug pour lorsque un ? est entré en fin de mot
                        test[i]=mot[i];
                    }
                    test[i]=mot[i];
                    compteur++;  ///compteur, lorsque le compteur atteint la longueur du mot, le blindage devient 1 et on sort de la grande boucle pour passer au tour suivant
                    printf("%d",compteur);
                    if(debug==0)
                        i++;
                }
                if(mot[i]=='?')
                {
                    if(mot[i+1]=='\0')
                    {
                        debug=1;
                        mot[i]='A';
                    }
                    joueur->chevalet[1][j*6+2]=0; ///remise à zéro du chevalet pour pas que une lettre soit comptée plus d'une fois si elle est en double dans le mot
                    compteur++;
                    if(debug==0)
                        i++;
                }
            }
            if(test[i]!=0)
            {
                compt++;
                if(mot[i]!=test[i])
                {
                    printf("le mot n'est pas accepte\n"); ///si le mot ne correspond pas a la chaine test
                    break;
                }
                if(mot[i]==test[i])
                {
                    compteur++;
                    if(compteur==strlen(mot)) ///ouvre la boucle si le mot est correct
                    {
                        blind=1;
                        break;
                    }
                }
            }
            if(test[i]==0)
            {
                for(j=0; j<8; j++)
                {
                    if(mot[i]==joueur->chevalet[1][j*6+2])
                    {
                        joueur->chevalet[1][j*6+2]=0;
                        compteur++;
                    }
                    if(compteur==strlen(mot))   ///ouvre la boucle si le mot est correct
                    {
                        blind=1;
                        break;
                    }
                }
            }
        }
        if(blind2==5)
        {
            blind=0;
        }
        if(debug==1)
            mot[i]='?';
        if(blind==0)
        {
            printf("Vous ne possedez pas les lettres correspondantes.\n"); ///message générale lorsqu'il y a un problème dans la pose du mot
            for(j=0; j<7; j++)
            {
                    joueur->chevalet[1][j*6+2]=chevalet2[j];
            }
        }
        if(blind==1)
        {
            printf("Voulez-vous verifier que le mot existe ?\n1-Oui\n2-Non\n"); ///vérification dans le dictionnaire de l'existence du mot
            fflush(stdin);
            scanf("%d",&existe);
            if(existe==1)
            {
                printf("entrez le numero du joueur qui veut verifier le mot\n"); ///choix du joueur qui va prendre la pénailté si le mot existe bel et bien
                for(j=0;j<nbrjoueur;j++)
                {
                    printf("\n%d-%s",j+1,nomjoueur[j]);
                }
                fflush(stdin);
                scanf("%d",&jj);
                jj--;
                printf("Ecrire le mot a chercher au singulier ou a l'infitif\n");  ///on rerentre le mot pour qu'il fonctionne si il est conjugué ou au pluriel
                scanf("%s",motV);
                blind=dico(motV);
                if(blind==1)
                {
                    tabjoueur[jj].score=tabjoueur[jj].score-10; ///pénalité de 10 points
                }
            }
        }
    }
    if(blind==1)
    {
        for(i=0; i<strlen(mot); i++)
        {

                plateau[ordonnee*2-1+i*2*sensv][((abscisse-64)*5-2)+i*5*sensh]=mot[i];
            mult = comptescore(joueur,plateau[ordonnee*2-1+i*2*sensv][((abscisse-64)*5-3)+i*5*sensh],mot[i]); ///compte le nouveau score du joueur si le mot est valide
        }
        if(strlen(mot)-compt==7) ///affiche scrabble si le joueur pose toutes ces tuiles en 1 tour et lui ajoute 50 points
        {
            Color(12,15);
            printf("SCRABBLE !!\n");
            joueur->score = joueur->score+50;
            Color(0,15);
        }

    }
    for(j=0;j<7;j++) ///remet le chevalet correctement (sans les cartes utilisées)
    {
        joueur->chevalet[1][j*6+2]=chevalet2[j];
    }
    if (blind==1)
    {
        for(i=0;i<16;i++)
        {
            for(j=0;j<7;j++)
            {
                if(mot[i]!=0)
                {
                    if(test[i]==mot[i])
                    {
                        mot[i]=0;
                        break;
                    }
                    if(mot[i]==joueur->chevalet[1][j*6+2] && mot[i]!=0)
                    {
                        mot[i]=0;
                        joueur->chevalet[1][j*6+2]=0;
                        break;
                    }
                }
            }
        }
    }
    joueur->score=joueur->score*mult;/// attribue le score au joueur
}

void changel(char pioche[102],t_joueur *joueur)
{
    int nb,j,i,k;
    char lettre[7];
    printf("combien de lettre voulez-vous changer ?\n"); ///change les tuiles d'un joueur
    fflush(stdin);
    scanf("%d",&nb);
    printf("Quel(s) lettre(s) voulez-vous changer ?\n");
    for (i=0; i<nb; i++)
    {
        fflush(stdin);
        scanf("%c",&lettre[i]);
        for(j=0;j<7;j++)
        {
            if(lettre[i]==joueur->chevalet[1][j*6+2])
            {
                for(k=0;k<102;k++)
                {
                    if(pioche[k]==0)
                    {
                        pioche[k]=joueur->chevalet[1][j*6+2];
                        joueur->chevalet[1][j*6+2]=0;
                    }
                }
            }
        }
    }
}
