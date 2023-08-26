#include <gtk/gtk.h>
typedef struct{
int  idob;
char nom[20];
char prenom[20];
int  idBV;
int  age;
char nationalite[30];
char sexe[20];
char profession[20];
}observateur;

int ajouter_observateur(char filename[], observateur o);
int modifier_observateur( int id,observateur nouv);
int supprimer_observateur(int id );
int chercher_obser(char*filename , int id );
int nbobservateur (char*filename);
float taux (char*filename);
void afficher_observateur(GtkWidget *liste,char *fname);

