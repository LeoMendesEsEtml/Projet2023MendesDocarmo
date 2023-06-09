/*
 -------------------------------------------------
 -- Projet : ProjectProg2023
 -- Fichier : EngistrementLogs.c
 -- Versions : 1.0
 -- Date : 04.06.23
 -- Autheur : L�o Mendes , Antonio DoCarmo
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
	//Si le fichier n'est pas pr�sent
	if (file == NULL) {
		file = fopen("logs.txt", "w"); // Cr�ation du fichier s'il n'existe pas
		//Si la cr�ation du code n'est pas valable
		if (file == NULL) {
			printf("Erreur lors de la cr�ation du fichier de logs.\n");
			return;
		}
	}

	while (fgets(ligne, sizeof(ligne), file)) {
		if (sscanf(ligne, "Compteur utilisation de fonction trigonom�trique : %d", &compteurTrigonometrie) == 1) {
			break; // Sortir de la boucle si la ligne avec le num�ro du compteur est trouv�e
		}
	}
	while (fgets(ligne, sizeof(ligne), file)) {
		if (sscanf(ligne, "Compteur utilisation de fonction binaire : %d", &compteurConversionBinaire) == 1) {
			break; // Sortir de la boucle si la ligne avec le num�ro du compteur est trouv�e
		}
	}
	// Fermeture du fichier
	fclose(file);
}

void Ecriturelogs(const char* message) {
	//Ouverture du fichier en mode read et write
	FILE* file = fopen("logs.txt", "r+");
	if (file == NULL) {
		//Si la cr�ation du code n'est pas valable
		file = fopen("logs.txt", "w"); // Cr�ation du fichier s'il n'existe pas
		//Si la cr�ation du fichier n'est pas valable
		if (file == NULL) {
			printf("Erreur lors de la cr�ation du fichier de logs.\n");
			return;
		}
	}

	// R��criture des deux premi�res lignes
	fprintf(file, "Compteur utilisation de fonction binaire : %02d\n", compteurConversionBinaire);
	fprintf(file, "Compteur utilisation de fonction trigonom�trique : %02d\n", compteurTrigonometrie);

	// D�placement du curseur de fichier � la fin pour ajouter le message
	fseek(file, 0, SEEK_END);

	//--Obtention de la date et de l'heure actuelles--//
	//D�clarartion d'une variable now de type time_t, qui est utilis�e pour stocker la date et l'heure actuelles.
	time_t now;
	//Utilisation de la fonction time() pour obtenir la date et l'heure actuelles, puis assigne cette valeur � la variable now.
	time(&now);
	//d�claration pointeur de type struct tm appel� timeinfo qui recois l'adresse de la variable now pour reception des donn�e de l'heure
	struct tm* timeinfo = localtime(&now);

	// �criture de la date et de l'heure actuelles
	fprintf(file, "%02d.%02d.%04d - %02d:%02d\n",
		timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
		timeinfo->tm_hour, timeinfo->tm_min);

	// �criture du message
	fprintf(file, "%s\n", message);

	// Fermeture du fichier
	fclose(file);
}