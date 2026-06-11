#ifndef GROUPE3_H_INCLUDED
#define GROUPE3_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

void setColor(int couleur); // declaration de la fonction qui gere les couleurs
void gotoxy(int abs, int ord); // declaration de la fonction qui gere le positionnement
void printAnime(int , int , char*); // declaration de la fonction qui gere les dactilots
void saisie(char*,int); // declaration de la fonction qui gere  les bugs overflow ou depassement de tampon
typedef struct{
    int numero_abonnement;
    char nom[40];
    char prenom[40];
    char adresse[40];                   // structure des abonnés
    char categorie[40];
    int plan_de_location;
    int nb_livres_empruntee;
}abonnee; 
typedef struct{
    int code;
    char titre [40];                    // structure des livres 
    int nb_total_exemplaire;
    int nb_exemplaire_dispo;
}livre; 
int nbvalide(char chaine[]); // declaration de la fonction qui gere les saisies pour les stockages de type int.
int authentification() ;// declaration de la fonction authentification qui gere l'acces au logiciel
int compare(const void*a , const void *b); // declaration de la fonction qui gere le tri des abonnés par ordre alphabetique 
void afficher(abonnee classe[],int n);// declaration de la fonction qui affiche les abonnes par ordre alphabetique
int comparechiffre(const void*a , const void *b); // declaration de la fonction qui gere le tri des abonnés par ordre croissant de num
void affichercroissant(abonnee classe[],int n);// declaration de la fonction qui affiche les abonnes par ordre croissant de num
#endif // GROUPE3_H_INCLUDED 
