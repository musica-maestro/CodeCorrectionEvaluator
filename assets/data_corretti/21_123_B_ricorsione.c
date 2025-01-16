/*
5pt minimo dispari:..4
1pt scrivi numeri:...0.7
2pt quanti numeri:...1.4
2pt leggi numeri:....1.2
TOTALE ..............7.3
*/
#include <stdio.h>

/* funzione che calcola il minimo in una sequenza di tre elementi */
int minimo(int a, int b, int c){
	int minimo;
	if((a<=b) &&  (a<=c))
		minimo = a;
	if((b<=a) &&  (b<=c))
		minimo = b;
	if((c<=a) &&  (c<=b))
		minimo = c;
	return minimo;
}

/* funzione che verifica se in ogni tripla consecutiva il minimo Ã¨ dispari */
int minimoDispari(int* interi, int n){
	int verificata;							// per dirmi se Ã¨ vera l'ipotesi
	// passo base
	if(n<3)
		verificata = 0; //**** variabile di universalità inizializzata male -1
						//**** quando arriva al passo base verificata=0 fa diventare falsa tutta l'espressione booleama
						//**** quindi il risultato è sempre falso
	// passo ricorsivo
	else
		verificata = ((minimo(interi[n-1], interi[n-2], interi[n-3])%2) != 0) && minimoDispari(interi, n-1);
	return verificata;
}

/* funzione che scrive i valori di un array di interi su di un file */
void scriviNumeri(int* interi, int n){
	// il file testuale
	FILE* fp = fopen("interi.txt", "w");
	if(fp==NULL)
		printf("Il file non esiste o l'apertura %c andata male!", 138);
	else
		// scrivo gli interi dell'array nel file
		for(int i = 0; i<n; i++)
			fprintf(fp, "%c ", interi[i]); //**** sono interi! -0.3
	fclose(fp);
}

/* funzione per vedere quanti numeri sono presenti nel file */
int quantiNumeri(){
	int i = 0;												// variabile contatore
	char caratteri;											// i caratteri del file
	// il file testuale
	FILE* fp = fopen("interi.txt", "w"); //**** il file va aperto in lettura, altrimenti perdi tutto! -0.3
	if(fp==NULL)
		printf("Il file non esiste o l'apertura %c andata male!", 138);
	else
		// scorro i caratteri del file e li conto
		while(fscanf(fp, "%c", &caratteri)>0)//**** sono interi! -0.3
			i++;
	fclose(fp);
	return i;
}

/* funzione che legge una sequenza di interi da un file */
void leggiNumeri(int* interi, int n){
	int i = 0;												// posizione dell'elemento nell'array
	char caratteri;											// i caratteri del file
	// il file testuale
	FILE* fp = fopen("interi.txt", "w");  //**** il file va apero in lettura! -0.3
	if(fp==NULL)
		printf("Qualcosa %c abdato storto!", 138);
		else{
			// memorizzo i caratteri del file nell'array
			while(fscanf(fp, "%c", &caratteri)>0){//**** sono interi! -0.3
				interi[i] = caratteri;
				i++;
			}
			i=n;
		}//**** non chiudi il file -0.2
}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("In ogni tripla consecutiva il minimo %c dispari!\n", 138);
		else
			printf("In almeno una tripla dell'array il minimo non %c dispari!\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("In ogni tripla consecutiva il minimo %c dispari!\n", 138);
		else
			printf("In almeno una tripla dell'array il minimo non %c dispari!\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}