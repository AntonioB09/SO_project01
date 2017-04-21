# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <semaphore.h>



long v[100];// vector padre.
long promedio_compartido = 0;// variable que comparten los hilos.
sem_t h ;// variable del control tipo semaforo.


void * promedio_hilo1 ( void * arg )
    {
     long sum = 0;
     int valor_semaforo;
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh1 antes del wait %d\n", valor_semaforo);
     sem_wait(&h);
     for (long i = 0; i < 24 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 1 %li\n", sum);
        }//fin del for i 
     
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh1 despues del wait %d\n", valor_semaforo);
      
     sum = sum/25;
     promedio_compartido = sum;
    
     sem_post(&h);
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh1 despues del post %d\n", valor_semaforo);
     pthread_exit(0);
    }//fin del void promedio_hilo1

void * promedio_hilo2 ( void * arg )
    {
     long sum = 0;
     int valor_semaforo;
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh2 antes del wait %d\n", valor_semaforo);
     sem_wait(&h);
     for (long i = 25; i < 49 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 2 %li\n", sum);
        }//fin del for i 
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh2 despues del wait %d\n", valor_semaforo);

     sum = sum/25;
     promedio_compartido = sum;

     sem_post(&h);
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh2 despues del post %d\n", valor_semaforo);
     pthread_exit(0);
    }//fin del void promedio_hilo2

void * promedio_hilo3 ( void * arg )
    {
     long sum = 0;
     //int valor_semaforo;
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh3 antes del wait %d\n", valor_semaforo);
     sem_wait(&h);
     for (long i = 50; i < 74 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 2 %li\n", sum);
        }//fin del for i 
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh3 despues del wait %d\n", valor_semaforo);

     sum = sum/25;
     promedio_compartido = sum;
  
     sem_post(&h);
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh3 despues del post %d\n", valor_semaforo);
     pthread_exit(0);
    }//fin del void promedio_hilo3

void * promedio_hilo4 ( void * arg )//calcula es promedio del segmento hilo4
    {
     long sum = 0;
     //int valor_semaforo;
     //sem_getvalue(&h,&valor_semaforo);
     //printf("valor del semaforoh4 antes del wait %d\n", valor_semaforo);
     sem_wait(&h);
     for (long i = 75; i < 99 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 2 %li\n", sum);
        }//fin del for i 
       //sem_getvalue(&h,&valor_semaforo);
       //printf("valor del semaforoh4 despues del wait %d\n", valor_semaforo);

      sum = sum/25;
      promedio_compartido = sum;
    
      sem_post(&h);
      //sem_getvalue(&h,&valor_semaforo);
      //printf("valor del semaforoh4 despues del post %d\n", valor_semaforo);
      pthread_exit(0);
     }//fin del void promedio_hilo4
 

int main () 
{  
    sem_init(&h, 0  , 1);//inicializacion del semaforo.
   
    long i = 0;
    srand(time(NULL)); //semilla. 
    for(i = 0 ;i <(sizeof(v)/sizeof(long)) ; i++) 
       { 
        v[i]=rand()%1001;//llena al vector padre numeros random entre 0 y 1000.
       } 
 
    pthread_t tid,tid2,tid3,tid4;// id de los 4 hilos.
    
// creacion de los hilos y llamada a calcular/mostrar su promedio.
    pthread_create(&tid, NULL , promedio_hilo1 ,NULL);
    pthread_join(tid, NULL);
    printf("promedio del hilo1 es:  %li\n",promedio_compartido);sleep(1);
    pthread_create(&tid2, NULL , promedio_hilo2 ,NULL);
    pthread_join(tid2,NULL);
    printf("promedio del hilo2 es:  %li\n",promedio_compartido);sleep(1); 
    pthread_create(&tid3, NULL , promedio_hilo3 ,NULL);
    pthread_join(tid3,NULL);
    printf("promedio del hilo3 es:  %li\n",promedio_compartido);sleep(1); 
    pthread_create(&tid4, NULL , promedio_hilo4 ,NULL);
    pthread_join(tid4,NULL);
    printf("promedio del hilo4 es:  %li\n",promedio_compartido);sleep(1); 
 
    sem_destroy(&h);//termina el semaforo.
    

}/*fin del main */
