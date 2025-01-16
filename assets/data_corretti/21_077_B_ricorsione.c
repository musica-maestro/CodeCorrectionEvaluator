/*
5pt minimo dispari:..1
1pt scrivi numeri:...0.7
2pt quanti numeri:...0
2pt leggi numeri:....1.6
TOTALE ..............3.3
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in ogni tripla di interi il
minimo della tripla Ã¨ dispari */
int minimoDispari(int seq[], int lunghezza){
	int minimo;
	int minimo2;

	if(lunghezza<=2) //**** come fai ad accedere a 3 componenti se ne hai due o meno? -2
		minimo=((seq[0]<seq[1] && seq[0]<seq[2]) && (seq[0]%3==0))  ||
				((seq[1]<seq[0] && seq[1]<seq[2]) && (seq[1]%3==0)) ||
				((seq[2]<seq[0] && seq[2]<seq[3]) && (seq[2]%3==0));
		else
			minimo2 = minimo && minimoDispari(seq+1, lunghezza-1);
				//**** il valore di minimo non è inizializzato ne' calcolato -1
			return minimo2;
		  //**** il passo base calcola minimo, non minimo 2, non puoi usare 2 variabili -1
}

/* funzione che conta ... */
int quantiNumeri() {

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("Il file %c vuoto", 138);
		else {
			fread("%d",1,fp);//**** sintassi fread (sequenza,sizeof(int),1,fp)  -0.4
			fclose(fp);
		}

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","wb");
	if(fp==NULL)
		printf("file vuoto\n ");
		else {
			for(int i=0; i<lunghezza; i++)
				fwrite(sequenza[i],"%d", 1, fp);//**** primo parametro con/senza & -0.3
				fclose(fp);
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
			printf(" Esiste una triple di interi in cui il minimo %c dispari\n", 138);
		else
			printf(" Esiste una triple di interi in cui il minimo %c dispari\n", 138

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
			printf(" ... \n");
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}