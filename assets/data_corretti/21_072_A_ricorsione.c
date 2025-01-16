/*
5pt massimo pari:..3.7
1pt scrivi numeri:.1
2pt quanti numeri:.1.8
2pt leggi numeri:..1.8
TOTALE ............8.3
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica che per ogni tripla in un array di interi il massimo fra i tre interi Ã¨ pari */
int massimoPari(int *seq, int lunghezza){
	int boole=0; //inizializzo la variabile booleana
	if(lunghezza==3){
		boole=(seq[0]>seq[1] && seq[0]>seq[2] && seq[0]%2==0)
		|| (seq[1]>seq[2] && seq[1]>seq[0] && seq[1]%2==0)
		|| (seq[2]>seq[1] && seq[2]>seq[0] && seq[2]%2==0);
	}
	//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

	//**** lunghezza==3 fa parte del passo ricorsivo.
	//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3

	else{
		if(((seq[0]>seq[1] && seq[0]>seq[2] && seq[0]%2==0)
		|| (seq[1]>seq[2] && seq[1]>seq[0] && seq[1]%2==0)
		|| (seq[2]>seq[1] && seq[2]>seq[0] && seq[2]%2==0)) && massimoPari(seq+1,lunghezza-1)){
			boole=1;
		}
	}
	return boole; //restituisco la variabile booleana
}

/* funzione che conta quanti interi sono salvati nel file */
int quantiNumeri() {
	FILE *fp = fopen("interi.dat","rb"); //apro il file in lettura
	int contaNumeri=0;
	if(fp==NULL){ //verifico l'esistenza del file
		printf("File non esistente!\n");
	}
	else{
		int numero;
		while(fread(&numero,sizeof(int),1,fp)>0){
			contaNumeri++; //conto quanti numeri sono salvati nel file
		}
	}
	return contaNumeri; //**** non chiudi il file -0.2
}

/* funzione che legge gli interi salvati nel file e li salva all'interno di un array */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat","rb"); //apro il file in lettura
	if(fp==NULL){
		printf("File non esistente!\n");
	}
	else{
		int numero;
		int i=0;
		while(fread(&numero,sizeof(int),1,fp)>0){
			sequenza[i]=numero; //salvo i file dentro un array
			i++;
		}
	}//**** non chiudi il file -0.2
}

/* funzione che scrive i numero di un array all'interno di un file binario */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat","wb"); //apro il file in scrittura
	if(fp==NULL){
		printf("File non creato correttamente!\n"); //verifico la creazione del file
	}
	else{
		for(int i=0;i<lunghezza;i++){
			fwrite(&sequenza[i],sizeof(int),1,fp); //scrivo i numeri all'interno del file
		}
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
			printf("Verificato!\n");
		else
			printf("Non verificato!\n");

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
			printf(" Verificato! \n");
		else
			printf(" Non verificato! \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}