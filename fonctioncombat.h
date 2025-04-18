int choix;

printf("Choisis ton attaque :\n");
for (int i = 0; i < 2; i++) {
    printf("%d - %s (dégâts : %d)\n", i+1, joueur.attaques[i].nom, joueur.attaques[i].degats);
}

printf("Ton choix : ");
scanf("%d", &choix);

// On vérifie que le choix est valide
if (choix >= 1 && choix <= 2) {
    Attaque a = joueur.attaques[choix - 1];
    printf("Tu as utilisé : %s et infligé %d points de dégâts !\n", a.nom, a.degats);
} else {
    printf("Choix invalide !\n");
}
