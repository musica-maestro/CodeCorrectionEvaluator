/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>


/* funzione che calcola il minimo fra tre interi */
int minimo(int num1, int num2, int num3)
{
	int min;

	if(num1 < num2 && num1 < num3)
	{
		min = num1;
	}
	else if(num2 < num1 && num2 < num3)
	{
		min = num2;
	}
	else if(num3 < num1 && num3 < num1)
	{
		min = num3;
	}

	return min;
}

/* funzione ricorsiva che verifica se in un array di interi ogni tripla di interi consecutivi nella sequenza
   è tale che il minimo fra i tre interi è dispari */
// PS: PROBLEMA DI VERIFICA UNIVERSALE
int minimoDispari(int *seq, int lunghezza)
{
	// VARIABILE CHE MEMORIZZA IL RISULTATO
	int risultato;

	// CASO BASE
	if(lunghezza < 3)
	{
		risultato = 1;
	}

	// PASSO RICORSIVO
	else
	{
		risultato = (minimo(seq[lunghezza - 1], seq[lunghezza - 2], seq[lunghezza - 3]) % 2 != 0) &&
		minimoDispari(seq, lunghezza - 1);
	}

	return risultato;
}

/* funzione che conta quanti interi ci sono all'interno di un file testuale */
int quantiNumeri() {
	// CONTATORE
	int quanti = 0;

	// APERTURA DEL FILE IN LETTURA
	FILE* fp = fopen("interi.txt", "r");

	// APERTURA NON RIUSCITA
	if(fp == NULL)
	{
		printf("\nApertura non riuscita o file non esistente\n\n");
	}

	// APERTURA RIUSCITA
	else
	{
		int numero;
		while(fscanf(fp, "%d", &numero) != EOF)
		{
			quanti++;
		}
		fclose(fp);
	}

	return quanti;
}

/* funzione che legge gli elementi da un file testuale e li salva su un array */
void leggiNumeri(int* sequenza, int lunghezza) {
	// APERTURA DEL FILE IN LETTURA
	FILE* fp = fopen("interi.txt", "r");

	// APERTURA NON RIUSCITA
	if(fp == NULL)
	{
		printf("\nApertura non riuscita o file non esistente\n\n");
	}

	// APERTURA RIUSCITA
	else
	{
		for(int i = 0; i < lunghezza; i++)
		{
			fscanf(fp, "%d", &sequenza[i]);
		}
		fclose(fp);
		printf("\nLETTURA COMPLETATA\n\n");
	}
}

/* funzione che scrive gli elementi di un array su un file testuale */
void scriviNumeri(int* sequenza, int lunghezza)
{
	// APERTURA DEL FILE IN SCRITTURA
	FILE* fp = fopen("interi.txt", "w");

	// APERTURA NON RIUSCITA
	if(fp == NULL)
	{
		printf("\nApertura non riuscita\n\n");
	}

	// APERTURA RIUSCITA
	else
	{
		for(int i = 0; i < lunghezza; i++)
		{
			fprintf(fp, "%d ", sequenza[i]);
		}
		fclose(fp);
		printf("\nSCRITTURA COMPLETATA\n\n");
	}
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
		{
			printf("\nAll'interno della sequenza ogni tripla di interi consecutivi %c tale che...\n", 138);
			printf("...il minimo fra i tre interi %c dispari!\n\n", 138);

		}
		else
		{
			printf("\nAll'interno della sequenza non tutte le triple di interi consecutivi sono tali che...\n");
			printf("...il minimo fra i tre interi della tripla %c dispari...\n\n", 138);
		}
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
		{
			printf("\nAll'interno della sequenza ogni tripla di interi consecutivi %c tale che...\n", 138);
			printf("...il minimo fra i tre interi %c dispari!\n\n", 138);

		}
		else
		{
			printf("\nAll'interno della sequenza non tutte le triple di interi consecutivi sono tali che...\n");
			printf("...il minimo fra i tre interi della tripla %c dispari...\n\n", 138);

		}

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}

	return 0;
}