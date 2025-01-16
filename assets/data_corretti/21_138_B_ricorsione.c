/*
5pt minimo dispari:..3.5
1pt scrivi numeri:...0.5
2pt quanti numeri:...1.2
2pt leggi numeri:....1.5
TOTALE ..............6.7
*/

#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int seq[], int lunghezza){
	int min;
	int risultato;
	if (lunghezza==2){ //****  se lunghezza=1, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -0.8
		return risultato ;}//**** devi assegnare un valore al risultato -0.7
	else{
		if (seq[0]<seq[1] && seq[0]<seq[2]){
		min=seq[0];}
		else if (seq[1]<seq[0] && seq[1]<seq[2]){
		min=seq[1];}
		else if (seq[2]<seq[0] && seq[2]<seq[1]){
		min=seq[2];}
		risultato=min%2!=0 && minimoDispari(seq+1,lunghezza-1);
	}

}

/* funzione che conta ... */
int quantiNumeri() {
	FILE* fp=fopen("interi.txt","r");
	//**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL) -0.5
	int c=0;
	int x;
	while(fscanf(fp,"%d",&x)==1){ //**** while(fscanf(fp,"%d",&x)==1) -0.3 cioè, finché leggo un valore dal file...
		c++;
	}
	fclose(fp);
	return c;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.txt","r");
    //**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL) -0.5
	for (int i =0;i<lunghezza;i++){
		fscanf(fp,"%d",&sequenza[i]);
	}fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int sequenza[], int lunghezza) {
	FILE* fp=fopen("interi.txt","w");
	//**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL) -0.5
		for ( int i =0; i<lunghezza;i++){
			fprintf(fp,"%d ",sequenza[i]);
		}
		fclose(fp);}

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
		if(minimoDispari(array,lunghezza)==1)

			printf("Si in ogni tripla , il minimo e' dispari \n");
		else
			printf("No in ogni tripla , il minimo non e' dispari \n");

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
		if(minimoDispari(array,lunghezza)==1)

			printf("Si in ogni tripla , il minimo e' dispari \n");
		else
			printf("No in ogni tripla , il minimo non e' dispari \n");
		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}