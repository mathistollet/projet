Pour notre projet, nous avons utilisé un fichier .h dans lequel se trouvent nos structures champion, technique, attaque et type.
Il y a également le nom de toutes nos fonctions utilisées dans notre programme.
Nous avons utilisé cinq fichiers .c contenant nos fonctions que nous avons triées en fonction de leur utilité, ainsi que notre main.
Pour finir, nous avons utilisé un Makefile (qui contient tous nos fichiers) permettant de compiler notre programme.

Concernant le fonctionnement de notre jeu, il s'agit d'un combat entre deux joueurs, chaque joueur possédant une équipe de trois champions. Cela fonctionne en tour par tour, et le premier joueur parvenant à éliminer les trois champions du joueur adverse remporte la victoire.

Au début du programme, le jeu demande si les joueurs souhaitent jouer.
Ensuite, les joueurs ont le choix entre directement lancer le combat et jouer avec les personnages déjà implémentés dans le jeu ou créer leurs propres personnages en choisissant les caractéristiques du champion, qui vont alors se rajouter aux champions de base.
Les joueurs doivent ensuite sélectionner leur équipe ainsi que leur nom.

Le combat peut ensuite commencer : chaque champion attaque si sa barre de vitesse est chargée à 100 % (chaque champion possédant une vitesse différente).
Lorsqu’un champion attaque, il peut choisir d’attaquer n’importe quel champion de l’équipe adverse. Il peut ensuite choisir entre ses deux attaques principales (qui peuvent être un soin si le champion est de type soigneur) et sa technique spéciale si elle est chargée.
Si son attaque consiste à infliger des dégâts au champion adverse et que ce dernier n’esquive pas, sa barre de vie descendra.

À la fin de chaque tour, il y a un affichage de la barre de vie et de vitesse de chaque champion. Lorsqu’un champion est KO, il ne peut plus attaquer ni se faire attaquer.
À la fin du jeu, l’équipe victorieuse est déclarée vainqueur.


