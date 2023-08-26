#ifndef bv_H_INCLUDED
#define bv_H_INCLUDED
#include <stdio.h>

typedef struct {
int ID;
int IDAGBV;
char Region[30];
char Adresse[100];
char Mnp[30];
int cpt_obser;
int cpt_elec;
int salle ;
}BVOTE;

int ajouterbv(BVOTE p);
int modifierbv(int ID_modifier,BVOTE nouv);
int supprimerbv(int ID_supprimer);
int recherchebv(int ID_recherche);
int afficherbv();
#endif
