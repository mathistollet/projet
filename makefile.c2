all: projet.exe

main.o: main.c projet.h
	gcc -c main.c -o main.o

affichage.o: affichage.c projet.h
	gcc -c affichage.c -o affichage.o

ajouter_personnage.o: ajouter_personnage.c projet.h
	gcc -c ajouter_personnage.c -o ajouter_personnage.o

combat.o: combat.c projet.h
	gcc -c combat.c -o combat.o

art.o: art.c projet.h
	gcc -c art.c -o art.o

utilisertechnique.o: technique.c projet.h
	gcc -c technique.c -o technique.o

projet.exe: main.o affichage.o ajouter_personnage.o combat.o art.o technique.o
	gcc main.o affichage.o ajouter_personnage.o combat.o art.o technique.o -o projet.exe

clean:
	rm -f *.o
	rm -f projet.exe
