/*
5pt massimo pari:..5
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.7
2pt leggi numeri:..2
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
    int tutte;
    /*PASSO BASE*/
    if(lunghezza<3){
        tutte =1;
    }
    else{
        /*se uno Ã¨ massimo e pari, controllo con la ricorsione le altre triple*/
        tutte = (((seq[0]>seq[1])&&(seq[0]>seq[2])&&(seq[0]%2==0))
        ||((seq[1]>seq[0])&&(seq[1]>seq[2])&&(seq[1]%2==0))
        ||((seq[2]>seq[0])&&(seq[2]>seq[1])&&(seq[2]%2==0)))&&(massimoPari(seq+1,lunghezza-1));
    }
    return tutte;
}

/* funzione che conta quanti numeri ci sono nel file */
int quantiNumeri() {
    int n;
    int contatore;
    FILE *fp = fopen("interi.dat","rb");
    //**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
    while(fread(&n,sizeof(int),1,fp)>0){
        contatore++;
    }
    fclose(fp);
    return contatore;

}

/* funzione che legge un file */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE *fp = fopen("interi.dat","rb");
    if(fp==NULL)
        printf(("Impossibile aprire il file\n"));
    else{
        fread(sequenza,sizeof(int),lunghezza,fp);
    }
    fclose(fp);
}

/* funzione che scrive sul file la sequenza */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE *fp = fopen("interi.dat","wb");
    if(fp==NULL)
        printf(("Impossibile aprire il file\n"));
    else{
        fwrite(sequenza,sizeof(int),lunghezza,fp);
    }
//**** non chiudi il file -0.2
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
			printf(" Ogni tripla contiene un massimo intero pari \n");
		else
			printf(" Almeno una tripla non contiente un massimo intero pari \n");

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
			printf(" Ogni tripla contiene un massimo intero pari \n");
		else
			printf(" Almeno una tripla non contiente un massimo intero pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}