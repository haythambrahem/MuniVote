#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED
typedef struct
{
    int id;
    char nom[20];
    char prenom[20];
    int idBV;
    char nationalite[20];
    int profession;
    int sexe;
} observateur;

typedef struct 
{ int jour;
 int mois;
 int annee; } Date; 
typedef struct
 { char Nom[20];
 char Prenom[20]; 
int cin;
 Date d; 
int sexe;
 int etatSocial;
 int Role;
 int idBV;
 int Vote; } User; 
#endif
float TVB (char * filename);
void taux ( char * filename , float * tn, float * te);
