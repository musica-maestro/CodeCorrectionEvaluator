/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10
*/
/*INPUT: un array di interi e un intero lunghezza
 * PRE-CONDIZIONE: lunghezza è la lunghezza dell'array e lunghezza>=3
 * OUTPUT: un valore intero
 * POST-CONDIZIONE: il valore intero vale 1 se esiste una tripla di elementi consecutivi tali che almeno due elementi della tripla hanno una somma
 * compresa tra 10 e 20(estremi inclusi) ed esattamente due elementi della tripla sono tra loro uguali, restituisce 0 altrimenti.
 * Tipologia di problema:verifica esistenziale.*/

#include <stdio.h>

int ugualiCompresi(int array[], int lunghezza){
	int valore=0; //valore della funzione inizializzato a zero essendo una verifica esistenziale
	for(int i=0; i<lunghezza-2 && !valore;i++){ //scorro tutta l'array fino a che non trovo una tripla che soddisfi la mia condizione
		if(((array[i]+array[i+1]>=10 && array[i]+array[i+1]<=20)
		||(array[i]+array[i+1]+array[i+2]>=10 && array[i]+array[i+1]+array[i+2]<=20) ||//**** QUESTA CONDIZIONE NON C'ENTRA NIENTE: -1
		(array[i]+array[i+2]>=10 && array[i]+array[i+2]<=20)                           //**** SE AVESSI [2,3,5] NON SAREBBE VERO CHE ALMENO 2
		||(array[i+1]+array[i+2]>=10 && array[i+1]+array[i+2]<=20))                    //**** HANNO SOMMA COMPRESA TRA 10 E 20
		&& ((array[i]==array[i+1] && array[i]!=array[i+2]) ||                          //**** "ALMENO" VUOL DIRE, MINIMO DUE, MA POSSONO ANCHE ESSERE DI PIU'
		(array[i]==array[i+2] && array[i]!=array[i+1])
		|| (array[i+1]==array[i+2] && array[i+1]!=array[i])))
			valore=1;
    }
	return valore;
}

int main(){
	int lunghezza; //lunghezza array
	printf("Caro utente, quanti interi vuoi introdurre?\n");
	scanf("%d",&lunghezza); //acquisizione lunghezza
	int array[lunghezza];
	for(int i=0; i<lunghezza; i++){ //riempimento array da tastiera
		printf("Introduci un intero:\n");
		scanf("%d", &array[i]);
	}
	if(ugualiCompresi(array,lunghezza)) // se la funzione è verificata
		printf("Nell'array esiste una tripla di interi consecutivi tale che almeno due elementi della tripla hanno una somma compresa tra 10 e 20(estremi inclusi) ed esattamente due elementi della tripla sono uguali fra loro");
	else
		printf("Nell'array non esiste una tripla di interi consecutivi tale che almeno due elementi della tripla hanno una somma compresa tra 10 e 20(estremi inclusi) ed esattamente due elementi della tripla sono uguali fra loro");
	}


