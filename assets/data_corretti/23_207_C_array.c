/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.9
*/
/*SPECIFICA:
*input: una sequenza x1, x2, ..., xn
*pre-condizione: x1, x2, ..., xn sono numeri interi positivi
*output: un valore booleano "unaCifra"
*post-condizione: "unaCifra" vale true se in ogni tripla di elementi adiacenti della sequenza x1, x2, ..., xn
sono presenti almeno due numeri composti da una sola cifra, vale false altrimenti

*TIPO DI PROBLEMA: verifica universale*/

#include <stdio.h>

/*funzione dueUnaCifra con parametri: 1) un array di interi; e 2) un intero che rappresenta la lunghezza
dell'array. La funzione restituisce 1 se in tutte le triple di elementi adiacenti della sequenza sono
presenti almeno due numeri composti da una sola cifra, 0 altrimenti*/
int dueUnaCifra(int* interi, int lunghezza) {
	int unaCifra; //variabile di universalità
	int i; //variabile contatore

	/*inizializzazioni*/
	unaCifra = 1; //ancora non è stata trovata una tripla che non rispetta le condizioni richieste
	i = 0;

	/*controllo tutte le triple dell'array finché non ne incontro una che non rispetta le condizioni richieste*/
	while(i<lunghezza-2 && unaCifra) {
		/*ci sono almeno due interi all'interno della tripla che hanno una cifra?*/
		if(!((interi[i]<10 && interi[i+1]<10) || (interi[i]<10 && interi[i+2]<10) || (interi[i+1]<10 && interi[i+2]<10))) {
			unaCifra = 0; //è stata trovata una cifra che ha meno di due elementi composti da una sola cifra
		}
		else {
			i++; //vai alla tripla successiva
		}
	}
	return unaCifra;
}

/*funzione principale*/
int main() {
	int l; //lunghezza dell'array
	int seq[l]; //array per la sequenza di interi
	int i; //variabile contatore

	/*INPUT*/
	printf("Caro utente, da quanti interi %c composta la tua sequenza?\n", 138);
	scanf("%d", &l);
	printf("Perfetto! Ora inserisci i numeri.\n");
	/*salvo gli interi all'interno dell'array*/
	for(i=0; i<l; i++) {
		printf("Dammi un intero:"); //****** APPICCICATO -0.1
		scanf("%d", &seq[i]);
	}

	/*OUTPUT*/
	if(dueUnaCifra(seq,l)) {
		printf("In tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra.\n");
	}
	else {
		printf("Non in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra.\n");
	}
}