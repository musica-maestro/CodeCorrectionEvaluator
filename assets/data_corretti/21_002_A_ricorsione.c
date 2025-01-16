/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *a, int l){
    //pre:una sequenza di interi di l>=3
    int vero;  //valore booleano di verifica
    /*caso base*/
    if(l<=2)
        vero=1;
    /*passo ricorsivo*/
    else
        vero=((a[0]>a[1]&&a[0]>a[2]&&a[0]%2==0)
        	||(a[1]>a[0]&&a[1]>a[2]&&a[1]%2==0)
        	||(a[2]>a[0]&&a[2]>a[1]&&a[2]%2==0))&&massimoPari(a+1,l-1);

    return vero;
}

/* funzione che conta ... */
int quantiNumeri() {
    FILE *fp=fopen("interi.dat","rb");  //apertura file binario
    int numero;  //variabile per lettura
    int quanti=0;  //variabile per conteggio
    if(fp==NULL)  //controllo se il file esiste
        printf("impossibile accedere al file\n");
    else{
        while(fread(&numero,sizeof(int),1,fp)>0)  //fin quando c'è qualcosa da leggere
            quanti++;  //incrementa variabile conteggio
    }
    fclose(fp);  //chiususra file
    return quanti;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("interi.dat","rb");  //apertura file binario
    if(fp==NULL)  //controllo se il file esiste
        printf("Impossibile accedere al file\n");
    else
        fread(sequenza,sizeof(int),lunghezza,fp);  //lettura su file
    fclose(fp);  //chiususra file
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("interi.dat","wb");  //apertura file binario
    if(fp==NULL)  //controllo se il file esiste
        printf("Impossibile accedere al file\n");
    else
        fwrite(sequenza,sizeof(int),lunghezza,fp);  //scrivi sul file
    fclose(fp);  //chiusura file
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
			printf("Ogni massimo della tripla e' pari\n");
		else
			printf("Ogni massimo della tripla non e' pari\n");

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
			printf("Ogni massimo della tripla e' pari\n");
		else
			printf("Ogni massimo della tripla non e' pari\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}

