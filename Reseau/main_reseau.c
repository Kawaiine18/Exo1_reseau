#include "reseau.h"
int main()
{
    char* ip = NULL;
    char* netmask = NULL;
    ip = getdata(ip); 
    netmask = getdata_2(netmask);
    verification(ip,netmask);
    free_all_array(ip,netmask);
    return 0;
}
