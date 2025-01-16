/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10,8
*/
/*SPECIFICA
 * Input : (x1,x2,...,xn) e un intero n
 * pre-cond : (x1,x2,...,xn) sono interi e n è la lunghezza della sequenza
 * output : un valore booleano "trovato"
 * post-cond : trovato vale 1 se esiste almeno una tripla che contiene almeno due elementi il cui valore è compreso fra -10 e 10(estremi inclusi) e che contiene
 *             esattamente due elementi multipli di 3  //******** POST-CONDIZIONE NON COMPLETA (0, ALTRIMENTI) -0.2
 *
 * PROBLEMA DI : VERIFICA ESISTENZIALE */



#include <stdio.h>

/*funzione che verifica se un intero è multiplo di 3*/
int isMultiplo3(int n){
	int multiplo;   //******** BASTAVA SCRIVERE return (n%3==0);
	if (n%3==0)
		multiplo=1;
	else
		multiplo=0;
	return multiplo;
}

/*funzione che verifica se un intero è compreso fra -10 e 10*/

int compreso(int m){
	int comp;           //********* COME SOPRA
	if(m<=10 && m>=-10)
		comp=1;
	else
		comp=0;
	return comp;

}


int compresiMultipli3(int *seq, int l){
	int i = 1; //scorro l'array da sinistra partendo dal secondo elemento
	int trovato = 0; //variabile booleana di esistenza
	/*finchè non finisce la stringa o finchè non trovo una tripla che soddisfa la condizioni vai avanti */
	while (i<l-1 && !trovato){
		if( ( (compreso(seq[i]) && compreso(seq[i-1]))
		|| (compreso(seq[i]) && compreso(seq[i+1]))
		|| (compreso(seq[i-1])&&compreso(seq[i+1])) )
		&& ((isMultiplo3(seq[i-1]) && isMultiplo3(seq[i]) && !(isMultiplo3(seq[i+1])))
		|| (isMultiplo3(seq[i]) && isMultiplo3(seq[i+1]) && !(isMultiplo3(seq[i-1])))

		|| (isMultiplo3(seq[i-1]) && isMultiplo3(seq[i+1]) && !(isMultiplo3(seq[i])) )))
			trovato=1;
		else
			i++;

	}
	return trovato;
}

int main(int argc, char **argv)
{
	/*input*/
	int lunghezza;
	printf("ciao utente, inserisci la lunghezza della sequenza : ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for (int i=0 ; i<lunghezza ; i++){
		printf("introduci un intero : ");
		scanf("%d",&sequenza[i]);
	}

	/*invocazione della funzione + output*/
	if (compresiMultipli3(sequenza,lunghezza)){
		printf("esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore\n");
		printf("e' compreso fra -10 e 10 estremi inclusi e che contiene esattamente due elementi multipli di 3\n");
	}
	else {
		printf("NON esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore\n");
		printf("e' compreso fra -10 e 10 estremi inclusi e che contiene esattamente due elementi multipli di 3\n");
	}
}
