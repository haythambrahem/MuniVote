#include "observateur.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
	EID,
	ENOM,
	EPRENOM,
        EIDBV,
	EPROFESSION,
	EGENRE,
	ENATION,
	ENBVOTE,
	ECOLUMNS,
};


int ajouter_observateur(char filename[], observateur o)
{
    FILE *f;
f=fopen("observateur.txt","a");
    if(f!=NULL)
    {
	fprintf(f,"%d %s %s %s %s %d  %d  %s\n",o.idob,o.nom,o.prenom,o.nationalite,o.sexe,o.age,o.idBV,o.profession);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier_observateur(int id,observateur nouv )
{
    int tr=0;
    observateur anc;
    FILE *f=fopen("observateur.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %s %s  %s\n",&anc.idob,anc.nom,anc.prenom,&anc.idBV,anc.nationalite,anc.sexe,anc.profession)!=EOF)
        {
            if(anc.idob==id)
            {
                fprintf(f2,"%d %s %s %d %s %s %s\n",nouv.idob,nouv.nom,nouv.prenom,nouv.idBV,nouv.nationalite,nouv.sexe,nouv.profession);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %d %s %s  %s\n",anc.idob,anc.nom,anc.prenom,anc.idBV,anc.nationalite,anc.sexe,anc.profession);

        }
    }
    fclose(f);
    fclose(f2);
    remove("observateur.txt");
    rename("nouv.txt","observateur.txt");
    return tr;

}
int supprimer_observateur(int id)
{
    int tr=0;
    observateur o;
    FILE *f=fopen("observateur.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %s %s  %s\n",&o.idob,o.nom,o.prenom,&o.idBV,o.nationalite,o.sexe,o.profession)!=EOF)
        {
            if(o.idob==id)
                tr=1;
            else
                fprintf(f2,"%d %s %s %d %s %s  %s\n",o.idob,o.nom,o.prenom,o.idBV,o.nationalite,o.sexe,o.profession);
        }
    }
    fclose(f);
    fclose(f2);
    remove("observateur.txt");
    rename("nouv.txt","observateur.txt");
    return tr;
}

int chercher_obser(char*filename , int id )
{
    observateur o;
    int tr=0;
    FILE *f=fopen(filename,"r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %d %s %s  %s\n",&o.idob,o.nom,o.prenom,&o.idBV,o.nationalite,o.sexe,o.profession)!=EOF)
        {
            if(o.idob==id)
                tr=1;		
        }
    }
    fclose(f);
    
    return tr;
}
int nbobservateur(char*filename)
{
   observateur o;
   int nbr=0;
   char k[]="Observateur";
   FILE*f=fopen(filename,"r");
  if(f!=NULL)
{ while(fscanf(f,"%d %s %s %d %s %s  %s\n",&o.idob,o.nom,o.prenom,&o.idBV,o.nationalite,o.sexe,o.profession)!=EOF)
{ if(strcmp(o.profession,k)==0)
	{ nbr=nbr+1;

}
}
}
fclose(f);
return nbr ;
}
float taux (char*filename)
{ 
observateur o ;
int nbn=0, n=0 ;
float l;

char t[]="Tunisien";
FILE*f=fopen(filename,"r");
if(f!=NULL)
{ while(fscanf(f,"%d %s %s %d %s %s  %s\n",&o.idob,o.nom,o.prenom,&o.idBV,o.nationalite,o.sexe,o.profession)!=EOF)
{
n++;
if(strcmp(o.nationalite,t)==0)
nbn++;

}
}
l=((nbn*100)/n);

fclose(f);
return l;
}



void afficher_observateur(GtkWidget *liste,char *fname){
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    observateur o ;
    char ido[20];
    char nBV[40];
   
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prénom",renderer,"text",EPRENOM,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Profession",renderer,"text",EPROFESSION,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nationalité",renderer,"text",ENATION,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Genre",renderer,"text",EGENRE,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("idBV",renderer,"text",EIDBV,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	
    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen(fname,"r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%d %s %s %d %s %s %s %s %s\n",&o.idob,o.nom,o.prenom,&o.idBV,o.nationalite,o.sexe,o.profession)!=EOF){
			sprintf(ido,"%d",o.idob);
			sprintf(nBV,"%d",o.idBV);

			          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,ido,ENOM,o.nom,EPRENOM,o.prenom,EPROFESSION,o.profession,ENATION,o.nationalite,EGENRE,o.sexe,EIDBV,nBV,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
}
    



