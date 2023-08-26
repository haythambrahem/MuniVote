#include<stdio.h>
#include<stdlib.h>
#include "bv.h"

int ajouterbv(BVOTE p){
	FILE *f;
	f=fopen("bureauvote.txt","a+");
	if(f==NULL){
		return 0;
	}
	else{
		fprintf(f,"%d %d %s %s %s %d %d %d \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
		};
		fclose(f);
		return 1;
	}

int modifierbv(int ID_modifier,BVOTE nouv){
	BVOTE p;
	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			if(p.ID==ID_modifier){
				fprintf(f1,"%d %d %s %s %s %d %d %d  \n",ID_modifier,nouv.IDAGBV,nouv.Region,nouv.Mnp,nouv.Adresse,nouv.salle,nouv.cpt_elec,nouv.cpt_obser);
			}
			else{
				fprintf(f1,"%d %d %s %s %s %d %d %d \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);

			}
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		return 1;
	}
	
}
int supprimerbv(int ID_supprimer){
	BVOTE p;
	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		return 0;
	}
	
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
	if(p.ID!=ID_supprimer){
				fprintf(f1,"%d %d %s %s %s %d %d %d  \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
			}
			
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		return 1;
	}
}
int recherchebv(int ID_recherche){
	int trouve=0;
	BVOTE p;
	FILE *f;
	f=fopen("bureauvote.txt","r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			if(ID_recherche==p.ID)
				trouve= 1;
		}
		fclose(f);
		return trouve;
	}
}
int afficherbv(){
	BVOTE p;
	FILE *f;
	f=fopen("bureauvote.txt","r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			printf("%d %d %s %s %s %d %d %d  \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
		}
		fclose(f);
		return 1;
	}
}



