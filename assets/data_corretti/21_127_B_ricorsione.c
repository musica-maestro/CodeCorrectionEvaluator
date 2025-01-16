/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.5
2pt quanti numeri:...1.5
2pt leggi numeri:....0.5
TOTALE ..............7.5
*/
#include <stdio.h>
#include <stdlib.h>
int minimo(int n1, int n2, int n3){
	int min=n1;  //**** qui non serve inizializzare, basta dichiarare
	if (n1<=n2 && n1<=n3)
		min=n1;
	else if(n2<=n1 && n2<=n3)
		min=n2;
	else if(n3<=n1 && n3<=n1)
		min=n3;
	printf("Minimo: %d", min);
	return(min);

}
/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int l){
	int verificato;
	/*Passo base*/
	if (l<=2)
		verificato=1;
	else{
		if (minimo(seq[0],seq[1],seq[2])%2==0)
			verificato=0;
		else
			verificato=minimoDispari(seq+1,l-1);
	}
	return(verificato);
}

/* funzione che conta ... */
int quantiNumeri() {
	int n; // per la letturqa
	int c; // contatore            //**** il contatore non è inizializzato -0.5
	FILE* fp=fopen("interi.bin", "rb");
	if (fp==NULL)
		printf("Apertura file non riuscita. \n");
	else{
		while(fread(&n,sizeof(int),1,fp)>0)
			c=c+1;
	}
	fclose(fp);
	return(c);
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.bin", "rb");
	if (fp==NULL)
	printf("Apertura file non riuscita. \n");
	else{
		int n;
		int array[lunghezza]; //**** memorizzi gli elementi che leggi in "locale", mentre dovevi memorizzarli
							  //**** nell'array passato come parametro, cioè sequenza! -1
		for (int i=0; i<lunghezza;i++)
			array[i]=fread(&n,sizeof(int),1,fp); //****la fread restituisce il numero di elementi letti, non il valore letto -0.5
	}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.bin", "wb");
	if (fp==NULL)
		printf("Apertura file non riuscita. \n");
	else{
		int n;
		for (int i=0;i<n;i++){
			fwrite(&n,sizeof(int),1,fp); //**** &sequenza[i] -0.5
		}
		printf("Salvataggio sequenza riuscito. \n");
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
		if(minimoDispari(array,lunghezza))
			printf(" Ogni tripla ha il minimo fra di essi dispari.\n");
		else
			printf("  Ogni tripla NON ha il minimo fra di essi dispari.\n");

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
			printf("Ogni tripla ha il minimo fra di essi dispari.\n");
		else
			printf("  Ogni tripla NON ha il minimo fra di essi dispari.\nn");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
