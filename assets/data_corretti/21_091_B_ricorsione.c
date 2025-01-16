/*
5pt minimo dispari:..2
1pt scrivi numeri:...0.7
2pt quanti numeri:...0.6
2pt leggi numeri:....1.2
TOTALE ..............4.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int r;
	if(lunghezza<3)
		r=0;
	else
		r=(((seq[0]<seq[1] || seq[0]<seq[2]) && seq[0]%2!=0) ||
					//**** &&
		((seq[1]<seq[0] || seq[1]<seq[2]) && seq[1]%2!=0)) ||
					//**** &&
		((seq[2]<seq[1] || seq[2]<seq[0])&&seq[2]%2!=0) ||  //**** errori nella verifica della proprietà -1
					//**** &&                    //**** &&
		minimoDispari(*seq+1, lunghezza-1); //**** fai una verifica esistenziale invece che universale -2
	return r;
}

/* funzione che conta ... */
int quantiNumeri() {
	int n;   //**** il contatore non è inizializzato -0.5
	FILE *fp=fopen("interi.dat","rd"); //**** opzione "d" mai vista! -0.5
	if(fp==NULL)
		printf("\nFile vuoto\n");
	while(fread(&fp,sizeof(int),1,fp)!=EOF)//**** fread torna un intero -0.4
		n++;
	fclose(fp);
	return n;

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE *fp=fopen("interi.dat","rd");//**** opzione "d" mai vista! -0.5
	if(fp==NULL)
		printf("\nFile vuoto\n");
    while(fp!=EOF){
		for(int i=1;i<lunghezza;i++)//**** salti la prima componente dell'array -0.3
		fread(&sequenza[i],sizeof(int),i,fp);
	}
	fclose(fp);

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {

	FILE *fp=fopen("interi.dat","wb");
	if(fp==NULL)
		printf("\nFile vuoto\n");
	for(int i=1; i<lunghezza; i++){//**** salti la prima componente dell'array -0.3
		fwrite(&sequenza[i],sizeof(int),1,fp);
	}
	fclose(fp);
	printf("Valori array salvati nel file!");
}

/* funzione principale */
int main(int argc, char **argv) {
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
		for(int i=1;i<lunghezza;i++)
			scanf("%d ",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla di interi ha un valore minimo ed e' dispari!\n");
		else
			printf("Ogni tripla di interi ha un valore minimo ma non e' dispari!\n");

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
		for(int i=1;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla di interi ha un valore minimo ed e' dispari!\n");
		else
			printf("Ogni tripla di interi ha un valore minimo ma non e' dispari!\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}