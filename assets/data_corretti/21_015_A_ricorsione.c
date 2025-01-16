/*
5pt massimo pari:..2
1pt scrivi numeri:.1
2pt quanti numeri:.1
2pt leggi numeri:..1.2
TOTALE ............5.2
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
    int verifica=1;
    int i=0;
    int max;
    if((verifica==1)&&(i<lunghezza-2))
     massimoPariric(seq, lunghezza, i+1); //**** i, non i+1 -0.3
    else
        verifica=0;
        return verifica;
    }


int massimoPariric(int *seq, int lunghezza, int i){ //**** non e' una fuzione ricorsiva
    int verifica;                                   //**** verifichi solo la proprietà (il max della terna deve essere pari)
    int max;                                        //**** -2.5
       if((seq[i]>seq[i+1])&&seq[i]>seq[i+2])
    {
        max=seq[i];
        if ((max%2)==0)
            verifica=1;
    }
    else  if((seq[i]<seq[i+1])&&seq[i+1]>seq[i+2])
    {
        max=seq[i+1];
        if ((max%2)==0)
            verifica=1;
    }
     else if((seq[i]<seq[i+1])&&seq[i+1]<seq[i+2]) //**** seq[i]<seq[i+2] -0.2
    {
        max=seq[i+2];
        if ((max%2)==0)
            verifica=1;
    }
    return verifica;
}

/* funzione che conta ... */
int quantiNumeri()
{
    int letto;
    int valori=0;
    FILE  *fp=fopen("interi.dat", "wb");
    if(fp==NULL)
        printf("errore nell'apertura del file\n");
     else
    {     //**** manca il ciclo per la lettura! -1
           letto=fread(&letto, sizeof(int), 1, fp);
           if(letto);
           valori=valori+1;
           return valori;
    }
    printf("Ci sono %d Valori nel file", valori);
    fclose(fp);
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
    int valore;
    FILE  *fp=fopen("interi.dat", "rb");
    if(fp==NULL)
        printf("errore nell'apertura del file\n");
     else
    {
        for(int i=0;i<lunghezza;i++)
                     //**** &valore -0.3
           sequenza[i]=fread(valore, sizeof(int), 1, fp);
    } //**** la fread ritorna il numero di elementi letti, non il valore acquisito -0.5
    fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE  *fp=fopen("interi.dat", "wb");
    if(fp==NULL)
        printf("errore nell'apertura del file\n");
    else
       for(int i=0; i<lunghezza-1; i++){
           int valore=sequenza[i];
        fwrite(&valore, sizeof(int), 1, fp);
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
			printf(" Il massimo di ogni tripla ha valore pari\n");
		else
			printf("Il massimo di ogni tripla non ha valore pari\n");

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
            printf(" Il massimo di ogni tripla ha valore pari\n");
		else
			printf("Il massimo di ogni tripla non ha valore pari\n");


		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}