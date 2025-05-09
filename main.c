#include"projet.h"


int main() {


char z[10000];
jouer();
printf("\n");
scanf("%s",z);
if(strcmp(z,"oui")!=0){
	return 0;
	}

    char nomEquipe1[SIZE];
    char nomEquipe2[SIZE];
    int b=0;
    
    	
    srand(time(NULL));
    
    int choix;
do {
	lancer();
	 printf("\n");
	    scanf("%d", &choix);
	while (choix!=1 && choix!=2) {
		    printf("choix incorrect\n");
		        scanf("%d",&choix);
	    }

    switch (choix) {
        case 1: {
        
        
        printf("Entrez le nom de la première équipe : ");
    scanf("%s",nomEquipe1);
    while(strlen(nomEquipe1)>SIZE||strlen(nomEquipe1)==0){
   	 printf("votre nom est incorrect,veuillez recommencer\n");
    		scanf("%s",nomEquipe1);
    
	}
    printf("Entrez le nom de la deuxième équipe : ");
    scanf("%s",nomEquipe2);
    while(strlen(nomEquipe2)>SIZE||strlen(nomEquipe2)==0){
   	 printf("votre nom est incorrect,veuillez recommencer\n");
    		scanf("%s",nomEquipe2);
    	}
    	
    
          Champion* tous_les_champions=malloc(sizeof(Champion)*(6+b));
    if(tous_les_champions==NULL){
    printf("erreur\n");
    exit(1);
    }
    int nb_champions = chargerChampionsDepuisFichier("personnages.txt", tous_les_champions, 6+b);

    if (nb_champions == 0) {
        printf("Erreur : Aucun champion chargé.\n");
        return 1;
    }
    
    Champion*equipe1=malloc(sizeof(Champion)*3);
    if(equipe1==NULL){
    printf("erreur\n");
    exit(1);
    }
    
    Champion*equipe2=malloc(sizeof(Champion)*3);
    if(equipe2==NULL){
    printf("erreur\n");
    exit(1);
    }
    
selectionnerpersos(tous_les_champions,nb_champions,equipe1,equipe2,nomEquipe1,nomEquipe2);
  combat3v3(tous_les_champions,nb_champions,equipe1,equipe2,nomEquipe1,nomEquipe2); 
  
    free(tous_les_champions);
    free(equipe1);
    free(equipe2);
            break;
            }
        case 2:
            ajouter_personnage("personnages.txt");
            b++;
            break;

    }
} while (choix != 1);
    
