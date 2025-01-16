/*
5pt minimo dispari:..4
1pt scrivi numeri:...1
2pt quanti numeri:...1.5
2pt leggi numeri:....2
TOTALE ..............8.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int minimo = seq[0];  //inizializzo minimo al primo elemento della sequenza
	int res;   //da restituire

	if (minimo > seq[1])  //assegno a minimo l'intero piÃ¹ piccolo della tripla
		minimo = seq[1];
	else
		if (minimo > seq[2])
			minimo = seq[2];
	//**** va bene, ma lo devi calcolare dopo il passo base, cioe' dopo aver verificato
	//**** che nell'array ci sono almeno 3 elementi! -1
	//caso base
	if (lunghezza<3)
		res = 1;
	else
		res = (minimo % 2 != 0) && minimoDispari (seq+1, lunghezza-1);   //chiamata ricorsiva

	return res;
}

/* funzione che conta ... */
int quantiNumeri() {
	int i;  //variabile di appoggio per leggere su file e permettere a quanti di aumentare
	int quanti;  //variabile da restituire
                                             //**** il contatore non è inizializzato -0.5
	FILE* fp = fopen ("interi.dat", "rb");

	//verifico che il file si sia aperto
	if (fp == NULL)
		printf ("apertura file fallita!\n");
	else{
		while (fread(&i, sizeof(int), 1, fp) > 0)  //fintanto che ho qualcosa da leggere incremento di 1 quanti
			quanti++;

		fclose(fp);  //chiudo il file
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE* fp = fopen ("interi.dat", "rb");

	//verifico che il file si sia aperto
	if (fp == NULL)
		printf ("apertura file fallita!\n");
	else{
		for (int i=0; i<lunghezza; i++)  //leggo da file gli interi all'interno della sequenza
			fread (&sequenza[i], sizeof(int), 1, fp);

		printf ("lettura file completata\n");
		fclose (fp);  //chiudo il file
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {

	FILE* fp = fopen ("interi.dat", "wb");

	//verifico che il file si sia aperto
	if (fp == NULL)
		printf ("apertura file fallita!\n");
	else{

		fwrite (sequenza, sizeof(int), lunghezza, fp);   //scrivo su file gli interi

		printf ("salvataggio effettuato!\n");
		fclose (fp);   //chiudo il file
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
			printf("il minimo di ogni tripla e' dispari! \n");
		else
			printf("non in tutte le triple il minimo e' dispari! \n");

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
			printf("il minimo di ogni tripla e' dispari! \n");
		else
			printf("non in tutte le triple il minimo e' dispari! \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}