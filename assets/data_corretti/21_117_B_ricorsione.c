/*
5pt minimo dispari:..3.5
1pt scrivi numeri:...0.7
2pt quanti numeri:...1.7
2pt leggi numeri:....1.7
TOTALE ..............7.6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* funzione ricorsiva che verifica se in ogni tripla di interi consecutivi il minimoo è dispari */
int minimoDispari(int *seq, int lunghezza){

	int risultato;
	int minimo = seq[0];  //**** sembra che il PB sia mischiato tra lungezza==2 e il calcolo del minimo tra 3 elementi
                          //**** lo schema ricorsivo è confuso
                          //**** la chiamata ricorsiva viene fatta se seq[2] non è minore di minimo!! -1.5
	if(lunghezza==2)
		risultato=1;

		if(seq[1] < minimo)
			minimo = seq[1];
		//verifico se il minimo della tripla e' il secondo elemento
		if(seq[2] < minimo)

			minimo = seq[2];

		else{
			minimo = (minimo % 2 != 0) && minimoDispari(seq + 1, lunghezza - 1);
		}
	return minimo;
	}


/* funzione che conta quanti interi sono memorizzati su un file*/
int quantiNumeri() {

	FILE *fp =  fopen("interi.dat","rb");
	int lunghezza = 0;
	int valore;
	if(fp != NULL)//se fp non e' null allora esiste il file desiderato
	//**** se fp==NULL  -0.3
		printf("Nessun file!\n");
	else{
		while(fread(&valore,sizeof(int),1,fp)>0){
			lunghezza++;//incremento la lunghezza
		}
	}
	fclose(fp); //salvo le azioni fatte sul file
	return lunghezza;//fornisco il risultato
}


/* funzione che legge una sequenza di interi da un file*/
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE *fp =  fopen("interi.dat","rb");//dichiaro un puntatore al file in modalità lettura
	if(fp != NULL) //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	{
		for(int i=0; i<lunghezza;i++)
		{
			fread(&sequenza[i],sizeof(int),1,fp);
		}
	}
	fclose(fp); //salvo le azioni fatte sul file
}

/* funzione che scrive i valori di un array di interi su un file*/
void scriviNumeri(int* sequenza, int lunghezza) {

	FILE *fp =  fopen("interi.dat","wb");//dichiaro un puntatore al file in modalità scrittura
	if(fp != NULL)//se fp non e' null allora esiste il file desiderato
	{//**** devi segnalare con una stampa in output se l'apertura del file è fallita if(fp==NULL) -0.3
		for(int i=0; i<lunghezza;i++)
		{
			fwrite(&sequenza[i],sizeof(int),1,fp);//leggo il dato attuale
		}
	}
	fclose(fp); //salvo le azioni fatte sul file
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
			printf("In ogni tripla consecutiva di interi il minimo fra i tre e' dispari\n");
		else
			printf("Non e' verificato che in ogni tripla di interi il minimo fra i tre e' dispari\n");

		/* salva la sequenza su file*/
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file
	else {
		/* determina la lunghezza della sequenza*/
		lunghezza = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file*/
		int array[lunghezza];
		//leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato*/
		if(minimoDispari(array,lunghezza))
			printf("In ogni tripla consecutiva di interi il minimo fra i tre e' dispari\n");
		else
			printf("Non e' verificato che in ogni tripla di interi il minimo fra i tre e' dispari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}


