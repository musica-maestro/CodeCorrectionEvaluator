/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE..................6.2
*/
/*SPECIFICA
 * Input: una sequenza di interi s e la sua lunghezza l
 * Pre-condizione: l è la lunghezza della sequenza s
 * Output: un intero triplaConsecutiva
 * Post-condizione: La funzione restiruisce 1 se esiste una tripla di elementi consecutivi tale
 * che almeno due elementi della tripla la cui somma è compresa fra 10 e 20(estremi inclusi) ed
 * due elementi uguali, altrimenti restiruisce 0
 * TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>
#include <stdlib.h>

/*Una funzione ugualiCompresi che prende come parametro un array di interi
 * e una lunghezza . Resistuisce 1 se esiste una tripla di elementi consecuti compresa tra 10 e 20
 * con 2 elementi uguali, altrimenti restituisce 0.
*/
int ugualiCompresi(int array[],int lunghezza){
	int triplaConsecutiva=1; //variabile di esistenza della triplaConsecutiva  //********** triplaConsecutiva=0; -1
	int i; //variabile contatore

	i=0; //contatore parte da 0
	while(i<lunghezza-2 && triplaConsecutiva){
		if((array[i]+array[i+1]>=10 && array[i]+array[i+1]<=20) &&  //********** ||, NON && -1
		  (array[i+1]+array[i+2]>=10 && array[i+1]+array[i+2]<=20) &&
		  (array[i]==array[i+1] || array[i+1]==array[i+2])) //*********** DEVI CONSIDEARE ANCHE array[i]==array[i+2], MA NON BASTA -1
		  //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		  //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			triplaConsecutiva=0; //triplaConsecutiva =0 quindi si interrompe il ciclo
			//******** SE LA PROPRIETA' E' SODDISFATTA triplaConsecutiva E' FALSO! -1
		else{
			triplaConsecutiva=1;
			i++;

		}


	}
	return triplaConsecutiva;
}


/*funzione principale*/
int main(int argc, char **argv){
	int dim;//dimensione dell'array

	/*INPUT*/
	printf("Questo programma calcola se in una stringa esiste una tripla la cui somma\n");
	printf("%c compresa tra 10 e 20 e due dei elementi della tripla sono uguali\n",138);
	printf("Inserisci la dimensione dell'array: ");   //******** NON ESPRESSO BENE -0.3
	scanf("%d",&dim);

	int array[dim]; //creazione dell'array con dimensione dim

	/*Caricamento dell'array*/
	for(int i=0;i<dim;i++){
		printf("inserisci il %d* numero: ",i+1);
		scanf("%d",&array[i]);
	}


	/*OUTPUT*/
	if(ugualiCompresi(array,dim))
		printf("Esiste una tripla di elementi consecutivi compresi tra 10 e 20 con 2 elementi uguali\n");
	else
		printf("NON esiste una tripla di elementi consecutivi compresi tra 10 e 20 con 2 elementi uguali\n");
	return 0;
}
