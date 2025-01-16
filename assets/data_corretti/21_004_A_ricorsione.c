/*
5pt massimo pari:..2.7
1pt scrivi numeri:.0
2pt quanti numeri:.1.3
2pt leggi numeri:..1
TOTALE ............5.0
*/

#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza)
{
	int pari; int somma;//**** sintassi: no int pari,  ma int pari; -0.3
	//**** PB sbagliato: <=2 (perché devi considerare una terna di elementi) -0.5
	if (lunghezza<=1)
	{
		pari = 1;
	}
	else
	{//**** verifichi un'altra proprietà -1.5
	 //**** il piu' grande dei 3 deve essere pari, non la somma
		somma=seq[0]+seq[1]+seq[2];
		pari = somma%2==0 && massimoPari(seq+1, lunghezza-1);
	}
	return pari;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE *fp = fopen("interi.txt", "r");
	int contatore=0;
	int numero;
	//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	while (fread(&numero, sizeof(int), 1, fp)>0)
	{         //***** fread si usa per file binari, non per file di testo -0.3
		contatore++;
	}
	//**** non chiudi il file -0.2
	return contatore;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE *fp = fopen("interi.txt", "r");
	//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	int i;  //**** non inizializzi i=0; -0.3
	while (i<lunghezza)
	{    //***** fread si usa per file binari, non per file di testo -0.2
		fread(&(sequenza[i]), sizeof(int), 1, fp);
		printf("Numero letto: %d", sequenza);
		i++;
	}
	//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.txt", "w");
	//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.2
	int i;//**** non inizializzi i=0; -0.3
	while (i<lunghezza)
	{   //***** fwrite si usa per file binari, non per file di testo -0.2
		fwrite(sequenza, sizeof(int), 1, fp);
		sequenza++;
		i++;
	}
	//**** non chiudi il file -0.2
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
		if(massimoPari(array,lunghezza))
			printf("Tutte le triple hanno il massimo pari.\n");
		else
			printf("NON Tutte le triple hanno il massimo pari. \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();
		printf("Lunghezza: %d", lunghezza);
		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf("Tutte le triple hanno il massimo pari.\n");
		else
			printf("NON Tutte le triple hanno il massimo pari. \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
