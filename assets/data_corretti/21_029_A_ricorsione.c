/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1.1
2pt leggi numeri:..2
TOTALE ............9.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Funzione che mi permette di individuare il massimo nella sequenza */
int massimo(int a,int c,int b)
{
	int max;
	max=a;
	if(b>max)
		max=b;
	else
		max=c;
	return max;
}
/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza)
{
	int max; /* Variabile per il massimo */
	/* PASSO BASE */
	if(lunghezza<3)
	{
		max=1;
	}
	/* PASSO RICORSIVO */
	else
	{
		max = (massimo(seq[0],seq[1],seq[2])%2==0) && massimoPari(seq+1,lunghezza-1);
	}
	return max;
}

/* funzione che conta ... */
int quantiNumeri() {

	int numero=0; /* Variabile per il numero di elementi della sequenza */
	FILE *fp = fopen("massimoPari.dat","rb");
	/* Apertura avvenuta */
	if(fp!=NULL)
	{
		while(fread(numero,sizeof(int),1,fp))//**** sintassi fread (&numero,sizeof(int),1,fp)  -0.4
		{
			numero++; //**** non puoi usare numero sia per contare, sia per la fread,
		}             //**** così ad ogni lettura perdi il contatore e in numero acquisisci
	}                 //**** il valore letto dal file (in teoria) -0.5
	else
		printf("Apertura file non avvenuta\n");

	fclose(fp); /* Chiusura file */
	return numero;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza)
{
	/* APERTURA DEL FILE */
	FILE *fp = fopen("massimoPari.dat","rb");
	/* Apertura file avvenuta */
	if(fp!=NULL)
	{
		/* leggi da file */
		fread(sequenza,sizeof(int),lunghezza,fp);
		/* Chiusura file */
		fclose(fp);
	}
	else
		printf("Apertura non avvenuta\n");
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza)
{
	/* APERTURA DEL FILE IN SCRITTURA */
	FILE *fp = fopen("massimoPari.dat","wb");
	/* Apertura file avvenuta */
	if(fp!=NULL)
	{
		/* leggi da file */
		fwrite(&sequenza,sizeof(int),lunghezza,fp);
		/* Chiusura file */
		fclose(fp);
	}
	else
		printf("Salvataggio non avvenuto\n");
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
			printf("Ogni tripla nell'array e' tale che il valore massimo sia pari\n");
		else
			printf("Ogni tripla nell'array non e' tale che il valore massimo sia pari\n");

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
			printf("Ogni tripla nell'array e' tale che il valore massimo sia pari\n");
		else
			printf("Ogni tripla nell'array non e tale che il valore massimo sia pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}