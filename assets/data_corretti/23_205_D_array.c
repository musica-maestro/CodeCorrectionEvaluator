/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.6
*/
/*SPECIFICA:
Input = una sequenza di len interi, dove len e' una lunghezza che sceglie l'utente
pre-condizione = e' necessario che la sequenza abbia al suo interno solo interi
Output = la funzione restituisce vero se esiste all'interno della sequenza una tripla di interi per
cui il resto della divisione tra due elementi e' uguale all'altro elemento della tripla
*/ //****** MISCHI OUTPUT E POSTCONDIZIONE -0.4
//Probelam di tipo: verifica esistenziale

#include <stdio.h>
#include <string.h>

//funzione secondaria
int restoDivisione(int *sequenza, int lunghezza){
	int restoDivisione=0;		// valore restituito
	for(int i=0; i<lunghezza; i++)		// controllo tutti gli interi della sequenza
    //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<l-2 -1

		/* se il risultato della divisione di due valori della tripla
			ha come resto il terzo valore della tripla...*/

		if((sequenza[i]%sequenza[i+1]==sequenza[i+2]) ||
			(sequenza[i]%sequenza[i+2]==sequenza[i+1]) ||
			(sequenza[i+1]%sequenza[i+2]==sequenza[i]) ||
			(sequenza[i+1]%sequenza[i]==sequenza[i+2]) ||
			(sequenza[i+2]%sequenza[i+1]==sequenza[i]) ||
			(sequenza[i+2]%sequenza[i]==sequenza[i+1]))
			restoDivisione=1;		// ...il valore da restituire vale 1
		else
			i++;		// altrimenti controlla la tripla successiva
return restoDivisione;
}

//funzione principale
int main(){
	int len;
	printf("Quanto vuoi che si alunga la tua sequenza?\n");
	//input
	scanf("%d", &len);

	int sequenza[len];
	for(int i=0; i<len; i++){
		printf("Dammi un numero: ");
		scanf("%d", &sequenza[i]);
	}

int resto;
resto=restoDivisione(sequenza, len);
//output
if(resto==1)
	printf("Esiste almeno una tripla di numeri adiacenti in cui\nuno dei tre e' il resto della divisione degli altri due");
else
	printf("NON esistono triple di numeri adiacenti in cui\nuno dei tre e' il resto della divisione degli altri due");
}