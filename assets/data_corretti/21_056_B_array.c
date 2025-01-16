/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.7
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8.7
*/
/*SPECIFICA: problema che verifica se in ogni tripla di interi nella sequenza in input contiene esattamente
 * due elementi magggiori o uguali a 5 ed almeno due pari.
 * INPUT:array di numeri, lunghezza dell'array.
 * PRE-CONDIZIONE:Array di interi.
 * OUTPUT: Messaggio che dice all'utuente se la condizione è verificata o meno. //******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * POST-CONDIZIONE:Condizione verificata oppure no. //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 *TIPO DI PROBLEMA: Verifica universale*/
#include <stdio.h>
/*funzione che verifica se l'istanza è positiva o meno*/
int maggiori5Pari(int *a, int l){
	int verificata=1;
	if(l<3){              //se l'array contiene meno di 3 numeri l'istanza è sempre positiva
		verificata=0;
	}
	else{
		for(int i=0; i<l-2;i++){ //se esiste esattamente uno o tre numeri maggiori o uguali a 5 l'istanza è negativa
		//******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
			if((a[i]<5 && a[i+1]<5) || (a[i]<5 && a[i+2]<5) || (a[i+1]<5 && a[i+2]<5) || (a[i]>=5 && a[i+1]>=5 && a[i+2]>=5)){
				verificata=0;
			}
			else{          // se esattamente un solo elemento è pari l'istanza è negativa
			           //***** IL COMMENTO NON E' CORRETTO, MA LA CONDIZIONE SI -0.3
				if((a[i]%2!=0 && a[i+1]%2!=0) || (a[i]%2!=0 && a[i+2]%2!=0) || (a[i+1]%2!=0 && a[i+2]%2!=0)){
					verificata=0;
				}
			}
		}
	}
	return verificata;
}

int main(int argc, char **argv)
{   /*INPUT*/
	int lunghezza; //dichiaro la variabile lunghezza dell'array
	int i;//dichiaro la variabile contatore
	printf("Caro utente sono un programma che verifica se ogni tripla di interi presente nell'array inserito");
	printf("contiene esattamente due elementi magggiori o uguali a 5 ed almeno due pari.\n");
	printf("Inserisci la lunghezza dell'array\n");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	for(i=0; i<lunghezza; i++){ //input array
		printf("Inserisci l'elemento dell'array in posizione %d\n", i);
		scanf("%d", &array[i]);
	/*OUTPUT*/
	}
	if(maggiori5Pari(array, lunghezza)){
		printf("ogni tripla dell'array contiene esattamente due elementi magggiori o uguali a 5 ed almeno due pari.\n");
	}
	else{
		printf("Esiste almeno una tripla che non contiene esattamente due elementi magggiori o uguali a 5 ed almeno due pari.\n");

	}

}
