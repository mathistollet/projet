void utiliserTechnique(Champion *utilisateur, Champion *cible) {
    Technique *tech = &utilisateur->technique;


    printf("%s utilise sa technique spéciale : %s !\n", utilisateur->nom, tech->nom);


    if (strcmp(tech->propriete, "pvc") == 0 && tech->tours_actifs == 0) {
        if (strcmp(tech->operation, "add") == 0) {
            utilisateur->pvc += tech->valeur;
            if (utilisateur->pvc>utilisateur->pvm) {
                utilisateur->pvc = utilisateur->pvm;
            }
            printf("%s récupère %.0f PV !\n", utilisateur->nom, tech->valeur);
        }
        else if (strcmp(tech->operation, "sub") == 0) {
            cible->pvc =cible->pvc-tech->valeur;

            if (cible->pvc < 0){
                cible->pvc = 0;
            }
            printf("%s fais une grosse attaque et tape %s de  %.0f dégats !\n",utilisateur->nom, cible->nom, tech->valeur);

        }

        else if (strcmp(tech->operation, "div") == 0) {
            cible->pvc =cible->pvc/tech->valeur;

            if (cible->pvc < 0){
                cible->pvc = 0;
            }
            printf("%s fais une grosse attaque et tape %s de  %.0f dégats !\n",utilisateur->nom, cible->nom, (cible->pvc*tech->valeur)-cible->pvc);

        }
        else if (strcmp(tech->operation, "mul") == 0) {
            utilisateur->pvc = utilisateur->pvc* tech->valeur;
            if (utilisateur->pvc>utilisateur->pvm) {
                utilisateur->pvc = utilisateur->pvm;
            }

            printf("%s récupère %.0f PV !\n", utilisateur->nom, utilisateur->pvc-(utilisateur->pvc/tech->valeur));
        }

    }


    if (strcmp(tech->propriete, "pvc") == 0 && tech->tours_actifs > 0) {
        if (strcmp(tech->operation, "add") == 0) {
            utilisateur->pvc += tech->valeur;
            if (utilisateur->pvc>utilisateur->pvm) {
                utilisateur->pvc = utilisateur->pvm;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s récupère %.0f PV pendant encore %d tours !\n", utilisateur->nom, tech->valeur, tech->tours_actifs);
        }
        else if (strcmp(tech->operation, "sub") == 0) {
            cible->pvc =cible->pvc-tech->valeur;

            if (cible->pvc < 0){
                cible->pvc = 0;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s fais une attaque sur la durée (encore %d tours) et tape %s de  %.0f dégats !\n",utilisateur->nom, tech->tours_actifs,cible->nom, tech->valeur);

        }

        else if (strcmp(tech->operation, "div") == 0) {
            cible->pvc =cible->pvc/tech->valeur;

            if (cible->pvc < 0){
                cible->pvc = 0;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s fais une grosse attaque et tape %s de  %.0f dégats pendant encore %d !\n",utilisateur->nom, cible->nom, (cible->pvc*tech->valeur)-cible->pvc, tech->tours_actifs);

        }
        else if (strcmp(tech->operation, "mul") == 0) {
            utilisateur->pvc = utilisateur->pvc* tech->valeur;
            if (utilisateur->pvc>utilisateur->pvm) {
                utilisateur->pvc = utilisateur->pvm;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s récupère %.0f PV pendant %d tours !\n", utilisateur->nom, utilisateur->pvc-(utilisateur->pvc/tech->valeur),tech->tours_actifs);
        }

    }




    if (strcmp(tech->propriete, "vitess") == 0 && tech->tours_actifs == 0) {
        if (strcmp(tech->operation, "div") == 0) {
            cible->vitess = cible->vitess/tech->valeur;

            if (cible->vitess < 0){
                cible->vitess = 0;
            }
            printf("%s perd %.0f%% de vitesse !\n", cible->nom, (tech->valeur-1)*100);
        }


        else if (strcmp(tech->operation, "mul") == 0) {
            utilisateur->vitess = tech->valeur* utilisateur->vitess;
            if (utilisateur->vitess>=80){
                utilisateur->vitess= 80;
            }


            printf("%s gagne %.0f%% de vitesse !\n", utilisateur->nom, (tech->valeur-1)*100);
        }

        else if (strcmp(tech->operation, "sub") == 0) {
            cible->vitess = cible->vitess-tech->valeur;

            if (cible->vitess < 0){
                cible->vitess = 0;
            }
            printf("%s perd %0f de vitesse !\n",cible->nom, tech->valeur);
        }


        else if (strcmp(tech->operation, "add") == 0) {
            utilisateur->vitess = utilisateur->vitess+tech->valeur;
            if (utilisateur->vitess>=80){
                utilisateur->vitess= 80;
            }

            printf("%s gagne %0f de vitesse !\n",utilisateur->nom, tech->valeur);
        }
    }



    if (strcmp(tech->propriete, "vitess") == 0 && tech->tours_actifs > 0) {
        if (strcmp(tech->operation, "div") == 0) {
            cible->vitess = cible->vitess/tech->valeur;

            if (cible->vitess < 0){
                cible->vitess = 0;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s perd %.0f%% de vitesse pour %d tours !\n", cible->nom, (tech->valeur-1)*100, tech->tours_actifs);
        }


        else if (strcmp(tech->operation, "mul") == 0) {
            utilisateur->vitess = tech->valeur* utilisateur->vitess;
            if (utilisateur->vitess>=80){
                utilisateur->vitess= 80;
            }


            utilisateur->tours_effet_restant = tech->tours_actifs;

            printf("%s gagne %.0f%% de vitesse pour %d tours !\n", utilisateur->nom, (tech->valeur-1)*100, tech->tours_actifs);
        }

        else if (strcmp(tech->operation, "sub") == 0) {
            cible->vitess = cible->vitess-tech->valeur;

            if (cible->vitess < 0){
                cible->vitess = 0;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s perd %0f de vitesse pendant %d tours!\n",cible->nom, tech->valeur, tech->tours_actifs);
        }


        else if (strcmp(tech->operation, "add") == 0) {
            utilisateur->vitess = utilisateur->vitess+tech->valeur;
            if (utilisateur->vitess>=80){
                utilisateur->vitess= 80;
            }


            utilisateur->tours_effet_restant = tech->tours_actifs;
            printf("%s gagne %0f de vitesse pendant %d tours!\n",utilisateur->nom, tech->valeur, tech->tours_actifs);
        }
    }



    if (strcmp(tech->propriete, "def") == 0 && tech->tours_actifs > 0) {
        if (strcmp(tech->operation, "div") == 0) {
            cible->def = cible->def/tech->valeur;

            if (cible->def < 0) {
                cible->def = 0;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s perd %.0f de defense pour %d tours !\n", cible->nom, (tech->valeur-1)*100, tech->tours_actifs);
        }


        else if (strcmp(tech->operation, "mul") == 0) {
            utilisateur->def = tech->valeur* utilisateur->def;
            if (utilisateur->def>=80){
                utilisateur->def= 80;
            }



            utilisateur->tours_effet_restant = tech->tours_actifs;
            printf("%s gagne %.0f%% de defense pour %d tours !\n", utilisateur->nom, (tech->valeur-1)*100, tech->tours_actifs);
        }


        else if (strcmp(tech->operation, "sub") == 0) {
            cible->def = cible->def-tech->valeur;

            if (cible->def < 0) {
                cible->def = 0;
            }
            cible->tours_effet_restant = tech->tours_actifs;
            printf("%s perd %.0f de defense pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
        }


        else if (strcmp(tech->operation, "add") == 0) {
            utilisateur->def = utilisateur->def+tech->valeur;

            if (utilisateur->def > 80) {
                cible->def = 80;
            }

            utilisateur->tours_effet_restant = tech->tours_actifs;
            printf("%s gagne %.0f de defense pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
        }

    }



    if (strcmp(tech->propriete, "def") == 0 && tech->tours_actifs ==0) {
        if (strcmp(tech->operation, "div") == 0) {
            cible->def = cible->def/tech->valeur;

            if (cible->def < 0) {
                cible->def = 0;
            }

            printf("%s perd %.0f de defense !\n", cible->nom, (tech->valeur-1)*100);
        }


        else if (strcmp(tech->operation, "mul") == 0) {
            utilisateur->def = tech->valeur* utilisateur->def;
            if (utilisateur->def>=80){
                utilisateur->def= 80;
            }




            printf("%s gagne %.0f%% de defense !\n", utilisateur->nom, (tech->valeur-1)*100);
        }


        else if (strcmp(tech->operation, "sub") == 0) {
            cible->def = cible->def-tech->valeur;

            if (cible->def < 0) {
                cible->def = 0;
            }

            printf("%s perd %.0f de defense !\n", cible->nom, tech->valeur);
        }


        else if (strcmp(tech->operation, "add") == 0) {
            utilisateur->def = utilisateur->def+tech->valeur;

            if (utilisateur->def > 80) {
                cible->def = 80;
            }

            printf("%s gagne %.0f de defense !\n", cible->nom, tech->valeur);
        }

    }



    tech->recharge_restante = tech->recharge_max;

}
