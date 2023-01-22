#include "header.h"

void Color(int couleurDuTexte,int couleurDeFond) ///change la couleur du texte ou du fond
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
