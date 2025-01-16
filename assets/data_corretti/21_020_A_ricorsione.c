/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..0
TOTALE ............8
*/
#include <stdio.h>
#include <stdlib.h>

/* INPUT: una sequenza e la sua lunghezza
 * PRE-CONDIZIONE: la sequenza è di interi
   OUTPUT: un intero risultato
   POST-CONDIZIONE: risultato vale 1 se nella sequenza inserita ogni tripla di interi consecutivi è tale
    che il massimo fra i tre interi è pari
   TIPO DI PROBLEMA: Verifica universale  */
/******************************/
//RICORSIONE
/*funzione massimo*/
int massimo(int interi[], int l){
	int max=interi[0];
	for(int i=1; i<l; i++){
		if(interi[i]>max)
			max=interi[i];
	}

	return max;
}

/*funzione pari*/
int pari(int a){
	return (a%2==0);
}

/* funzione ricorsiva che verifica ... */
int massimoPari(int interi[], int l){
	int risultato; //booleano

	/*caso base*/
	if(l<3)
		risultato=1;
	/*passo ricorsivo*/
	else
		risultato=pari(massimo(interi, 3)) && massimoPari(interi+1, l-1);

	return risultato;
}

/************************************/
//GESTIONE DEI FILE

//void leggiNumeri(int *sequenza, int lunghezza)

/* funzione che conta ... */
int quantiNumeri(){
	int numero; //intero d'appoggio
	int quanti=0;

	FILE *fp=fopen("LeggiInteri.txt","r");
	if(fp!=NULL){
		while(fscanf(fp,"%d", &numero)>0)
			quanti++;
	}
	//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	fclose(fp);
	return quanti;
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int l) {

	FILE *fp=fopen("LeggiInteri.txt", "w");
	if(fp!=NULL){
		for(int i=0; i<l; i++){
			fprintf(fp,"%d ", *(&sequenza[i]));//**** cioé sequenza[i]
		}
	}
	else
		printf("scrittura non possibile...\n\n");
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
			printf("Si, la sequenza inserita ha tutte le triple in cui l'elemento massimo e' pari\n\n");
		else
			printf("No, la sequenza inserita non ha tutte le triple in cui l'elemento massimo e' pari\n\n");

		/* salva la sequenza su file */
			scriviNumeri(array, lunghezza);
	}
/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();
		printf("lunghezza e' pari a %d\n", lunghezza);
		/* crea l'array e leggine i valori degli elementi da file */

	}
}