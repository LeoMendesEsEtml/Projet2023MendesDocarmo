/*
-------------------------------------------------
-- Projet : ProjectProg2023
-- Fichier : CalculTriangle.c
-- Version : 1.0
-- Date : 30.05.23
-- Auteur : L�o Mendes, Antonio DoCarmo
-------------------------------------------------
*/
//--- librairie standart ---//
#include <stdio.h>
#include <math.h>

//-- librairie personnelle --//  
#include "Fonctions.h"

// Fonction de calcul trigonom�trique
void calculateTriangle() {
	Triangle triangle;
	char logMessage[200];
	float abscisse;
	float coteOppose;
	float hypotenuse;
	int unite;
	while (1) {
		printf("Entrez les valeurs de l'abscisse [0 si la valeur est a calculer] :  ");
		scanf("%f", &abscisse);
		printf("Entrez les valeurs du cote oppose [0 si la valeur est a calculer] : ");
		scanf("%f", &coteOppose);
		printf("Entrez les valeurs de l'hypotenuse [0 si la valeur est a calculer] : ");
		scanf("%f", &hypotenuse);
		printf("Choisissez l'unite de l'angle [1 pour radian, 2 pour degre] : ");
		scanf("%d", &unite);

		// Validation des valeurs entr�es par l'utilisateur
		if (abscisse < 0 || coteOppose < 0 || hypotenuse < 0) {
			printf("Erreur : Les valeurs doivent etre positives ou nulles.\n");
		}
		else
		{
			break;  // Quitter la boucle si la condition est remplie
		}
	}

	// Calcul de l'abscisse, du c�t� oppos� et de l'hypot�nuse si n�cessaire
	if (abscisse == 0) {
		if ((coteOppose * coteOppose) >= (hypotenuse * hypotenuse)) {
			printf("Erreur : Les valeurs des cotes ne permettent pas de calculer l'abscisse.\n");
			return;
		}
		abscisse = sqrt((hypotenuse * hypotenuse) - (coteOppose * coteOppose));
	}
	else if (coteOppose == 0) {
		if ((abscisse * abscisse) >= (hypotenuse * hypotenuse)) {
			printf("Erreur : Les valeurs des cotes ne permettent pas de calculer le cote oppose.\n");
			return;
		}
		coteOppose = sqrt((hypotenuse * hypotenuse) - (abscisse * abscisse));
	}
	else if (hypotenuse == 0) {
		hypotenuse = sqrt((coteOppose * coteOppose) + (abscisse * abscisse));
	}
	
	// Calcul de l'angle alpha
	if (unite == 1) {
		// Calcul pour trouv� l'angle alpha en radians
		triangle.angle.radians = atan(abscisse / coteOppose);
		printf("Angle A: %.2f rad\n", triangle.angle.radians);
	}
	else {
		// Calcul pour trouv� l'angle alpha en degr�e
		triangle.angle.degres = (int)(atan(abscisse / coteOppose) * 180 / PI);
		printf("Angle A: %d degres\n", triangle.angle.degres);
	}
	// Calcul et r�cup�ration des autres valeurs trigonom�triques
	triangle.abscisse = abscisse;
	triangle.coteOppose = coteOppose;
	triangle.hypotenuse = hypotenuse;
	triangle.cosinus = coteOppose / hypotenuse;
	triangle.sinus = abscisse / hypotenuse;
	triangle.tangente = abscisse / coteOppose;

	// Affichage des valeurs calcul�es
	printf("Abscisse: %.2f\n", triangle.abscisse);
	printf("Cote oppose: %.2f\n", triangle.coteOppose);
	printf("Hypotenuse: %.2f\n", triangle.hypotenuse);
	printf("Sinus: %.2f\n", triangle.sinus);
	printf("Cosinus: %.2f\n", triangle.cosinus);
	printf("Tangente: %.2f\n", triangle.tangente);

	// Appel de la fonction logToFile pour enregistrer les informations
	compteurTrigonometrie++;
	//utilisation de la fonction sprintf() pour formater une cha�ne de caract�res logMessage avec les valeurs des attributs du triangle
	sprintf(logMessage, "Abscisse: %.2f, Cote oppose: %.2f, Hypotenuse: %.2f, Sinus: %.2f, Cosinus: %.2f, Tangente: %.2f",
		triangle.abscisse, triangle.coteOppose, triangle.hypotenuse, triangle.sinus, triangle.cosinus, triangle.tangente);
	//Appel de la fonction permettant l'�criture des logs
	Ecriturelogs(logMessage);
}