# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>

long v[100];// vector padre

void * promedio_hilo1 ( void * arg )
    {
     long sum = 0;
     for (long i = 0; i < 24 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 1 %li\n", sum);
        }//fin del for i 
     

     sum = sum/25;
     long *answer_hilo1 = malloc(sizeof(*answer_hilo1));
     *answer_hilo1 = sum;
     
     pthread_exit(answer_hilo1);
    }//fin del void promedio_hilo1

void * promedio_hilo2 ( void * arg )
    {
     long sum = 0;
     for (long i = 25; i < 49 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 2 %li\n", sum);
        }//fin del for i 
     

     sum = sum/25;
     long *answer_hilo2= malloc(sizeof(*answer_hilo2));
     *answer_hilo2 = sum;
     
     pthread_exit(answer_hilo2);
    }//fin del void promedio_hilo2

void * promedio_hilo3 ( void * arg )
    {
     long sum = 0;
     for (long i = 50; i < 74 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 2 %li\n", sum);
        }//fin del for i 
     

     sum = sum/25;
     long *answer_hilo3= malloc(sizeof(*answer_hilo3));
     *answer_hilo3 = sum;
     
     pthread_exit(answer_hilo3);
    }//fin del void promedio_hilo3

void * promedio_hilo4 ( void * arg )
    {
     long sum = 0;
     for (long i = 75; i < 99 ; i++) 
        {
         fflush(stdout);
         sum = sum + v[i] ;
         //printf("Sum hilo 2 %li\n", sum);
        }//fin del for i 
     

      sum = sum/25;
      long *answer_hilo4= malloc(sizeof(*answer_hilo4));
      *answer_hilo4 = sum;
     
      pthread_exit(answer_hilo4);
     }//fin del void promedio_hilo4
 

int main ( int argc , char * argv []) 
{  
   

    long i = 0;
    
    srand(time(NULL)); //semilla 
    for(i = 0 ;i <(sizeof(v)/sizeof(long)) ; i++) 
       { 
        v[i]=rand()%1001;//llena numeros entre 0 y 1000
       } 

   
     /*for(i=0;i <(sizeof(v)/sizeof(long)) ;i++)// ver el vecto padre
       { 
        printf(" vec %li\n",v[i]);
       } */
 
    pthread_t tid,tid2,tid3,tid4;

    long *result_h1 = 0;
    long *result_h2 = 0;
    long *result_h3 = 0;
    long *result_h4 = 0;
    long promedio_total = 0;

    pthread_create(&tid, NULL , promedio_hilo1 ,NULL);
    pthread_create(&tid2, NULL , promedio_hilo2 ,NULL);
    pthread_create(&tid3, NULL , promedio_hilo3 ,NULL);
    pthread_create(&tid4, NULL , promedio_hilo4 ,NULL);
    
    pthread_join(tid, (void**)&result_h1);
    pthread_join(tid2,(void**)&result_h2);
    pthread_join(tid3,(void**)&result_h3);
    pthread_join(tid4,(void**)&result_h4);

    printf("promedio del hilo1 es  %li\n", *result_h1);
    printf("promedio del hilo2 es  %li\n", *result_h2);
    printf("promedio del hilo3 es  %li\n", *result_h3);
    printf("promedio del hilo4 es  %li\n", *result_h4);

    promedio_total = (*result_h4 + *result_h3 + *result_h2 + *result_h1)/4;

    printf("promedio total es:  %li\n", promedio_total);

}/*fin del main */
