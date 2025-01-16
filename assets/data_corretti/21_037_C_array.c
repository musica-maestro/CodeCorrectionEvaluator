/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE.................10.5
*/
#include <stdio.h>

/*SPECIFICA:
 * Input: una sequenza di interi 'seq' e un intero 'dim'
 * Pre-Condizione: dim è la lunghezza della sequenza
 * Output: un valore booleano 'verificato'
 * Post-Condizione: verificato vale 1 se esiste almeno una tripla tale che abbia almeno due elementi compresi tra -10 e
 * 10 (inclusi) e che contiene esattamente due multipli di tre,
 * 					vale 0 altrimenti
 * Tipo Di Problema: Verifica esistenziale
 */

/*Questo programma controlla se in una sequenza esiste almeno una tripla tale che abbia almeno due elementi compresi tra
 * -10 e 10 inclusi e che abbia esattamente due multipli di tre*/

/*funzione che controlla se tra i tre elementi passati della tripla ce ne sono esattamente due multipli di 3 e uno non multiplo di tre, in questo caso ritorna 1, ritorna 0 altrimenti*/
int dueMultipli(int x, int y, int z)
{

	int risultato = 0; //variabile di ritorno

	/*tra i tre interi che sto guardando ce ne sono due multipli di 3 e uno non multiplo di 3?*/
	if((x%3==0 && y%3==0 && z%3!=0) || (y%3==0 && z%3==0 && x%3!=0) || (x%3==0 && z%3==0 && y%3!=0) ){
	/*se si il risultato deve essere uguale a 1*/
		risultato = 1;
	}
	/*altrimenti rimane invariato*/

	return risultato;

}


/*funzione che controlla se almeno due numeri inseriti compresi (estremi inclusi) tra -10 e 10, in questo caso ritorna 1, ritorna 0 altrimenti*/
int compreso(int x, int y, int z)
{

    int risultato = 0; //variabile di ritorno

	/*ci sono almeno due elementi che sono compresi tra -10 e 10?*/
    if(((x >= -10 && x <= 10) && (y >= -10 && y <= 10))
    || ((x >= -10 && x <= 10) && (z >= -10 && z <= 10)) ||
        ((y >= -10 && y <= 10) && (z >= -10 && z <= 10))) {
    /*se ci sono allora la variabile booleana è uguale a 1*/
	risultato = 1;
    }
	/*rimane invariata altrimenti*/

    return risultato;
}

/*funzione che torna un uno se almeno una tripla ha due elementi compresi tra -10 e 10 (inclusi) e esattamente due
 * multipli di tre, torna 0 altrimenti*/
int compresiMultipli3(int array[], int dim)
{

    int i = 0; // per scandire la sequenza

    int verificato = 0; // variaible di esistenza che ritorna al main inizializzata a 0

    /*fintanto che non hai controllato tutte le triple o che la variaible verificato cambia valore*/
    while(i < dim - 2 && !verificato) {
	/*tra la tripla che sto controllando ci sono almeno due numeri che sono compresi tra -10 e 10 e esattamente due multipli di 3?*/
	if(compreso(array[i], array[i + 1], array[i + 2]) && dueMultipli(array[i],array[i+1],array[i+2])){
		verificato = 1;
	/*altrimenti incrementa i così al prossimo ciclo puoi guardare la prossima tripla*/
	}else{
	i++;
	}
    }

return verificato;
}

int main()
{

    int dim; // per la lunghezza della stringa

    printf("Gentile utente, dimmi quanti numeri vuoi inserire:");
    scanf("%d", &dim);

    int seq[dim]; // sequenza con lunghezza scelta da utente

    /*riempio l'array*/
    for(int i = 0; i < dim; i++) {
	printf("\n(%d) Inserisci un intero: ", i + 1);
	scanf("%d", &seq[i]);
    }

    /*se la funzione che controlla la proprietà torna un 1 allora stampa un messaggio positivo, altrimenti stampane uno
     * negativo*/
    if(compresiMultipli3(seq, dim)) {

	printf("\nLa sequenza contiene almeno una tripla che rispetta la condizione.\n");

    } else {
	printf("\nLa sequenza NON contiene NESSUNA una tripla che rispetta la condizione.\n");
    }
}//******** OUTPUT MOLTO POVERO -0.5
