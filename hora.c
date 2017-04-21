#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void despedida() 
{    
    printf("------------------------\n");
    printf("¿Por qué me interrumpes?\n");
    printf("------------------------\n");
    sleep(30);
    
}


int main()
{   
    FILE* fichero;
    fichero = fopen("cursoso.txt", "wt");
    int i = 7;
    signal(SIGINT, despedida);
    while(i != 0)
    {
    signal(SIGINT, despedida);
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    sleep(10);
    printf("%s\n",output);
    fputs(output, fichero);
    fputs("\n", fichero);
    printf("Proceso completado\n");
    i = i -1;
    }
fclose(fichero);
 raise(SIGTERM);       
}
