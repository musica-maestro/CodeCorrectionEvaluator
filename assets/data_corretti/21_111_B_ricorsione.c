/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.7
2pt quanti numeri:...1.2
2pt leggi numeri:....2
TOTALE ..............8.9
*/
#include <stdio.h>
#include <stdlib.h>

int calcolaMinimo(int*seq,int l) {
	int min;
	if((seq[0]<seq[1]) && (seq[0]<seq[2]))
		min=seq[0];
	else {
		if((seq[1]<seq[0]) && (seq[1]<seq[2])) {
			min=seq[1];
		}
		else
			min=seq[2];
	}
	return min;
}

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int l){
	int dispari;
	int minimo;
	if(l<3)
		dispari=1;
	else {
		minimo=calcolaMinimo(seq,l);
		dispari=(minimo%2!=0) && minimoDispari(seq+1,l-1);
	}
	return dispari;
}

/* funzione che conta ... */
int quantiNumeri() {
	int l;  //**** il contatore non è inizializzato -0.5
	FILE*fp=fopen("minimoDisp.dat","rb");
	if(fp==NULL)
		printf("niente\n\n");
	else {
		int numero;
		while(fread(&numero,sizeof(int),1,fp)>0) {
			l++;
		}
	}//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	fclose(fp);
	return l;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("minimoDisp.dat","rb");
	if(fp==NULL)
		printf("niente\n\n");
	else {
		fread(sequenza,sizeof(int),lunghezza,fp);
	}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("minimoDisp.dat","wb");
	if(fp==NULL)
		printf("niente\n\n");
	else {
		fwrite(&sequenza,sizeof(int),lunghezza,fp);  //**** nella fwrite primo parametro con & -0.3
	}
	fclose(fp);
	printf("salvataggio eseguito\n\n");
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
			printf(" ogni tripla di interi cons ha il minimo dispari\n");
		else
			printf(" ogni tripla di interi cons NON ha il minimo dispari\n");

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
			printf("ogni tripla di interi cons ha il minimo dispari \n");
		else
			printf(" ogni tripla di interi cons NON ha il minimo dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}