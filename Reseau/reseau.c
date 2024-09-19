#include "reseau.h"
char* getdata (char* ip)
{
    char* A = NULL;
    A = (char*)malloc(d*sizeof(char));
    printf("Entrez votre ip:");
    scanf("%s",A);
    return (A);
}
char* getdata_2(char* netmask)
{
    char* MSR = NULL;
    MSR = (char*)malloc(d*sizeof(char));
    printf("Entrez le netmask: ");
    scanf("%s",MSR);
    return (MSR);
}
void verification(char* ip,char* netmask)
{
    int IP[4];
    int MSR[4];
    int i;
    int j;
    int k;
    int c = 256;
    if(sscanf(netmask,"%d.%d.%d.%d",&MSR[0],&MSR[1],&MSR[2],&MSR[3]) != 4)
    {
        printf("netmask invalid\n");
    }
    else if(sscanf(ip,"%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]) != 4)
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
                    printf("L'IP du reseau: %d.0.0.0\n",IP[i]);
                    printf("L' IP du broadcast: %d.255.255.255\n",IP[i]);
                    printf("Nombre de machine pouvont etre connecter: %.0f\n",(pow(2,24)-2));
                    if(MSR[0] == 255 && MSR[i+1] == 0 && MSR[i+2] == 0 && MSR[i+3] == 0)
                    {
                        printf("netmask valid\n");
                    }
                    else
                    {
                        printf("netmask invalid !!\n");
                    }
                    break;
                }
                else if(IP[i] >= 128 && IP[i] < 192)
                {
                    printf("L'addresse IP est de classe B\n");
                    printf("L'IP du reseau: %d.%d.0.0\n",IP[i],IP[i+1]);
                    printf("l'IP du broadcast: %d.%d.255.255\n",IP[i],IP[i+1]);
                    printf("Nombre de machine pouvont etre connecter: %.0f\n",(pow(2,16)-2));
                    if(MSR[0] == 255 && MSR[i+1] == 255 && MSR[i+2] == 0 && MSR[i+3] == 0)
                    {
                        printf("netmask valid\n");
                    }
                    else
                    {
                        printf("netmask invalid !!\n");
                    }
                    break;        
                }
                else if(IP[i] >= 192 && IP[i] < 224)
                {
                    printf("l'addrese IP est de classe C\n");
                    printf("l'IP du reseau: %d.%d.%d.0\n",IP[i],IP[i+1],IP[i+2]);
                    printf("l'IP du broadcast: %d.%d.%d.255\n",IP[i],IP[i+1],IP[i+2]);
                    printf("Nombre de machine connecter: %.0f\n",(pow(2,8)-2));
                    if(MSR[0] == 255 && MSR[i+1] == 255 && MSR[i+2] == 255 && MSR[i+3] == 0)
                    {
                        printf("netmask valid\n");
                    }
                    else
                    {
                        printf("netmask invalid !!\n");
                    }
                    break;
                }
                else
                {
                    printf("IP invalid ou dans le classe D ou E!!\n");
                }
            }
            break;
        }   
    }
}
void free_all_array(char* ip,char* netmask)
{
    free(ip);
    free(netmask);
}
