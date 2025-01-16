/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA DEL PROBLEMA
input: una  sequenza di interi e la sua dimensione,
pre-condizioni: la dimensione è la lunghezza dell'array,
output: variabile booleana
post_condizioni: la variabile booleana assume valore 1 se esiste una tripla di elementi consecutivi tali che almeno due elementi della tripla hanno somma compresa fra 10 e 20
                 ed esattamente due elementi della tripla sono uguali. vale 0 altrimenti.

TIPO DI PROBLEMA: problema di verifica esistenziale.*/
#include <stdio.h>

/*funzione che prende come parametro una sequenza di interi e restituisce 1 se esiste una tripla di elementi consecutivi tale che la
almeno du elementi della tripla hanno somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono uguali*/
int ugualiCompresi( int array[], int lunghezza){

	int esiste;   //variabile booleana
	esiste=0;   //inizialmente non ho trovato nessuna tripla
	int i;     //variabile contatore

	i=0;
	/*vado avanti finche' la sequenza non è terminata*/
	while(i<lunghezza-2 && !esiste){

		/*se la somma di almeno due elementi è compresa fra 10 e 20*/
		if((array[i]+array[i+1]>=10 && array[i]+array[i+1]<=20)||(array[i]+array[i+2]>=10 && array[i]+array[i+2]<=20)||(array[i+1]+array[i+2]>=10 && array[i+1]+array[i+2]<=20)){
			/*se esattamente due elementi sono uguali*/
			if((array[i]==array[i+1] && array[i]!=array[i+2]) || (array[i]==array[i+2] && array[i]!=array[i+1]) || (array[i+1]==array[i+2]&&array[i+1]!=array[i]))
				esiste=1;
		}
		else
			i++;
	}
	return esiste;
}

/*funzione principale*/
int main(){

	int lunghezza;   //lunghezza della sequenza

	/*input*/
	printf("caro utente, inserisci la lunghezza della sequenza\n");
	scanf("%d", &lunghezza);
	int array[lunghezza];

	for(int i=0; i<lunghezza; i++){
		printf("inserisci un intero\n");
		scanf("%d", &array[i]);
	}

	/*richiamo la funzione*/
	if(ugualiCompresi(array, lunghezza))
		printf("esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono fra loro uguali\n");
	else
		printf("Non esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono fra loro uguali\n");
}