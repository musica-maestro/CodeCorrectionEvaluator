/*
5pt massimo pari:..5
1pt scrivi numeri:.0.7
2pt quanti numeri:.2
2pt leggi numeri:..1.8
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/*FUNZIONE CHE RESTITUISCE IL MASSIMO TRA TRE INTERI*/
int massimo(int a,int b,int c){
    int massimo=a;
    if(b>a){
        if(c>b){
            massimo=c;
        }
        else{
            massimo=b;
        }
    }
    else if(c>a){
        if(b>c){
            massimo=b;
        }
        else{
            massimo=c;
        }
    }
    else{
        massimo=a;
    }
    return massimo;
}

/* funzione ricorsiva che verifica ... */
int massimoPari(int *seq, int lunghezza){
    int verificato;
    /*CASO BASE*/
    if(lunghezza<3){  //se la lungheza dell'array è minore di 3 la condizione non è mai verificata
        verificato=0;
    }
    else if(lunghezza==3){  //se la lunghezza è uguale a 3, la codizione è verificata solo se il massimo tra i 3 è pari
        if(massimo(seq[0],seq[1],seq[2])%2==0){
            verificato=1;
        }
        else{
            verificato=0;
        }
    }
    /*PASSO INDUTTIVO*/
    else{
        verificato=massimo(seq[lunghezza-3],seq[lunghezza-2],seq[lunghezza-1])%2==0 && massimoPari(seq,lunghezza-1);  //verifico ogni tripla di interi fino ad arrivare alla lunghezza pari a 3
    }
    return verificato;
}

/* funzione che conta ... */
int quantiNumeri() {
    int conta=0;
    int intero;
    FILE *fp=fopen("interi.dat","rb");  //apro il file(binario) in lettura
    if(fp!=NULL){
        while(fread(&intero,sizeof(int),1,fp)>0){ //finchè leggo variabili di tipo int incremento la variabile conta
            conta++;
        }
    }
    else{  //se non leggo nessun intero
        printf("Non ci sono numeri interi all'interno del file");
    }
    fclose(fp);  //chiudo il file
    return conta;  //numero di interi contati
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("interi.dat","rb");
    if(fp!=NULL){
        while(lunghezza>=1){
        fread(&(sequenza[lunghezza-1]),sizeof(int),1,fp);
        lunghezza=lunghezza-1;
        }
    }
    else{
        printf("FILE VUOTO O IMPOSSIBILE APRIRE FILE");
    }//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("interi.dat","wb");
    while(lunghezza>=1){
        fwrite(&(sequenza[lunghezza-1]),sizeof(int),1,fp);
        lunghezza=lunghezza-1;
    }
    fclose (fp);
//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
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
			printf(" Tutte le triple di interi presenti nell'array hanno il valore massimo pari \n");
		else
			printf(" Non tutte le triple di interi presenti nell'array hanno il valore massimo pari \n");

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
			printf(" Tutte le triple di interi presenti nell'array hanno il valore massimo pari \n");
		else
			printf(" Non tutte le triple di interi presenti nell'array hanno il valore massimo pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}