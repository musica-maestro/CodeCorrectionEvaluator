/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
/*Francesco De Nadai*/
#include <stdio.h>
#include <stdlib.h>
/*funzione che trova il massimo tra tre numeri*/
int trovaMax(int a, int b, int c) {
	int max; //variabile in cui memorizzo il massimo tra i tre numeri
	if (a>b)
		if (a>c)
			max=a;
		else
			max=c;
	else
		if (b>c)
			max=b;
		else
			max=c;
	/*restituisco il massimo trovato*/
	return max;
}
/* funzione ricorsiva che verifica se ogni tripla di elementi consecutivi
 * dell'array è tale che il massimo fra i tre interi è pari */
int massimoPari(int *seq, int lunghezza){
	int ris; //variabile in cui memorizzo il risultato della verifica su ciascuna tripla
	/*caso base, ho meno di 3 elementi*/
	if (lunghezza<3)
		ris=1;
	/*passo ricorsivo*/
	else
		ris=(trovaMax(seq[0],seq[1],seq[2])%2==0)&&massimoPari(seq+1,lunghezza-1);
	/*restiuisco il booleano ris*/
	return ris;
}

/* funzione che conta quanti numeri sono salvati nel file "interi.dat" */
int quantiNumeri() {
	int tot=0; //conta i numeri letti
	int temp; //salva temporaneamente qui il numero letto
	/*apro il file da cui leggere i numeri presenti*/
	FILE *fp=fopen("interi.dat","rb");
	/*se l'apertura non va a buon fine lo comunico all'utente*/
	if (fp==NULL)
		printf("Impossibile contare quanti numeri ci sono sul file\n");
	/*atrimenti leggo il numero di numeri presenti incrementando la variabile tot ogni
	 * volta che ne leggo uno dal file*/
	else {
		while(fread(&temp,sizeof(int),1,fp))
			tot++;
		printf("Ho letto %d numeri\n",tot); //messaggio di controllo per l'utente
	}
	/*chiudo il file:
	 * (a volte il sistema operativo rimanda il salvataggio
	 * e la chiusura del file alla fine per ottimizzare i processi)*/
	fclose(fp);
	/*restituisco il numero di elementi letti*/
	return tot;
}

/* funzione che legge i numeri salvati nel file "interi.dat" */
void leggiNumeri(int* sequenza, int lunghezza) {
	/*apro il file*/
	FILE *fp=fopen("interi.dat","rb");
	/*se l'apertura non va a buon fine lo comunico all'utente*/
	if (fp==NULL)
		printf("Impossibile leggere numeri da file!\n");
	/*altrimenti leggo i numeri salvati sul file e li memorizzo nell'array "sequenza" */
	else {
		fread(sequenza,sizeof(int),lunghezza,fp);
		printf("Numeri letti da file e salvati sull'array\n");
	}
	/*chiudo il file:
	 * (a volte il sistema operativo rimanda il salvataggio
	 * e la chiusura del file alla fine per ottimizzare i processi)*/
	fclose(fp);
}

/* funzione che scrive i numeri precedentemente inseriti da input nel file "interi.dat"*/
void scriviNumeri(int* sequenza, int lunghezza) {
	/*apro il file*/
	FILE *fp=fopen("interi.dat","wb");
	/*se l'apertura non va a buon fine lo comunico all'utente*/
	if (fp==NULL)
		printf("Impossibile salvare numeri su file!\n");
	/*altrimenti scrivo sul file i numeri salvati nell'array*/
	else {
		fwrite(sequenza,sizeof(int),lunghezza,fp);
		printf("Numeri salvati su file\n");
	}
	/*chiudo il file:
	 * (a volte il sistema operativo rimanda il salvataggio
	 * e la chiusura del file alla fine per ottimizzare i processi)*/
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
		if(massimoPari(array,lunghezza))
			printf("In ogni tripla di interi consecutivi il massimo tra i tre interi e' pari\n");
		else
			printf("Non in tutte le triple di interi consecutivi il massimo tra i tre interi e' pari\n");

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
		if(massimoPari(array,lunghezza))
			printf("In ogni tripla di interi consecutivi il massimo tra i tre interi e' pari\n");
		else
			printf("Non in tutte le triple di interi consecutivi il massimo tra i tre interi e' pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}