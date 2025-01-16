/*
5pt massimo pari:..5
1pt scrivi numeri:.0.7
2pt quanti numeri:.1.7
2pt leggi numeri:..1.7
TOTALE ............9.1
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int max,pari=0;
	if(lunghezza>2){
		if(seq[0]>seq[1] && seq[0]>seq[2]){
			max=seq[0];
		}
		if(seq[1]>seq[2] && seq[1]>seq[0]){
			max=seq[1];
		}
		else{
			max=seq[2];
		}
		if(max%2==0){
			pari = massimoPari(seq+1,lunghezza -1);
		}
		else{
			pari=0;
		}
	}else
	{
		pari=1;  //**** di solito si scrive prima il passo base e poi quello ricorsivo
	}
	return pari;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp = fopen("interi.txt", "r"); //**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	int quanti=0,numero;
	while(fscanf(fp,"%d\n",&numero)>0){
		quanti++;
	}
	fclose(fp);
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt", "r");//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	int i=0,numero;
	while(fscanf(fp,"%d\n",&numero)>0){
		sequenza[i]=numero;
		i++;
	}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt", "w");//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	for(int i=0;i<lunghezza;i++){
		fprintf(fp,"%d\n",sequenza[i]);
	}
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
			printf(" Massimi pari \n");
		else
			printf(" Non tutti i massimi sono pari \n");

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
			printf(" Massimi pari \n");
		else
			printf(" Non tutti i massimi sono pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}