#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "admin.h"
Admin cherche(char * filename, int id)
{
  Admin A;
  
  int i;
  FILE * f= fopen("admin.txt","r");
  if(f!=NULL)
  {
    while(i==0 && fscanf(f,"%d %d  \n",&A.id,&A.mp)!=EOF)
     {
         if(A.id == id)
               i=1;
      }
    }
    fclose(f);
    if(i==0)
        A.id=-1;
     return A;
}

