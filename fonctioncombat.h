void afficherVie(Champion p1, Champion p2) {
    printf("\n--- ÉTAT DES COMBATTANTS ---\n");
    printf("%s : %d PV\t\t%s : %d PV\n\n", p1.nom, p1.pvc, p2.nom, p2.pvc);
}


void utiliserAttaque(Champion *attaquant, Champion *cible, Attaque a) {
    printf("%s utilise %s et inflige %d dégâts à %s !\n", attaquant->nom, a.nom, a.degats, cible->nom);
    cible->pvc= a.degats;
    if (cible->pvc < 0) cible->pvc= 0;
}
