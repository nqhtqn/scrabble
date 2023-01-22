#include "header.h"

int comptescore(t_joueur *joueur,char lettreplateau,char lettremot)
{
    int score=0,mult=0,multm=1; ///compte le score en fonction de la case sur laquelle la tuile est posée et en fonction de la valeur de la tuile
    score=0;
    mult=1;
    multm=1;
    switch (lettremot)
    {
    case 'A' :
        score++;
        break;
    case 'B' :
        score=score+3;
        break;
    case 'C' :
        score=score+3;
        break;
    case 'D' :
        score=score+2;
        break;
    case 'E' :
        score++;
        break;
    case 'F' :
        score=score+4;
        break;
    case 'G' :
        score=score+2;
        break;
    case 'H' :
        score=score+4;
        break;
    case 'I' :
        score++;
        break;
    case 'J' :
        score=score+8;
        break;
    case 'K' :
        score=score+10;
        break;
    case 'L' :
        score++;
        break;
    case 'M' :
        score=score+2;
        break;
    case 'N' :
        score++;
        break;
    case 'O' :
        score++;
        break;
    case 'P' :
        score=score+3;
        break;
    case 'Q' :
        score=score+8;
        break;
    case 'R' :
        score++;
        break;
    case 'S' :
        score++;
        break;
    case 'T' :
        score++;
        break;
    case 'U' :
        score++;
        break;
    case 'V' :
        score=score+4;
        break;
    case 'W' :
        score=score+10;
        break;
    case 'X' :
        score=score+10;
        break;
    case 'Y' :
        score=score+10;
        break;
    case 'Z' :
        score=score+10;
        break;
    case '?' :
        break;
    }
    switch (lettreplateau)
    {
    case '&' :
        mult = 2;
        break;
    case '%' :
        mult = 3;
        break;
    }
    if (lettreplateau=='@')
        multm=multm*2;
    if(lettreplateau=='§')
        multm=multm*3;
    joueur->score=joueur->score+(score*mult); ///calcule pour avoir la bonne valeur finale
    return multm;
}

int scoref(char lettre) ///donne la valeur d'une lettre
{
    int score=0;
    switch (lettre)
    {
    case 'A' :
        score++;
        break;
    case 'B' :
        score=score+3;
        break;
    case 'C' :
        score=score+3;
        break;
    case 'D' :
        score=score+2;
        break;
    case 'E' :
        score++;
        break;
    case 'F' :
        score=score+4;
        break;
    case 'G' :
        score=score+2;
        break;
    case 'H' :
        score=score+4;
        break;
    case 'I' :
        score++;
        break;
    case 'J' :
        score=score+8;
        break;
    case 'K' :
        score=score+10;
        break;
    case 'L' :
        score++;
        break;
    case 'M' :
        score=score+2;
        break;
    case 'N' :
        score++;
        break;
    case 'O' :
        score++;
        break;
    case 'P' :
        score=score+3;
        break;
    case 'Q' :
        score=score+8;
        break;
    case 'R' :
        score++;
        break;
    case 'S' :
        score++;
        break;
    case 'T' :
        score++;
        break;
    case 'U' :
        score++;
        break;
    case 'V' :
        score=score+4;
        break;
    case 'W' :
        score=score+10;
        break;
    case 'X' :
        score=score+10;
        break;
    case 'Y' :
        score=score+10;
        break;
    case 'Z' :
        score=score+10;
        break;
    case '?' :
        break;
    }
    return score;
}
