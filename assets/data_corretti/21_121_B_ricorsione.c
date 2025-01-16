/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...1.5
2pt leggi numeri:....2
TOTALE ..............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */

int minimoDispari(int *seq, int l){      //l=lunghezza ,l>=3
    int verificato;
    /*CASO BASE*/
    if(l<3)
        verificato=1;
    else
      //passo ricorsivo
        verificato=((((seq[l-2]<seq[l-1])&&(seq[l-2]<seq[l-3]))&&(seq[l-2]%2!=0))||
                   (((seq[l-1]<seq[l-2])&&(seq[l-1]<seq[l-3]))&&(seq[l-1]%2!=0))||
                   (((seq[l-3]<seq[l-2])&&(seq[l-3]<seq[l-1]))&&(seq[l-3]%2!=0)))&& minimoDispari(seq,l-1);

        return verificato;
}

/* funzione che conta ... */
int quantiNumeri() {
    int quanti; //**** il contatore non è inizializzato -0.5
    FILE*fp=fopen("interi.txt","r");
    if(fp==NULL)
        printf("apertura file non riuscita!\n");
    else{
        int numero;
        while(fscanf(fp,"%d ",&numero)!=EOF)
            quanti++;
            fclose(fp);

    }
    return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
      FILE*fp=fopen("interi.txt","r");
    if(fp==NULL)
        printf("apertura file non riuscita!\n");
    else{
        for(int i=0;i<lunghezza;i++)
            fscanf(fp,"%d ",&sequenza[i]);
            fclose(fp);
}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
      FILE*fp=fopen("interi.txt","w");
    if(fp==NULL)
        printf("apertura file non riuscita!\n");
    else{
        for(int i=0;i<lunghezza;i++)
            fprintf(fp,"%d ",sequenza[i]);
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
			printf(" ogni sequenza di tre interi e' tale che il minimo e' dispari \n");
		else
			printf(" non ogni sequenza di tre interi e' tale che il minimo e' dispari \n");

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
			printf("ogni sequenza di tre interi e' tale che il minimo e' dispari\n");
		else
			printf(" non ogni sequenza di tre interi e' tale che il minimo e' dispari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}