/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.4
*/
#include <stdio.h>

/*input: sequenza di interi  //***** MANCA LA LUNGHEZZA -0.2
precondizione: nessuna
output: un valore booleano "esiste"
postcondizione: esiste una tripla in cui uno dei 3 numeri è il resto della divisione degli altri 2*/
//**** LA FUNZIONE RESTITUISCE VERO SE... FALSO ALTRIMENTI -0.3
/*problema di verifica esistenziale*/



/*funzione che calcola se esiste una tripla in cui uno dei due numeri è il resto della divisione degli altri due*/
int restoDivisione(int *seq, int lunghezza){
int esiste=0; /*variabile di esistenza*/
int i=0; /*variabile contatore*/

	while(i<lunghezza-2 && !esiste){
    if (seq[i]%seq[i+1]==seq[i+2] || (seq[i+1]%seq[i]==seq[i+2]) ||
    	(seq[i]%seq[i+2]==seq[i+1]) || (seq[i+2]%seq[i]==seq[i+1]) ||
    	(seq[i+1]%seq[i+2]==seq[i]) || (seq[i+2]%seq[i+1]==seq[i])){
    	esiste=1;
    }
i++;

	}

return esiste;

}


int main(){
	/*input*/
	int lunghezza; /*lunghezza array*/
	printf("Ciao, sono un programma che calcola se esiste una tripla\n");
	printf("contente un numero uguale al resto della divisione degli altri 2\n");
	printf("Quanti interi vuoi inserire?"); //*** APPICCICATO -0.1
	scanf("%d", &lunghezza);

	int seq[lunghezza]; /*array*/
	for (int i = 0; i < lunghezza; i++)
	{
		printf("Dammi un intero\n");
		scanf("%d", &seq[i]);
	}
/*output*/
	if (restoDivisione(seq, lunghezza)){
		printf("Esiste una tripla che rispetta le condizioni\n");
	}
	else {
		printf("Non esiste una tripla che rispetta le condizioni\n");
	}
}