#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
int x;
int main (int argc, char  **argv) {

 pid_t child, parent;
 
 parent = getpid();

int  p , h;
 h=0;
 p=0;
 


for(x=1;x<=20;x++) 
  {
   if ((child = fork()) < 0) 
    {
     perror ("No se puede crear proceso");
     exit (-1);
    }//fin del if error
   else 
       if (child == 0 ) 
         {
           /* Estoy en el proceso hijo */ 
           h=h+1;
           //printf ("Hijo %d : Mi pid es %d. El pid de mi padre es %d\n", 
           //h,getpid(), getppid());
             printf (" padre estas vivo?\n");sleep(1);
             if (getppid() != 1){
                printf (" estoy vivo hijo!!\n");
             }
             else {
                printf (" padre a muerto!!\n");
                kill (getpid(), SIGTERM);//suicidar
             }
           sleep(1);
         }//fin el if hijo
         else 
            {
             /* Estoy en el Proceso padre */
             /* En el proceso padre, el valor child
             es el pid del hijo */
              
             p=p+1;
             printf ("      %d\n",getpid());
             printf ("        |\n"); 
             printf ("        v\n");
             
             wait(0); 
             
            }//fin del esle 
   

             if ( x == 15){
                printf ("kill primer hijo: %d\n",parent +1);
                kill (child, SIGTERM);// matar primer hijo
              }
   }//fin del for x
 
//Enviamos la señal de terminación al proceso hijo.

//kill (child, SIGTERM);

 return 0;


}//fin del main
