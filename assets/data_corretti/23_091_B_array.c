/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............8.3
*/
#include <stdio.h>
/*specifica del problema
 *input:una sequenza di interi s e l è la sua lunghezza
 *pre-cond:l è la lunghezza di s l>=3
 *output:intero duepos
 *post-cond:duepos vale 1 se in ogni tripla di elementi
 *adiacenti ci sono esattamente due numeri positivi
 *altrimenti vale 0
 *tipo di problema:verifica universale*/

/*funzione che riceve come parametro una sequenza di interi s e la sua lunghezza l
 *e restituisce 1 se in tutte le triple di elementi adiacenti ci sono
 * esattamente due numeri positivi altrimenti restituisce 0*/

int duePositivi(int sequenza[],int lunghezza) {
 int duePos;  //variabile universale
 int i;     // variabile contatore

 /*inizializzo la variabile universale a 1*/
 duePos=1;
 i=0;

 while(i<=lunghezza-3 && duePos){
 	if(!((sequenza[i]>0 && sequenza[i+1]>0)
 		             ||
 	     (sequenza[i+1]>0 && sequenza[i+2]>0)
 	                 ||
 	     (sequenza[i]>0 && sequenza[i+2]>0)))
 		duePos=0;
 	else        //****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
 		i++;
  }

 return duePos;
}



/*funzione principale*/
 int main() {
 	int lunghezza;    // variabile lunghezza
 	int i;           // variabile contatore
/*input*/
 	printf("caro utente sono un programma che data una sequenza di interi\n");
 	printf("verifica se in ogni tripla di elementi adiacenti\n");
 	printf("ci sono esattamente due numeri positivi\n\n");


 	printf("quanto la vuoi lunga la sequenza?"); //****** APPICCICATO -0.1
 	scanf("%d",&lunghezza);

   int sequenza[lunghezza];
   for(i=0;i<lunghezza;i++){
   	printf("inserisci un intero");//****** APPICCICATO -0.1
   	scanf("%d",&sequenza[i]);
   }


   /*output*/
   if(duePositivi(sequenza,lunghezza)){
   	  printf("in ogni tripla di elementi adiacenti\n");
      printf("ci sono esattamento due interi positivi\n\n");
    }
    else{
    	printf("in ogni tripla di elementi adiacenti\n");
        printf("non ci sono esattamento due interi positivi\n\n");
    }




 }