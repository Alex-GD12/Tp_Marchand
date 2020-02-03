#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Structures
struct Objet{

	char nom [30];
	int prix;

};	
typedef struct Objet item;


//Fonctions 
void viewInventory (item * inventaire) {
	printf ("\n*************************************************************************************************************\n");
	printf ("\nVOTRE INVENTAIRE : \n");
	printf ("___________________\n");
	
	for (int i = 0; i<5; i++) {
		if (strcmp(inventaire[i].nom , "") > 0){
			printf ("\n%s", inventaire[i].nom);
			printf (" | PRIX : %d\n", inventaire[i].prix);
			
		}
		
	}
	printf ("\n*************************************************************************************************************\n");
};

void sortInventory (item * inventaire) {
	int tamponPrix;
	char tamponNom[30];
	
	for (int i = 0; i<4; i++) {
		
		for (int j = (i+1); j<5; j++) {
			
			if (strcmp(inventaire[j].nom , "") > 0){
				
				for (int k = 0; k<30; k++) {
					
					if (strncmp(inventaire[i].nom, inventaire[j].nom, k) > 0 ) {
						
						strcpy( tamponNom, inventaire[i].nom);
						strcpy( inventaire[i].nom, inventaire[j].nom);
						strcpy( inventaire[j].nom, tamponNom);
						
						tamponPrix = inventaire[i].prix;
						inventaire[i].prix = inventaire[j].prix;
						inventaire[j].prix = tamponPrix;
					}
					
				}
			
			}
		
		}
		
	}
	printf ("\nje fonctionne");
};


//Début
int main () {
	
	item inventaireJoueur [5] = { {"Briquet", 10}, {"Chemise", 3}, {"Pantalon", 4}, {"bottes", 6} };
	
	viewInventory (&inventaireJoueur[0]);
	printf ("\n");
	sortInventory (&inventaireJoueur[0]);
	printf ("\n");
	viewInventory (&inventaireJoueur[0]);
	
	return 0;
}