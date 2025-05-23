#include "projet.h"

// Ajoute un nouveau personnage dans le fichier "personnages.txt" après avoir collecté ses informations via des entrées utilisateur
void ajouter_personnage(const char* personnages) {
    FILE *file = fopen("personnages.txt", "a+");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    Champion p;

    // Collecte des informations de base sur le personnage (nom, PV, défense, agilité, etc.)
    printf("Nom : ");
    scanf("%s", p.nom);
    vider();

    printf("PV max : ");
    while (!lireEntier(&p.pvm) || p.pvm <= 0 || p.pvm > 1000) {
        printf("Entrée invalide, veuillez entrer un nombre entre 1 et 1000.\n");
        printf("PV max : ");
    }
    p.pvc = p.pvm;

    printf("DEF (entre 0 et 30) : ");
    while (!lirefloat(&p.def) || p.def <= 0 || p.def > 30) {
        printf("Entrée invalide, veuillez entrer un nombre entre 0 et 30.\n");
        printf("DEF (entre 0 et 30) : ");
    }

    printf("VIT (entre 0 et 30) : ");
    while (!lirefloat(&p.vitess) || p.vitess <= 0 || p.vitess > 30) {
        printf("Entrée invalide, veuillez entrer un nombre entre 0 et 30.\n");
        printf("VIT (entre 0 et 30) : ");
    }

    p.defmax = p.def;
    p.vitessmax = p.vitess;
    p.barre_action = 0;

    // Collecte de l'agilité et des informations sur les attaques
    printf("Agilité (entre 0 et 80) : ");
    while (!lirefloat(&p.agl) || p.agl <= 0 || p.agl > 80) {
        printf("Entrée invalide, veuillez entrer un nombre entre 0 et 80.\n");
        printf("Agilité (entre 0 et 80) : ");
    }

    printf("Nom attaque 1 (pas d'espaces) : ");
    scanf("%s", p.att[0].nom);
    vider();

    printf("Dégâts attaque 1 (entre 0 et 500) : ");
    while (!lireEntier(&p.att[0].degats) || p.att[0].degats < 0 || p.att[0].degats > 500) {
        printf("Entrée invalide, veuillez entrer un nombre entre 0 et 500.\n");
        printf("Dégâts attaque 1 (entre 0 et 500) : ");
    }

    printf("Nom attaque 2 (pas d'espaces) : ");
    scanf("%s", p.att[1].nom);
    vider();

    printf("Dégâts attaque 2 (entre 0 et 500) : ");
    while (!lireEntier(&p.att[1].degats) || p.att[1].degats < 0 || p.att[1].degats > 500) {
        printf("Entrée invalide, veuillez entrer un nombre entre 0 et 500.\n");
        printf("Dégâts attaque 2 (entre 0 et 500) : ");
    }

    // Collecte des informations sur le rôle, la technique spéciale et ses caractéristiques
    printf("Rôle (tank=0 / assassin=1 / soutien=2) : ");
    while (!liretype(&p.type) || (p.type != 0 && p.type != 1 && p.type != 2)) {
        printf("Erreur, réessayez.\n");
        printf("Rôle (tank=0 / assassin=1 / soutien=2) : ");
    }

    printf("Nom technique spéciale : ");
    scanf("%s", p.technique.nom);
    vider();

    printf("Effet (sans espaces, utilisez _ à la place) : ");
    scanf("%s", p.technique.description);
    vider();

    printf("Valeur effet (entre 0 et 500) : ");
    while (!lirefloat(&p.technique.valeur) || p.technique.valeur < 0 || p.technique.valeur > 500) {
        printf("Erreur, réessayez.\n");
        printf("Valeur effet (entre 0 et 500) : ");
    }

    printf("Propriété (def, vitess, pvc) : ");
    scanf("%s", p.technique.propriete);
    while (strcmp(p.technique.propriete, "def") != 0 &&
           strcmp(p.technique.propriete, "vitess") != 0 &&
           strcmp(p.technique.propriete, "pvc") != 0) {
        printf("Erreur, réessayez : ");
        scanf("%s", p.technique.propriete);
        vider();
    }

    printf("Type effet (add, mul, sub, div) : ");
    scanf("%s", p.technique.operation);
    while (strcmp(p.technique.operation, "add") != 0 &&
           strcmp(p.technique.operation, "mul") != 0 &&
           strcmp(p.technique.operation, "sub") != 0 &&
           strcmp(p.technique.operation, "div") != 0) {
        printf("Erreur, réessayez : ");
        scanf("%s", p.technique.operation);
        vider();
    }

    printf("Durée (en tours) : ");
    while (!lireEntier(&p.technique.tours_actifs) || p.technique.tours_actifs <= 0 || p.technique.tours_actifs > 5) {
        printf("Erreur, réessayez.\n");
        printf("Durée (en tours) : ");
    }

    printf("Temps de recharge : ");
    while (!lireEntier(&p.technique.recharge_max) || p.technique.recharge_max <= 0 || p.technique.recharge_max > 5) {
        printf("Erreur, réessayez.\n");
        printf("Temps de recharge : ");
    }

    p.technique.recharge_restante = p.technique.recharge_max;
    p.tours_effet_restant = 0;

    // Sauvegarde des informations du personnage dans le fichier
    fprintf(file,
            "%s %d %d %.1f %.1f %.1f %.1f %.1f %.1f %s %d %s %d %d %s %s %.1f %s %s %d %d %d %d\n",
            p.nom, p.pvc, p.pvm, p.def, p.defmax, p.agl,
            p.vitess, p.vitessmax, p.barre_action,
            p.att[0].nom, p.att[0].degats,
            p.att[1].nom, p.att[1].degats,
            p.type, p.technique.nom, p.technique.description,
            p.technique.valeur, p.technique.propriete, p.technique.operation,
            p.technique.tours_actifs, p.technique.recharge_max,
            p.technique.recharge_restante, p.tours_effet_restant);

    fclose(file);
    printf("Personnage ajouté avec succès !\n");
}

// Permet à deux équipes de choisir leurs champions parmi une liste
void selectionnerpersos(Champion *tous_les_champions, int nb_champions, Champion *equipe1, Champion *equipe2, char *nomEquipe1, char *nomEquipe2) {
    printf("=== SELECTION DES EQUIPES ===\n");
    int choix;
    int totalchoix = 0;

    while (totalchoix < 6) {
        if (totalchoix % 2 == 0) {
            printf("Choix de ");
            printCouleur(nomEquipe1, "\033[0;34m");
            printf("\n");
        } else {
            printf("Choix de ");
            printCouleur(nomEquipe2, "\033[0;31m");
            printf("\n");
        }

        // Affiche les champions disponibles
        for (int i = 0; i < nb_champions; i++) {
            if (!estDejaChoisi(equipe1, 3, &tous_les_champions[i]) &&
                !estDejaChoisi(equipe2, 3, &tous_les_champions[i])) {
                afficherChampion(&tous_les_champions[i], i + 1);
            }
        }

        printf("\n");

        if (!lireEntier(&choix)) {
            printf("Entrée invalide, veuillez entrer un nombre.\n");
            continue;
        }

        // Vérifie que le choix est valide
        if (choix < 1 || choix > nb_champions ||
            estDejaChoisi(equipe1, 3, &tous_les_champions[choix - 1]) ||
            estDejaChoisi(equipe2, 3, &tous_les_champions[choix - 1])) {
            printf("Choix invalide ou déjà pris. Réessayez.\n");
            continue;
        }

        // Affecte le champion choisi à l'équipe correspondante
        if (totalchoix % 2 == 0) {
            equipe1[totalchoix / 2] = tous_les_champions[choix - 1];
        } else {
            equipe2[totalchoix / 2] = tous_les_champions[choix - 1];
        }

        totalchoix++;
    }
}

// Charge les champions depuis le fichier "personnages.txt" et les stocke dans un tableau
int chargerChampionsDepuisFichier(const char* personnages, Champion* champions, int max) {
    FILE *file = fopen("personnages.txt", "r");
    if (file == NULL) {
        printf("Erreur de lecture du fichier\n");
        return 0;
    }

    int i = 0;
    char ligne[512];

    while (fgets(ligne, sizeof(ligne), file) && i < max) {
        Champion *c = &champions[i];
        int nb = sscanf(ligne,
                        "%s %d %d %f %f %f %f %f %f %s %d %s %d %d %s %s %f %s %s %d %d %d %d\n",
                        c->nom, &c->pvc, &c->pvm, &c->def, &c->defmax, &c->agl,
                        &c->vitess, &c->vitessmax, &c->barre_action,
                        c->att[0].nom, &c->att[0].degats,
                        c->att[1].nom, &c->att[1].degats,
                        &c->type, c->technique.nom, c->technique.description,
                        &c->technique.valeur, c->technique.propriete,
                        c->technique.operation, &c->technique.tours_actifs,
                        &c->technique.recharge_max, &c->technique.recharge_restante,
                        &c->tours_effet_restant);
        if (nb >= 23) {
            i++;
        }
    }

    fclose(file);
    return i;
}

// Lit un entier depuis l'entrée standard
int lireEntier(int *valeur) {
    char tab[100];
    if (fgets(tab, sizeof(tab), stdin) != NULL) {
        char *a;
      *valeur=strtol(tab,&a,10);
          if(a==tab||*a!='\n'){
              return 0;  
          } 
    return 1;
    }
return 0;
} 



float lirefloat(float* valeur) {
    char tab[100];
    if (fgets(tab, sizeof(tab), stdin) != NULL) {
        char *a;
      *valeur=strtol(tab,&a,10);
          if(a==tab||*a!='\n'){
              return 0;  
          } 
    return 1;
    }
return 0;
}



Type liretype(Type* valeur) {
    char tab[100];
    if (fgets(tab, sizeof(tab), stdin) != NULL) {
        char *a;
      *valeur=strtol(tab,&a,10);
          if(a==tab||*a!='\n'){
              return 0;  
          } 
    return 1;
    }
return 0;
}


    int estDejaChoisi(Champion* equipes, int taille, Champion* candidat) {
        for (int i = 0; i < taille; i++) {
            if (strcmp(equipes[i].nom, candidat->nom) == 0) {
                return 1;
            }
        }
        return 0;
    }
