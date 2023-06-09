/*
 -------------------------------------------------
 -- Projet : ProjectProg2023
 -- Fichier : ConversionBinaire.c
 -- Versions : 1.0
 -- Date : 30.05.23
 -- Autheur : Léo Mendes , Antonio DoCarmo
 -------------------------------------------------
*/

//--- librairie standart ---//
#include <stdio.h>
//-- librairie personnelle --//  
#include "Fonctions.h"

// Fonction de conversion binaire
void convertToBinary()
{
	//-- Déclaration des variables --//

	int valEntier = 0;
	float valeurDecimale = 0;
	int moduloValEntier = 0;
	float testVariable = 0;
	float testModValDec = 0;
	int modeValide = 0;
	int saisieValide = 0;
	int tailleEnt = 0;
	int tailleDec = 0;
	int retenue = 1;
	int somme = 0;
	float valueUser;
	int modeDigit;
	int mode = 0;
	const MODE0 = 0;
	const MODE8 = 8;
	const MODE16 = 16;
	const MODE32 = 32;
	int tabEntier[33];
	int tabDecimal[33];
	int valEntBin = 0;
	int valDecBin = 0;
	int taille = 0;
	char logMessage[200] = "";
	char valeur[2]; // Chaîne de caractères pour stocker chaque valeur

	//-- Gestion des saisies de l'utilisateur --//

	do {
		printf("Entrez une valeur a convertir : ");
		scanf("%f", &valueUser); //Recupération de la saisie de l'utilisateur

		if (valueUser >= 0 || valueUser == (int)valueUser) {  //Test pour savoir si le nombre n'es pas négatif à virgules
			saisieValide = 1; //Si oui -> saisie valide
		}
		else {
			printf("Saisie invalide. Veuillez entrer une valeur negative sans virgule.\n"); //Si non -> saisie invalide
		}
	} while (saisieValide == 0); //Si la saisie est valide on sort de la boucle

	do {
		printf("Selectionnez le mode d'affichage\n 0 = normal\n 1 = 8 bits\n 2 = 16 bits\n 3 = 32 bits\n");
		scanf("%d", &modeDigit); //Récupération du mode d'affichage

		switch (modeDigit) { //Test si le mode est valide
			case 0:
				mode = MODE0;
				modeValide = 1;
				break;
			case 1:
				mode = MODE8;
				modeValide = 1;
				break;
			case 2:
				mode = MODE16;
				modeValide = 1;
				break;
			case 3:
				mode = MODE32;
				modeValide = 1;
				break;
			default:
				printf("Saisie invalide\n"); //Mode sélectionné invalide
		}
	} while (modeValide == 0); //Si la saisie est valide on sort de la boucle
	
	valEntier = (int)valueUser; //Récupération de la valeur entière de la saisie de l'utilisateur
	valeurDecimale = valueUser - valEntier; //Récupération de la valeur décimale de la saisie de l'utilisateur

	if (valEntier < 0) { //Si la valeur entière est négative on la rend positive
		valEntier = -valEntier;
	}

	//-- Mise dans un tableau de la valeur entière --//

	for (int i = 0; valEntier > 0; i++) {
		moduloValEntier = valEntier % 2; //Modulo par 2 de la valeur entière
		tabEntier[i] = moduloValEntier; //Mise dans un tableau de la valeur
		valEntier = valEntier / 2; //Division de la valeur entière par deux
		tailleEnt++; //Actualisation de la taille de l'entier
	}

	//-- Mise dans un tableau de la valeur décimale --//

	if (valeurDecimale != 0) {
		for (int i = 0; valeurDecimale != 1; i++) {
			tailleDec++; //Actualisation de la taille de la valeur décimale
			valeurDecimale = valeurDecimale * 2; //Multiplication par 2 de la valeur décimale

			if (valeurDecimale < 1) { // si la résultat est plus petit que 1 on inscrit un 0
				tabDecimal[i] = 0;
			}
			else if (valeurDecimale >= 1) { // si la résultat est plus grand ou égal à 1 on inscrit un 1
				tabDecimal[i] = 1;
			}
			if (valeurDecimale == 1) {  //Si la résultat vaut 1 -> conversion finie -> on sort de la boucle
				break;
			}
			else if (valeurDecimale > 1) {  //Sinon on soustrait 1 pour continuer la conversion
				valeurDecimale = valeurDecimale - 1;
			}
		}
	}

	//-- Cas valeur négative --//

	if (valueUser < 0) {
		if (valeurDecimale == 0) {
			for (int i = 0; i < tailleEnt; i++) { //Complément à 1
				tabEntier[i] = -tabEntier[i];
			}

			for (int i = tailleEnt - 1; i >= 0; i--) {
				somme = tabEntier[i] + retenue; // Addition du bit actuel et du bit de retenue

				if (somme == 2) {
					tabEntier[i] = 0;
					retenue = 1; // Débordement, donc le bit de retenue reste à 1
				}
				else {
					tabEntier[i] = somme;
					retenue = 0; // Pas de débordement, donc le bit de retenue devient 0
					break; // Arrêter l'addition car pas besoin de continuer
				}
			}

			if (mode == MODE0) { //Mode 0 impossible avec chiffre négatif
				printf("Impossible avec un chiffre negatif. Veuillez choisir un autre mode\n");
			}

			else {
				printf("0b");

				for (int i = 0; i < mode; i++) { //Affichage de la valeur
					if (tabEntier[i] == 1) {
						printf("1");
					}
					else {
						printf("0");
						tabEntier[i] = 0;
					}
				}
			}
		}
		printf("\n");
	}

	//-- Cas valeur à virgules --//

	else if (valeurDecimale > 0) {
		printf("0b");

		if (mode != MODE0) {
			tailleDec = mode - tailleEnt;
		}

		for (int i = 0; i < tailleEnt; i++) { //Partie entière
			if (tabEntier[i] == 1) {
				printf("1");
			}
			else {
				printf("0");
				tabEntier[i] = 0;
			}
		}
		printf(".");
		for (int i = 0; i < tailleDec; i++) {//Partie décimale
			if (tabDecimal[i] == 1) {
				printf("1");
			}
			else {
				printf("0");
				tabEntier[i] = 0;
			}
		}
		printf("\n");
	}
		

	//-- Cas valeur entière --//

	else {
		printf("0b");

		if (mode != MODE0) {
			tailleEnt = mode;
		}

		for (int i = 0; i < tailleEnt; i++) {
			if (tabEntier[i] == 1) {
				printf("1");
			}
			else {
				printf("0");
				tabEntier[i] = 0;
			}
		}
		printf("\n");
	}

	//-- Mise des valeurs dans une variable --//

	taille = 0;

	for (int j = 0; j < tailleEnt; j++) {
		sprintf(valeur, "%d", tabEntier[j]); // Convertir l'entier en chaîne de caractères
		strcat(logMessage, valeur); // Concaténer la valeur à logMessage
	}

	// Vérifier si la valeur décimale est présente
	if (valeurDecimale != 0) {
		strcat(logMessage, "."); // Ajouter un point entre la partie entière et la partie décimale
		for (int j = 0; j < tailleDec; j++)
		{
			sprintf(valeur, "%d", tabDecimal[j]); // Convertir l'entier en chaîne de caractères
			strcat(logMessage, valeur); // Concaténer la valeur à logMessage
		}
	}
	//Addition du compteur d'ulitisation de la fonction trigonométrique 
	compteurConversionBinaire++;
	// Appel de la fonction logToFile pour enregistrer les informations
	//Récupère la valeur finale en binaire type 0b0101010 à  la place de val utilisateur
	Ecriturelogs(logMessage);
}