#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define d 255
//Pour recupérer l'addresse ip entrez par l'utilisateur
char* getdata(char* ip);
//Pour recupérer le Masque de sous reseau entrez par l'utilisateur
char* getdata_2(char* netmask);
 //Pour verifier si l'addresse ip et le Masque de sous reseau est valide ou non 
void verification(char* ip,char* netmask);
//liberer les tableaux
void free_all_array(char* ip,char* netmask);
