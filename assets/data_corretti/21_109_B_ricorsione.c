/*
5pt minimo dispari:..5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............10
*/
#include <stdio.h>
#include <stdlib.h>
/*funzione che restituisce il minimo in una tripla di interi*/
int minimoTripla(int a,int b, int c){
    int minimo; //il minimo fra tre interi

    minimo=a; //inizializza il minimo al primo intero
    if(b<minimo)
        minimo=b;
    if(c<minimo)
        minimo=c;

        return minimo;
}
/* funzione ricorsiva che verifica se ogni tripla di interi consecutivi nella sequenza è tale che il minimo
fra i tre interi è dispari */
int minimoDispari(int *seq, int lunghezza){

    int risultato; //risultato da restituire

    /*caso base*/
    if(lunghezza<3)
        risultato=1;

        /*passo ricorsivo*/
        else
            risultato= (minimoTripla(seq[0],seq[1],seq[2])%2!=0) && minimoDispari(seq+1,lunghezza-1);

            return risultato;
}

/* funzione che conta il numero di interi memorizzati su un file binario */
int quantiNumeri() {

    int quanti=0; //variabile di conteggio

    /*apri il file*/
    FILE*fp=fopen("interi.dat","rb");

    /*file non aperto*/
    if(fp==NULL)
        printf("File non esistente o apertura non riuscita!\n\n");
        /*file aperto*/
        else{
            int numero; //intero del file
            while(fread(&numero,sizeof(int),1,fp)>0)
                quanti++;

             /*chiudi il file*/
                fclose(fp);
        }
        return quanti;
}

/* funzione che legge una sequenza di interi da file binario */
void leggiNumeri(int* sequenza, int lunghezza) {

   /*apri il file*/
    FILE*fp=fopen("interi.dat","rb");

    /*file non aperto*/
    if(fp==NULL)
        printf("File non esistente o apertura non riuscita!\n\n");
        /*file aperto*/
        else{
            for(int i=0; i<lunghezza;i++)
                fread(&sequenza[i],sizeof(int),1,fp);

                /*chiudi il file*/
                fclose(fp);
        }
}

/* funzione che scrive una sequenza di interi su file binario */
void scriviNumeri(int* sequenza, int lunghezza) {

    /*apri il file*/
    FILE*fp=fopen("interi.dat","wb");

    /*file non aperto*/
    if(fp==NULL)
        printf("Salvataggio non riuscito!\n\n");
        /*file aperto*/
        else{
            fwrite(sequenza,sizeof(int),lunghezza,fp);
            /*chiudi il file*/
            fclose(fp);
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
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla di interi consecutivi %c tale che il minimo fra i tre interi %c dispari!\n",138,138);
		else
			printf("Non tutte le triple di interi consecutivi sono tali che il minimo fra i tre interi sia dispari!\n");

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
           printf("Ogni tripla di interi consecutivi %c tale che il minimo fra i tre interi %c dispari!\n",138,138);
		else
			printf("Non tutte le triple di interi consecutivi sono tali che il minimo fra i tre interi sia dispari!\n");
		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}