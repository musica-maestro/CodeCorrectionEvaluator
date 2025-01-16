/*
5pt massimo pari:..3.7
1pt scrivi numeri:.1
2pt quanti numeri:.0.5
2pt leggi numeri:..2
TOTALE ............7.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se in una sequenza di interi il massimo di tutte le triple e' pari*/
int massimoPari(int *seq, int lunghezza){
	int max;                //valore massimo
	int risultato;             //variabile di ritorno
	if(lunghezza==3){
	//**** Passo base se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	//**** lunghezza==3 fa parte del passo ricorsivo. Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3
		if(seq[lunghezza-1]>=seq[lunghezza-2] && seq[lunghezza-1]>=seq[lunghezza-3])   //se l'ultimo elemento e' il maggiore
			max=seq[lunghezza-1];                                                       // massimo uguale ultimo elemento
		else{
			if(seq[lunghezza-2]>=seq[lunghezza-1] && seq[lunghezza-2]>=seq[lunghezza-3])
				max=seq[lunghezza-2];                                      //altrimenti massimo uguale al penultimo
			else
				max=seq[lunghezza-3];                   // altrimenti massimo uguale al terzultimo
		}
		if(max%2==0)                 //e' pari?
			risultato=1;
		else
			risultato=0;
	}
	else{
		if(seq[lunghezza-1]>=seq[lunghezza-2] && seq[lunghezza-1]>=seq[lunghezza-3])
			max=seq[lunghezza-1];
		else{
			if(seq[lunghezza-2]>=seq[lunghezza-1] && seq[lunghezza-2]>=seq[lunghezza-3])
				max=seq[lunghezza-2];
			else
				max=seq[lunghezza-3];
		}
		risultato=(max%2==0) && massimoPari(seq,lunghezza-1);    //ricorsione con lunghezza -1
	}
	return risultato;
}

/* funzione che conta la lunghezza della sequenza */
int quantiNumeri() {
	int conta;                                         //variabile contatore
//**** il contatore non è inizializzato -0.5
	FILE* fp=fopen("massiomoPari.dat","rb");
	if(fp==NULL)
		printf("File vuoto\n");
	else{
//**** while(fp!=NULL): così hai un loop infinito! -1
		while(fp!=NULL){                          //vai avanti fino alla fine file
			conta++;                        //incrementa il contatore
		}
		fclose(fp);
	}
	return conta;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("massiomoPari.dat","rb");
	if(fp==NULL)
		printf("File vuoto\n");
	else{
		int intero;
		fread(&intero,sizeof(int),lunghezza,fp);
		fclose(fp);
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("massiomoPari.dat","wb");   //creo il file
	if(fp==NULL)                               //se e' vuoto scrive che non c'e' nulla da salvare
		printf("Nulla da salvare\n");
	else{                                     //altrimenti
		fwrite(&sequenza,sizeof(int),lunghezza,fp);         //scrivi sul file
		printf("Salvato\n");
		fclose(fp);                        //chiudi il file
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
		if(massimoPari(array,lunghezza))
			printf(" Condizione confermata \n");
		else
			printf(" Condizione non confermata \n");

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
			printf(" Condizione confermata \n");
		else
			printf(" Condizione non confermata \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}