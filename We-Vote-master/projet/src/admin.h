#define ADMIN_H_INCLUDED
#include <stdio.h>

typedef struct
{
 int id;
 int mp;
 
} Admin;

Admin cherche(char * filename, int id);
