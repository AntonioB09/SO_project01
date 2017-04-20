# SO_project01
(01)Escribir un programa en C o C++ llamado replicaMuerte.c El proceso crea un hijo que
cada 5 segundos comprueba si su padre está vivo. En caso que sí, se replica a sí mismo.
En caso que no, se suicida. El primer padre por su parte queda esperando que se presione
una tecla tras lo cual mata a su primer hijo y termina.
AYUDA: El resultado debe presentar un crecimiento exponencial en la cantidad de
procesos al comienzo y tras presionar un botón o tecla, un decrecimiento exponencial.
(02)Escribir un programa multihilo en C llamado promedioDehilos.c El padre crea un arreglo
aleatorio de 100 enteros (entre 0 y 1000) y da acceso a fragmentos de 25 elementos a 4 hilos que promedian el subarreglo y retornan este valor. Al terminar todos los hilos, el padre despliega por pantalla la media de los elementos del arreglo promediando el retorno de las 4 hilos.
(2.2)Solucione el punto anterior, utilizando semáforos de la siguiente manera: cada vez que un hilo tenga el resultado, escribirá en una variable compartida el resultado y terminará. El padre leerá este resultado y lo desplegará en pantalla. El resultado es que el padre despliega el resultado cada vez que el hijo termina.
(03)Implementar un simulador de interrupciones que reciba una petición de interrupción de un dispositivo e interrumpa el flujo de la ejecución del programa. Para esto se debe implementar:
a. Simulador de interrupciones
b. CPU: una aplicación que actúa como si fuera el CPU que va ejecutando una secuencia de instrucciones
c. Driver / Dispositivo: una aplicación que maneja un recurso
