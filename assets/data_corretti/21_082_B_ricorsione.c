/*
5pt minimo dispari:..5   //**** scrive DISPARO invece di DISPARI
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/


#include <stdio.h>
/*programma che data una sequenza di interi verifica se tutte le triple consecutive
sono tali che il loro numero piupiccoolo è dispari*/

int minimoDispari(int array[],int l){
	int verificata; //variabile di verifica universale

	if(l<3)
	verificata=1;
	else{
		verificata=(((array[0]<array[1] && array[0]<array[2] && array[0]%2!=0)||
		(array[1]<array[0] && array [1]<array[2] && array[1]%2!=0)||
		(array[2]<array[0] && array[2]<array[1] && array[2]%2!=0)) &&(minimoDispari(array+1,l-1)));

	}

	return verificata;
}

//*****FILE******//

void scriviNumeri(int array[],int l){
	FILE* fp=fopen("MinimoDis.dat","wb");

	if(fp==NULL){
		printf("Apertura fallita!\n");
	}
	else{
		fwrite(array,sizeof(int),l,fp);
		printf("Salvataggio effettuato!\n");
		fclose(fp);

	}

}
//*lettura dela sequenza da file*//
void leggiNumeri(int array[],int l){
	FILE* fp=fopen("MinimoDis.dat","rb");

	if(fp==NULL)
		printf("File vuoto!\n");
		else{
			for(int i=0;i<l;i++){
				fread(& array[i],sizeof(int),1,fp);
			}
			fclose(fp);
		}
}

//*Funzione che calcola qunati interi sono nel file*//
int quantiNumeri(){
	FILE* fp=fopen("MinimoDis.dat","rb");
	int quanti=0;  //variabile per contare gli interi nel file

	if(fp==NULL)
	printf("Apertura fallita!\n");
	else{
		int letto; //elemento di tipo int generico per leggere i valori nel file
		while(fread(& letto,sizeof(int),1,fp)>0){
			quanti++;
		}
		fclose(fp);
	}
	return quanti;
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
			printf("Ogni tripla consecutiva ha come elemento minimo un numero disparo \n"); //***** DISPARI!
		else
			printf("Non tutte le triple hanno come elemento minimo un numero disparo \n"); //***** DISPARI!

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
		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla consecutiva ha come elemento minimo un numero disparo \n");
		else
			printf("Non tutte le triple hanno come elemento minimo un numero disparo \n");


		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}