#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Objet{

	char nom [30];
	int prix;

};	

typedef struct Objet item;

void viewInventory (item * inventaire) {
	printf ("INVENTAIRE : \n");
	for (int i = 0; i<5; i++) {
		printf ("\n%s", inventaire[i].nom);
		printf (" | PRIX : %d\n", inventaire[i].prix);
		
	}
};

int main () {
	
	item inventaire [5] = { {"Briquet", 10}, {"Chemise", 3}, {"Pentalon", 4}, {"bottes", 6}, {"Rapiere", 50} };
	
	
	viewInventory (&inventaireJoueur);
	
	
	

	
	
	
	
	
	
	return 0;
}