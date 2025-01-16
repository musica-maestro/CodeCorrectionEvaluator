/*
5pt minimo dispari:..3.7
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............8.7
*/
#include <stdio.h>
#include <stdlib.h>
int verificaProprieta(int a, int b, int c){
	int min;
	if((a<=b) && (a<=c))
		min=a;
	else if((b<=a) && (b<=c))
		min=b;
	else if((c<=a) && (c<=b))
		min=c;
	printf("\n**%d***\n",min);
	return (min%2==1);
}
/* funzione ricorsiva che verifica ... */
int minimoDispariRic(int *seq, int lunghezza,int i){
	int verifica;
	/*CASO BASE*/
	if(i>=lunghezza-3)//**** PB sbagliato: <=2 (perché devi considerare una terna di elementi) -0.5
//**** se i>lunghezza-3 non puoi accedere a 3 componenti! -0.5
//**** se i==lunghezza- questo fa parte del passo ricorsivo, a meno di non ripeter il controllo esplicitamente -0.3
		verifica= verificaProprieta(seq[i],seq[i+1],seq[i+2]);
	/*PASSO RICORSIVO*/
	else{
		verifica= verificaProprieta(seq[i],seq[i+1],seq[i+2]) && minimoDispariRic(seq,lunghezza,i+1);
	}
	return verifica;
}
int minimoDispari(int*seq,int l){
	return minimoDispariRic(seq,l,0);
}
/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0;
	FILE*fp=fopen("minimoDispari.txt","r");
	if(fp==NULL)
		printf("Apertura file non riuscita!\n");
	else{
		int numero;
		while(fscanf(fp,"%d",&numero)!=EOF)
			quanti++;
		fclose(fp);
	}
	return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE*fp=fopen("minimoDispari.txt","r");
	if(fp==NULL)
		printf("Apertura file non riuscita!\n");
	else{
		for(int i=0;i<lunghezza;i++)
			fscanf(fp,"%d",&sequenza[i]);
		printf("Acquisizione sequenza dal file riuscita!\n");
		fclose(fp);
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE*fp=fopen("minimoDispari.txt","w");
	if(fp==NULL)
		printf("Apertura file non riuscita!\n");
	else{
		for(int i=0; i<lunghezza; i++){
			fprintf(fp,"%d ",sequenza[i]);
		}
		printf("Salvataggio riuscito!\n");
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
			printf("Ogni tripla di interi consecutivi a come minimo un intero dispari.\n");
		else
			printf("NON ogni tripla di interi consecutivi a come minimo un intero dispari\n");

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
			printf("Ogni tripla di interi consecutivi a come minimo un intero dispari.\n");
		else
			printf("NON ogni tripla di interi consecutivi a come minimo un intero dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}