/*
 -------------------------------------------------
 -- Projet : ProjectProg2023
 -- Fichier : EngistrementLogs.c
 -- Versions : 1.0
 -- Date : 04.06.23
 -- Autheur : Léo Mendes , Antonio DoCarmo
 -------------------------------------------------
*/
//--- librairie standart ---//
#include <stdio.h>
#include <time.h>

//-- librairie personnelle --//  
#include "Fonctions.h"
void recuperationCompteur() {
	char ligne[256];
	//Ouverture du fichier en mode read
	FILE* file = fopen("logs.txt", "r");	
	//Si le fichier n'est pas présent
	if (file == NULL) {
		file = fopen("logs.txt", "w"); // Création du fichier s'il n'existe pas
		//Si la création du code n'est pas valable
		if (file == NULL) {
			printf("Erreur lors de la création du fichier de logs.\n");
			return;
		}
	}

	while (fgets(ligne, sizeof(ligne), file)) {
		if (sscanf(ligne, "Compteur utilisation de fonction trigonométrique : %d", &compteurTrigonometrie) == 1) {
			break; // Sortir de la boucle si la ligne avec le numéro du compteur est trouvée
		}
	}
	while (fgets(ligne, sizeof(ligne), file)) {
		if (sscanf(ligne, "Compteur utilisation de fonction binaire : %d", &compteurConversionBinaire) == 1) {
			break; // Sortir de la boucle si la ligne avec le numéro du compteur est trouvée
		}
	}
	// Fermeture du fichier
	fclose(file);
}

void Ecriturelogs(const char* message) {
	//Ouverture du fichier en mode read et write
	FILE* file = fopen("logs.txt", "r+");
	if (file == NULL) {
		//Si la création du code n'est pas valable
		file = fopen("logs.txt", "w"); // Création du fichier s'il n'existe pas
		//Si la création du fichier n'est pas valable
		if (file == NULL) {
			printf("Erreur lors de la création du fichier de logs.\n");
			return;
		}
	}

	// Réécriture des deux premières lignes
	fprintf(file, "Compteur utilisation de fonction binaire : %02d\n", compteurConversionBinaire);
	fprintf(file, "Compteur utilisation de fonction trigonométrique : %02d\n", compteurTrigonometrie);

	// Déplacement du curseur de fichier à la fin pour ajouter le message
	fseek(file, 0, SEEK_END);

	//--Obtention de la date et de l'heure actuelles--//
	//Déclarartion d'une variable now de type time_t, qui est utilisée pour stocker la date et l'heure actuelles.
	time_t now;
	//Utilisation de la fonction time() pour obtenir la date et l'heure actuelles, puis assigne cette valeur à la variable now.
	time(&now);
	//déclaration pointeur de type struct tm appelé timeinfo qui recois l'adresse de la variable now pour reception des donnée de l'heure
	struct tm* timeinfo = localtime(&now);

	// Écriture de la date et de l'heure actuelles
	fprintf(file, "%02d.%02d.%04d - %02d:%02d\n",
		timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
		timeinfo->tm_hour, timeinfo->tm_min);

	// Écriture du message
	fprintf(file, "%s\n", message);

	// Fermeture du fichier
	fclose(file);
}