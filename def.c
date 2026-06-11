#include "unite 4.h"
#define COLOR_DEFAULT (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)       
int nbvalide(char chaine[]){
    if (strlen(chaine) == 0)
        return 0;
        for (size_t i = 0; i < strlen(chaine); i++)  // Definition de la fonction nbvalide pour la gestion des saisies en int.
        {
            if (!isdigit(chaine[i])){
                return 0;
            }
        }
        
    
    return 1;
}
void setColor(int couleur)
{
    HANDLE ecran = GetStdHandle(STD_OUTPUT_HANDLE);    // definition de la fonction setcolor
    SetConsoleTextAttribute(ecran, couleur);                 
}
void printAnime(int x, int y, char* texte) {
    gotoxy(x, y);
    for (int i = 0; i < strlen(texte); i++) {   // definition de la fonction printanime
        printf("%c", texte[i]);
        Sleep(50); } 
    }
    void saisie (char*chaine,int taille){
        fgets(chaine,taille,stdin);
        size_t longeur = strlen(chaine);                // definition de la fonction saisie
        if(longeur > 0 && chaine[longeur - 1] == '\n'){
            chaine[longeur - 1] = '\0';
        }
    }
    void gotoxy(int abs, int ord){
    HANDLE ecran = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD repere;
    repere.X = abs;                                   //  definition de la fonction pour le positionnement 
    repere.Y = ord;
    SetConsoleCursorPosition(ecran, repere);
}
  int authentification() {    
  P: char NomUtilisateur[20];
    char MotDepasse[20];                                                            
    const char UtilisateurCorrect[]="ADMIN";
    const char MdpCorrect[]="projet8";
    int i = 0; 
    char ch; 
    int stat; 
   system("cls");
    gotoxy(40, 1); printf("**************** I D E N T I F I C A T I O N****************\n");        // definition de la fonction authentification 
    gotoxy(46, 2); printf("N O M  D'U T I L I S A T E U R : \n");
    gotoxy(50, 3); printf("P A S S W O R D : ");
    gotoxy(80, 2); scanf("%s",NomUtilisateur);
    gotoxy(69, 3); 
  while (i < 19)
    {
       ch = getch() ;
    if (ch == 13) {
       break;
    } else if(ch == 8)
       { if ( i > 0){ i-- ;
   printf("\b \b"); }
  } else { MotDepasse[i] = ch ;i++; printf("*");  
}
}
MotDepasse[i] = '\0';
   if (strcmp(NomUtilisateur,UtilisateurCorrect) == 0 && strcmp(MotDepasse,MdpCorrect) == 0 ){
       printf("\nconnexiom reussie !!.\n");
       return 1;}
        else {
            gotoxy(58, 6);
            printf(" IDENTIFIANT INCORRECT ."); 
        Sleep(2000); system("cls"); goto P; 
            return 0;
        }         
   }
int compare(const void*a, const void*b){
    const abonnee *abonneA = (const abonnee *)a;
    const abonnee *abonneB = (const abonnee *)b;                 //definition de la fonction pour le classement par ordre alphabetique
    int resultat = strcmp(abonneA->prenom, abonneB->prenom);
    if (resultat == 0) {
        return strcmp (abonneA->nom, abonneB->nom); }
        return resultat;
    } 
    void afficher(abonnee classe[],int n ){
         system("cls");
     gotoxy(60, 3);
       setColor(FOREGROUND_BLUE);
        printf("************ AFFICHAGE DES ABONNEES PAR ORDRE ALPHA.. ***************");
         gotoxy(60, 5);
        setColor(FOREGROUND_BLUE);                                 // definition de la fonction pour l'affichage par ordre aplabetique
        printf("prenom");
          gotoxy(80, 5);
        setColor(FOREGROUND_BLUE);
        printf("NOM");
        setColor(COLOR_DEFAULT);
        for(size_t i = 0; i < n ; i++)
        {
            gotoxy(60, 6 + i);
            printf("%s", classe[i].prenom );
            gotoxy(80, 6 + i);
            printf("%s", classe[i].nom);
        } 
    }
    int comparechiffre(const void*a, const void*b){
    const abonnee *abonneA = (const abonnee *)a;
    const abonnee *abonneB = (const abonnee *)b;
    int resultat = abonneA->numero_abonnement - abonneB->numero_abonnement;  // definition de la fonction pour le classement par ordre croissant de num.
    if (resultat == 0) {
        return strcmp (abonneA->nom, abonneB->nom); }
        return resultat;
    } 
    void affichercroissant(abonnee classe[],int n ){
         system("cls");
     gotoxy(60, 3);
       setColor(FOREGROUND_BLUE);
        printf("************AFFICHAGE DES ABONNEES PAR NUM CROISSANT ***************");
         gotoxy(60, 5);
        setColor(FOREGROUND_BLUE);
        printf("prenom");
          gotoxy(80, 5);
        setColor(FOREGROUND_BLUE);                                             // definition de la fonction pour l'affichage des abonnes par ordre croissant de num 
        printf("NOM");
          gotoxy(100, 5);
        setColor(FOREGROUND_BLUE);
        printf("NUMERO D'ABONNEMENT");
        setColor(COLOR_DEFAULT);
        for(size_t i = 0; i < n ; i++)
        {
            gotoxy(60, 6 + i);
            printf("%s", classe[i].prenom );
            gotoxy(80, 6 + i);
            printf("%s", classe[i].nom);
            gotoxy(100, 6 + i);
            printf("%d", classe[i].numero_abonnement);

        } 
    }

