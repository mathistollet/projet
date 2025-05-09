#include"projet.h"




void ajouter_personnage(const char* personnages) {
    FILE *file = fopen("personnages.txt", "a+");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    Champion p;
    char typeStr[20]; 

    printf("Nom : ");
    scanf("%s", p.nom);

    printf("PV max : ");
    scanf("%d", &p.pvm);
    p.pvc = p.pvm;

    printf("  DEF / VIT : ");
    scanf(" %f %f",  &p.def, &p.vitess);
    p.defmax = p.def;
    p.vitessmax = p.vitess;
    p.barre_action = 0;
    
    printf("quelle est son agilité(entre 0 et 100) : ");
    scanf("%f",&p.agl);
    while(p.agl<0||p.agl>100){
    	printf("erreur,reessayez\n");
      		scanf("%f",&p.agl);
      		}
    

    printf("Nom attaque 1 et dégâts : ");
    scanf("%s %d", p.att[0].nom, &p.att[0].degats);

    printf("Nom attaque 2 et dégâts : ");
    scanf("%s %d", p.att[1].nom, &p.att[1].degats);

    printf("Rôle (tank=0/assassin=1/soutien=2) : ");
       scanf("%f",&p.agl);
    while(p.type!=0&&p.type!=1&&p.type!=2){
    	printf("erreur,reessayer\n");
    	  scanf("%f",&p.agl);

    printf("Nom technique spéciale : ");
    scanf("%s", p.technique.nom);

    printf("Effet (sans espaces, utilisez _ à la place) : ");
    scanf("%s", p.technique.description);

    printf("Valeur effet (float ou int selon le type) : ");
    scanf("%f", &p.technique.valeur);
    
     while(p.technique.valeur<0||p.technique.valeur>1000){
    	printf("erreur,reessayer\n");
    	  scanf("%f",&p.technique.valeur);
    	  }

    
    printf("quelle est sa propriete?(def,vitess,pvc)");
    scanf("%s",p.technique.propriete);

    printf("Type effet (add, mul, sub, div) : ");
    scanf("%s", p.technique.operation);

    printf("Durée (en tours) : ");
    scanf("%d", &p.technique.tours_actifs);

    printf("Temps de recharge : ");
    scanf("%d", &p.technique.recharge_max);

    
  

    fprintf(file, "%s %d %d %1f %1f %1f %1f %1f %1f %s %d %s %d %d %s %s %.1f %s %s %d %d\n",
        p.nom, p.pvc, p.pvm, p.def, p.defmax, p.agl,
        p.vitess, p.vitessmax, p.barre_action,
        p.att[0].nom, p.att[0].degats, p.att[1].nom, p.att[1].degats,
       p.type, p.technique.nom, p.technique.description, p.technique.valeur,
        p.technique.propriete, p.technique.operation,
        p.technique.tours_actifs, p.technique.recharge_max);

    fclose(file);
    printf("Personnage ajouté avec succès !\n");
}





void selectionnerpersos(Champion *tous_les_champions,int nb_champions,Champion*equipe1,Champion*equipe2,char* nomEquipe1,char* nomEquipe2){
 printf("=== SELECTION DES EQUIPES ===\n");
 int choix;
 int totalchoix=0;
 while(totalchoix<6){
 
 
 if(totalchoix%2==0){
                       printf("Choix de ",nomEquipe1);
                       printCouleur(nomEquipe1, "\033[0;34m");
                       printf("\n");
               } 
               
               else {
                       printf("Choix de ");
                       printCouleur(nomEquipe2, "\033[0;31m");
                       printf("\n");
               }
 		
 for (int i = 0; i < nb_champions; i++) {
 
            if (!estDejaChoisi(equipe1, 3, &tous_les_champions[i]) && !estDejaChoisi(equipe2, 3, &tous_les_champions[i])) {
        	afficherChampion(&tous_les_champions[i], i + 1);
    }
        }
         printf("\n");
         
         




if (!lireEntier(&choix)) {
    printf("Entrée invalide, veuillez entrer un nombre.\n");
    continue; // ou return, selon le contexte
}


         printf("\n");
         
           if (choix < 1 || choix > nb_champions|| estDejaChoisi(equipe1, 3, &tous_les_champions[choix - 1]) || estDejaChoisi(equipe2, 3,&tous_les_champions[choix - 1])) {
            printf("Choix invalide ou déjà pris. Réessayez.\n");
            continue;
           }
           
           
               if(totalchoix%2==0){
                       equipe1[totalchoix/2]=tous_les_champions[choix-1];
               } 
               
               else {
                       equipe2[totalchoix/2]=tous_les_champions[choix-1];
               }
        totalchoix++;
        }

 }
 
 
 
 
 int chargerChampionsDepuisFichier(const char* personnages, Champion* champions, int max) {
    FILE *file = fopen("personnages.txt", "r");
    if (file == NULL) {
        printf("Erreur de lecture du fichier\n");
        return 0; // Si le fichier n'est pas trouvé, on retourne 0 pour indiquer une erreur
    }

    int i = 0;


    while (fscanf(file, 
                  "%s %d %d %f %f %d %f %f %f %s %d %s %d %d %s %s %f %s %s %d %d\n",
        
                  champions[i].nom, 
                  &champions[i].pvc, &champions[i].pvm, &champions[i].def, &champions[i].defmax,
                  &champions[i].agl, &champions[i].vitess, &champions[i].vitessmax, &champions[i].barre_action,
                  champions[i].att[0].nom, &champions[i].att[0].degats, 
                  champions[i].att[1].nom, &champions[i].att[1].degats, 
                  &champions[i].type, // <- on lit ici dans la variable temporaire
                  champions[i].technique.nom, champions[i].technique.description, 
                  &champions[i].technique.valeur, champions[i].technique.propriete, 
                  champions[i].technique.operation, &champions[i].technique.tours_actifs, 
                  &champions[i].technique.recharge_max) != EOF) {
        
        // Conversion de typeStr en enum Type


        i++;
        if (i >= max){
         break; // On s'assure de ne pas dépasser le nombre maximal de champions
    }
}
    fclose(file);
    return i;
}


    int lireEntier(int *valeur) {
    char tab[100];
    if (fgets(tab, sizeof(tab), stdin) != NULL) {
        char *endptr;
        *valeur = strtol(tab, &endptr, 10);
        if (endptr == tab || *endptr != '\n') {
            return 0;  // Pas un entier valide
        }
        return 1;  // Succès
    }
    return 0; // Erreur de lecture 
}



int estDejaChoisi(Champion* equipes, int taille, Champion* candidat) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(equipes[i].nom, candidat->nom) == 0) {
            return 1;
        }
    }
    return 0;
}
