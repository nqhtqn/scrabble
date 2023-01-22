#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct joueur {                                                      /// Structure d'un joueur contenant son score et la composition de son chevalet
    char chevalet[3][41];
    int score;
    }t_joueur;

int menu(char nomjoueur[4][30],t_joueur tabjoueur[4],int nbrjoueur);         ///menu
void pioche();                                                               /// ?
int nombrejoueur();                                                          ///compte le nombre de joueurs
void Color(int couleurDuTexte,int couleurDeFond);                            ///Permet de changer la couleur du texte
void nomjoueurf(int i,char nom [30]);                                        ///Rentre le nom de chaque joueur
void creerpioche(char pioche[102]);                                          ///crétion de la pioche et mélange
void distribution(t_joueur *joueur,char pioche[102]);                        ///Distribue des lettres à un chevalet complétement ou partiellement vide
void creationplateau(char plateau [32][78]);                                 ///Crée le plateau
void affichageplateau(char plateau [32][78],t_joueur joueur,char nom[30]);   ///Affiche le plateau
void changel(char pioche[102],t_joueur *joueur);                             ///change les cartes du chevalet contre des cartes de la pioche
void posel(t_joueur *joueur,char plateau [32][78],int nbrjoueur,char nomjoueur[4][30],t_joueur tabjoueur[4]);///pose les lettres sur le plateau
int comptescore(t_joueur *joueur,char lettreplateau,char lettremot);         ///compte le score de chaque joueur
int verifpioche(char pioche[102]);                                           ///vérifie que la piooche n'est pas vide
int verifchevalet (t_joueur *joueur);                                        ///Vérifie que le chevalet de chaque joueur n'est pas vide
int dico(char MOT[16]);                                                      ///Vérifie si un mot est dans le dictionnaire
void afflettre(int i);                                                       ///Affiche les lettres et leur valeurs à droite du plateau
int scoref(char lettre);



#endif // HEADER_H_INCLUDED
