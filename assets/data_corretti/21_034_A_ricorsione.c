/*
5pt massimo pari:..3.7
1pt scrivi numeri:.0.7
2pt quanti numeri:.2
2pt leggi numeri:..1.7
TOTALE ............8.1
*/
#include <stdio.h>
#include <stdlib.h>


int massimo(int seq[], int l){  //la funzione ricerca e ritorna il massimo elemento di una tripla data
	int max = seq[0];
	for(int i = 0; i<l; i++)
		if(max < seq[i])
			max = seq[i];
	return max;
}
/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int res;
	//**** Passo base se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	//**** lunghezza==3 fa parte del passo ricorsivo.
	//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.2
	if(lunghezza == 3)  //PASSO BASE: sequenza di 3 elementi
		res = (massimo(seq, 3)%2 == 0);  //il massimo Ã¨ pari : res = 1
	else                //PASSO RICORSIVO
		res = (massimo(seq, 3)%2 == 0) && massimoPari(seq+1,lunghezza-1);

	return res;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti = 0;   // variabile di conteggio
	FILE *fp = fopen("interi.dat", "rb");  //apertura file
	if(fp!= NULL){
		int num;
		while(fread(&num, sizeof(int), 1, fp))   //finche leggo un intero
			quanti++;  //aumenta il conteggio
	}
	fclose(fp);  //chiusura file
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");   // apertura file
	if(fp != NULL){   //se l'apertura Ã¨ riuscita
		fread(sequenza, sizeof(int), lunghezza, fp); //scrivi gli elementi
	}  //**** cosa succede se l'apertura del file è fallita? if(fp==NULL) -0.3
	fclose(fp);  //chiudi file
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb");
	if(fp != NULL)  //**** cosa succede se l'apertura del file è fallita? if(fp==NULL) -0.3
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
		if(massimoPari(array,lunghezza))
			printf("Nella sequenza ogni tripla ha il suo massimo pari\n");
		else
			printf("Nella sequenza non tutte le triple hanno il massimo pari\n");

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
			printf("Nella sequenza ogni tripla ha il suo massimo pari\n");
		else
			printf("Nella sequenza non tutte le triple hanno il massimo pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}