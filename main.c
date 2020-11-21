#include <stdio.h>
#include <stdlib.h>
#define Nmax 50
#include <time.h>
#include <windows.h>
void Menu();
int Moulin(int);
void moulin1();
void moulin2();
void RegleDuJeu(int);
int isNull();
int verif2(int,int);
int verif3(int);
int verif1(int);
void who(int,int);
void deplacement(int);
void jeu(int);
void grille();
void hesitation();
void add1(int);
void add2(int);
int nogain();
int stop();
void Quitter(int);
int notnuLL11();
int notnuLL22();
void supp1(int);
void supp2(int);
int allignee(int,int);
int possible(int,int);
void qui();
void ajout(int,int);
int B[24]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
int C[24]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
int s1=0,s2=0;
int ouf;
int pe1,pe2;
int tab[24]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
int H1[8][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24}};
int V1[8][3]={{1,10,22},{4,11,19},{7,12,16},{2,5,8},{17,20,23},{9,13,18},{6,14,21},{3,15,24}};
int H2[8][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24}};
int V2[8][3]={{1,10,22},{4,11,19},{7,12,16},{2,5,8},{17,20,23},{9,13,18},{6,14,21},{3,15,24}};
int H[8][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24}};
int V[8][3]={{1,10,22},{4,11,19},{7,12,16},{2,5,8},{17,20,23},{9,13,18},{6,14,21},{3,15,24}};
char  A[19][44]={
    {'0','1','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','0','2','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','0','3'},
    {'\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','0','4','-','-','-','-','-','-','-','-','-','-','-','0','5','-','-','-','-','-','-','-','-','-','-','-','0','6','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','0','7','-','-','-','-','-','-','-','0','8','-','-','-','-','-','-','-','0','9','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'1','0','-','-','-','-','-','-','1','1','-','-','1','2','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','1','3','\0','\0','1','4','-','-','-','-','-','-','1','5','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','1','6','-','-','-','-','-','-','-','1','7','-','-','-','-','-','-','-','1','8','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','1','9','-','-','-','-','-','-','-','-','-','-','-','2','0','-','-','-','-','-','-','-','-','-','-','-','2','1','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0'},
    {'\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','|','\0'},
    {'2','2','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','2','3','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','2','4'}};


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
char nom1[Nmax],nom2[Nmax];
char nom[Nmax];





int main()
{Color(0,15);
  printf("\n\n\n");
printf("\t\t\t                        $$\\                                                     $$\\ \n");
printf("\t\t\t                        $$ |                                                    $$ | \n");
printf("\t\t\t$$\\  $$\\  $$\\  $$$$$$\\  $$ | $$$$$$$\\  $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\        $$$$$$\\    $$$$$$\\         \n");
printf("\t\t\t$$ | $$ | $$ |$$  __$$\\ $$ |$$  _____|$$  __$$\\ $$  _$$  _$$\\ $$  __$$\\       \\_$$  _|  $$  __$$\\       \n");
printf("\t\t\t$$ | $$ | $$ |$$$$$$$$ |$$ |$$ /      $$ /  $$ |$$ / $$ / $$ |$$$$$$$$ |        $$ |    $$ /  $$ |      \n");
printf("\t\t\t$$ | $$ | $$ |$$   ____|$$ |$$ |      $$ |  $$ |$$ | $$ | $$ |$$   ____|        $$ |$$\\ $$ |  $$ |     \n");
printf("\t\t\t\\$$$$$\\$$$$  |\\$$$$$$$\\ $$ |\\$$$$$$$\\ \\$$$$$$  |$$ | $$ | $$ |\\$$$$$$$\\         \\$$$$  |\\$$$$$$  |      \n");
printf("\t\t\t \\_____\\____/  \\_______|\\__| \\_______| \\______/ \\__| \\__| \\__| \\_______|         \\____/  \\______/       \n");
printf("\t\t\t                                                                                                       \n");
printf("\t\t\t                                                                                                        \n");
printf("\t\t\t                                                                                                         \n\n\n");
printf("                                                                     ***** MENU DU JEU DU MOULIN *****                               \n");
    Menu();
    return 0;
}







void Menu()
{   int votrechoix;
    Color(3,15);
    printf("1- jouer Homme vs Homme\n");
    Color(4,15);
    printf("2- jouer Homme vs Machine\n");
    Color(5,15);
    printf("3- Regles du jeu\n");
    Color(6,15);
    printf("4- Quitter le jeu\n");
    Color(0,15);
    scanf("%d",&votrechoix);
    switch(votrechoix)
    {case 4:
        {int confirmation=0;
        Quitter(confirmation);}
        break;
    case 3:
        {int choix3=0;
        printf(" **** REGLES DU JEU **** \n");
        Color(8,15);
        printf("1-Posez D'ABORD vos 9 pions, MAIS ATTENTION! N'ecrasez pas une des positions de ton adversaire\n2-Deplacez vos pions vers une intersection VOISINe, LIBRE, et ALIGNEE pour former un moulin\n3-Une fois réussi, vous pouvez CAPTURER un pion de l'autre A CONDITION QU'IL NE FASSE PAS DEJA PARTIE D'UN MOULIN\n4- Le joueur qui ne possedera plus que 2 PIONS sera le PERDANT\n");
        Color(1,15);
        printf(" ------------------      Amusez-vous ^_^      -------------------\n");
        Color(0,15);
        RegleDuJeu(choix3);}
        break;
    case 1:
       {srand(time(NULL));
        ouf=rand()%1;
{  int choix1=0;

        printf(" ^^^^^^^^  Entrez vos noms ^^^^^^^^ :\n");
        scanf("%s %s",&nom1,&nom2);
        printf(" <<<<<<         Jolis noms! ^_^        >>>>>> \n");

        hesitation(choix1);
        break;}
    case 2:
       {int choix2=0;
        printf("-------- ENTRER TON NOM ---------: \n");
        scanf("%s",nom);
        printf(" <<<<<<<<         Joli nom! ^_^        >>>>>>>> \n");

        //Hesitation(choix2);}
        break;
    }}}}
    void jouer(int joueur)
{
    int position;
    while (stop())
        {
    printf("l'Homme %d, chosis une position :",joueur);
    scanf("%d",&position);
    if (position>=1 && position <=24)
    {
        if ((tab[position-1])!=0)
        {
            tab[position-1]=0;
            ajout(position,joueur);

            switch(position)  //les symboles deposees dans les positions saisies varient selon le joueur ( ouf ou 1-ouf )
    {
        case 1:
        {if (joueur == ouf)
        {
            A[0][0]='#';
            A[0][1]=A[0][0];
        }
        if (joueur==1-ouf)
        {
            A[0][0]='&';
            A[0][1]=A[0][0];
        }}
        break;
         case 2:
                if (joueur==ouf)
        {
            A[0][21]='#';
            A[0][22]=A[0][21];
        }
        if (joueur==1-ouf)
        {
            A[0][21]='&';
            A[0][22]=A[0][21];
        }
        break;
         case 3:
           if (joueur==ouf)
        {
            A[0][42]='#';
            A[0][43]=A[0][42];
        }
        if (joueur==1-ouf)
        {
            A[0][42]='&';
            A[0][43]=A[0][42];
        }
        break;
         case 4:
             if (joueur==ouf)
        {
            A[3][8]='#';
            A[3][9]=A[3][8];
        }
        if (joueur==1-ouf)
        {
            A[3][8]='&';
            A[3][9]=A[3][8];
        }
        break;
         case 5:
           if (joueur==ouf)
        {
            A[3][21]='#';
            A[3][22]=A[3][21];
        }
        if (joueur==1-ouf)
        {
            A[3][21]='&';
            A[3][22]=A[3][21];
        }
        break;
         case 6:
           if (joueur==ouf)
        {
            A[3][34]='#';
            A[3][35]=A[3][34];
        }
        if (joueur==1-ouf)
        {
            A[3][34]='&';
            A[3][35]=A[3][34];
        }
        break;
         case 7:
        if (joueur==ouf)
        {
            A[6][12]='#';
            A[6][13]=A[6][12];
        }
        if (joueur==1-ouf)
        {
            A[6][12]='&';
            A[6][13]=A[6][12];
        }
        break;
              case 8:
        if (joueur==ouf)
        {
            A[6][21]='#';
            A[6][22]=A[6][21];
        }
        if (joueur==1-ouf)
        {
            A[6][21]='&';
            A[6][22]=A[6][21];
        }
        break;

              case 9:
        if (joueur==ouf)
        {
            A[6][30]='#';
            A[6][31]=A[6][30];
        }
        if (joueur==1-ouf)
        {
            A[6][30]='&';
            A[6][31]=A[6][30];
        }
        break;

              case 10:
        if (joueur==ouf)
        {
            A[9][0]='#';
            A[9][1]=A[9][0];
        }
        if (joueur==1-ouf)
        {
            A[9][0]='&';
            A[9][1]=A[9][0];
        }
        break;

              case 11:
        if (joueur==ouf)
        {
            A[9][8]='#';
            A[9][9]=A[9][8];
        }
        if (joueur==1-ouf)
        {
            A[9][8]='&';
            A[9][9]=A[9][8];
        }
        break;

              case 12:
        if (joueur==ouf)
        {
            A[9][12]='#';
            A[9][13]=A[9][12];
        }
        if (joueur==1-ouf)
        {
            A[9][12]='&';
            A[9][13]=A[9][12];
        }
        break;
          case 13:
        if (joueur==ouf)
        {
            A[9][30]='#';
            A[9][31]=A[9][30];
        }
        if (joueur==1-ouf)
        {
            A[9][30]='&';
            A[9][31]=A[9][30];
        }
        break;

              case 14:
        if (joueur==ouf)
        {
            A[9][34]='#';
            A[9][35]= A[9][34];
        }
        if (joueur==1-ouf)
        {
            A[9][34]='&';
            A[9][35]= A[9][34];
        }
        break;

              case 15:
        if (joueur==ouf)
        {
            A[9][42]='#';
            A[9][43]= A[9][42];
        }
        if (joueur==1-ouf)
        {
            A[9][42]='&';
            A[9][43]= A[9][42];
        }
        break;

              case 16:
        if (joueur==ouf)
        {
            A[12][12]='#';
            A[12][13]= A[12][12];
        }
        if (joueur==1-ouf)
        {
            A[12][12]='&';
            A[12][13]= A[12][12];
        }
        break;

              case 17:
        if (joueur==ouf)
        {
            A[12][21]='#';
            A[12][22]= A[12][21];
        }
        if (joueur==1-ouf)
        {
            A[12][21]='&';
            A[12][22]= A[12][21];
        }
        break;

              case 18:
        if (joueur==ouf)
        {
            A[12][30]='#';
            A[12][31]=A[12][30];
        }
        if (joueur==1-ouf)
        {
            A[12][30]='&';
            A[12][31]=A[12][30];
        }
        break;

              case 19:
        if (joueur==ouf)
        {
            A[15][8]='#';
            A[15][9]=A[15][8];
        }
        if (joueur==1-ouf)
        {
            A[15][8]='&';
            A[15][9]=A[15][8];
        }
        break;

              case 20:
        if (joueur==ouf)
        {
            A[15][21]='#';
            A[15][22]=A[15][21];
        }
        if (joueur==1-ouf)
        {
            A[15][21]='&';
            A[15][22]=A[15][21];
        }
        break;

              case 21:
        if (joueur==ouf)
        {
            A[15][34]='#';
            A[15][35]=A[15][34];
        }
        if (joueur==1-ouf)
        {
            A[15][34]='&';
            A[15][35]=A[15][34];
        }
        break;

              case 22:
        if (joueur==ouf)
        {
            A[18][0]='#';
            A[18][1]=A[18][0];
        }
        if (joueur==1-ouf)
        {
            A[18][0]='&';
            A[18][1]=A[18][0];
        }
        break;

              case 23:
        if (joueur==ouf)
        {
            A[18][21]='#';
            A[18][22]=A[18][21];
        }
        if (joueur==1-ouf)
        {
            A[18][21]='&';
            A[18][22]=A[18][21];
        }
        break;

              case 24:
        if (joueur==ouf)
        {
            A[18][42]='#';
            A[18][43]=A[18][42];
        }
        if (joueur==1-ouf)
        {
            A[18][42]='&';
            A[18][43]=A[18][42];
        }

        break;}
        jouer(1-joueur);

        }
    else
          {
         printf(" =====      Position deja remplie -_- ! Choisis une autre valide     =====\n");
          jouer(joueur);}
    }
    else {
        printf(" ======    entrer une position valide -__-   ====== \n");
        jouer(joueur);
    }
}

}
void deplacement(int joueur)
  {
       int p1,p2,P1,P2;

      while (Moulin(joueur))
        {
       if (joueur==ouf)
            {
                printf("%d, Deplacez un de tes pions\n",joueur);
              printf(" -Entrez la position a deplacer : \n");
              scanf("%d",&p1);
               if (verif1(p1))
               {

                   printf("-Entrez la position destinee: ");
                    scanf("%d",&p2);
                    if (verif2(p2,p1))
                    {        moulin1(P2);
                             supp1(p1);
                             add1(p2);
                             switch(p2)
                            {
                                case 1:

           {

            A[0][0]='#';
            A[0][1]=A[0][0];

        break;}
         case 2:

           {

           A[0][21]='#';
            A[0][22]=A[0][21];

        break;}
         case 3:

            {A[0][42]='#';
            A[0][43]=A[0][42];

        break;}
         case 4:

            {A[3][8]='#';
            A[3][9]=A[3][8];

        break;}
         case 5:

            {A[3][21]='#';
            A[3][22]=A[3][21];

        break;}
         case 6:

           {

            A[3][34]='#';
            A[3][35]=A[3][34];

        break;}
         case 7:

            {A[6][12]='#';
            A[6][13]=A[6][12];

        break;}
              case 8:

            {A[6][21]='#';
            A[6][22]=A[6][21];

        break;}
           case 9:
           {

            A[6][30]='#';
            A[6][31]=A[6][30];

        break;}
          case 10:
           {

            A[9][0]='#';
            A[9][1]=A[9][0];

        break;}
           case 11:
           {

            A[9][8]='#';
            A[9][9]=A[9][8];

        break;}

              case 12:

           {

            A[9][12]='#';
            A[9][13]=A[9][12];

        break;}
          case 13:

            {A[9][30]='#';
            A[9][31]=A[9][30];

        break;}

              case 14:

           {

            A[9][34]='#';
            A[9][35]= A[9][34];

        break;}

              case 15:

            {A[9][42]='#';
            A[9][43]= A[9][42];

        break;}

              case 16:

           {

            A[12][12]='#';
            A[12][13]= A[12][12];

        break;}

              case 17:

            {A[12][21]='#';
            A[12][22]= A[12][21];

        break;}

              case 18:

            {A[12][30]='#';
            A[12][31]=A[12][30];

        break;}

              case 19:

            {A[15][8]='#';
            A[15][9]=A[15][8];

        break;}

              case 20:

           {

            A[15][21]='#';
            A[15][22]=A[15][21];

        break;}

              case 21:

            {A[15][34]='#';
            A[15][35]=A[15][34];

        break;}

              case 22:

           {

            A[18][0]='#';
            A[18][1]=A[18][0];

        break;}

              case 23:

           {

            A[18][21]='#';
            A[18][22]=A[18][21];

        break;}

              case 24:

           {

            A[18][42]='#';
            A[18][43]=A[18][42];

        break;}}
        grille();
        deplacement(1-joueur);}

            else { printf("---- Entrer une position destinee valide!!!!!  ----\n");
            deplacement(joueur);}

              } else //Color(4,15);
                    {printf("Vous ne pouvez deplacer que VOS PIONS -_- \n");
                    Color(0,15);
                    deplacement(joueur);}}

  if (joueur==1-ouf)
{   printf("%d,Deplacez un de tes pions \n",joueur);
    printf("-Entrez la position a deplacer :");
    scanf("%d",&P1);
           if (verif3(P1))
                   {
                    printf("-Entrez la position destinee: ");
                    scanf("%d",&P2);
                   if (verif2(P2,P1))
                   {         moulin2(P2);
                             supp2(P1);
                             add2(P2);
                            switch(P2)
                            {
                     case 1:

           {
            A[0][0]='&';
            A[0][1]=A[0][0];

        break;}
         case 2:
        {

            A[0][21]='&';
            A[0][22]=A[0][21];

        break;}
         case 3:

           {
            A[0][42]='&';
            A[0][43]=A[0][42];

        break;}
         case 4:
{

            A[3][8]='&';
            A[3][9]=A[3][8];

        break;}
         case 5:
{


            A[3][21]='&';
            A[3][22]=A[3][21];

        break;}
         case 6:

          {

            A[3][34]='&';
            A[3][35]=A[3][34];

        break;}
         case 7:

           {

           A[6][12]='&';
            A[6][13]=A[6][12];

        break;}
              case 8:
{

            A[6][21]='&';
            A[6][22]=A[6][21];

        break;}

              case 9:

           {

           A[6][30]='&';
            A[6][31]=A[6][30];

        break;}

              case 10:

           {

           A[9][0]='&';
            A[9][1]=A[9][0];

        break;}

              case 11:

           {

            A[9][8]='&';
            A[9][9]=A[9][8];

        break;}

              case 12:

           {

           A[9][12]='&';
            A[9][13]=A[9][12];

        break;}
              case 13:
           {

            A[9][30]='&';
            A[9][31]=A[9][30];

        break;}

              case 14:

            {A[9][34]='&';
            A[9][35]= A[9][34];

        break;}

              case 15:

            {A[9][42]='&';
            A[9][43]= A[9][42];

        break;}

              case 16:

           {

    A[12][12]='&';
            A[12][13]= A[12][12];

        break;
           }
        case 17:
            {A[12][21]='&';
            A[12][22]= A[12][21];

        break;}

              case 18:

           {

            A[12][30]='&';
            A[12][31]=A[12][30];

        break;}

              case 19:

            {A[15][8]='&';
            A[15][9]=A[15][8];

        break;}

              case 20:

           {

            A[15][21]='&';
            A[15][22]=A[15][21];

        break;}

              case 21:
{

            A[15][34]='&';
            A[15][35]=A[15][34];

        break;}

              case 22:

           {

            A[18][0]='&';
            A[18][1]=A[18][0];

        break;}

              case 23:

           {

            A[18][21]='&';
            A[18][22]=A[18][21];

        break;}

              case 24:

            {A[18][42]='&';
            A[18][43]=A[18][42];

        break; }}
        grille();
        deplacement(1-joueur);
        } else
          Color(4,15);
                {printf(" ------ entrer une position destinee valide!!!!! ------\n");
                Color(0,15);
                deplacement(joueur);}}
   else {printf("Vous ne pouvez deplacer que VOS PIONS -_-\n");
          deplacement(joueur);}}
          }
          qui();}






void jeu(int joueur)
{
 while (notnuLL11() || notnuLL22())
{  deplacement(joueur);
}
who(s1,s2);}


int verif1(int p)
{
       if(B[p-1]==0)
           {
               return 1;
           }
        else {return 0;}


    }

int verif2(int P, int R)
{

        if ((C[P-1]!=0 && B[P-1]!=0) &&  (possible(R,P)))
           {
               return 1;
           }
        else {return 0;}


    }

int verif3(int e)
{

        if(C[e-1]==0)
           {
               return 1;
           }
        else {return 0;}


    }

int notnuLL11()
{

for (int i=0;i<24;i++)
{
    if (B[i]==0)
    {
        s1++;
    }}
if (s1==2)
    {
    return 0;
    }
    else {return 1;}
}


int notnuLL22()
{

for (int i=0;i<24;i++)
{
    if (C[i]==0)
    {
        s2++;
    }}
if (s2==2)
    {
    return 0;
    }
    else {return 1;}

}
void  who(int s1,int s2)
{
    if (s1>s2)
    {printf("%d YOU WIIIIIIN",ouf);}
    else {printf("%d YOU WIIIIIIN",1-ouf);}
}



void add1(int p)
{B[p-1]=0;}


void add2(int p)
 {C[p-1]=0;}

void supp1(int position)
{
B[position-1]=position;
switch(position)
{
case 1:
    {
     A[0][0]='0';
     A[0][1]='1';
     break;
    }
case 2:
    {
        A[0][21]='0';
        A[0][22]='2';
         break;
    }
case 3:
    {
        A[0][42]='0';
        A[0][43]='3';
         break;
    }
case 4:
    {
    A[3][8]='0';
    A[3][9]='4';
     break;}
case 5:
    {
        A[3][21]='0';
        A[3][22]='5';
         break;
    }
case 6:
    {
        A[3][34]='0';
        A[3][34]='6';
         break;
    }
case 7:
    {
        A[6][12]='0';
        A[6][13]='7';
         break;
    }
case 8:
    {
        A[6][21]='0';
        A[6][22]='8';
         break;
    }
case 9:
    {
        A[6][30]='0';
        A[6][31]='9';
         break;
    }
case 10:
    {
        A[9][0]='1';
        A[9][1]='0';
         break;
    }
case 11:
    {
        A[9][8]='1';
        A[9][9]='1';
         break;
    }
case 12:
    {
        A[9][12]='1';
        A[9][13]='2';
         break;
    }
case 13:
    {
        A[9][30]='1';
        A[9][31]='3';
         break;
    }
case 14:
    {
        A[9][34]='1';
        A[9][35]='4';
         break;
    }
case 15:
    {
        A[9][42]='1';
        A[9][43]='5';
         break;
    }
case 16:
    {
        A[12][12]='1';
        A[12][13]='6';
         break;
    }
case 17:
    {
        A[12][21]='1';
        A[12][22]='7';
         break;
    }
case 18:
    {
        A[12][30]='1';
        A[12][31]='8';
         break;
    }
case 19:
    {
        A[15][8]='1';
        A[15][9]='9';
         break;
    }
case 20:
    {
        A[15][21]='2';
        A[15][22]='0';
         break;
    }
case 21:
    {
        A[15][34]='2';
        A[15][35]='1';
         break;
    }
case 22:
    {
        A[18][0]='2';
        A[18][1]='2';
         break;
    }
case 23:
    {
        A[18][21]='2';
        A[18][22]='3';
         break;
    }
case 24:
    {
        A[18][42]='2';
        A[18][43]='4';
        break;
    }
}}
void ajout(int position,int joueur)
{
if (joueur==ouf)
                {
                    add1(position);
                }
else if (joueur==1-ouf)
                {
                    add2(position);
                }
}
void supp2(int position)
{
C[position-1]=position;
switch(position)
{
case 1:
    {
     A[0][0]='0';
     A[0][1]='1';
     break;
    }
case 2:
    {
        A[0][21]='0';
        A[0][22]='2';
         break;
    }
case 3:
    {
        A[0][42]='0';
        A[0][43]='3';
         break;
    }
case 4:
    {
    A[3][8]='0';
    A[3][9]='4';
     break;}
case 5:
    {
        A[3][21]='0';
        A[3][22]='5';
         break;
    }
case 6:
    {
        A[3][34]='0';
        A[3][34]='6';
         break;
    }
case 7:
    {
        A[6][12]='0';
        A[6][13]='7';
         break;
    }
case 8:
    {
        A[6][21]='0';
        A[6][22]='8';
         break;
    }
case 9:
    {
        A[6][30]='0';
        A[6][31]='9';
         break;
    }
case 10:
    {
        A[9][0]='1';
        A[9][1]='0';
         break;
    }
case 11:
    {
        A[9][8]='1';
        A[9][9]='1';
         break;
    }
case 12:
    {
        A[9][12]='1';
        A[9][13]='2';
         break;
    }
case 13:
    {
        A[9][30]='1';
        A[9][31]='3';
         break;
    }
case 14:
    {
        A[9][34]='1';
        A[9][35]='4';
         break;
    }
case 15:
    {
        A[9][42]='1';
        A[9][43]='5';
         break;
    }
case 16:
    {
        A[12][12]='1';
        A[12][13]='6';
         break;
    }
case 17:
    {
        A[12][21]='1';
        A[12][22]='7';
         break;
    }
case 18:
    {
        A[12][30]='1';
        A[12][31]='8';
         break;
    }
case 19:
    {
        A[15][8]='1';
        A[15][9]='9';
         break;
    }
case 20:
    {
        A[15][21]='2';
        A[15][22]='0';
         break;
    }
case 21:
    {
        A[15][34]='2';
        A[15][35]='1';
         break;
    }
case 22:
    {
        A[18][0]='2';
        A[18][1]='2';
         break;
    }
case 23:
    {
        A[18][21]='2';
        A[18][22]='3';
         break;
    }
case 24:
    {
        A[18][42]='2';
        A[18][43]='4';
        break;
    }
}}


void qui()
{
  if (((A[0][0]==A[0][21])&&(A[0][0]==A[0][42])&&(A[0][0]=='#')) || ((A[3][8]==A[3][21])&&(A[3][8]==A[3][34])&&(A[3][8]='#')) || ((A[6][12]==A[6][21]) &&(A[6][12]==A[6][30])&&(A[6][12]='#'))|| ((A[9][0]==A[9][8])&&(A[9][0]==A[9][12])&&(A[9][0]='#')) || ((A[9][30]==A[9][34])&&(A[9][30]==A[9][42])&&(A[9][30]='#')) || ((A[12][12]==A[12][21])&&(A[12][12]==A[12][30])&&(A[12][12]='#')) || ((A[15][8]==A[15][21])&&(A[15][8]==A[15][34])&&(A[15][8]='#')) || ((A[18][0]==A[18][21])&&(A[18][0]==A[18][42])&&(A[18][0] == '#')) ||((A[0][42]==A[9][42])&&(A[0][42]==A[18][42])&&(A[0][42]='#')) || ((A[3][34]==A[9][34])&&(A[3][34]==A[15][34])&&(A[0][42]='#')) || ((A[6][30]==A[9][30])&&(A[6][30]==A[12][30])&&(A[6][30]='#')) || ((A[0][21]==A[3][21])&&(A[0][21]==A[6][21])&&(A[0][21]='#')) || ((A[12][21]==A[15][21])&&(A[12][21]==A[18][21])&&(A[12][21]='#')) || ((A[6][12]==A[9][12])&&(A[6][12]==A[12][12])&&(A[6][12]='#')) || ((A[3][8]==A[9][8])&&(A[3][8]==A[15][8])&&(A[3][8]='#')) || ((A[0][0]==A[9][0])&&(A[0][0]==A[18][0])&&(A[0][0]=='#')))
        {
        printf("le joueur %d , Tu as forme un MOULIN *_* !tu peux enlever un pion de ton adversaire",ouf);
        printf("Entrer la position du pion que tu veux eliminer :p : ");
        scanf("%d",&pe1);

            if (C[pe1-1]==0)
            {
                B[pe1-1]=pe1;
                supp1(pe1);
            }
            else {printf("Entrer une position a eliminer valide");
                  qui();}}
    if (((A[0][0]==A[0][21])&&(A[0][0]==A[0][42])&&(A[0][0]=='&')) || ((A[3][8]==A[3][21])&&(A[3][8]==A[3][34])&&(A[3][8]='&')) || ((A[6][12]==A[6][21]) &&(A[6][12]==A[6][30])&&(A[6][12]='&'))|| ((A[9][0]==A[9][8])&&(A[9][0]==A[9][12])&&(A[9][0]='&')) || ((A[9][30]==A[9][34])&&(A[9][30]==A[9][42])&&(A[9][30]='&')) || ((A[12][12]==A[12][21])&&(A[12][12]==A[12][30])&&(A[12][12]='&')) || ((A[15][8]==A[15][21])&&(A[15][8]==A[15][34])&&(A[15][8]='&')) || ((A[18][0]==A[18][21])&&(A[18][0]==A[18][42])&&(A[18][0] == '&')) ||((A[0][42]==A[9][42])&&(A[0][42]==A[18][42])&&(A[0][42]='&')) || ((A[3][34]==A[9][34])&&(A[3][34]==A[15][34])&&(A[0][42]='&')) || ((A[6][30]==A[9][30])&&(A[6][30]==A[12][30])&&(A[6][30]='&')) || ((A[0][21]==A[3][21])&&(A[0][21]==A[6][21])&&(A[0][21]='&')) || ((A[12][21]==A[15][21])&&(A[12][21]==A[18][21])&&(A[12][21]='&')) || ((A[6][12]==A[9][12])&&(A[6][12]==A[12][12])&&(A[6][12]='&')) || ((A[3][8]==A[9][8])&&(A[3][8]==A[15][8])&&(A[3][8]='&')) || ((A[0][0]==A[9][0])&&(A[0][0]==A[18][0])&&(A[0][0]=='&')))
        {
   printf("le joueur %d , Tu as forme un MOULIN *_* !tu peux enlever un pion de ton adversaire",1-ouf);
            printf("Entrer la position du pion que tu veux eliminer :p : ");


            if (B[pe2-1]==0)
            {
                 C[pe2-1]=pe2;
                 supp2(pe2);
            }
            else {printf("Entrer une position a eliminer valide");
                  qui();}}
        jeu(ouf);}
void grille()
{
      for (int i=0;i<19;i++)
  {
      for (int j=0;j<44;j++){
      printf("%c",A[i][j]);
  }
 printf("\n");}}
int isNull()
{   int s=0;
    for (int i=0;i<24;i++)
       {
        if (tab[i]==0)
        {s++;}}
        return(s);}
//LA FONCTION STOP
int stop()
{
if (isNull()!=18)
         {return (1);}
if (isNull()==18)
    {
        return (0);
    }
}
void Quitter(int confirm)
{confirm=0;
printf(" ----- Vous voulez vraiment quitter? ------ \n1-Oui :( \n2-Non :) \n");
scanf("%d",&confirm);
if (confirm==1)
{system("exit");}

else if (confirm==2)
    {printf(" ******* Bienvenue encore une fois :D ******** \n");
    Menu();}
else
    {Quitter(confirm);}}

int allignee(int P1, int P2)
{   int R=0;

    for (int u=0; u<8; u++)
    {
        if (((H[u][0]==P1 && H[u][1]==P2) || ((H[u][1]==P1) && (H[u][2]==P2 || H[u][0]==P2)) || ((H[u][2]==P1) && (H[u][1]==P2))) || ((V[u][0]==P1 && V[u][1]==P2) || ((V[u][1]==P1) && (V[u][2]==P2 || V[u][0]==P2)) || ((V[u][2]==P1) && (V[u][1]==P2))))
            R++;
    }
    return R;
}



int  possible(int J1,int J2)
{
    if (allignee(J1,J2))
    {
        return 1;
    }
    else {return 0;}
}
void RegleDuJeu(int ch3)
{ch3=0;
printf("1-Retour vers le menu\n2-Quitter le jeu  \n");
scanf("%d",&ch3);
if (ch3==1)
{
    Menu();
}
else if (ch3==2)
{
    int confirmation1;
    Quitter(confirmation1);
}
else {RegleDuJeu(ch3);}}
//LA FONCTION HESITATION
void hesitation(int ch)
{

  printf("1-Commencer le jeu\n2-Retour vers le menu\n");
        scanf("%d",&ch);
if (ch==1)
  {
   printf("%s -> 0 :) \n%s -> 1 :) \n",nom1,nom2);
   Color(4,15);
   printf("Hmmmm ... \n");
   printf("%d a toi de commencer! :D \n",ouf);
   Color(0,15);
   printf("%d, TES PIONS SERONT  : ",ouf);
   printf("##\n");
   printf("%d, TES PIONS SERONT  : ",1-ouf);
   printf("&&\n");
   grille();
   jouer(ouf);
   grille();
   printf("Parfait *_* \n ----- Maintenant, Deplacez attentivement vos pions! -----\n");
   jeu(ouf);
}
else if (ch==2)
{
Menu();
}
else {hesitation(ch);
}}
void moulin1(int position)
{
    for (int i=0;i<8;i++)
        for (int j=0;j<3;j++)
    {
        if (H1[i][j]==position)
            H1[i][j]=0;
        if (V1[i][j]==position)
            V1[i][j]=0;
    }
}
void moulin2(int position)
{
    for (int i=0;i<8;i++)
        for (int j=0;j<3;j++)
    {
        if (H2[i][j]==position)
            H2[i][j]=0;
        if (V2[i][j]==position)
            V2[i][j]=0;
    }
}
int Moulin(int joueur)
{
    if (joueur==ouf)
    {
       {
       for (int i=0;i<8;i++)
            if ((((H1[i][0]==H1[i][1]) && (H1[i][0]==H1[i][2]) && (H1[i][0]==0)))  || ((V1[i][0]==V1[i][1]) && (V1[i][0]==V1[i][2]) && (V1[i][0]==0)))
                return 0;
         else {return 1;}}
    }
     if (joueur==1-ouf)
    {
        for (int i=0;i<8;i++)
          {
        if ((((H2[i][0]==H2[i][1]) && (H2[i][0]==H2[i][2]) && (H2[i][0]==0))) || ((V2[i][0]==V2[i][1]) && (V2[i][0]==V2[i][2]) && (V2[i][0]==0)))
                return 0;
         else {return 1;}}
    }
}
