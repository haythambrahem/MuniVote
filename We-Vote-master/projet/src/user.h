
#define USER_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct
{
 int jour;
 int mois;
 int annee;
} Date;
typedef struct
{
 char Nom[20];
 char Prenom[20];
 int cin;
 Date d;
 int sexe;
 int nationalite;
 int etatSocial;
 char municipalite[20];
 char gouvernorat[20];
 int Role;
 int idBV;
 int Vote;
} User;
typedef struct
{
 int id;
 int mp;
}admin;

 

int ajouter(char filename[], User U);
int modifier(char * filename,int cin, User New);
int supprimer(char * filename,int cin);
User chercher(char* filename ,int cin);
int agemoyen(char*filename, User U);
int nbe (char*filename,int id);
int verifaj( User U, char filename[]);
void affiche_user(GtkWidget *liste);
