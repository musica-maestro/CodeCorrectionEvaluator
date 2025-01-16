/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1.5
2pt leggi numeri:..2
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
    int max;
    int isPari=-1;
    /*Caso base**/
    if(lunghezza<3)
      isPari=1;
    /*Passo ricorsivo: cerco il massimo della tripla,mi chiedo se sia pari e se questa proprietà valga nel resto della funzione*/
    else{
        if(seq[0]>seq[1] && seq[0]>seq[2])
            max=seq[0];
        if(seq[1]>seq[0] && seq[1]>seq[2])
            max=seq[1];
        if(seq[2]>seq[0] && seq[2]>seq[1])
            max=seq[2];
        isPari=(max%2==0) && massimoPari(seq+1,lunghezza-1);
    }
    return isPari;
}

/* funzione che conta ... */
int quantiNumeri() {
    int n;
    int quanti; //**** il contatore non � inizializzato -0.5
    FILE *fp=fopen("maxpari.dat","rb");
    while(fread(&n,sizeof(int),1,fp)) // finchè la fread restituisce 1,incremento il contatore
        quanti++;
    fclose(fp);
    return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("maxpari.dat","rb");
    if(fp==NULL)
        printf("Apertura file non riuscita!\n\n");
    else
        fread(sequenza,sizeof(int),lunghezza,fp);
    fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
     FILE *fp=fopen("maxpari.dat","wb");

     fwrite(sequenza,sizeof(int),lunghezza,fp);
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
			printf("Ogni tripla della sequenza %c tale che il massimo fra i tre interi %c pari. \n\n",138,138);
		else
			printf("Non ogni tripla della sequenza %c tale che il massimo fra i tre interi %c pari. \n\n",138,138);

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
			printf("Ogni tripla della sequenza %c tale che il massimo fra i tre interi %c pari. \n\n",138,138);
		else
			printf("Non ogni tripla della sequenza %c tale che il massimo fra i tre interi %c pari. \n\n",138,138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
