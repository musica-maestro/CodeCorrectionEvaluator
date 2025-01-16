/*
5pt massimo pari:..3.5
1pt scrivi numeri:.0.7
2pt quanti numeri:.1.7
2pt leggi numeri:..1.7
TOTALE ............7.6
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int check;
	if(lunghezza <= 2){
		check = 1;
	}
	else{
		if((seq[0]+seq[1]+seq[2] % 2== 0)){  //**** verifica della proprietà sbagliata -1.5
			check = massimoPari(seq+1, lunghezza-1);
		}
		else{
			check = 0;
		}
	}
	return check;
}

/* funzione che conta ... */
int quantiNumeri() {
	int V[30]; //**** bastava un int
	int i=0;
	int count = 0;
	FILE *fp = fopen("interi.dat", "rb");
	if(fp != NULL){
		while(fread(&(V[i]),sizeof(int), 1,fp)){ //**** infatti usi solo la prima componente dell'array,
			count = count +1;                    //**** perché i non varia. -0.3
		}
	}
	fclose(fp);
	return count;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	int i=0;
	FILE *fp = fopen("interi.dat", "rb");
	if(fp != NULL){ //**** cosa succede se l'apertura del file è fallita? if(fp==NULL) -0.3
		while(fread(&(sequenza[i]),sizeof(int), 1 ,fp)){
			i++;
	}
	fclose(fp);
}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	int i;
	FILE *fp = fopen("interi.dat", "wb");
	for(i=0; i<lunghezza; i++){//**** cosa succede se l'apertura del file è fallita? if(fp==NULL) -0.3
		fwrite(&(sequenza[i]),sizeof(int), 1, fp);
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
		if(massimoPari(array,lunghezza) == 1)
			printf(" Tutte le somme triple sono pari \n");
		else
			printf(" Non utte le somma triple sono pari \n");

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
		if(massimoPari(array,lunghezza)== 1)
			printf(" Sono tutti pari \n");
		else
			printf("Non sono tutti pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	system("pause");
	return 0;
}