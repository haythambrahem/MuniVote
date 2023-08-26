#include "authentification.h"
#include <stdio.h>
#include "admin.h"
#include <string.h>

int verif (char id[], char mp[])
{
int trouve=-1;
FILE * f = NULL;
char ch1[20], ch2[20];
f=fopen("admin.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
  if((strcmp(ch1,id)==0) && (strcmp(ch2,mp)==0))
  {
    trouve=1;
  }
  fclose(f);
}
}
return(trouve);
}


