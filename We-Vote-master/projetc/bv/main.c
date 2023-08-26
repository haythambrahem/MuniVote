#include <stdio.h>
#include <stdlib.h>
#include "bv.h"

int main(){
	int choix,ID_modifier,ID_supprimer;
int resultat_afficher;
	
	BVOTE p,nouv;
	do{
		do{
			printf("----------------MENU--------------------\n");
			printf("1) Ajouter un bureau de vote\n");
			printf("2) Modifier un bureau de vote\n");
			printf("3) Supprimer un bureau de vote\n"); 
			printf("4) Afficher les bureaux de votes\n");
			printf("0) Quitter\n");
			printf("Donner votre choix:");
			scanf("%d",&choix);
		}while(choix<0 || choix>4);
		switch(choix){
			case 1:
				printf("donnez l'identifient de bureau de vote:");
	scanf("%d",&p.ID);
	fflush(stdin);
	printf("donnez l'identifient d'agent de bureau de vote:");
	scanf("%d",&p.IDAGBV);
	fflush(stdin);
	printf("donnez la region de bureau de vote:");
	scanf("%s",p.Region);
	fflush(stdin);
	printf("donnez la municipalite de bureau de vote:");
	scanf("%s",p.Mnp);
	fflush(stdin);
	printf("donnez l'adress de bureau de vote:");
	scanf("%s",p.Adresse);
	fflush(stdin);
	printf("donnez les nombre des salles de bureau de vote:");
	scanf("%d",&p.salle);
	printf("donnez la capacite des electeurs de bureau de vote:");
	scanf("%d",&p.cpt_elec);
	fflush(stdin);
	printf("donnez la capacite des observateurs de bureau de vote:");
	scanf("%d",&p.cpt_obser);
	
				int resulat_ajouter=ajouterbv(p);
				if(resulat_ajouter==0){
					printf("erreur \n");
				}
				else{
					printf("Ajout avec succes\n");
				}
				break;

			case 2:
				printf("Donner l'id du liste a modifier:");
				scanf("%d",&ID_modifier);
				if(recherchebv(ID_modifier)==0){
					printf("liste introuvable\n");
				}
				else{
	printf("donnez l'identifient d'agent de bureau de vote:");
	scanf("%d",&nouv.IDAGBV);
	fflush(stdin);
	printf("donnez la region de bureau de vote:");
	scanf("%s",nouv.Region);
	fflush(stdin);
	printf("donnez la municipalite de bureau de vote:");
	scanf("%s",nouv.Mnp);
	fflush(stdin);
	printf("donnez l'adress de bureau de vote:");
	scanf("%s",nouv.Adresse);
	fflush(stdin);
	printf("donnez les nombre des salles de bureau de vote:");
	scanf("%d",&nouv.salle);
	printf("donnez la capacite des electeurs de bureau de vote:");
	scanf("%d",&nouv.cpt_elec);
	fflush(stdin);
	printf("donnez la capacite des observateurs  de bureau de vote:");
	scanf("%d",&nouv.cpt_obser);
	
	int resulat_modification=modifierbv(ID_modifier,nouv);
					if(resulat_modification==0){
						printf("erreur \n");
					}
					else{
						printf("Modification avec succes\n");
					}
				}
				break;
			case 3:
				printf("Donner l'id du liste a supprimer:");
				scanf("%d",&ID_supprimer);
				if(recherchebv(ID_supprimer)==0){
					printf("liste introuvable\n");
				}
				else{
		int resulat_supprimer=supprimerbv(ID_supprimer);
					if(resulat_supprimer==0){
						printf("erreur \n");
					}
					else{
						printf("Methode a supprimer avec succes\n");
					}
				}
				break;
			case 4:
				resultat_afficher=afficherbv();
				if(resultat_afficher==0){
						printf("erreur \n");
				}
				break;
		}
	}while(choix!=0);
	

	return 0;
}
