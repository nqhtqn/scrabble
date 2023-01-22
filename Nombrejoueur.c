#include "header.h"

int nombrejoueur()
{
    int nbr = 0;
    while(nbr != 1 && nbr != 2 && nbr != 3 && nbr != 4) ///saisi le nombre je joueur et le renvoie au main
    {
        printf("Saisissez le nombre de joueur (4 max)\n");
        fflush(stdin);
        scanf("%d",&nbr);
        if(nbr != 1 && nbr != 2 && nbr != 3 && nbr != 4)
            printf("La saisie n'est pas valide\n");
    }
    return nbr;

}
