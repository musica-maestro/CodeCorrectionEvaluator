/*
5pt massimo pari:..3.8
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............8.8
*/
#include <stdio.h>
#include <stdlib.h>

//funzione che trova il massimo tra 3 elementi
int trovaMassimo(int uno,int due, int tre){
	int massimo;
	if(uno>due && uno>tre)
			massimo=uno;
		else if(due>uno && due>tre)
			massimo=due;
		else if(tre>uno && tre>due)
			massimo=tre;
	return massimo;
}
/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
	int massimo; //creo una variabile per allocare il massimo di 3 elementi adiacenti
//**** lunghezza==3 fa parte del passo ricorsivo.
//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.2
//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	if(lunghezza==3){ //passo base
		//trovo il massimo tra i 3
		massimo = trovaMassimo(seq[0],seq[1],seq[2]);
			//se il massimo è pari torna 1, se no 0
		return (massimo%2==0);
	}
	else{
		//passo ricorsivo
		massimo = trovaMassimo(seq[0],seq[1],seq[2]);
		return (massimo%2==0) && massimoPari(seq+1,lunghezza-1);
	}
}

/* funzione che conta ... */
int quantiNumeri() {
	//apriamo il file
	FILE* fp = fopen("interi.dat","rb");
	int contatore=0; //variabile contatore inizializzata

	//se il puntatore fp è NULL non possiamo aprire il file
	if(fp==NULL)
		printf("Impossibile aprire il file\n\n");

	else{
		int appoggio; //creo una variabile di appoggio

		//finchè leggo un elemento aumento il mio contatore
		while(fread(&appoggio,sizeof(int),1,fp)>0){
			contatore++;
		}
	}

	fclose(fp); //chiudo il file
	return contatore;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	//apro il file
	FILE* fp = fopen("interi.dat","rb");
	if(fp==NULL)
		printf("Impossibile aprire il file\n\n");
	else
		fread(sequenza,sizeof(int),lunghezza,fp); //leggo la sequenza dal file
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp = fopen("interi.dat","wb"); //apro il file
	if(fp==NULL)
		printf("Impossibile aprire il file\n\n");
	else{
		fwrite(sequenza,sizeof(int),lunghezza,fp); //scrivo la sequenza
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
		if(massimoPari(array,lunghezza))
			printf(" Ogni tripla di interi consecutivi ha massimo pari! \n");
		else
			printf(" Non tutte le triple di interi consecutivi hanno massimo pari. \n");

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
			printf(" Ogni tripla di interi consecutivi ha massimo pari! \n");
		else
			printf(" Non tutte le triple di interi consecutivi hanno massimo pari. \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}