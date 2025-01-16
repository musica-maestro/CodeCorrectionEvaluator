/*
5pt minimo dispari:..4.5
1pt scrivi numeri:...0.6
2pt quanti numeri:...1.8
2pt leggi numeri:....1.3
TOTALE ..............8.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in un array di tutti interi ogni tripla e' tale che il minimo della tripla sia dispari*/
int minimoDispari(int *seq, int lunghezza){
	int ris;
	ris=minimoDispariRic(seq, lunghezza, 0);
	//**** minimoiDispariRic ancora non è stata dichiarata, devi dichiarare la sua segnatura all'inizio -0.3
	return ris;
}

//funzione ricorsiva ausiliaria di minimoDDispari
int minimoDispariRic(int vet[], int l, int i){//i=indice che parte da zero
int ris=1; //risultato
//contrario del caso base
if(i<l-2 ) {
								printf("\n\n file!\n\n");  //**** che vuol dire? -0.2

if(((vet[i]<vet[i+1])&&(vet[i]<vet[i+2]) &&(vet[i]%2!=0))
|| ((vet[i+1]<vet[i])&&(vet[i+1]<vet[i+2]) &&(vet[i+1]%2!=0))
|| ((vet[i+2]<vet[i])&&(vet[i+2]<vet[i+1]) &&(vet[i+2]%2!=0))) {
	//passo ricorsivo

	ris=minimoDispariRic(vet, l, i+1);

	} else {
ris=0;
}
return ris;
} }


/* funzione che conta ... */
int quantiNumeri() {
	int c=0; //variabile che conta quanti interi salvati
	int ap; //variabile di appoggio per la scrittura da file
			FILE* fp= fopen("interi.dat", "rb");
			if(fp==NULL){
						printf("Errore apertura file!\n\n");
			} else{
			while (fread(ap, sizeof(int), 1, fp)>0) {
				//**** &ap
						c=c+1;
			}
	//**** non chiudi il file -0.2

}
return c;//ritorno quantita' di interi nel file
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {


			FILE* fp= fopen("interi.dat", "rb");
			if(fp==NULL){
						printf("Errore apertura file!\n\n");
			}
			else{
			while (fread(lunghezza, sizeof(int), lunghezza, fp)>0) {
			      //**** sequenza -0.5
			}
			printf("Acquisizione dati copmpletata!\n\n");

	       //**** non chiudi il file -0.2
} }

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	if(lunghezza<=0)
		printf("per favore prima deve inserire degli elementi!\n\n");
		else{
			FILE* fp= fopen("interi.dat", "wb");
			if(fp==NULL){
						printf("Errore apertura / creazione file!\n\n");
			} else{
				fwrite(sequenza, sizeof(int), lunghezza, stdin); //**** fp!!!! -0.4
						printf("Scrittura dati completata!\n\n");
			}
			fclose(fp);
			}

}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente
    printf("Ciao! sono un programma che   verifica se in un array di tutti interi ogni tripla e' tale che il minimo della tripla sia dispari");

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
			printf("Utente la sequenza rispetta le caratteristiche richieste arrivderci\n");
		else
			printf(" Utente la sequenza NON rispetta le caratteristiche richieste arrivderci\n");

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
			printf(" Utente la sequenza rispetta le caratteristiche richieste arrivderci \n");
		else
			printf(" Utente la sequenza NON rispetta le caratteristiche richieste arrivderci \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}