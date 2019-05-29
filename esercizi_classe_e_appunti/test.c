#include <stdio.h>

void euclide(){
   printf("ALGORITMO DIEUCLIDE\n");
   int a;
   int b;
   scanf("%d",&a);
   scanf("%d",&b);

   while(a!=b){
      if(a>b){
         a = a-b;
      }else{
         b = b-a;
      }
   }

   printf("MCD: %d\n",a);

}

/*Trova il massimo di una sequenza di numeri
che termina quando 2 numeri inseriti consecutivi
sono uguali*/

void maxSec(){

   printf("MASSIMO DI UNA SEQUENZA DI NUMERI CHE TERMINA CON 2 NUMERI UGUALI\n");

   int primo;
   int secondo;
   int max;

   scanf("%d",&primo);
   max = primo;

   do{
      secondo = primo;
      scanf("%d",&primo);
      if(primo>max){
         max = primo;
      }

   }while(primo != secondo);
   printf("Il numero massimo della sequenza : %d\n",max);
}

/*6/03/2019*/
/*
un array e ua collezione contigua in memoria di variabili di tipo
omogeneo.Ogniuna di queste variabili puo essere letta o scritta
tramite il suo indice che e un espressione int

DICHIARAZIONE

double       nomeVet          [dimensione_vet];
  |            |                    |
 tipo       identificatore       e una costante
 cella         vettore           intera

gli indici dell array variano tra 0 e dim-1

*/

/*programma per prendere i valori da mettere nell array da tastiera*/
void scan_vet_e_print(){
   float vet [10];/*il 10 e costante obligatoria*/
   int i = 0;
   for(i = 0; i<10; i++){
      scanf("%f",&vet[i]);
   }

   for (i = 0; i < 10; i++) {
      printf("%lf ",vet[9 - i]);
   }
}


/*passaggio di array come parametro*/

/*funzione che decide se un elemento e presente in un array*/
int cerca(int vet[],int elem,int dim){
   int i;
   int trovato = 0;
   while (i<dim && !trovato){
      if(vet[i] == elem){
         trovato = 1;
      }
      /*oppure
         trovato = (vet[i] == elem)
      */
      i++;
   }
   return trovato;
}

/*
PASSAGGIO PER COPPIA DI UN ARRAY:
le modifiche agli elementi dell'array sono
percepiti dal chiamante(SIDE EFFECT)
*/

void fun(int dim){
   int v[dim];/*GUARDARE QUADERNO TOMMY*/
}


/*
INIZIALIZZAZIONE DI UN ARRAY MONO-DIM;

int vet[]={12,7,4,3};

double vet[20]={3.5,2.5,6.3};
le prime 3 sono inizializzati ai valori specificati,le
rimanenti a 0

COSE CHE NON SI POSSONO FARE CON GLI ARRAY:
siano v1 e v2 due array
non si puo fare v1 = v2,ma bisogna procedere elemento per elemento

invece il CONFRONTO si puo,ovvero non controlla che i 2 array abbiano
gli stessi elementi,questo va fatto elemento per elemento

*/

/**/
int uguali(int v1[],int v2[],int dim){
   int risposta = 1;
   int i = 0;
   while(i < dim && risposta){
      if(v1[i] != v2[i]){
         risposta = 0;
      }
      i++;
   }
   return risposta;
}

/*
testa una proprieta P su una collezione di oggetti

   --- esistenziale (esiste un elemento della collezione tali che...)
  /
P
  \
   --- universale (e vero che tutti gli elementi soddisfano...)


ESISTENZIALE : assumo che P sia FALSA e cerco l'esempio che la rende vera

UNIVERSALE : assumo che P sia VERA e cerco il contro esempio che la rende falsa

*/


/*RICERCHE DI MINIMO MASSIMO*/


/*esercizi
1)scrivere la funzione min in modo che restituisca la posizione
   di un elemento
*/








int main()
{
   read_string();
   return 0;
}
