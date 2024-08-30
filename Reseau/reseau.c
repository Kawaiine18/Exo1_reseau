#include "reseau.h"
char* getdata (char* ip)
{
    int d = 255;
    char* A = NULL;
    A = (char*)malloc(d*sizeof(char));
    printf("Entrez votre ip:");
    scanf("%s",A);
    return (A);
}
void verification(char* ip)
{
    int IP[4];
    char delim;
    int i;
    int j;
    int k;
    int c = 256;
    if(sscanf(ip,"%d%c%d%c%d%c%d",&IP[0],&delim,&IP[1],&delim,&IP[2],&delim,&IP[3]) != 7)
    {
        printf("IP invalid\n");
    }
    else if(IP[0] < 0 || IP[1] < 0 || IP[2] < 0 || IP[3] < 0 || IP[0] > c || IP[1] > c || IP[2] > c || IP[3] > c)
    {
        printf("IP invalide !!\n");
    }
    else
    {
        for(i = 0; i < 4 ; i++)
        {
            if(IP[i] >= 0 && IP[i] < c)
            {
                if(IP[i] >= 0 && IP[i] < 128)
                {
                    printf("L'addresse IP est de classe A\n");
                    printf("Masque de sous reseau: 255.0.0.0\n"); 
                    printf("L'IP du reseau: %d.0.0.0\n",IP[i]);
                    printf("L' IP du broadcast: %d.255.255.255\n",IP[i]);
                    printf("Nombre de machine pouvont etre connecter: %.0f\n",(pow(2,24)-2));
                    break;
                }
                else if(IP[i] >= 128 && IP[i] < 192)
                {
                    printf("L'addresse IP est de classe B\n");
                    printf("Masque de sous reseau : 255.255.0.0\n");
                    printf("L'IP du reseau: %d.%d.0.0\n",IP[i],IP[i+1]);
                    printf("l'IP du broadcast: %d.%d.255.255\n",IP[i],IP[i+1]);
                    printf("Nombre de machine pouvont etre connecter: %.0f\n",(pow(2,16)-2));
                    break;        
                }
                else if(IP[i] >= 192 && IP[i] < 224)
                {
                    printf("l'addrese IP est de classe C\n");
                    printf("Masque de sous reseau: 255.255.255.0\n");
                    printf("l'IP du reseau: %d.%d.%d.0\n",IP[i],IP[i+1],IP[i+2]);
                    printf("l'IP du broadcast: %d.%d.%d.255\n",IP[i],IP[i+1],IP[i+2]);
                    printf("Nombre de machine connecter: %.0f\n",(pow(2,8)-2));
                    break;
                }
            }
            break;
        }   
    }
}