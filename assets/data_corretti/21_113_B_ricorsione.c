/*
5pt minimo dispari:..4
1pt scrivi numeri:...0.5
2pt quanti numeri:...1.5
2pt leggi numeri:....1.5
TOTALE ..............7.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se data una sequenza di interi per ogni tripla della sequenza il minimo Ã¨ dispari */
int minimoDispari(int *seq, int dim){
	/*caso base: dim<3 */
	int verificata=0; //variabile di verifica universale //**** variabile di universalità inizializzata male -1
	if (dim>=3){
		verificata= ((seq[0]<seq[1] && seq[0]<seq[2] && seq[0]%2!=0) ||
					(seq[1]<seq[0] && seq[1]<seq[2] && seq[1]%2!=0) ||
					(seq[2]<seq[1] && seq[2]<seq[0] && seq[2]%2!=0)) && minimoDispari(seq+1, dim-1);
	}
}

/* funzione che conta i numeri interi memorizzati su un file */
int quantiNumeri() {
	int quanti=0; //variabile che conta il numero di interi memorizzati su un file
	/* apri file in lettura */
	FILE* fp=fopen("interi.txt", "r");
	/*apertura fallita*/
	if (fp==NULL){
		printf("Apertura file non riuscita!\n\n");
	/*apertura riuscita*/
	}else{
		/*scrri il file fino ad end of file*/
		while (fscanf(fp,"%d")!=EOF){  //**** nella scanf manca la variabile in cui viene acquisito il valore del file
			quanti++;                  //**** es. int n; fscanf(fp,"%d",&n); -0.5
		}
		fclose(fp);
		/*file terminato*/
		printf("Il file contiene %d numeri interi!\n\n", quanti);
	}
}

/* funzione che legge una sequenza di interi da un file e li memorizza in un array */
void leggiNumeri(int* sequenza, int dim) {
	/*apri file in lettura*/
	FILE* fp=fopen("interi.txt", "r");
	/*apertura fallita*/
	if (fp==NULL){
		printf("Apertura file non riuscita!\n\n");
	/*apertura riuscita*/
	}else{
		for (int i=0; i<dim; i++){
			if (quantiNumeri()){
				fscanf(fp,"%d", &sequenza[i]);
			}
			i++; //**** non devi incrementare tu la i! -0.5
		}
		fclose(fp);
		/*hai riempito tutto l'array*/
		printf("Acquisizione comletata!\n\n");
	}
}

/* funzione che scrive un array fornito come parametro in un file testuale*/
void scriviNumeri(int* sequenza, int dim) {
	/*apri file in scrittura*/
	FILE* fp=fopen("interi.txt", "w");
	/*apertura fallita*/
	if (fp==NULL){
		printf("Apertura file non riuscita!\n\n");
	/*apertura riuscita*/
	}else{
		for (int i=0; i<dim; i++){
			fprintf(fp, "%d", sequenza[i]);
			i++; //**** non devi incrementare tu la i! -0.5
		}
		fprintf(fp, "\n");
		fclose(fp);
		/*hai riempito tutto l'array*/
		printf("Salvataggio comletato!\n\n");
	}
}

/* funzione principale */
int main() {
    int dim; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&dim);

		/* crea l'array e leggine i valori degli elementi */
		int array[dim];
		printf("Scrivi %d elementi \n",dim);
		for(int i=0;i<dim;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,dim))
			printf("Tutti i minimi delle triple appartenenti alla sequenza sono dispari!\n");
		else
			printf("Non tutti i minimi delle triple appartenenti alla sequenza sono dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,dim);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
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
			printf("Tutti i minimi delle triple appartenenti alla sequenza sono dispari!\n");
		else
			printf("Non tutti i minimi delle triple appartenenti alla sequenza sono dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,dim);
	}
}