/*
 -------------------------------------------------
 -- Projet : ProjectProg2023			
 -- Fichier : Fonctions.h					
 -- Versions : 1.0								
 -- Date : 30.05.23								
 -- Autheur : Léo Mendes , Antonio DoCarmo						
 -------------------------------------------------
*/

#ifndef FONCTIONS
#define FONCTIONS

//Définition de PI
#define PI 3.14159265359

// Déclaration de la variable globale : 
extern int compteurTrigonometrie; 
extern int compteurConversionBinaire; 

// Déclaration de type de structure triangle 
typedef struct {
	float abscisse;
	float coteOppose;
	float hypotenuse;
	float sinus;
	float cosinus;
	float tangente;
	union {
		int degres;
		float radians;
	} angle;
} Triangle;

//--Prototype de fonctions--//

// Fonction de récupération des compteur 
void recuperationCompteur();
// Fonction d'enregistrement des informations dans un fichier
void Ecriturelogs(const char* message);
// Fonction de conversion binaire
//void convertToBinary(float value, int numBits);
void convertToBinary2();
// Calcul des triangles
void calculateTriangle();
#endif
