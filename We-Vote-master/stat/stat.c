#include <stdio.h>
#include <string.h>
#include "stat.h"
void taux ( char * filename , float * tn, float * te){
    int tun=0,etr=0;
    
    FILE *f=fopen("obs.txt","r");
    observateur o;
    if(f!=NULL){
        while(fscanf(f,"%d %s %s %d %s %d %d",&o.id,o.nom,o.prenom,&o.idBV,o.nationalite,&o.sexe,&o.profession)!= EOF){
            if(strcmp(o.nationalite,"tunisien")==0){//if char
                tun+=1;
            }
            else if(strcmp(o.nationalite,"etrange")==0){//if char
                etr+=1;
            }
        }
    }


*tn=((float)tun/(tun+etr))*100;
     *te=((float)etr/(tun+etr))*100;
}
float TVB (char * filename)  { 

    int  n=0;
    float tvb=0;
    User u;
    FILE * f=fopen("user.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d  ",u.Nom,u.Prenom,&u.cin,&u.idBV,&u.Role,&u.sexe,&u.Vote,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
                  {
                  if (u.Vote!=-1)
			n=n+1;

                  if (u.Vote==0)
			tvb = tvb+1 ;
                   }
        tvb=(tvb/n)*100;
      }
fclose(f);

   return tvb ;
}
