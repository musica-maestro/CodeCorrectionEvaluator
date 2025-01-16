/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>

/*funzione che restituisce il minimo di una tripla di interi*/
int minimo(int a,int b,int c){
    int min;
    if(a<b)
        min = a;
    else
        min = b;
    if(c<min)
        min = c;
    return min;
}

/* funzione ricorsiva che verifica se nell'array parametro il minimo di gogni
tripla di interi adiacenti è dispari */
int minimoDispari(int *seq, int lunghezza){
    int ris;
    if(lunghezza<3)
        ris = 1;
    else{
        ris = (minimo(seq[0],seq[1],seq[2])%2!=0) && minimoDispari(seq+1,lunghezza-1);
    }
    return ris;
}

/* funzione che conta il numero di interi presenti in un file binario */
int quantiNumeri() {
    int conteggio=0;
    FILE* fp = fopen("interi.dat","rb");
    if(fp!=NULL){
        int num;
        while(fread(&num,sizeof(int),1,fp)>0)
            conteggio++;
        fclose(fp);
    }
    return conteggio;
}

/* funzione che legge una sequenza di interi da file */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE* fp = fopen("interi.dat","rb");
    if(fp==NULL)
        printf("Apertura file non riuscita\n");
    else{
        for(int i=0;i<lunghezza;i++)
            fread(&sequenza[i],sizeof(int),1,fp);
        fclose(fp);
    }
}

/* funzione che scrive un array di interi su un file binario */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE* fp = fopen("interi.dat","wb");
    if(fp==NULL){
        printf("Salvataggio non riuscito\n");
    }
    else{
        for(int i=0;i<lunghezza;i++)
            fwrite(&sequenza[i],sizeof(int),1,fp);
        fclose(fp);
        printf("Salvataggio effettuato\n");
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
			printf(" Ogni tripla di interi %c tale che il minimo sia dispari \n",138);
		else
			printf(" Non ogni tripla di interi %c tale che il minimo sia dispari \n",138);

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
			printf(" Ogni tripla di interi %c tale che il minimo sia dispari \n",138);
		else
			printf(" Non ogni tripla di interi %c tale che il minimo sia dispari \n",138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
