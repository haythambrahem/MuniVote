#include <stdio.h>
#include <string.h>
#include "stat.h"
int main()
{ 
float tn,te,y;
taux ("obs.txt",&tn,&te);
printf("\nle taux des observateurs tunisiennes %.2f %% ,et le taux des observateurs etranges %.2f %%\n",tn,te);
y=TVB("user.txt");

printf("\nle taux de votes blancs est %.2f %% \n",y);

return 0 ;
}
