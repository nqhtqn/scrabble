#include "header.h"

void creationplateau(char plateau [32][78])
{
    int i, j, a, b, c;
   for (i=0;i<32;i++)
   {
       for (j=0;j<78;j++)
       {
           plateau [i][j]=0x00; ///initialise le plateau à 0
       }
   }
   for (i=0;i<31;i++) ///grille
   {
       for (j=0;j<76;j++)
       {

           if (i%2==0 && j%5!=0)
                  plateau [i][j]=0xC4;  /// barre horizontale
           if (i%2==1 && j%5==0)
                  plateau [i][j]=0xB3;  /// barre verticale
           if (i%2==0 && j%5==0)
                  plateau [i][j]=0xC5;  /// croix
           if (i%2==0 && j==0)
                  plateau [i][j]=0xC3;  /// barre verticale plus droite
           if (i%2==0 && j==75)
                  plateau [i][j]=0xB4;  /// barre verticale plus gauche
           if (i==0 && j%5==0)
                  plateau [i][j]=0xC2;  ///barre horizontale vers le bas
           if (i==30 && j%5==0)
                  plateau [i][j]=0xC1;  ///barre horizontale vers le haut
       }
   }
   a=0;
   b=1;
   c=0;
   for (i=0;i<32;i++) ///coordonnées (ABC... 123...)
   {
       for (j=0;j<78;j++)
       {
           if(i==31 && j%5==2 && j<76)
           {
               plateau[i][j]=65+a;
               a++;
           }
           if(j==76 && i%2==1&&i<18)
           {
               plateau[i][j]=48+b;
               b++;
           }
           if (j==76 && i%2==1 &&i>17 && i<31)
           {
               plateau[i][76]=49;
               plateau[i][77]=48+c;
               c++;
           }
       }
   }

   plateau [0][0]=0xDA; ///4 coins du plateau
   plateau [0][75]=0xBF;
   plateau [30][0]=0xC0;
   plateau [30][75]=0xD9;

   for (i=0;i<16;i++) ///premier quart
   {
       for (j=0;j<39;j++)
       {
           if((i==3 && j==7) || (i==5 && j==12) || (i==7 && j==17) || (i==9 && j==22)) ///@
            plateau[i][j]=0x40;
           if((i==1 && (j==2||j==37))||(i==15 && j==2)) ///§
            plateau[i][j]=-11;
           if((i==1 && j==17)||(i==5 && j==32) || (i==7 && (j==2||j==37)) || (i==13 && (j==12 || j==32)) || (i==15 && j==17)) ///&
            plateau[i][j]=0x26;
           if((i==3 && j==27) || (i==11 && (j==7 || j==27))) ///%
            plateau[i][j]=0x25;
           if(i==15 && j==37) ///#
            plateau[i][j]=0x23;
       }
   }
for (i=0;i<16;i++) ///deuxieme quart (pivot à 90°)
   {
       for (j=0;j<39;j++)
       {
           if((i==3 && j==7) || (i==5 && j==12) || (i==7 && j==17) || (i==9 && j==22)) //@
            plateau[i][74-j]=0x40;
           if((i==1 && (j==2||j==37))||(i==15 && j==2)) //§
            plateau[i][74-j]=-11;
           if((i==1 && j==17)||(i==5 && j==32) || (i==7 && (j==2||j==37)) || (i==13 && (j==12 || j==32)) || (i==15 && j==17)) //&
            plateau[i][74-j]=0x26;
           if((i==3 && j==27) || (i==11 && (j==7 || j==27))) //%
            plateau[i][74-j]=0x25;
           if(i==15 && j==37) //#
            plateau[i][74-j]=0x23;
       }
   }
   for (i=0;i<16;i++) ///troisieme quart
   {
       for (j=0;j<39;j++)
       {
           if((i==3 && j==7) || (i==5 && j==12) || (i==7 && j==17) || (i==9 && j==22)) //@
            plateau[30-i][j]=0x40;
           if((i==1 && (j==2||j==37))||(i==15 && j==2)) //§
            plateau[30-i][j]=-11;
           if((i==1 && j==17)||(i==5 && j==32) || (i==7 && (j==2||j==37)) || (i==13 && (j==12 || j==32)) || (i==15 && j==17)) //&
            plateau[30-i][j]=0x26;
           if((i==3 && j==27) || (i==11 && (j==7 || j==27))) //%
            plateau[30-i][j]=0x25;
           if(i==15 && j==37) //#
            plateau[30-i][j]=0x23;
       }
   }
   for (i=0;i<16;i++) ///quatrieme quart
   {
       for (j=0;j<39;j++)
       {
           if((i==3 && j==7) || (i==5 && j==12) || (i==7 && j==17) || (i==9 && j==22)) //@
            plateau[30-i][74-j]=0x40;
           if((i==1 && (j==2||j==37))||(i==15 && j==2)) //§
            plateau[30-i][74-j]=-11;
           if((i==1 && j==17)||(i==5 && j==32) || (i==7 && (j==2||j==37)) || (i==13 && (j==12 || j==32)) || (i==15 && j==17)) //&
            plateau[30-i][74-j]=0x26;
           if((i==3 && j==27) || (i==11 && (j==7 || j==27))) //%
            plateau[30-i][74-j]=0x25;
           if(i==15 && j==37) //#
            plateau[30-i][74-j]=0x23;
       }
   }
}


void affichageplateau(char plateau [32][78],t_joueur joueur,char nom[30])
{

    int i, j;
    Color(0,15);  ///"scrabble"
    printf("\t\t\t\t\t\t\t\t\t\t\t        ");
    Color(14,2);
    printf(" SCRABBLE ");
    Color(0,15);
    printf("                                      ");
    printf("\t    Valeurs des lettres:");
    printf("\n");
    Color(10,15);
   for (i=0;i<32;i++)
   {
       printf("\t\t\t\t\t\t\t\t");
       for (j=0;j<78;j++)
       {
           if (plateau[i][j]==0x40 || plateau[i][j]==-11 || plateau[i][j]==0x26 || plateau[i][j]==0x25) ///colorie les cases spéciales
           {
               if (plateau[i][j]==0x40)
                Color(5,15);
               if (plateau[i][j]==-11)
                Color(12,15);
                if (plateau[i][j]==0x26)
                Color(9,15);
                if (plateau[i][j]==0x25)
                Color(10,15);
           }
           else
            Color(0,15);
            printf("%c",plateau[i][j]);
       }
       afflettre(i); ///affiche les lettres sur le cotès
       printf("\n");
   }

    printf("\n"); ///legende
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xDA);
    for(i=0;i<21;i++)
    {
        printf("%c",0xC4);
    }
    printf("%c",0xBF);
    printf("\n");
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xB3);
    Color(8,15);
    printf(" LEGENDE :           ");
    Color(0,15);
    printf("%c",0xB3);
    printf("\t    ' M ' pour afficher le menu ");
    printf("\n");
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xB3);
    printf(" # : point de depart ");
    printf("%c",0xB3);
    printf("\n");
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xB3);
    Color(9,15);
    printf(" & : lettre double   ");
    Color(0,15);
    printf("%c",0xB3);
    printf("\n");
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xB3);
    Color(10,15);
    printf(" %% : lettre triple   ");
    Color(0,15);
    printf("%c",0xB3);
    Color(2,15);
    printf("\t\tSCORE DE %s : %dpts",nom,joueur.score); ///affiche le score du joueur
    Color(0,15);
    printf("\n");
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xB3);
    Color(5,15);
    printf(" @ : mot double      ");
    Color(0,15);
    printf("%c",0xB3);
    printf("\n");
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xB3);
    Color(12,15);
    printf(" %c : mot triple      ",-11);
    Color(0,15);
    printf("%c\n",0xB3);
    printf("\t\t\t\t\t\t\t        ");
    printf("%c",0xC0);
    for(i=0;i<21;i++)
    {
        printf("%c",0xC4);
    }
    printf("%c",0xD9);
    printf("\n");

    for(i=0;i<3;i++) ///crée le chevalet
    {
        for(j=0;j<41;j++)
        {
            if(i%2==0)
                joueur.chevalet[i][j]=0xC4;
            if(i==1 && (j%6==4 || j%6==0))
                joueur.chevalet[i][j]=0xB3;
            if(j==0||j==41||(i==2&&j%6==0))
               joueur.chevalet[i][j]=0;
            if(i==0 && j%6==4)
                joueur.chevalet[i][j]=0xBF;
            if(i==2 && j%6==4)
                joueur.chevalet[i][j]=0xD9;
            if(i==0 && j%6==0)
                joueur.chevalet[i][j]=0xDA;
            if(i==2 && j%6==0)
                joueur.chevalet[i][j]=0xC0;
            if(j%6==5)
                joueur.chevalet[i][j]=0;
            if(i==1 && j%2==1)
                joueur.chevalet[i][j]=0;
        }
    }
   joueur.chevalet [0][0]=0xDA; ///coins du chevalet
   joueur.chevalet [0][40]=0xBF;
   joueur.chevalet [2][0]=0xC0;
   joueur.chevalet [2][40]=0xD9;
   joueur.chevalet [1][0]=0xB3;
   for(i=0;i<3;i++)
    {
        printf("\t\t\t\t\t\t\t\t\t\t");
        for(j=0;j<41;j++)
        {
            printf("%c",joueur.chevalet[i][j]); ///affichage chevalet
        }
        printf("\n");
    }
}

void afflettre(int i) ///affichage des lettres et leur valeur
{
        if(i==1)
        printf("\t\t\tA = 1pt");
        if(i==2)
        printf("\t\t\tB = 3pts");
        if(i==3)
        printf("\t\t\tC = 3pts");
        if(i==4)
        printf("\t\t\tD = 2pts");
        if(i==5)
        printf("\t\t\tE = 1pt");
        if(i==6)
        printf("\t\t\tF = 4pts");
        if(i==7)
        printf("\t\t\tG = 2pts");
        if(i==8)
        printf("\t\t\tH = 4pts");
        if(i==9)
        printf("\t\t\tI = 1pt");
        if(i==10)
        printf("\t\t\tJ = 8pts");
        if(i==11)
        printf("\t\t\tK = 10pts");
        if(i==12)
        printf("\t\t\tL = 1pt");
        if(i==13)
        printf("\t\t\tM = 2pts");
        if(i==14)
        printf("\t\t\tN = 1pt");
        if(i==15)
        printf("\t\t\tO = 1pt");
        if(i==16)
        printf("\t\t\tP = 3pts");
        if(i==17)
        printf("\t\t\tQ = 8pts");
        if(i==18)
        printf("\t\t\tR = 1pt");
        if(i==19)
        printf("\t\t\tS = 1pt");
        if(i==20)
        printf("\t\t\tT = 1pt");
        if(i==21)
        printf("\t\t\tU = 1pt");
        if(i==22)
        printf("\t\t\tV = 4pts");
        if(i==23)
        printf("\t\t\tW = 10pts");
        if(i==24)
        printf("\t\t\tX = 10pts");
        if(i==25)
        printf("\t\t\tY = 10pts");
        if(i==26)
        printf("\t\t\tZ = 10pts");
        if(i==27)
        printf("\t\t\t? = 0pt");

}
