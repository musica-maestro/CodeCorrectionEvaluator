/*
5pt massimo pari:..4.5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

int massimo(int a,int b,int c){
	int max = a;
	if(max<b && b>c)
		max = b;
	else
		if(max<c)
			max = c;

	return max;
}
/* funzione ricorsiva che verifica ... */
int massimoPari(int *a, int l){
	int risultato;

	if(l<=2)
		risultato = ((massimo(a[0],a[1],a[2]))%2) == 0; //**** se l<=2 non puoi accedere a 3 componenti! -0.5
	else
		risultato = (((massimo(a[0],a[1],a[2]))%2) == 0) && massimoPari(a+1,l-1);

	return risultato;
}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp = fopen("interi.dat","rb");
	int l = 0;
	int app;
	if(fp==NULL)
		printf("il file non esiste\n");
	else
		while(fread(&app,sizeof(int),1,fp))
			l++;
	printf("nel file ci sono %d numeri\n\n",l);
	fclose(fp);
	return l;
}

/* funzione che legge ... */
void leggiNumeri(int* a, int l) {
	FILE* fp = fopen("interi.dat","rb");
	if(fp==NULL)
		printf("il file non esiste\n");
	else
		fread(a,sizeof(int),l,fp);
	printf("lettura da file eseguita\n\n");
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* a, int l) {
	FILE* fp = fopen("interi.dat","wb");

	if(fp==NULL)
		printf("impossibile aprire il file\n");
	else
		fwrite(a,sizeof(int),l,fp);

	fclose(fp);
	printf("salvato\n");
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
			printf("Esiste il massimo pari in ogni terzina \n");
		else
			printf("NON esiste il massimo pari in ogni terzina\n");

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
			printf(" Esiste il massimo pari in ogni terzina\n");
		else
			printf("NON esiste il massimo pari in ogni terzina\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}

