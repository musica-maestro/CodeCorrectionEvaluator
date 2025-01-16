/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.8
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8.5
*/

#include <stdio.h>
/*SPECIFICA
 * Input: una sequenza di interi n e un intero d
 * Pre-condizione: d è la dimensione di n
 * Output: una variabile booleana
 * Post-condizione: La funzione retituisce 1 se esiste una tripla di elementi consecutivi in cui risultano
 * almeno due elementi il sui valore è compreso fra -10 e 10, restituisce 0 altrimenti.
 * TIPO DI PROBLEMA: Verifica esistenziale*/  //***** MANCA LA CONDIZIONE SUI MULTILI DI 3 -0.3


/*Funzione che verifica l'esistenza di due elementi di una tripla di elementi consecutivi compresi tra -10 e 10*/
int compresiMultipli3(int seq[], int dim){
	int i=0; //variabile contatore
	int multipli3=0; //variabile d'esistenza

	/*Se in una tripla esistono almeno due elementi compresi fra -10 e 10, multipli3= i, altrimenti passa alla prossima tripla*/
	while(i<dim-2 && !multipli3){
		if(((seq[i]>=-1 && seq[i]<=10) && (seq[i+1]>=-1 && seq[i+1]<=10)) //***** -10, NON -1 -0.2
		|| ((seq[i]>=-1 && seq[i]<=10) && (seq[i+2]>=-1 && seq[i+2]<=10))
		|| ((seq[i+1]>=-1 && seq[i+1]<=10) && (seq[i+2]>=-1 && seq[i+2]<=10)))
			multipli3=1;
		//******* MANCA L'ALTRA CONDIZIONE! -2
		else
			i++;
	}

return multipli3;
}

int main(int argc, char **argv)
{
int dim; //dimensione dell'array
printf("Questo programma verifica che in una sequenza esista una tripla di elementi consecutivi che contiene almeno ");
printf("due elementi il cui valore %c compreso fra -10 e 10 estrmi inclusi.\n\n", 138);
/*INPUT*/
printf("Inserisci la dimensione della sequenza: ");
scanf("%d", &dim);

int seq[dim]; //Sequenza di interi

/*immissione dei dati nell'array*/
for(int i=0; i<dim; i++){
	printf("inserisci un valore intero: ");
	scanf("%d", &seq[i]);
}
/*OUTPUT*/
if(compresiMultipli3(seq, dim))
	printf("Nella sequenza esiste una tripla contenente almeno due interi con valore compreso fra -10 e 10.\n\n");
else
	printf("Non esiste nessuna tripla della sequenza con almeno due interi compresi fra -10 e 10.\n\n");

}
