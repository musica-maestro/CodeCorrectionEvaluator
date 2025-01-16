/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.4
*/
/*SPECIFICA:
INPUT:Sequenza s
PRE-CON:lunghezza è la lunghezza di s //******** SE SCRIVI COSI', LUNGHEZZA DEVE ESSERE UN INPUT -0.4
OUTPUT:verità  //******** OUTPUT: MANCA IL TIPO -0.2
POST-COND:  //******** LA POST-CONDIZIONE MANCA -0.5
Problema di verifica esistenziale
*/

#include <stdio.h>
/*Funzione che datta una sequenza di interi verifica se esiste una tripla consecutiva tale che il valore di
 almeno due elementi sia compreso tra -10 e 10 esclusi e che aESATTAMENTE 2 elemnenti siano multiplo di 3*/
int compresiMultipliDi3(int sequenza[],int lunghezza){
	int trovato=0;   //variabile di esistenza

	int i=0;   // var contatore
	//Guardo tutti gli elementi della sequenza
	while(i<lunghezza-2 && !trovato){
		//se è valida la condizione ho trovato l'ellemento che cercavo ed esco dal ciclo.
		//******* CI VA ANCHE L'UGUALE -0.5
		if((((sequenza[i]>-10 && sequenza[i]<10)&&(sequenza[i+1]>-10 && sequenza [i+1]<10))||
		  ((sequenza[i]>-10 && sequenza[i]<10)&&(sequenza[i+2]>-10 && sequenza[i+2]<10))||
		  ((sequenza[i+1]<-10 && sequenza[i+1]<10)&&sequenza[i+2]<-10 && sequenza[i+2]<10))&&
		  ((sequenza[i]%3==0 && sequenza[i+1]%3==0 && sequenza[i+2]%3!=0)||
		  (sequenza[i]%3==0 && sequenza[i+1]%3!=0 && sequenza[i+2]%3==0)||
		  (sequenza[i]%3!=0 && sequenza[i+1]%3==0 && sequenza[i+2]%3==0)))
			  trovato=1;
			  else //altrimenti passo alla prossima tripla
				  i++;



	}
	return trovato;


}
/*Funzione principale*/
int main(int argc, char **argv)
{
	int lunghezza;  //variabile lunghezza stringa
	//Interazione con l'utente
	printf("Ciao sono un programma che data una sequenza verifica ");
	printf("se almeno due elementi sono compresi tra -10 e 10 ");
	printf("ed inoltre verifico se ci sono esattamente due numeri multipli di 3\n");

	//L'utente inserisce la lunghezza della sua sequenza
	printf("Quanti elementi deve avere la tua sequenza %c \n",63);
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];  //dichiaro l'array con lunghezza il valore inserito dall'utente

	//L'utente inserisce tanti elementi quanto è il valore di lunghezza
	for(int i=0;i<lunghezza;i++){
		printf("Inserisci un intero\n");
		scanf("%d",&sequenza[i]);
	}
		if(compresiMultipliDi3(sequenza,lunghezza)){
			printf("Esiste una tripla consecutiva con almeno due elementi ");
            printf("compresi tra -10 e 10 e che abbia esattamente due elemementi multipli di 3 \n");
		}
		else{
			printf("Non esiste una tripla consecutiva con almeno due elementi ");
            printf("compresi tra -10 e 10 e che abbia esattamente due elemementi multipli di 3 \n");
		}



}
