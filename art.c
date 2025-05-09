#include"projet.h"


void debutc(){
	FILE *fichier=fopen("debutcombat.txt","r");
	if(fichier==NULL){
	printf("ERREUR 'affiche_debutcombat':%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(11);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}


void rayman(){
	FILE *fichier=fopen("rayman.txt","r");
	if(fichier==NULL){
	printf("ERREUR :%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(12);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}




void boo(){
	FILE *fichier=fopen("boo.txt","r");
	if(fichier==NULL){
	printf("ERREUR :%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(12);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}

void groot(){
	FILE *fichier=fopen("groot.txt","r");
	if(fichier==NULL){
	printf("ERREUR :%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(12);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}

void yoda(){
	FILE *fichier=fopen("yoda.txt","r");
	if(fichier==NULL){
	printf("ERREUR :%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(12);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}



void toad(){
	FILE *fichier=fopen("toad.txt","r");
	if(fichier==NULL){
	printf("ERREUR :%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(12);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
  }
  
  
  
void yoshi(){
	FILE *fichier=fopen("yoshi.txt","r");
	if(fichier==NULL){
	printf("ERREUR :%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(12);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
  }
  
  
  void lancer(){
	FILE *fichier=fopen("lancer.txt","r");
	if(fichier==NULL){
	printf("ERREUR 'affiche_debutcombat':%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(11);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}
void cible(){
	FILE *fichier=fopen("cible.txt","r");
	if(fichier==NULL){
	printf("ERREUR 'affiche_debutcombat':%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(11);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}
void vs(){
	FILE *fichier=fopen("vs.txt","r");
	if(fichier==NULL){
	printf("ERREUR 'affiche_debutcombat':%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(11);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}

void jouer(){
	FILE *fichier=fopen("jouer.txt","r");
	if(fichier==NULL){
	printf("ERREUR 'affiche_debutcombat':%d\n",errno);
	printf("Message d'erreur:%s\n",strerror(errno));
	exit(11);
	}
	int c=fgetc(fichier);
	
	while(c!=EOF){
	
	printf("%c",c);
	c=fgetc(fichier);
	}
	fclose(fichier);
	
}
