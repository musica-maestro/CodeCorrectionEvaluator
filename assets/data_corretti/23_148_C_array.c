/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.9
*/
/*  SPECIFICA DEL PROBLEMA
	*INPUT: un intero n e una sequenza di interi positivi  //******* IL FATTO CHE GLI INTERI SIANO POSITIVI VA SPECIFICATO NELLA PRE-CONDIZIONE -0.1
	*PRE-CONDIZIONE: n e' maggiore di 1 ed e' la lunghezza della sequenza
	*OUTPUT: una variabile intera tutte
	*POST-CONDIZIONE: tutte vale 1 se in ogni tripla di elementi consecutivi della sequenza
			   siano presenti almeno due numeri composti da una sola cifra, vale 0 altrimenti

	TIPO DI PROBLEMA: Verifica universale
*/
#include <stdio.h>

/*  Funzione che controlla se in ogni tripla di elementi consecutivi della sequenza
	siano presenti almeno due numeri composti da una sola cifra */
int dueUnaCifra(int* seq, int n){
	//pre: seq e' l'array contenente i valori inseriti dall'utente e n e' la sua lunghezza

	int tutte = 1;	//variabile contentente l'esito del controllo

	int i = 0;	//variabile contatore

	//ciclo per controllare tutti i valori dell'array
	while(i < n-2 && tutte){
		//controllo se nella tripla attuale non ci sono almeno due elementi con una cifra
		if(!((seq[i] <= 9 && seq[i+1] <= 9) || (seq[i] <= 9 && seq[i+2] <= 9) || (seq[i+1] <= 9 && seq[i+2] <= 9)))
			tutte = 0;

		//passo all'elemento successivo
		else
			i++;
	}

	//ritorno l'esito
	return tutte;
}

int main(){

	int n;	//variabile lunghezza array;

	//INPUT LUNGHEZZA ARRAY
	printf("Inserire quanti numeri si vuole inserire: ");
	scanf("%d", &n);

	int seq[n];		//array che contiene la sequenza

	//INPUT ARRAY
	for(int i = 0; i < n; i++){
		printf("Inserire il %d' numero: ", i+1);
		scanf("%d", &seq[i]);
	}

	//controllo il valore riportato dalla funzione dueUnaCifra
	if(dueUnaCifra(seq, n)){
		//OUTPUT POSITIVO
		printf("In ogni tripla di elementi adiacenti della sequenza sono ");
		printf("presenti almeno due numeri composti da una sola cifra. \n");
	}

	else{
		//OUTPUT NEGATIVO
		printf("Non in ogni tripla di elementi adiacenti della sequenza sono ");
		printf("presenti almeno due numeri composti da una sola cifra. \n");
	}

	return 0;
}