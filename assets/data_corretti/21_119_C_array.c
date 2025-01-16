/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
#include <stdio.h>

/* DATA UNA SEQUENZA DI INTERI, VERIFICA SE ESISTE UNA TRIPLA DI ELEMENTI CONSECUTIVI CHE CONTIENE
 * ALMENO DUE ELEMENTI IL CUI VALORE è COMPRESO FRA -10 E 10 E CONTIENE ESATTAMENTE DUE MULTIPLI DI 3*/

/* INPUT: sequenza s di n interi
 * PREC: n è lunghezza della sequenza
 * OUTPUT: variabile di tipo int
 * POSTC: variabile vale 1(true) se esiste una tripla di elementi consecutivi che contiene almeno due elementi
 * il cui valore è compreso fra -10 e 10 e che contiene esattamente due elementi multipli di 3, vale 0(false) altrimenti*/

 /* TIPO PROBLEMA: verifica esistenziale*/

int compresiMultipli3(int seq[],int l){
	int i=0;
	int esiste=0;
	/*scandisci la sequenza*/
	while(i<l-2 && !esiste){
		/*verifica se almeno due elementi di una tripla sono compresi fra -10 e 10*/
		if(((seq[i]>=-10 && seq[i]<=10) && (seq[i+1]>=-10 && seq[i+1]<=10)) ||
			((seq[i]>=-10 && seq[i]<=10) && (seq[i+2]>=-10 && seq[i+2]<=10)) ||
			((seq[i+1]>=-10 && seq[i+1]<=10) && (seq[i+2]>=-10 && seq[i+2]<=10))){
				/*verifica se esistono esattamente due multipli mdi tre nella tripla*/
				if(((seq[i]%3==0) &&  (seq[i+1]%3==0) && (seq[i+2]%3!=0)) ||
					((seq[i]%3==0) &&  (seq[i+2]%3==0) && (seq[i+1]%3!=0))||
					((seq[i+1]%3==0) &&  (seq[i+2]%3==0) && (seq[i]%3!=0)))
						esiste=1;
						i++; //*** NON SERVE
		} else i++;
	}
	return esiste;
}


int main(){
	printf("sono il programma che verifica se esiste una tripla di elementi consecutivi\n");
	printf("che contiene almeno due elementi il cui valore %c compreso fra -10 e 10 e\n",138);
	printf("contiene esattamente due multipli di 3\n");

	int dim=0; //dimensione array(numero interi)
	int risultato; //variabile di controllo
	/* INPUT*/
	printf("quanti interi vuoi inserire? ");
	scanf("%d",&dim);

	int sequenza[dim]; //creo un array di dimensione dim

	/* popolo il mio array*/
	for(int j=0;j<dim;j++){
		printf("inserisci un intero: ");
		scanf("%d",&sequenza[j]);
	}

	risultato=compresiMultipli3(sequenza,dim); //assegno a risultato il valore della funzione compresiMultipli3

	/*OUTPUT*/
	if(risultato){
		printf("esiste una tripla di elementi consecutivi che contiene almeno due elementi\n");
		printf("il cui valore %c compreso fra -10 e 10 e che contiene esattamente due elementi\n",138);
		printf("multipli di 3\n");
	}else printf("NON esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso fra -10 e 10 e che contiene esattamente due elementi multipli di 3\n",138);

}
