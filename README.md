#include <stdio.h>
#include<stdlib.h>

typedef struct {
     char nom[50];
     int pvc;
      int pvm;
     int defense;
     float agl;
     float vitesse;
     Type type;
     Attaque att;
 } Champion;
 
    typedef struct {
  char attrap[100];
  int attrap1;
  char def_nom[100];
  int def_valeur;
  
  
 } Attaque;
 typedef enum{
 tank,assassin,soutien
 }Type;
 








