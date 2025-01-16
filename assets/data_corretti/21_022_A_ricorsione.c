/*
5pt massimo pari:..3.7
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.8
2pt leggi numeri:..1.8
TOTALE ............8.1
*/
#include <stdio.h>
#include <stdlib.h>

/*funzione che calcola il massimo fra 3 elementi*/
int max(int n1, int n2, int n3){
    int max;

    if(n1>n2 && n1>n3)//se il primo numero è maggiore degli altri è il massimo
        max=n1;
    else if(n2>n1 && n2>n3)//se il secondo numero è maggiore degli altri è il massimo
        max=n2;
    else if(n3>n1 && n3>n2)//se il terzo numero è maggiore degli altri è il massimo
        max=n3;
    return max;
}
/* funzione ricorsiva che verifica se in ogni tripla l'elemento massimo è pari */
int massimoPari(int *seq, int lunghezza){
    int res;
    //passo base
    //**** lunghezza==3 fa parte del passo ricorsivo.
	//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3
    if(lunghezza==3)
        res=(max(seq[0],seq[1],seq[2])%2==0);//invoco la funzione per calcolare il masssimo tra 3 elementi e vedo se è pari

     //**** Passo base se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

    else//invoco la funzione sulla terna attuale e vedo tramite il pass riscorsivo se la proprietà vale per tutte le terne
        res= (max(seq[0],seq[1],seq[2])%2==0 )&& massimoPari(seq+1,lunghezza-1);//paso ricorsivo
    return res;
}

/* funzione che conta quanti numeri ci sono nel file */
int quantiNumeri() {
    FILE *fp=fopen("interi.dat", "rb");
    int n;
    int quanti =0;

    if(fp==NULL)
        printf("Impossibile aprire o creare il file \n");
    else{
        while(fread(&n,sizeof(int),1,fp)>0)
            quanti++;
    }

//**** non chiudi il file -0.2
    return quanti;
}

/* funzione che legge i numeri da file e li scrive sull'array */
void leggiNumeri(int* sequenza, int lunghezza) {
    FILE *fp=fopen("interi.dat","rb");
    if(fp==NULL)
        printf("Impossibile aprire il file \n");
    else
        fread(sequenza,sizeof(int),lunghezza,fp);
//**** non chiudi il file -0.2

}

/* funzione che scrive i numeri dall'array su un file */
void scriviNumeri(int* sequenza, int lunghezza) {
     FILE *fp=fopen("interi.dat","wb");
    if(fp==NULL)
        printf("Impossibile aprire il file \n");
    else
        fwrite(sequenza,sizeof(int),lunghezza,fp);

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
			printf("Nella sequenza ogni tripla di elemenmti ha il massimo che e' un numero pari \n");
		else
			printf(" Nella sequenza NON tutte le triple hanno l'elemento massimo pari \n");

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
			printf(" Nella sequenza ogni tripla di elemenmti ha il massimo che e' un numero pari \n");
		else
			printf(" Nella sequenza NON tutte le triple hanno l'elemento massimo pari  \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}