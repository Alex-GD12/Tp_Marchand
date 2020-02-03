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
	
	for (int i = 0; i<50; i++) {
		if (strcmp(inventaire[i].nom , "") > 0){
			int nbSlot = i+1;
			printf ("\nCase %d : %s",nbSlot, inventaire[i].nom);
			
		}
		
	}
};

void sortInventory(item * inventaire){
	
    int tamponPrix = 0;
    char tamponNom[30];

    for(int i=0; i<49; i++){
        for(int j=(i+1); j<50; j++){
            if(strcmp(inventaire[j].nom, "") >0){
                for(int k=0; k<30; k++){
                    if(strncmp(inventaire[i].nom, inventaire[j].nom, k) > 0 ){
                        strcpy(tamponNom, inventaire[i].nom);
                        strcpy(inventaire[i].nom, inventaire[j].nom);
                        strcpy(inventaire[j].nom, tamponNom);

                        tamponPrix = inventaire[i].prix;
                        inventaire[i].prix = inventaire[j].prix;
                        inventaire[j].prix = tamponPrix;
						k = 30;
                    }
                }
            }
        }

    }

};

void viewMerchantStore (item * inventaire) {
	
	for (int i = 0; i<50; i++) {
		if (strcmp(inventaire[i].nom , "") > 0){
			int nbSlot = i + 1;
			printf ("\nCase %d : %s", nbSlot, inventaire[i].nom);
			printf (" | PRIX : %d\n", inventaire[i].prix);
			
		}
		
	}
	printf ("\n*************************************************************************************************************\n");
};

void sortStore(item * inventaire){
	
    int tamponPrix = 0;
    char tamponNom[30];

    for(int i=0; i<49; i++){
        for(int j=(i+1); j<50; j++){
			if (strcmp(inventaire[j].nom , "") > 0){
				if(inventaire[i].prix > inventaire[j].prix){
					
					strcpy(tamponNom, inventaire[i].nom);
					strcpy(inventaire[i].nom, inventaire[j].nom);
					strcpy(inventaire[j].nom, tamponNom);
					
					tamponPrix = inventaire[i].prix;
					inventaire[i].prix = inventaire[j].prix;
					inventaire[j].prix = tamponPrix;
				}
			}
        }

    }
	
	

};

void addMerchantItem (item * inventaire) {
	char nom [30];
	int prix;
	printf (" Objet : ");
	scanf ("%s", &nom);
	printf (" Prix : ");
	scanf ("%d", &prix);
	
	
	for(int i=0; i<50; i++){
        if(strcmp (inventaire[i].nom , "") == 0 ){
			strcpy (inventaire[i].nom , nom);
			inventaire[i].prix = prix;
			i=50;
        }
	}
};

void buyItem (item * inventaire, item * objet) {
	int nSlot;
	printf(" Choisissez un objet dans mon echope en tappant son numero !\n");
	scanf ("%d", &nSlot);
	nSlot -= 1;
	
	for(int i=0; i<50; i++){
        if(strcmp (inventaire[i].nom , "") == 0 ){
			strcpy (inventaire[i].nom ,objet[nSlot].nom);
			inventaire[i].prix = objet[nSlot].prix;
			strcpy(objet[nSlot].nom, "");
			objet[nSlot].prix=0;
			i=50;
        }
	}
	
};

//Début
int main () {
	
	
	//Definition des structures
	item inventaireJoueur [50] = { {"Briquet", 10}, {"Chemise", 3}, {"Pantalon", 4}, {"Bottes", 6} };
	
	item MerchantStore [50] = { {"ceinture", 10}, {"sac a dos", 15}, {"casquette", 5}, {"arc", 20} };
	
	
	//Inventaire joueur
	printf ("\nVOTRE INVENTAIRE : \n");
	printf ("___________________\n");
	sortInventory (&inventaireJoueur[0]);
	viewInventory (&inventaireJoueur[0]);
	printf ("\n*************************************************************************************************************\n");
	
	//Inventaire Marchand
	printf ("\nMAGASIN DU MARCHAND : \n");
	printf ("___________________\n");
	sortStore (&MerchantStore[0]);
	viewMerchantStore(&MerchantStore[0]);
	printf ("\n*************************************************************************************************************\n");
		
	//Commande
	printf ("\n Quel objet souhaitez vous commander ?\n");
	addMerchantItem (&MerchantStore[0]);
	sortStore (&MerchantStore[0]);
	viewMerchantStore (&MerchantStore[0]);
	printf ("\n*************************************************************************************************************\n");
	
	//Achat
	printf ("\n Que voulez vous acheter ?\n");
	buyItem (&inventaireJoueur[0], &MerchantStore[0] );
	sortInventory (&inventaireJoueur[0]);
	viewInventory (&inventaireJoueur[0]);
	sortStore (&MerchantStore[0]);
	
	printf ("\n*************************************************************************************************************\n");
	return 0;
}