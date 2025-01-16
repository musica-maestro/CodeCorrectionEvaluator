/* SPECIFICA (max 1):......0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............4.9
*/
/*SPECIFICA
*Input: sequenza di numeri interi //******** MANCA LA LUNGHEZZA -0.2
*Pre-condizione: n > 0
*Output: numero intero
*Post-condizione: (0||1) //******** LA POST CONDIZIONE NON E' QUESTA -0.3

*Tipo di problema: verifica universale*/

#include <stdio.h>

int multipli(){//******* MANCANO I PARAMETRI DELLA FUNZIONE int array[] E lunghezza -1.5

	int lunghezza;	//per memorizzare la lunghezza della sequenza
	int sequenza[lunghezza];	//per memorizzare la sequenza
	//******* NON DEVI DICHIARARE QUI L'ARRAY E LA LUNGHEZZA, Li DEVI PASSARE COME PARAMETRI -1
	int terna[3];	//per memorizzare le terne
	int valore=1;	//valore di verità

	for(int i=0;i<(lunghezza-1);i++){ //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lunghezza-2 -1
		terna[0]=sequenza[0+i];
		terna[1]=sequenza[1+i];
		terna[2]=sequenza[2+i];

		/*condizione*/
		if((terna[0]%terna[1]!=0||terna[0]%terna[2]!=0)||(terna[1]%terna[0]!=0||terna[1]%terna[2]!=0)||(terna[2]%terna[1]!=0||terna[2]%terna[0]!=0))
			valore=0;
	}

	return valore;
}

int main(){
	int lunghezza;

	/*input*/
	printf("Ciao, utente! Quanti interi ha la sequenza?");
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];
	printf("Introduci gli interi della sequenza:\n");

	for(int i=0;i<lunghezza;i++){
		scanf("%d",&sequenza[i]);
	}

	/*output*/
	//******** sequenza[lunghezza] NON E' L'ARRAY, E' UN ELEMENTO CHE NON APPARTIENE ALL'ARRAY -1
	multipli(sequenza[lunghezza],lunghezza);
	int valore;

	if(valore=0)
		printf("Il multiplo di uno degli altri due elementi della terna non e' stato trovato in tutte le terne della sequenza.\n");
	else
		printf("Esiste almeno un elemento multiplo di uno degli altri due in tutte le terne adiacenti della sequenza.\n");
}