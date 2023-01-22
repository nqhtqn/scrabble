#include"header.h"
int menu(char nomjoueur[4][30],t_joueur tabjoueur[4],int nbrjoueur)
{
    int choix,i=0;
    char key='w';
    system("cls"); ///affichage menu
    printf("\nsaisir '1' pour lancer une nouvelle partie\nsaisir '2' pour afficher une aide\nsaisir '3' pour afficher les scores des joueurs\nsaisir '4' pour quitter le jeu\nSaisir '5' pour retourner au jeu\n\n");
    fflush(stdin);
    scanf("%d",&choix);
    switch (choix)
    {
    case 1 : ///relance une nouvelle partie
        return 0;
    case 2 : ///affiche "l'aide"
        Color(0,15);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
        Color(0,14);
        printf(" AIDE : ");
        Color(0,15);
        printf("                             \n\n");
        Color(10,15);
        printf("Description du jeu :\n");
        Color(0,15);
        printf("Le Scrabble est un jeu de societe et un jeu de lettres ou l'objectif est de cumuler des points en creant des mots sur une grille carree avec les lettres de son chevalet.\n");
        printf("Chaque lettres a une valeur attribuee et certaines cases permettent de doubler ou tripler la valeur de la lettre ou encore de doubler ou tripler la valeur totale du mot pose.\n\n") ;
        Color(10,15);
        printf("Deroulement d'une partie :");
        Color(0,15) ;
        printf("\n1-Chaque joueur tire aleatoirement sept lettres et les depose sur son chevalet\n2- Le joueur choisi parmi les lettres qu'il a tire et pose une ou plusieurs lettres de maniere a former de nouveaux mots sur la grille, horizontalement ou verticalement.") ;
        Color(12,15);
        printf( "\nAttention !! Il n'est pas admis de poser un mot en diagonale.\n") ;
        Color(10,15);
        printf("\nCalcul du score:");
        Color(0,15);
        printf("\nLe score d'un coup est calcule en additionnant la valeur de toutes les lettres des nouveaux mots formes (y compris celles deja posées sur la grille).\nSi une nouvelle lettre posee recouvre une case");
        Color(9,15);
        printf(" lettre compte double ('&') ");
        Color(0,15);
        printf(" ou ");
        Color(10,15);
        printf(" lettre compte triple ('%%') ");
        Color(0,15);
        printf(" sa valeur est multipliee par 2 ou par 3.\nSi une case ");
        Color(5,15);
        printf(" mot compte double ('@') ");
        Color(0,15);
        printf("ou");
        Color(12,15);
        printf(" mot compte triple ('%c') ",-11);
        Color(0,15);
        printf("a ete recouverte, la valeur du mot entier est doublee ou triplee.\n") ;
        printf("Enfin, Placer ses sept lettres sur la grille apporte une prime de 50 points. Ce coup est appele scrabble");
        Color(10,15);
        printf("\n\nFin du tour;");
        Color(0,15);
        printf("\nApres avoir pose ses lettres et annonce son score, le tour est termine");
        Color(10,15);
        printf("\n\nQuelque astuce de notre code :\n");
        Color(0,15);
        printf("\t-Il est possible de verifier si un mot qu'un joueur est entrain de poser existe reellement dans le dictionnaire.");
        printf("\n\t-La Valeur de chaque lettre sera affichee tout le long de votre partie sur la droite de votre plateau.");
        printf("\n\t-au dessus du plateau est ecrit a qui est le tour et seule le chevalet de ce joueur et son score seront affiches.");
        printf("\n\t-Il est posible d'ouvrir le Menu en appuyant sur la touche 'm' qui propose ces 4 fonctionnalitees :");
        printf("\n\t\t\t-Lancer une nouvelle partie");
        printf("\n\t\t\t-Afficher l'aide");
        printf("\n\t\t\t-Afficher les scores des joueurs");
        printf("\n\t\t\t-Quitter le jeu\n\n");
        while(key=='w') ///sort du menu
        {
            if(kbhit())
            {
                key=getch();
            }
        }
        system("cls");
        return 1;
    case 3 : ///affiche les scores
        for(i=0; i<nbrjoueur; i++)
        {
            printf("score de ");
            printf("%s",nomjoueur[i]);
            printf(" : %d\n",tabjoueur[i].score);
        }
        break;
    case 4 : ///ferme le programme
        printf("vous quittez le programme...");
        exit(0);
    case 5 : ///retourne au jeu
        return 1;
    }
    return 123456789;
}
