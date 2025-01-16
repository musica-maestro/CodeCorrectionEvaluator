/*
5pt minimo dispari:..3.7
1pt scrivi numeri:...1
2pt quanti numeri:...1.7
2pt leggi numeri:....2
TOTALE ..............8.1
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int dim){
	int ris;

	if(dim <= 3){//**** accedi a tre componenti dell'array, anche se la sua lunghezza è 2 o 1? -1
				 //**** lunghezza==3 fa parte del passo ricorsivo.
				//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3
		if(*seq < *(seq+1) && (*seq< *(seq+2)))
			ris = ((*seq % 2 != 0));
		else if((*seq > *(seq+1) && *(seq+1) < *(seq+2)))
			ris = (*(seq+1)%2 != 0);
		else if((*seq > *(seq+2) && *(seq+1) > *(seq+2)))
			ris = (*(seq+2)%2 !=0);
	}
	else{
		if(*seq < *(seq+1) && (*seq < *(seq+2)))
			ris = ((*seq % 2 != 0) && minimoDispari(seq+1, dim-1));
		else if(*seq > *(seq+1) && *(seq+1) < *(seq+2))
			ris = ((*(seq+1)%2 != 0) && minimoDispari(seq+1, dim-1));
		else if(*seq > *(seq+2) && *(seq+1) > *(seq+2))
			ris = ((*(seq+2)%2 !=0) && minimoDispari(seq+1, dim-1));
	}
	return ris;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp = fopen("sequenza.dat", "rb");
	int n;
	int quanti = 0;
	if(fp!=NULL){
		while(fread(&n, sizeof(int), 1, fp)){
			quanti++;
		}//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
		fclose(fp);
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int dim) {
	FILE* fp = fopen("sequenza.dat", "rb");

	if(fp!=NULL){
		fread(sequenza, dim*sizeof(int), dim, fp);
		fclose(fp);
	}
	else
		printf("errore nell'apertura\n\n");

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int dim) {
	FILE* fp = fopen("sequenza.dat", "wb");

	if(fp != NULL){
		fwrite(sequenza, sizeof(int), dim, fp);
		printf("Salvataggio completato!\n\n");
		fclose(fp);
	}
	else
		printf("Errore nel salvataaggio!\n\n");
}

/* funzione principale */
int main() {
    int dim; 		//	dim dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la dim della sequenza */
		printf("Introduci la dim della sequenza: ");
		scanf("%d",&dim);

		/* crea l'array e leggine i valori degli elementi */
		int array[dim];
		printf("Scrivi %d elementi \n",dim);
		for(int i=0;i<dim;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,dim))
			printf(" Il minimo di ogni sequenza e' dispari \n");
		else
			printf("Non in tutte le triple il minimo e' dispari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,dim);
	}
	/* recupero sequenza da file */
	else {
		/* determina la dim della sequenza */
		dim = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[dim];
		leggiNumeri(array,dim);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<dim;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,dim))
			printf(" Il minimo di ogni sequenza e' dispari \n \n");
		else
			printf(" Non in tutte le triple il minimo e' dispari \n \n");

		/* salva la sequenza su file */
		scriviNumeri(array,dim);
	}
}