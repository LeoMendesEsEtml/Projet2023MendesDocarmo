/*
 -------------------------------------------------
 -- Projet : ProjectProg2023
 -- Fichier : Fonctions.h
 -- Versions : 1.0
 -- Date : 30.05.23
 -- Autheur : Léo Mendes , Antonio DoCarmo
 -- Description : programme principal utilisé pour projet de prog 2023
 -------------------------------------------------
*/

//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <math.h>

//-- librairie personnelle --//                                                                                                                                                                                                                                                                                                                  
#include "Fonctions.h"

//-- Variable globale --//  
int compteurConversionBinaire = 0;
int compteurTrigonometrie = 0;

//-- programme princiaple --// 
int  main()
{
	int choixUtilisateur;

	//Récupération du compteur dans fichier logs
	recuperationCompteur();

	while (1) {
		printf("Choisir entre conversion ou calcul de triangle [1 pour calcul triangle , 2 pour conversion, 3 pour quitter ] :  ");
		scanf("%d", &choixUtilisateur);
		// Option du programme
		switch (choixUtilisateur) {
		case 1:
			calculateTriangle();
			break;
		case 2:
			convertToBinary();
			break;
		case 3:
			exit(0);  // Quitter le programme
		default:
			printf("Choix invalide. Veuillez choisir une option valide.\n");
			break;
		};
	}
}
