/*
5pt minimo dispari:..4
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int risultato;
	int minimo;
	if(lunghezza==3) //**** se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
		risultato=1;
	else{
		minimo=seq[0];
		if(seq[1] < minimo && seq[1] < seq[2])
			minimo=seq[1];
		else if(seq[2] < minimo && seq[2] < seq[1])
			minimo=seq[2];
		risultato=(minimo % 2 != 0) && minimoDispari(seq+1, lunghezza-1);

	}
	return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0;
	FILE *fp = fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("Apertura file non riuscita!\n");
	else{
		int numero;
		while(fread(&numero, sizeof(int), 1, fp))
			quanti++;
	}
	fclose(fp);
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("Apertura file non riuscita!\n");
	else
		fread(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
		FILE *fp = fopen("interi.dat", "wb");
	if(fp==NULL)
		printf("Salvataggio non riuscito!\n");
	else
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);
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
			printf("Tutti i minimi trovati sono dispari!\n");
		else
			printf("Esiste almeno un minimo nella sequenza che non e' dispari!\n");

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
		for(int i=0;i<lunghezza;i++){

			printf("%d ", array[i]);
		printf("\n");
		}

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Tutti i minimi trovati sono dispari!\n");
		else
			printf("Esiste almeno un minimo nella sequenza che non e' dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
		/* salva la sequenza su file */