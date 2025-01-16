/*
5pt minimo dispari:..3.3
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............8.3
*/
#include <stdio.h>
#include <stdlib.h>

void leggiNumeri(int* array, int l)
{
	FILE* fp;

	if(!(fp = fopen("interi.dat", "rb")))
		printf("Errore nell'apertura del file\n");
	else
	{
		fread(array, sizeof(int), l, fp);			//con una sola operazione leggo l'intero array
		fclose(fp);
		printf("Lettura effettuata\n");
	}
}

int quantiNumeri()
{
	FILE* fp;
	int cont = 0;

	if(!(fp = fopen("interi.dat", "rb")))
		printf("Errore nell'apertura del file\n");
	else
	{
		int temp;
		while(fread(&temp, sizeof(int), 1, fp) > 0)  		//aumento il contatore finche ci sono elementi da leggere
			cont++;
		fclose(fp);
	}

	return cont;
}

void scriviNumeri(int* array, int l)
{
	FILE* fp;

	if(!(fp = fopen("interi.dat", "wb")))
		printf("Errore nell'apertura del file\n");
	else
	{
		fwrite(array, sizeof(int), l, fp);			//con una sola operazione scrivo l'intero array
		fclose(fp);									//chiudo il file
		printf("Scrittura effettuata\n");
	}
}

int minimoDispari(int* array, int l)
{
	int ris = 0;
	int minimo;

	//calcolo il minimo  //***** non puoi calcolare il minimo prima di sapere se hai elementi a sufficienza! -0.5
	if(array[0] < array[1] && array[0] < array[2])
			minimo = array[0];
		else if(array[1] < array[0] && array[1] < array[2])
			minimo = array[1];
		else
			minimo = array[2];

	//passo base
	if(l == 3)//**** se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	//**** lunghezza==3 fa parte del passo ricorsivo.
	//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.2
		ris = (minimo % 2) != 0;
	else									//passo ricorsivo
		ris = (minimo % 2) != 0 && minimoDispari(array + 1, l - 1);

	return ris;
}


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
			printf("Ogni tripla di interi consecutivi e' tale che il minimo fra i tre interi e' dispari\n");
		else
			printf("Ogni tripla di interi consecutivi non e' tale che il minimo fra i tre interi e' dispari\n");

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
			printf("Ogni tripla di interi consecutivi e' tale che il minimo fra i tre interi e' dispari\n");
		else
			printf("Ogni tripla di interi consecutivi non e' tale che il minimo fra i tre interi e' dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}