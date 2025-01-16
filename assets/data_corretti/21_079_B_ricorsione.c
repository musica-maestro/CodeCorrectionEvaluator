/*
5pt minimo dispari:..4
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....1.7
TOTALE ..............8.7
*/

#include <stdio.h>
#include <stdlib.h>

/* ANDREA MACALE */

/* funzione che presi tre interi ne calcola il minimo */
int calcolaMinimo(int a, int b, int c)
{
	int minimo; // minimo tra gli elementi

	if (a < b)
	{
		if (a < c)
			minimo = a;
		else
			minimo = c;
	}
	else
	{
		if (b < c)
			minimo = b;
		else
			minimo = c;
	}

	return minimo;

}
/* funzione ricorsiva che verifica se in ogni tripla di elementi adiacenti, il minimo e' un dispari */
int minimoDispari(int *seq, int lunghezza)
{
	int esito; // esito della verifica universale (1 se e' positivo, 0 se e' negativo)

	if (lunghezza == 3)
	//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

		/* Caso base */
		esito = 1;

	else
		/* Passo ricorsivo */
		esito = (calcolaMinimo(seq[0], seq[1], seq[2]) % 2 != 0) && minimoDispari(seq+1, lunghezza-1);

	return esito;

}

/* funzione che conta e restituisce quanti interi sono presenti nel file */
int quantiNumeri()
{
	int conta = 0; // variabile contatore
	int num; // numero letto
	FILE *fp = fopen("Numeri.dat", "rb"); // puntatore a file

	if (fp != NULL)
	{
		/* File aperto */
		while (fread(&num, sizeof(int), 1, fp) > 0)
			conta++;
		fclose(fp);

		/* Stampa di conferma */
		printf("Sequenza recuperata!\n");
	}
	else
		/* File non aperto */
		printf("Niente da recuperare!\n");

	return conta;
}

/* funzione che legge gli interi presenti nel file */
void leggiNumeri(int* sequenza, int lunghezza)
{
	int num; // numero letto
	int ind = 0; // indice della sequenza
	FILE* fp = fopen("Numeri.dat", "rb"); // puntatore a file

	if(fp != NULL)
	{
		/* Leggi la sequenza */
		while (fread(&num, sizeof(int), 1, fp) > 0)
		{
			sequenza[ind] = num;
			ind++;
		}
		fclose(fp);
	}
	//**** non segnali che l'apertura del file è fallita if(fp==NULL) -0.3
}

/* funzione che scrive il contenuto della sequenza nel file */
void scriviNumeri(int* sequenza, int lunghezza)
{
	FILE* fp = fopen("Numeri.dat", "wb");

	if (fp != NULL)
	{
		/* Salva la sequenza nel file */
		fwrite(sequenza, sizeof(int), lunghezza, fp);
		fclose(fp);

		/* Stampa di conferma */
		printf("Sequenza salvata con successo!\n");
	}
	else
		printf("Salvataggio fallito!\n");
}

/* funzione principale */
int main()
{
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
			printf("Ogni tripla consecutiva ha come suo intero minimo dispari!\n");
		else
			printf("Alcune triple consecutive non hanno come suo intero minimo dispari!\n");

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
			printf("Ogni tripla consecutiva ha come suo intero minimo dispari!\n");
		else
			printf("Alcune triple consecutive non hanno come suo intero minimo dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}