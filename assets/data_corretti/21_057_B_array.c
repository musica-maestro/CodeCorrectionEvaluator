/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA:
 * Input: Una sequenza di numeri di una determinata lunghezza inserita dall'utente
 * Pre-Condizione: il valore "lunghezza" è la lunghezza della sequenza
 * Output: un intero "verita", che può essere 0 o 1
 * Post-Condizione: L'intero "verita" è 1 se ogni tripla ha esattamente due numeri maggiori o uguali a 5 e almeno due elementi pari, altrimenti è 0
 * TIPO DI PROBLEMA: Verifica Universale */

#include <stdio.h>

int maggiori5pari(int array5pari[], int lungo) {
	int i=0; //Variabile contatore
	int verita=1; //Valore booleano
	/*Si apre un ciclo while, che dura finchè i è minore del valore della lunghezza e il valore booleano "verita" è a 1*/
	while(i<lungo&&verita) {
		/*Se ci sono esattamente due elementi maggiori o uguali a 5, la proprietà richiesta da questo if è verificata*/
		if(((array5pari[i]>=5)&&(array5pari[i+1]>=5)&&(array5pari[i+2]<5))
		||((array5pari[i+1]>=5)&&(array5pari[i+2]>=5)&&(array5pari[i]<5))
		||((array5pari[i]>=5)&&(array5pari[i+2]>=5)&&(array5pari[i+1]<5))) {
			/*Se ci sono almeno due elementi pari, la proprietà richiesta da questo if è verificata*/
			if(((array5pari[i]%2==0)&&(array5pari[i+1]%2==0))
			||((array5pari[i+1]%2==0)&&(array5pari[i+2]%2==0))
			||((array5pari[i]%2==0)&&(array5pari[i+2]%2==0))
			||((array5pari[i]%2==0)&&(array5pari[i+1]%2==0)&&(array5pari[i+2]==0)))
			//******* L'ULTIMA CONDIZIONE NON SERVE
				i++; //Se le proprietà richieste sono verificate, si va avanti
			else
				verita=0; //Se le proprietà richieste nell'if non sono verificate, il valore booleano si azzera e il ciclo si arresta
		}
		else
			verita=0; //Se le proprietà richieste nell'if non sono verificate, il valore booleano si azzera e il ciclo si arresta
	}
	return verita;
}

int main(int argc, char **argv)
{
	/*Viene illustrato lo scopo del programma e richiesta all'utente la lunghezza della sequenza*/
 	int lunghezza; //Dichiarazione della lunghezza
	printf("Ciao, questo programma calcola se in una sequenza di interi ogni tripla di elementi consecutivi\n");
	printf("contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari.\n");
	printf("Quanti numeri vuoi inserire nella sequenza?");
	scanf("%d", &lunghezza);
	int array[lunghezza]; //Dichiarazione dell'array
	/*Viene richiesto all'utente di aggiungere uno per uno i numeri nella sequenza*/
	for(int i=0; i<lunghezza; i++) {
		printf("Inserisci un numero: ");
		scanf("%d", &array[i]);
	}
	/*Se maggiori5pari riporta 1, verrà stampato un messaggio che dice che la proprietà è verificata, altrimenti
	 * ne verrà stampato un altro che dice che non è verificata*/
	if(maggiori5pari(array, lunghezza)) //Invocazione della funzione maggiori5pari
		printf("Ogni tripla di elementi consecutivi contiene esattamente due numeri maggiori o uguali a 5 e almeno due numeri pari\n");
	else
		printf("NON tutte le triple di elementi consecutive contengono esattamente due numeri maggiori o uguali a 5 e almeno due numeri pari\n");
}
