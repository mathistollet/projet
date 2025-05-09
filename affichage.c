#include"projet.h"



const char* lesroles(Type type) {
    switch (type) {
        case 0: return "tank";
        case 1: return "assassin";
        case 2: return "soutien";
        default: return "inconnu";
    }
} 



void afficherChampion( Champion* c, int index) {
    printf("%d - %s [Type: %s, PV: %d, Déf: %.1f, Vit: %.1f]\n",
           index, c->nom, lesroles(c->type), c->pvm, c->def, c->vitess);
}



void printCouleur(const char *texte, const char *couleur) {
    printf("%s%s\033[0m", couleur, texte);
}




void afficherBarreDeVie(int pvact, int pvmax) {
    int longueurBarre = 20;
    int nbBlocs = (pvact * longueurBarre) / pvmax;
    float ratio = (float)pvact / pvmax;

    const char *couleur;
    if (ratio > 0.6){
     couleur = GREEN;
     	}
    else if (ratio > 0.3){
     couleur = ORANGE;
     	}
    else{
     couleur = RED;
	}
    printf("[");
    for (int i = 0; i < longueurBarre; i++) {
        if (i < nbBlocs){
            printf("%s█", couleur);
            }
        else{
            printf("%s ", RESET);
            }
    }
    printf("%s] %d/%d PV  ", RESET, pvact, pvmax);
}





void afficherBarreDeVitesse(float barre_action) {
    int longueurBarre = 20;
    int nbBlocs = (barre_action * longueurBarre) / 100;

    printf("[");
    for (int i = 0; i < longueurBarre; i++) {
        if (i < nbBlocs){
            printf("%s█", GREEN);
            }
        else{
            printf("%s ", RESET);
            }
    }
    printf("] %.2f/100 Vitesse\n", barre_action);
}




void afficherVie(Champion p1) {
    
    printf("%s : ", p1.nom);
    afficherBarreDeVie(p1.pvc, p1.pvm);
    afficherBarreDeVitesse(p1.barre_action);
}
