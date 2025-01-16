/*
5pt minimo dispari:..3.5
1pt scrivi numeri:...0.8
2pt quanti numeri:...1.8
2pt leggi numeri:....1.8
TOTALE ..............7.9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in un array di numeri interi ogni tripla di interi consegutivi nella
sequenza è tale che il minimo fra i tre interi è dispari */
int minimoSeq(int n1, int n2, int n3){
	int valoreMin;
	if(n1<n2 && n1<n3)
		valoreMin = n1;
	else if(n2<n1 && n2 < n3)
		valoreMin = n2;
	else
		valoreMin = n3;

	return valoreMin;
}

int minimoDispari(int *seq, int lunghezza){
	int risultato;
	int i = 0;
	if(lunghezza == 3){
//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
		if(minimoSeq(seq[0],seq[1],seq[2])%2 != 0)
			risultato = 1;
		else
			risultato = 0;
	}
	else{
		risultato =  minimoSeq(seq[i],seq[i+1],seq[i+2]) && minimoDispari(seq+1, lunghezza-1);
		i++; //**** che senso ha incrementare la variabile i se ad ogni attivazione
	}        //**** 1) viene inizializzata a 0, 2) non viene comunque passta come paramtero -0.5

	return risultato;
}

/* funzione che conta quanti interi sono memorizzati nel file */
int quantiNumeri() {
	FILE* fp = fopen("interi.txt", "r");
	int cont = 0;
	int numero;
	if(fp != NULL){
		while(fscanf(fp,"%d",&numero) != EOF)
			cont++;
	}
	else
		printf("Lettura non riuscita!\n");

	return cont;//**** non chiudi il file -0.2
}

/* funzione che legge una sequenza di interi da un file */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt", "r");

	if(fp != NULL){
		for(int i = 0; i<lunghezza;i++)
			fscanf(fp, "%d", &sequenza[i]);
	}
	else
		printf("Lettura non riuscita!\n");
}//**** non chiudi il file -0.2

/* funzione che scrive una sequenza di interi su un file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.txt", "w");
	if(fp != NULL){
		for(int i = 0; i < lunghezza; i++)
			fprintf(fp, "%d ", sequenza[i]);

	}
	else
		printf("Apertura non riuscita!\n");
}//**** non chiudi il file -0.2

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
		do{
			printf("Introduci la lunghezza della sequenza: ");
			scanf("%d",&lunghezza);
			if(lunghezza <= 2)
				printf("Si parla di triple quindi la lunghezza deve essere almeno di 3!\n");
		}while(lunghezza <= 2);


		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla di interi consegutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari \n");
		else
			printf(" NON tutte le triple di interi consegutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari \n \n");

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
			printf("Ogni tripla di interi consegutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari \n");
		else
			printf(" NON tutte le triple di interi consegutivi nella sequenza e' tale che il minimo fra i tre interi e' dispari \n \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}