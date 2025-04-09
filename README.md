#include"perso.h"


void displayChampion(Champion champ) {
    printf("Nom: %s\n", champ.nom);
    printf("Santé maximum: %d\n", champ.pvm);
    printf("Santé courante: %d\n", champ.pvc);
    printf("Agilité: %d\n", champ.agl);
    printf("Défense: %d\n", champ.defense);
}

int main() {
Champion champion1;
displayChampion(champion1);


return 0;
}

#include<stdio.h>
#include<time.h>




typedef struct {
 char attrap[100];
 int attrap1;
 char def_nom[100];
 int def_valeur;
 
 
} Attaque;


typedef struct {
    char nom[50];
    int pvc;
     int pvm;
    Attaque att;
    int defense;
    float agl;
    float vitess;
    Type type;
} Champion;

typedef enum{
tank,assassin,soutien
}Type;

champion1.nom="led";
champion1.pvc = 100;
champion1.pvm = 120;
champion1.defense = 30;
champion1.agl = 12.5;
champion1.vitesse = 8.7;





