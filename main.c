#include <stdio.h>
#include <string.h>
#include "unite 4.h" 
#define COLOR_DEFAULT (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)       
int main()
{
 if (authentification() == 0){   // Appel a la fonction authentification pour l'acces au logiciel
       return 0;
    } 
    setlocale(LC_ALL, "fr_FR.UTF-8");
    system("cls");
    int choix, nbabonnee = 0;
    abonnee * classe = NULL;
    livre * casier = NULL;
    int nbplace;
    int valide = 0;
    char buffer[50]; 
    int gere;
    int num;
    int gerer;
    int nb_emprunt = 0;
    int nblivre = 0;
    int nb2place = 0;
    int effectif = 0;
    int b = 0;              // LA DESCRIPTION DU PROJET 
    printAnime(25,2,"BIENVENUE DANS LA BIBLIOTHEQUE DE L'INSTITUT SUPERIEUR DE L'INFORMATIQUE ET DE LA COMMUNICATION ");
    printAnime(42,5," COMMENÇANT PAR LA DESCRIPTION DU PROGRAMME ON A : " ); Sleep(500);
    printAnime(16,7," CE PROGRAMME PORTANT SUR LA GESTION D'UNE BIBLIOTHEQUE NOUS PERMET DE GERER LES ABONNEES ET LES LIVRES DE LA BIBLIOTHEQUE!!!. " );
    printAnime(42,9," ET EN ALLANT VERS LA PRESENTATION DES AUTEURS NOUS AVONS : " );  Sleep(500);
    printAnime(55,11," 1- SOULEYMANE BALDE ");
    printAnime(55,13," 2- AMADOU KABIROU BAH ");
    printAnime(55,15," 3- MAMADOU MOUCTAR DOUMBOUYA ");
    printAnime(55,17," 4- RAGUIATOU BANGOURA  ");
    printAnime(55,19," 5- BOUBACAR POTTY BALDE ");
                Sleep(400);
    printAnime(42,22," BIENVENUE A NOUVEAU CHER UTILISATEUR !!!!");

getch (); system("cls");
    
    menu :
    system("cls");
    gotoxy(60, 5);
    setColor(FOREGROUND_BLUE);
    printf("=============== MENU GENERAL =================");
    gotoxy(60, 6);
    setColor(FOREGROUND_BLUE);
    printf("= 1- GESTION DES ABONNEES                    =");
    gotoxy(60, 7);                                                        // LE MENU GENERAL
    setColor(FOREGROUND_BLUE);
    printf("= 2- GESTION DES LIVRES                      =");
    gotoxy(60, 8);
    setColor(FOREGROUND_BLUE);
    printf("= 0- Quitter                                 =");
    gotoxy(60, 9);
    setColor(FOREGROUND_BLUE);
    printf("===============================================");
    setColor(COLOR_DEFAULT);
    gotoxy(60, 10);
    printf("*** Votre choix :                                                                                   ");
    gotoxy(77, 10);
    scanf("%s", buffer);
    if (nbvalide(buffer)) {
        sscanf(buffer, "%d", &gere);
    }
    switch (gere)
    {
    case 1: { 
        if(nbplace == 0){
 A : gotoxy(60, 11) ; printf("Entrer le nombre de place neccesaire pour les abonnees : ");
     while(!valide){
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if(sscanf(buffer, "%d", &nbplace) == 1 && nbplace > 0)
            {
                valide = 1;
            } else { system("cls"); goto A; 
     }
    }


}   }
menu1 :
    system("cls");
    setColor(FOREGROUND_BLUE);                                                   // MENU POUR LES ABONNéS 
    gotoxy(60, 5);
    printf("========================= MENU =========================");
    gotoxy(60, 6);
    setColor(FOREGROUND_BLUE);
    printf("= 1- Ajout d'un abonne                                 =");             
    gotoxy(60, 7);
    setColor(FOREGROUND_BLUE);
    printf("= 2- Affichage de tous les abonnees                    =");
    gotoxy(60, 8);
    printf("= 3- Affichage des abonnees par ordre alphabetique     =");
    gotoxy(60, 9);
    printf("= 4- Affichage des abonnees par ordre croissant de num =");
    gotoxy(60, 10);
    setColor(FOREGROUND_BLUE);
    printf("= 5- Affichage des abonnees par identifiant            =");
    gotoxy(60, 11);
    setColor(FOREGROUND_BLUE);
    printf("= 6- Affichage des abonnees en etat d'emprunt          =");
    gotoxy(60, 12);
    setColor(FOREGROUND_BLUE);
    printf("= 7- menu suppression & modification                   =");
    gotoxy(60, 13);
    setColor(FOREGROUND_BLUE);
    printf("= 0- Quitter                                           =");
    gotoxy(60, 14);
    setColor(FOREGROUND_BLUE);
    printf("========================================================");
   E: gotoxy(60, 15);
    setColor(COLOR_DEFAULT);
    printf("*** Votre choix :                                                                                      ");
    gotoxy(79, 15);
      scanf("%s", buffer);
    if (nbvalide(buffer)) {
        sscanf(buffer, "%d", &choix);
    } else{ 
        setColor(FOREGROUND_RED);
        gotoxy( 78, 15);
            printf("Entree invalide. Veuillez entrer un nombre valide.\n");
            Sleep(2000); setColor(COLOR_DEFAULT);
            goto E;}
    switch(choix)
    {
    case 1 :
    { 
        if(nbabonnee < nbplace  )
        { 
            int num_saisie;
       do { gotoxy(60, 16);
        printf("Donner le numero d'abonnement :                                                                    ");
       gotoxy(93, 16);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {         // Appel a la fonction nbvalide pour gerer la saisie
            sscanf(buffer, "%d", &num_saisie);
        } else {
        gotoxy(92, 16);
           setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
        
        }   } while (!nbvalide(buffer));
        for(size_t i = 0; i < nbabonnee; i++)    // Boucle pour la verification du code afin qu'il soit unique 
        {
            if(classe[i].numero_abonnement == num_saisie)
            {
                gotoxy(60, 16);
                printf("Le numero d'abonnement existe deja!!!!!");
                Sleep(2000);system("cls"); 
                goto menu1;
            } else {
                continue;}
        }
        nbabonnee++;
        classe = realloc(classe, nbabonnee * sizeof(abonnee));
       classe[nbabonnee - 1].numero_abonnement = num_saisie;
       while (getchar()!= '\n');
        gotoxy(60, 17);    
        printf("Donner le nom : ");
        saisie( classe[nbabonnee - 1].nom , 40);   //Appel a la fonction saisie pour la saisie et la securité

        gotoxy(60, 18);
        printf("Donner le prenom : ");
        saisie( classe[nbabonnee - 1].prenom , 40); //Appel a la fonction saisie
        gotoxy(60, 19);
        printf("Donner son adresse : ");
        saisie( classe[nbabonnee - 1].adresse ,40 ); //Appel a la fonction saisie
      C: do{ gotoxy(60, 20);
        printf("Donner le plan de location ( 2/3 livres ):                                                                         ");
        gotoxy(104, 20);
         scanf("%s",buffer); 
         if (nbvalide(buffer))  // Appel a la fonction nbvalide
         {
            sscanf(buffer, "%d", &num_saisie);
         }else {
        gotoxy(103, 20);
         setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
        }       } while (!nbvalide(buffer));
         
            if ( num_saisie > 3 || num_saisie < 0 ){
                gotoxy(103, 20);
                setColor(FOREGROUND_RED );
                printf("Erreur!!!"); Sleep(1000); 
                setColor(COLOR_DEFAULT);
                goto C;
                }else 
      classe[nbabonnee - 1].plan_de_location= num_saisie;
     W: do{ gotoxy(60, 21);
        printf("Donner le nombre de livre empruntee:                                                                                         ");
        gotoxy(98, 21);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {   // Appel a la fonction nbvalide
            sscanf(buffer, "%d", &num_saisie);
            if(num_saisie != 0) nb_emprunt++;
        } else {
            gotoxy(97, 21);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
          Sleep(2000);
            setColor(COLOR_DEFAULT);
        }    } while(!nbvalide(buffer));
         if ( num_saisie >  classe[nbabonnee - 1].plan_de_location ){
                gotoxy(98, 21);
                setColor(FOREGROUND_RED );
                printf("Erreur!!! Le nombre de livre empruntee ne peut pas depasser le plan de location"); Sleep(3000); 
                setColor(COLOR_DEFAULT);
                goto W; 
                }else
        classe[nbabonnee - 1].nb_livres_empruntee = num_saisie;
        while (getchar() != '\n');
        gotoxy(60, 22);
        printf("Donner la categorie de l'abonnee ( Etudiant / enseignant / ... ) :  ");
        saisie( classe[nbabonnee - 1].categorie ,40 );   // Appel a la fonction saisie
        gotoxy(60, 23);
            setColor(FOREGROUND_GREEN);
        printf("Abonnee enregistree avec succes!!!!!");
        Sleep(3000);
        setColor(COLOR_DEFAULT);
        goto menu1;
        } else {system("cls");
        gotoxy(60, 16);
        setColor(FOREGROUND_RED); 
        printf("Desolee vous avez atteint la limite du nombre d'abonnee dans la bibliotheque !!!!!");
     Sleep(4000);
    setColor(COLOR_DEFAULT);
        goto menu1;}
        
    } // FIN DE CASE 1 SWITCH MENU1 POUR LES ABONNES  
    case 2:
    { 
        if (nbabonnee >=1 ){
        b = 0;
        effectif = 0;
        system("cls");
        gotoxy(60, 3);
       setColor(FOREGROUND_BLUE);
        printf("********************* AFFICHAGE DES ABONNEES ***************************");
        gotoxy(60, 5);
        setColor(FOREGROUND_BLUE);
        printf("prenom");
        gotoxy(80, 5);
        setColor(FOREGROUND_BLUE);
        printf("NOM");
        setColor(COLOR_DEFAULT);
        for(size_t i = 0; i < nbabonnee ; i++)
        {
            gotoxy(60, 6 + i);
            printf("%s", classe[i].prenom );
            gotoxy(80, 6 + i);
            printf("%s", classe[i].nom);
            b+=i;
            
        }
        effectif += nbabonnee;
            gotoxy(64, 9 + b);
        printf("L'effectif total des abonnee dans la bibliotheque est de : %d ", effectif);
        getch();
        goto menu1; } else system("cls");
        gotoxy(35, 8); printf("veillez entrer au moins un abonnee pour l'affichage :  ");
      Sleep(3000);goto menu1;
    } // FIN DE CASE 2 SWICTH MENU1 POUR LES ABONNES
    case 3 : 
    {
      if (classe == NULL) {
    printf("Erreur d'allocation de memoire.\n");
    return 1;
} 
    qsort(classe, nbabonnee, sizeof(abonnee), compare);   // Appel a la fonction qsort ou quicksort pour le tri des abonnes
   afficher(classe, nbabonnee);                           // Appel a la fonction afficher pour l'affichage des abonnes par ordre alphabetique 
    getch();
    goto menu1;
}  
     // FIN DE CASE 3 SWICTH MENU1 POUR LES ABONNES 
case 4 :
{
    qsort(classe, nbabonnee, sizeof(abonnee), comparechiffre); // Appel a la fonction qsort ou quicksort pour le tri des abonnes
    affichercroissant(classe, nbabonnee);                       // Appel a la fonction afficher pour l'affichage des abonnes par ordre croissant de num
    getch();
    goto menu1;
}  // FIN DE CASE 3 SWICTH MENU1 POUR LES ABONNES 
    case 5 :
    { 
         if(nbabonnee >= 1) {
        int id_recherche;
        bool trouve = false;
        system("cls");
        gotoxy (60, 5);
        printf("=== RECHERCHE D'UN ABONNE ===");
        gotoxy(60,7);
        printf("Entrer le numero d'abonnement :  ");
        scanf("%d",&id_recherche);
        for(size_t i = 0;  i < nbabonnee; i++){
            if (classe[i].numero_abonnement == id_recherche ){
                trouve = true;
                system("cls");
                gotoxy(55, 5);
                printf("====================INFORMATION DE L'ABONNE====================");
                gotoxy(60,  8);
                printf("Numero           : %d ",classe[i].numero_abonnement);
                gotoxy(60, 10);
                printf("Nom              : %s",classe[i].nom);
                gotoxy(60,  12);                                                                   // CASE 5 POUR LA RECHERCHE D'UN ABONNE
                printf("Prenom           : %s ",classe[i].prenom);
                gotoxy(60, 14);
                printf("Adresse          : %s",classe[i].adresse);
                gotoxy(60, 16);
                printf("plan de location : %d",classe[i].plan_de_location);
                gotoxy(60, 18);
                printf("categorie        : %s",classe[i].categorie);
                gotoxy(60, 20);
                printf("Etat d'emprunt   : %d",classe[i].nb_livres_empruntee);
            }
        }
        if (!trouve )
        {
            gotoxy(91, 7);
                setColor(FOREGROUND_RED);
            printf(" Aucun abonnee ne porte le numero %d !",id_recherche);
            Sleep(3000);
            setColor(COLOR_DEFAULT);
        }
        getch();
        goto menu1; } else system("cls");
        gotoxy(35, 8); 
        setColor(FOREGROUND_RED);
        printf("veillez entrer au moins un abonnee pour la recherche :  "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto menu1;
    }  // FIN DE CASE 5 SWICTH MENU1 POUR LES ABONNES 

    case 6:
    {
         if(nbabonnee >= 1) {
         if(nb_emprunt > 0) {
        int k = 0;
        int p = 0;
            system("cls");  
        gotoxy(60, 3);
       setColor(FOREGROUND_BLUE);   
        printf("************AFFICHAGE DES ABONNEES EN ETAT D'EMPRUNT*************");
         gotoxy(60, 5);
        setColor(FOREGROUND_BLUE);
        printf("prenom");
          gotoxy(80, 5);
        setColor(FOREGROUND_BLUE);                                               //CASE 6 POUR L'AFFICHAGE DES ABONEES EN ETAT D'EMPRUNT 
        printf("NOM");
          gotoxy(100, 5);
        setColor(FOREGROUND_BLUE);
        printf("nombre de livre empruntee");
        setColor(COLOR_DEFAULT);
        for(size_t i = 0; i < nbabonnee; i++)
       {
        if (classe[k].nb_livres_empruntee > 0)
        {
            gotoxy(60, 6 + p);
            printf("%s", classe[k].prenom );
            gotoxy(80, 6 + p);
            printf("%s", classe[k].nom);
            gotoxy(100, 6 + p);
            printf("%d", classe[k].nb_livres_empruntee);
            p++;
        }
        k++;
       }

        getch();
        goto menu1;
    } else system("cls");
        gotoxy(65, 16); 
        setColor(FOREGROUND_RED);
        printf("Aucun abonnee en etat d'emprunt :  "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto menu1; 
    }  else system("cls");
        gotoxy(35, 8); 
        setColor(FOREGROUND_RED);
        printf("veillez entrer au moins un abonnee pour l'affichage :  "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto menu1;
    }  // FIN DE CASE 6 SWICTH MENU1 POUR LES ABONNES 
    case 7:{
        system("cls");
 menu3: gotoxy(60, 5);
    setColor(FOREGROUND_BLUE);
    printf("========================= MENU SUP & MODIF============================");
    gotoxy(60, 6);
    setColor(FOREGROUND_BLUE);
    printf("= 1- SUPPRIMER UN ABONNEE                                            =");
    gotoxy(60, 7);
    setColor(FOREGROUND_BLUE);                                                              // CASE 7 MENU SUP & MODIF DES ABONNEES
    printf("= 2- MODIFIER UN ABONNEE                                             =");
    gotoxy(60, 8);
    setColor(FOREGROUND_BLUE);
    printf("= 0- Quitter                                                         =");
    gotoxy(60, 9);
    setColor(FOREGROUND_BLUE);
    printf("======================================================================");
    setColor(COLOR_DEFAULT);
   do { gotoxy(60, 10);
    printf("*** Votre choix :                                                                                   ");
    gotoxy(79, 10);
    scanf("%s", buffer);
    if (nbvalide(buffer)) {
        sscanf(buffer, "%d", &gerer);
    }else {
                gotoxy(78, 10);
                    setColor(FOREGROUND_RED );
                printf("Entree invalide. Veuillez entrer un nombre valide.");
                Sleep(2000);
            setColor(COLOR_DEFAULT);
    
 } } while(!nbvalide(buffer));
 
    switch (gerer)
    {
    case 1:{

        if (nbabonnee >= 1){
        int id_supp;
        bool trouve = false;
        bool valide = false;
       do { system("cls");
        gotoxy(60, 5);
        printf("============== SUPPRESSION D'UN ABONNE ============");
        gotoxy(60,6);
        printf("Entrer le numero d'abonnement de l'abonnee a supprimer :                                                             ");
      gotoxy(120, 6);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &id_supp);                                       //  CASE 1 DANS MENU SUP $ MODIF POUR LA SUPPRESSION 
            valide = true;
        } else {
            gotoxy(119, 6);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.\n");
            Sleep(2000);
            setColor(COLOR_DEFAULT);}
        } while (!valide);

        for(size_t i = 0; i < nbabonnee; i++){
            if (classe[i].numero_abonnement == id_supp){
                if (classe[i].nb_livres_empruntee == 0)
                {
                trouve = true;
                for(size_t j = i; j < nbabonnee - 1; j++){
                    classe[j] = classe[j + 1];
                }
                nbabonnee--;
                classe = realloc(classe, nbabonnee * sizeof(abonnee));
                gotoxy(60, 7);
                setColor(FOREGROUND_GREEN);
                printf("Abonnee supprimee avec succes!!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto menu3;
            } else { gotoxy(119, 6);
            setColor(FOREGROUND_RED);
            printf("l'abonnee %d est en etat d'emprunt ",id_supp);
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu3;}
        } 
    }
        if (!trouve)
            {
            gotoxy(119, 6);
            setColor(FOREGROUND_RED);
            printf("Aucun abonnee ne porte le numero %d !! ",id_supp);
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu3;
        } 
 } else system("cls");
        setColor(FOREGROUND_RED);
         gotoxy(65, 8);  
        printf("veillez entrer au moins un abonnee pour la suppression :  "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto menu3;
        
    }  // FIN DE CASE 1 SWICTH MENU SUP & MODIF POUR LES ABONNES 
    case 2 :{
         if( nbabonnee >= 1) 
        {
        size_t position;
        bool existe = false;
        int choixmodif;
        int searchnumero_abonnement; 
      do{  system("cls");
          gotoxy(60, 5);
        printf("============= MODIFICATION D'UN ABONNE ============");
        gotoxy(60, 6);
        printf("Donner le numero d'abonnement de l'abonnee a modifier :                                                                    ");
        gotoxy(120, 6);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &searchnumero_abonnement);                  //  CASE 2 DANS MENU SUP $ MODIF POUR LA MODIFICATION
        } else {
            gotoxy(119, 6);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
            
        }           } while(!nbvalide(buffer));
        for(size_t i = 0; i < nbabonnee; i++)
        {
            if(classe[i].numero_abonnement == searchnumero_abonnement)
            {
                position = i;
                existe = true;
                break;
            } 
        }
                if(!existe)
                {
                    gotoxy(119, 6);
                     setColor(FOREGROUND_RED );
                    printf("L'abonnee à modifier n'existe pas!!!!!!");
                    Sleep(3000);
                    setColor(COLOR_DEFAULT);
                    system("cls");
                    goto menu3; 
                }
                else {
modif :
            system("cls");                                                  // MENU MODIF POUR LA MODIFICATION
            gotoxy(60, 5);
            printf("=============== Que voulez vous Modifier ? ===============");
            gotoxy(60, 6);
            printf("= 1- numero d'abonnement                                 =");
            gotoxy(60, 7);
            printf("= 2- Nom                                                 =");
            gotoxy(60, 8);
            printf("= 3- Prenom                                              =");
            gotoxy(60, 9);
            printf("= 4- Adresse                                             =");
            gotoxy(60, 10);
            printf("= 5- Plan de location                                    =");
            gotoxy(60, 11);
            printf("= 6- Nombre de livres empruntés                          =");
            gotoxy(60, 12);
            printf("= 7- categorie                                           =");
            gotoxy(60, 13);
            printf("= 0- Retour                                              =");
            gotoxy(60, 14);
            printf("==========================================================");
           mo: gotoxy(60, 15);
            printf("*** Votre choix :                                                                  ");
            gotoxy(77, 15);
            scanf("%s", buffer);
            if (nbvalide(buffer)) {
                sscanf(buffer, "%d", &choixmodif);
            } else {
                gotoxy(76, 15);
                    setColor(FOREGROUND_RED );
                printf("Entree invalide. Veuillez entrer un nombre valide.");
                Sleep(2000);
            setColor(COLOR_DEFAULT);
                goto mo;
            }
            switch(choixmodif)
            {
            case 1 :                                     // CASE 1 DANS MENU MODIF 
              do{  gotoxy(60, 16);
               printf("Donner le nouveau Numero d'Abonnement :                                                                         ");
              gotoxy(101, 16);
               scanf("%s", buffer);
                if (nbvalide(buffer)) {
                    sscanf(buffer, "%d", &classe[position].numero_abonnement);
                } else {
                    gotoxy(100, 16);
                    setColor(FOREGROUND_RED );
                    printf("Entree invalide. Veuillez entrer un nombre valide.");
                    Sleep(2000);
                    setColor(COLOR_DEFAULT);
                 
                }           } while(!nbvalide(buffer));
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Numero d'Abonnement modifier avec succes!!!!");
                Sleep(3000);
                    setColor(COLOR_DEFAULT);
                goto modif;
            case 2 :                                                    // CASE 2 DANS MENU MODIF

                gotoxy(60, 16);
                printf("Donner le nouveau nom : ");
                 scanf("%s",classe[position].nom);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Nom modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modif;
            case 3 :                                                   // CASE 3 DANS MENU MODIF

                gotoxy(60, 16);
                printf("Donner le nouveau prenom : ");
               scanf("%s",classe[position].prenom);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Prenom modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modif;
            case 4 :                                                 // CASE 4 DANS MENU MODIF                 
                gotoxy(60, 16);
                printf("Donner la nouvelle Adresse : ");
                scanf("%s",classe[position].adresse);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Adresse modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modif;
            case 5 : {                                               // CASE 5 DANS MENU MODIF
            bool new_plan = false;
              do{ gotoxy(60, 16);
                printf("Donner le nouveau Plan de location ( 2 /3 livres ) :                                                                        ");
              gotoxy(114, 16);
                scanf("%s", buffer);
                if (nbvalide(buffer)) {
                    sscanf(buffer, "%d", &num);
                    if (num > 3 || num < 0) {
                        gotoxy(113, 16);
                            setColor(FOREGROUND_RED );
                        printf("nombre invalide !!!!"); Sleep(2000);
                        setColor(COLOR_DEFAULT);  
                        goto modif;  
                    }
                    else {
                        classe[position].plan_de_location = num;
                        num = 0;
                    } new_plan = true;
                } else {
                    gotoxy(113, 16);
                    setColor(FOREGROUND_RED );
                    printf("Entree invalide. Veuillez entrer un nombre valide.");
                    Sleep(2000);
                    setColor(COLOR_DEFAULT);
                }  } while(!new_plan);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Plan de location modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modif;
            }
            case 6 :{                                           // CASE 6 DANS MENU MODIF
            system("cls");
      setColor(FOREGROUND_RED);
      gotoxy(65, 8); 
      printf("Oupss erreur impossible de modifier le nombre de livre empruntés");
      Sleep(3000);
      setColor(COLOR_DEFAULT);
      goto modif;}
          
                case 7:                                           // CASE 7 DANS MENU MODIF
                {
                gotoxy(60, 16);
                printf("Donner la nouvelle categorie :  ");
                 gotoxy(93, 16);
                saisie(classe[position].categorie,40);
                 setColor(FOREGROUND_GREEN);
                gotoxy(60, 17);
                printf("Nouvelle categorie modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modif;
                }
               case 0 :                                     // CASE 0 DANS MENU MODIF      
               system ("cls");
                goto menu3;
            } // FIN DE SWICTH DANS MODIF 
        } //FIN DE ELSE IF(!EXISTE)
    } else 
      system("cls");
      setColor(FOREGROUND_RED);
      gotoxy(65, 8); 
      printf("veillez entrer au moins un abonnee pour la modification :  ");
      Sleep(3000);
      setColor(COLOR_DEFAULT);
      goto menu3;
    } // FIN DE CASE 2 SWICTH MENU SUPP. & MODIF.
    case 0:
    {
        goto menu1; 

    }
    default :
        goto menu1;
    } //FIN DE SWICTH MENU SUPP. & MODIF.
} // FIN DE CASE 7 SWICTH MENU1 POUR LES ABONNES .    
    case 0 :{ 
        system("cls");
       gotoxy(65,8); printf("Merci d'avoir utiliser notre programme!!!!!"); Sleep(3000);
       goto menu;
    } // FIN DE CASE 0 SWICTH MENU1 POUR LES ABONNES  
    default :
        goto menu1;
    }// FIN DE SWICTH MENU1 POUR LES ABONNES 
}  // FIN DU GRAND CASE 1 SWICTH MENU POUR LES ABONNES!!!!!!!! 
   case 2: {                                                          //  DEBUT DU GRAND CASE 2 MENU PRINCIPAL POUR LA GESTION DES LIVRES !!!!!
    system("cls");
    if( nb2place  == 0){
    valide = 0;
 B : gotoxy(60, 11) ; printf("Donner le nombre de livre pouvant etre stocké dans la bibliothèque  : ");
     while(!valide){
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if(sscanf(buffer, "%d", &nb2place) == 1 && nb2place > 0)
            {
                valide = 1;
            } else { system("cls"); goto B; 
     }
    }
} }
int nb2livre = 0;
menu1l :
    system("cls");
    setColor(FOREGROUND_BLUE);                                            // MENU1L POUR LES LIVRES 
    gotoxy(60, 1);
    printf("========================= MENU =========================");
    gotoxy(60, 2);
    setColor(FOREGROUND_BLUE);
    printf("= 1- Ajout d'un livre                                  =");
    gotoxy(60, 3);
    setColor(FOREGROUND_BLUE);
    printf("= 2- Affichage de tous les livres                      =");
    gotoxy(60, 4);
    setColor(FOREGROUND_BLUE);
    printf("= 3- Recherche d'un livre                              =");
    gotoxy(60, 5);
    setColor(FOREGROUND_BLUE);
    printf("= 4- Affichage des livres disponible                   ="); 
    gotoxy(60, 6);
    setColor(FOREGROUND_BLUE);
    printf("= 5- Retrait d'un livre                                =");   
    gotoxy(60, 7);
    setColor(FOREGROUND_BLUE);
    printf("= 6- Dépot d'un livre                                  =");   
    gotoxy(60, 8);
    setColor(FOREGROUND_BLUE);
    printf("= 7- Modifier les data d'un livre                      =");   
     gotoxy(60, 9);
    setColor(FOREGROUND_BLUE);
    printf("= 8- Supprimer un livre                                =");   
    gotoxy(60, 10);
    setColor(FOREGROUND_BLUE);
    printf("= 0- Quitter                                           =");
    gotoxy(60, 11);
    setColor(FOREGROUND_BLUE);
    printf("========================================================");
   do{ gotoxy(60, 12);
    setColor(COLOR_DEFAULT);
    printf("*** Votre choix :                                                                                      ");
    gotoxy(79, 12);
      scanf("%s", buffer);
    if (nbvalide(buffer)) {
        sscanf(buffer, "%d", &choix);
    } else{ 
        setColor(FOREGROUND_RED);
        gotoxy( 78, 12);
            printf("Entree invalide. Veuillez entrer un nombre valide.\n");
            Sleep(2000); setColor(COLOR_DEFAULT);
            }
        } while (!nbvalide(buffer));
        
    switch(choix)   // SWITCH MENU1L POUR LES LIVRES !!!!
    {
    case 1 :                                                      // DEBUT DE CASE 1 POUR L'AJOUT D'UN LIVRE
    { 
        int recup;
        if(nblivre < nb2place  )
        { 
             nblivre++;
             nb2livre++;
            int num_saisie;
            casier = realloc(casier, nblivre* sizeof(livre));    
          
       do { gotoxy(60, 13);
        printf("Donner le code du livre  :                                                                    ");
       gotoxy(87, 13);
        scanf("%s", buffer);
       if (nbvalide(buffer)) {
        sscanf(buffer, "%d", &num_saisie);
        } else {
        gotoxy(86, 13);
           setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
        
        }   } while (!nbvalide(buffer));
        for(size_t i = 0; i < nblivre; i++)
        {
            if( casier[i].code == num_saisie  )
            {
                gotoxy(60, 13);
                printf("Le code existe deja!!!!!            ");
                Sleep(2000);system("cls"); 
                goto menu1l;
            } 
        }
       casier[nblivre - 1].code = num_saisie;
      
       while (getchar()!= '\n');
        gotoxy(60, 14);    
        printf("Donner le titre : ");
        saisie( casier[nblivre - 1].titre, 40); 
      C1:  do{ gotoxy(60, 15);
        printf("Donner le nombre total d'exemplaire :                                                                         ");
        gotoxy(101, 15);
         scanf("%s",buffer); 
         if (nbvalide(buffer))
         {
            sscanf(buffer, "%d", &num_saisie);  recup = num_saisie;
         }else {
        gotoxy(100, 15);
         setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
        }       } while (!nbvalide(buffer));
         
            if ( num_saisie < 0 ){
                gotoxy(103, 15);
                setColor(FOREGROUND_RED );
                printf("Erreur!!!"); Sleep(1000); 
                setColor(COLOR_DEFAULT);
                 num_saisie = 0; goto C1;
                }else 
    casier[nblivre - 1].nb_total_exemplaire = num_saisie;
       num_saisie = 0;
     T: do{ gotoxy(60, 16);
        printf("Donner le nombre d'exemplaire dispo :                                                                                         ");
        gotoxy(99, 16);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &num_saisie);
        } else {
            gotoxy(97, 16);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
          Sleep(2000);
            setColor(COLOR_DEFAULT);
        }    } while(!nbvalide(buffer));
         if ( num_saisie < 0 || num_saisie > recup  ){
                gotoxy(98, 16);
                setColor(FOREGROUND_RED );
                printf("Erreur!!!"); Sleep(1000); 
                setColor(COLOR_DEFAULT);
                goto T;} 
        casier[nblivre- 1].nb_exemplaire_dispo = num_saisie;
              while (getchar() != '\n');
            gotoxy(60, 17);
            setColor(FOREGROUND_GREEN);
        printf("livre ajouter avec succes!!!!!");
        Sleep(3000);
        setColor(COLOR_DEFAULT);
        goto menu1l;
        } else {system("cls");
        gotoxy(60, 16);
        setColor(FOREGROUND_RED); 
        printf("Desolee vous avez atteint la limite du nombre de livre dans la bibliotheque !!!!!");
     Sleep(4000);
    setColor(COLOR_DEFAULT);
        goto menu1l;}
        
    } // FIN DE CASE 1 POUR L'AJOUT D'UN LIVRE 
    case 2:                                                   // DEBUT DE CASE 2 POUR L'AFFICHAGE DE TOUS LES LIVRES 
    { 
        effectif = 0;
        b = 0;
        if (nblivre >= 1 ){
        system("cls");
        gotoxy(60, 3);
       setColor(FOREGROUND_BLUE);
        printf("********************* AFFICHAGE DES LIVRES *****************************");
        gotoxy(60, 5);
        setColor(FOREGROUND_BLUE);
        printf("CODE ");
        gotoxy(80, 5);
        setColor(FOREGROUND_BLUE);
        printf("TITRE ");
         gotoxy(100, 5);
        setColor(FOREGROUND_BLUE);
        printf("NB_ TOTAL D'EXEMPLAIRE ");
        setColor(COLOR_DEFAULT);
                for(size_t i = 0; i < nblivre ; i++)
        {
            gotoxy(60, 6 + i);
            printf("%d", casier[i].code );
            gotoxy(80, 6 + i);
            printf("%s", casier[i].titre);
            gotoxy(110, 6 + i);
            printf("%d", casier[i].nb_total_exemplaire);
            b+=i;
            
        }
        getch();
        goto menu1l; } else system("cls");
        gotoxy(35, 8); printf("veillez entrer au moins un livre pour l'affichage :  ");
      Sleep(3000);goto menu1l;
    } // FIN DE CASE 2 POUR L'AFFICHAGE DE TOUS LES LIVRES
   
    case 3 :                                                   // DEBUT DE CASE 3 POUR LA RECHERCHE D'UN LIVRE 
    { 
         if(nblivre >= 1) {
         int id_recherche = 0;
        bool trouve = false;
        system("cls");
        gotoxy (65, 5);
        printf("=== RECHERCHE D'UN LIVRE ===");
        gotoxy(60,7);
        printf("Entrer le code du livre          :  ");
        scanf("%d",&id_recherche);
        for(size_t i = 0;  i < nblivre; i++){
            if (casier[i].code == id_recherche ){
                trouve = true;
                system("cls");
                gotoxy(55, 5);
                printf("====================INFORMATION DU LIVRE ====================");
                gotoxy(60,  8);
                printf("CODE                : %d ",casier[i].code);
                gotoxy(60, 10);
                printf("TITRE               : %s",casier[i].titre);
                gotoxy(60,  12);
                printf("NB_TOTAL EXEMPLAIRE : %d",casier[i].nb_total_exemplaire);
                gotoxy(60, 14);
               printf("NB_EXEMPLAIRE DISPO  : %d",casier[i].nb_exemplaire_dispo);
                           
            }
        }
        if (!trouve )
        {
            gotoxy(91, 7);
                setColor(FOREGROUND_RED);
            printf(" Aucun livre ne porte le code %d !",id_recherche);
            Sleep(3000);
            setColor(COLOR_DEFAULT);
        }
        getch();
        goto menu1l; } else system("cls");
        gotoxy(35, 8); 
        setColor(FOREGROUND_RED);
        printf("veillez entrer au moins un livre pour la recherche :  "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto menu1l;
    } // FIN DE CASE 3 POUR LA RECHERCHE D'UN LIVRE
   
 case 4: {                                                      // DEBUT DE CASE 4 POUR L'AFFICHAGE DES LIVRES DISPONIBLES
 effectif = 0;
        b = 0;
        if (nblivre >= 1 ){
        system("cls");
        gotoxy(60, 3);
       setColor(FOREGROUND_BLUE);
        printf("********************* LISTES DES LIVRES DISPONIBLE  *****************************");
        gotoxy(60, 5);
        setColor(FOREGROUND_BLUE);
        printf("CODE ");
        gotoxy(80, 5);
        setColor(FOREGROUND_BLUE);
        printf("TITRE ");
        setColor(COLOR_DEFAULT);
         gotoxy(100, 5);
        setColor(FOREGROUND_BLUE);
        printf("Nb_D'EXEMPLAIRE DISPONIBLE ");
        setColor(COLOR_DEFAULT);
        for(size_t i = 0; i < nblivre ; i++)
        {
            gotoxy(60, 6 + i);
            printf("%d", casier[i].code );
            gotoxy(80, 6 + i);
            printf("%s", casier[i].titre);
            gotoxy(112, 6 + i);
            printf("%d", casier[i].nb_exemplaire_dispo);
            b+=i;
            
        }
        getch();
        goto menu1l; } else system("cls");
        gotoxy(65, 8); printf("veillez entrer au moins un livre pour l'affichage :  ");
      Sleep(3000);goto menu1l;
    } //FIN DE CASE 4 POUR L'AFFICHAGE DES LIVRES DISPONIBLES

case 6 :{                                                       // DEBUT DE CASE 6 POUR LE DEPOT D'UN LIVRE
     if ( nbabonnee == 0 ){ 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf(" Desolée aucun abonné n'est inscrit pour faire un depot ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;} else {
        if (nblivre >= 1){
        int id_depot = 0;
        int num_saisie = 0;
        int emplacement = 0;
        bool cherche = false;
        system("cls");
        gotoxy(60, 5);
        printf("==============   DEPOT D'UN LIVRE   ============");
        do { gotoxy(60, 6);
        printf("Donner le numero d'abonnement de l'abonné :                                                                         ");
       gotoxy(103, 6);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &num_saisie);
        } else {
        gotoxy(105, 6);
           setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
        
        } 
                for(size_t i = 0; i < nbabonnee; i++)
        {
            if(classe[i].numero_abonnement == num_saisie)
            { 
                emplacement = i;
                cherche = true; break ;}
    }  
    if(!cherche){
         system("cls"); 
         setColor(FOREGROUND_RED);
         gotoxy(65, 8);  
        printf("Cet abonné n'existe pas dans cette bibliothèque veillez l'inscrire s'il vous plait !! "); Sleep(4000); 
        setColor(COLOR_DEFAULT); goto menu1l; 
    }
      } while (!nbvalide(buffer));

       
                
       l: do{ gotoxy(60,7);
        printf("Entrer le code du livre que voulez-vous deposer       :                                                                 ");
      gotoxy(118, 7);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &id_depot);           
        } else {
            gotoxy(118, 7);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.\n");
            Sleep(2000);
            setColor(COLOR_DEFAULT); }

        } while (!nbvalide(buffer));
        for(size_t i = 0; i < nblivre; i++){
            if (casier[i].code == id_depot){
                if (casier[i].nb_exemplaire_dispo <  casier[i].nb_total_exemplaire)
                {
                classe[emplacement].nb_livres_empruntee--;
                casier[i].nb_exemplaire_dispo++;
                nb_emprunt++;
                gotoxy(60, 8);
                setColor(FOREGROUND_GREEN);
                printf("Livre deposé avec succes!!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto menu1l;
            } else { 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf("Oupss le nombre d'exemplaire de ce livre est deja atteint dans la bibliothèque ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;}
            } else {  
        setColor(FOREGROUND_RED                                            );
         gotoxy(118, 7);  
        printf("Ce livre n'est pas enregistré dans cette bibliothèque "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto l;}
               } 
}else { 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf("Veillez entrer au moins un livre pour le retrait  ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;}

    }
}   // FIN DE CASE 6 POUR LE DEPOT D'UN LIVRE 
 case 5:{                                                   // DEBUT DE CASE 5 POUR LE RETRAIT D'UN LIVRE
        if ( nbabonnee == 0 ){ 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf(" Desolée aucun abonné n'est inscrit pour faire du retrait ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;} else {
        if (nblivre >= 1){
        int id_retrait;
        int num_saisie = 0;
        int emplacement;
        bool cherche = false;
        system("cls");
        gotoxy(60, 5);
        printf("==============   RETRAIT D'UN LIVRE   ============");
       do { gotoxy(60, 6);
        printf("Donner le numero d'abonnement de l'abonné :                                                                         ");
       gotoxy(103, 6);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &num_saisie);
        } else {
        gotoxy(105, 6);
           setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
        
        }
          } while (!nbvalide(buffer)); 
                for(size_t i = 0; i < nbabonnee; i++)
        {
            if(classe[i].numero_abonnement == num_saisie)
            { 
                emplacement = i;
                cherche = true; break ;}
    }  
    if(!cherche){
         system("cls"); 
         setColor(FOREGROUND_RED);
         gotoxy(65, 8);  
        printf("Cet abonné n'existe pas dans cette bibliothèque veillez l'inscrire s'il vous plait !! "); Sleep(4000); 
        setColor(COLOR_DEFAULT); goto menu1l; 
    }
    

       
                
       Q: do{ gotoxy(60,7);
        printf("Entrer le code du livre que voulez-vous retirer        :                                                                 ");
      gotoxy(118, 7);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &id_retrait);           
        } else {
            gotoxy(118, 7);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.\n");
            Sleep(2000);
            setColor(COLOR_DEFAULT); }

        } while (!nbvalide(buffer));
        bool cherches = false;
        for(size_t i = 0; i < nblivre; i++){
            if (casier[i].code == id_retrait){
                cherche = true;
                if (casier[i].nb_exemplaire_dispo <= casier[i].nb_total_exemplaire && casier[i].nb_exemplaire_dispo > 0)
                {
                    if(classe[emplacement].nb_livres_empruntee < classe[emplacement].plan_de_location){
                classe[emplacement].nb_livres_empruntee++;
                casier[i].nb_exemplaire_dispo--;
                nb_emprunt++;
                gotoxy(60, 8);
                setColor(FOREGROUND_GREEN);
                printf("Livre retiré avec succes!!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto menu1l;} else { 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf("Désolé cet abonné a atteint le maximun de son plan de location ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;}
            } else { 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf("Désolé aucun exemplaire de ce livre n'est disponible pour le moment  ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;}
            } }
            if (!cherches) {  
        setColor(FOREGROUND_RED                                            );
         gotoxy(118, 7);  
        printf("Ce livre n'est pas enregistré dans cette bibliothèque "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto Q;}
               
}else { 
            system ("cls");
            gotoxy(65, 8);
            setColor(FOREGROUND_RED);
            printf("Veillez entrer au moins un livre pour le retrait  ");
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;}

    }
}       // FIN DE CASE 5 POUR LE RETRAIT D'UN LIVRE
case 7 :{                                   // DEBUT DE CASE 7 POUR LA MODIFICATION D'UN LIVRE
     if( nblivre >= 1) 
        {
        size_t position = 0;
        bool existe = false;
        int choixmodif  = 0;
        int searchnumero_code = 0;
      do{  system("cls");
          gotoxy(60, 5);
        printf("============= MODIFICATION D'UN LIVRE ============"   );
        gotoxy(60, 6);
        printf("Donner le code du livre a modifier :                                                                    ");
        gotoxy(105, 6);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &searchnumero_code);
        } else {
            gotoxy(103, 6);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.");
            Sleep(2000);
            setColor(COLOR_DEFAULT);
            
        }           } while(!nbvalide(buffer));
        for(size_t i = 0; i < nblivre; i++)
        {
            if(casier[i].code == searchnumero_code)
            {
                position = i;
                existe = true;
                break;
            } 
        }
                if(!existe)
                {
                    gotoxy(103, 6);
                     setColor(FOREGROUND_RED );
                    printf("Le livre à modifier n'existe pas!!!!!!");
                    Sleep(3000);
                    setColor(COLOR_DEFAULT);
                    system("cls");
                    goto menu1l; 
                }
                else {
modife :
            system("cls");                               // MENU DE MODIFICATION D'UN LIVRE
            gotoxy(60, 8);
            printf("=============== Que voulez vous Modifier ? ===============");
            gotoxy(60, 9);
            printf("= 1- Code du livre                                       =");
            gotoxy(60, 10);
            printf("= 2- Titre                                               =");
            gotoxy(60, 11);
            printf("= 3- Nb_exemplaire dispo                                 =");
            gotoxy(60, 12);
            printf("= 4- Nb_total d'exemplaire                               =");
            gotoxy(60, 13);
            printf("= 0- Retour                                              =");
            gotoxy(60, 14);
            printf("==========================================================");
           moi: gotoxy(60, 15);
            printf("*** Votre choix :                                                                  ");
            gotoxy(77, 15);
            scanf("%s", buffer);
            if (nbvalide(buffer)) {
                sscanf(buffer, "%d", &choixmodif);
            } else {
                gotoxy(76, 15);
                    setColor(FOREGROUND_RED );
                printf("Entree invalide. Veuillez entrer un nombre valide.");
                Sleep(2000);
            setColor(COLOR_DEFAULT);
                goto moi;
            }
            switch(choixmodif)
            {
            case 1 :                                            // DEBUT DE CASE 1 DANS LE MENU DE MODIFICATION DU CODE D'UN LIVRE
              do{  gotoxy(60, 16);
               printf("Donner le nouveau code du livre :                                                                         ");
              gotoxy(101, 16);
               scanf("%s", buffer);
                if (nbvalide(buffer)) {
                    sscanf(buffer, "%d", &casier[position].code);
                } else {
                    gotoxy(100, 16);
                    setColor(FOREGROUND_RED );
                    printf("Entree invalide. Veuillez entrer un nombre valide.");
                    Sleep(2000);
                    setColor(COLOR_DEFAULT);
                 
                }           } while(!nbvalide(buffer));
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Code du livre modifier avec succes!!!!");
                Sleep(3000);
                    setColor(COLOR_DEFAULT);
                goto modife;                                        // FIN DE CASE 1 POUR LA MODIFFICATION DU CODE D'UN LIVRE 
                  
            case 2 :{                       // DEBUT DE CASE 2 POUR LA MODIFICATION DU TITRE D'UN LIVRE 

                gotoxy(60, 16);
                printf("Donner le nouveau titre : ");
                scanf("%s", casier[position].titre);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Titre modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modife;
                  }                             // FIN DE CASE 2  POUR LA MODIFICATION DU TITRE D'UN LIVRE

            case 3 : {                             // DEBUT DE CASE 3 POUR LA MODIFICATION DU NB_LIVRE DISPO D'UN LIVRE 

            bool new_plan = false;
              do{ gotoxy(60, 16);
                printf("Donner à nouveau le Nb_livre dispo :                                                                   ");
              gotoxy(114, 16);
                scanf("%s", buffer);
                if (nbvalide(buffer)) {
                    sscanf(buffer, "%d", &num);
                    if (num > casier[position].nb_total_exemplaire || num < 0) {
                        gotoxy(113, 16);
                            setColor(FOREGROUND_RED );
                        printf("nombre invalide !!!!"); Sleep(2000);
                        setColor(COLOR_DEFAULT);  
                        goto modife;  
                    }
                    else {
                        casier[position].nb_exemplaire_dispo = num;
                        num = 0;
                    } new_plan = true;
                } else {
                    gotoxy(113, 16);
                    setColor(FOREGROUND_RED );
                    printf("Entree invalide. Veuillez entrer un nombre valide.");
                    Sleep(2000);
                    setColor(COLOR_DEFAULT);
                }  } while(!new_plan);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Nb_livre dispo modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modife;
            }            // FIN DE CASE 3 POUR LA MODIFICATION DU NB_LIVRE DISPO D'UN LIVRE
            case 4:                         // DEBUT DE CASE 4  POUR LA MODIFICATION DU NB_LIVRE TOTAL D'UN LIVRE
            {
                bool new_plan = false;
            do{ gotoxy(60, 16);
                printf("Donner à nouveau le Nb_total de livre :                                                                   ");
              gotoxy(114, 16);
                scanf("%s", buffer);
                if (nbvalide(buffer)) {
                    sscanf(buffer, "%d", &num);
                    if ( num < 0 ) {
                        gotoxy(113, 16);
                            setColor(FOREGROUND_RED );
                        printf("nombre invalide !!!!"); Sleep(2000);
                        setColor(COLOR_DEFAULT);  
                        goto modife;  
                    }
                    else {
                        casier[position].nb_total_exemplaire = num;
                        num = 0;
                    } new_plan = true;
                } else {
                    gotoxy(113, 16);
                    setColor(FOREGROUND_RED );
                    printf("Entree invalide. Veuillez entrer un nombre valide.");
                    Sleep(2000);
                    setColor(COLOR_DEFAULT);
                }  } while(!new_plan);
                gotoxy(60, 17);
                setColor(FOREGROUND_GREEN);
                printf("Nb_total de livre modifier avec succes!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto modife;
            }     // FIN DE CASE 4 POUR LA MODIFICATION DU NB_LIVRE TOTAL D'UN LIVRE
               case 0 :
                goto menu1l;
            } // FIN DE SWICTH MODIFICATION DES DATA D'UN LIVRE 
        } //FIN DE ELSE IF(!EXISTE)
    } else 
      system("cls");
      setColor(FOREGROUND_RED);
      gotoxy(65, 8); 
      printf("veillez entrer au moins un livre pour la modification :  ");
      Sleep(3000);
      setColor(COLOR_DEFAULT);
      goto menu1l;
    }  // FIN DE CASE 7 POUR LA MODIFICATION D'UN LIVRE
case 8 : {   // DEBUT DE CASE 8 POUR LA SUPPRESSION D'UN LIVRE 
    if (nblivre >= 1){
        int id_supp = 0;
        bool trouve = false;
        bool valide = false;
       do { system("cls");
        gotoxy(60, 5);
        printf("============== SUPPRESSION D'UN LIVRE ============");
        gotoxy(60,6);
        printf("Entrer le code du livre  à  supprimer :                                                         ");
      gotoxy(120, 6);
        scanf("%s", buffer);
        if (nbvalide(buffer)) {
            sscanf(buffer, "%d", &id_supp);           
            valide = true;
        } else {
            gotoxy(119, 6);
                setColor(FOREGROUND_RED );
            printf("Entree invalide. Veuillez entrer un nombre valide.\n");
            Sleep(2000);
            setColor(COLOR_DEFAULT);}
        } while (!valide);

        for(size_t i = 0; i < nblivre; i++){
            if (casier[i].code == id_supp){
            
               // trouve = true;
                for(size_t j = i; j < nblivre - 1; j++){
                    casier[j] = casier[j + 1];
                }
                nblivre--;
                casier = realloc(casier, nblivre * sizeof(livre));
                gotoxy(60, 7);
                setColor(FOREGROUND_GREEN);
                printf("Livre supprimé avec succes!!!!!");
                Sleep(3000);
                setColor(COLOR_DEFAULT);
                goto menu1l;
            } else  {
            gotoxy(119, 6);
            setColor(FOREGROUND_RED);
            printf("Aucun livre ne porte le code %d !! ",id_supp);
            Sleep(3000);
            setColor(COLOR_DEFAULT);
            system("cls");
         goto menu1l;
         } 
        }
 } else system("cls");
        setColor(FOREGROUND_RED);
         gotoxy(65, 8);  
        printf("veillez entrer au moins un livre pour la suppression :  "); Sleep(3000); 
        setColor(COLOR_DEFAULT);
        goto menu1l; 
}      // FIN  DE CASE 8 POUR LA SUPPRESSION D'UN LIVRE 
  
   case 0 :{
              system("cls");
       gotoxy(65,8); printf(" merci d'avoir utiliser notre programme"); Sleep(3000);
       system("cls");
       goto menu;
   }  // FIN DE CASE 0 MENU1L 
  
 default :
  goto menu1l;
} // FIN DE SWICTH MENU1L POUR LES LIVRES 
} // FIN DU GRAND CASE 2 MENU PRINCIPAL POUR LA GESTION LES LIVRES !!!!!!
    case 0 : {
              system("cls");
       gotoxy(65,8); printf(" merci d'avoir utiliser notre logiciel"); Sleep(3000);
       system("cls");
       break;
 } // FIN CASE 0 POUR MENU GENERAL  

 default :
 system("cls");    
 goto menu;
} // FIN DE SWICTH POUR MENU GENERAL  

     free(classe);
    free(casier);
    return 0;
}                                                        //FIN DE INT MAIN(). 
