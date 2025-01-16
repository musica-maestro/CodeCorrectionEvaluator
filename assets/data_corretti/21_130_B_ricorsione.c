/*
5pt minimo dispari:..3.7
1pt scrivi numeri:...0.7
2pt quanti numeri:...0
2pt leggi numeri:....1
TOTALE ..............5.4
*/
#include <stdio.h>
#include <stdlib.h>
int minimoDispariRic (int array[],int i, int lunghezza)
{
	if (lunghezza==3)
	//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

	{
		return (((array[0]<array[1] && array[0]<array[2]) && (array[0]%2!=0))
		     || ((array[1]<array[0] && array[1]<array[2]) && (array[1]%2!=0))
		     || ((array[2]<array[0] && array[2]<array[1]) && (array[2]%2!=0) ))  ;
	}//**** lunghezza==3 fa parte del passo ricorsivo.
	 //**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3

	else
	{
		return (((array[i]<array[i+1] && array[i]<array[i+2]) && (array[i]%2!=0))
		     || ((array[i+1]<array[i] && array[i+1]<array[i+2])&& (array[i+1]%2!=0))
		     || ((array[i+2]<array[i] && array[i+2]<array[i]) && (array[i+2]%2!=0))
		     && (minimoDispariRic(array,i+1,lunghezza-1)));  ;
	}


}
/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	return minimoDispariRic(seq,0,lunghezza);
}

/* funzione che conta ... */
int quantiNumeri() {

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","rb");
	int i=0;
	if (fp!=NULL)
	{
		while (i<lunghezza)
		fread(&sequenza,sizeof(int),1,fp); //**** nella fread primo parametro &sequenza[i] -0.3
		i++;                   //**** loop infinito, mancano le parentesi graffe -0.5
	}
	else
	{
		printf("apertura errata");
	}
}//**** non chiudi il file -0.2

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","wb");

	if (fp!=NULL)
	{
	fwrite(&sequenza,sizeof(int),lunghezza,fp);//**** nella fwrite primo parametro senza & -0.3

	}
	else
	{
		printf("errore di apertura");
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
			printf("il tuo minimo e dispari \n");
		else
			printf(" il tuo minimo non e dispari \n");

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
			printf(" la sequenza rispetta le condizioni \n");
		else
			printf(" la sequenza non rispetta le condizioni \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}