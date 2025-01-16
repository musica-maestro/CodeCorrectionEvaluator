/*
5pt minimo dispari:..3.4
1pt scrivi numeri:...1
2pt quanti numeri:...1.5
2pt leggi numeri:....1
TOTALE ..............6.9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int minimoDispari(int *seq, int lunghezza){
	int ris;
	int minimo;
	//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
	if(lunghezza==3){//**** seq[0] -0.3
		if(seq[0]<seq[1] && seq[1]<seq[2])
			minimo=seq[0];
		else if(seq[1]<seq[2] && seq[1]<seq[0])
			minimo=seq[1];
		else
			minimo=seq[2];
		ris=minimo%2!=0;
	}else{//**** lunghezza==3 fa parte del passo ricorsivo.
		  //**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3
		if(seq[lunghezza-1]<seq[lunghezza-2] && seq[lunghezza-1]<seq[lunghezza-3])
			minimo=seq[lunghezza-1];
		else if(seq[lunghezza-2]<seq[lunghezza-1] && seq[lunghezza-2]<seq[lunghezza-3])
			minimo=seq[lunghezza-2];
		else
			minimo=seq[lunghezza-3];
		ris=minimo%2!=0 && minimoDispari(seq, lunghezza-1);
	}
	return ris;
}

/* funzione che conta ... */
int quantiNumeri() {
	int n;//**** il contatore non è inizializzato -0.5
	int l;
	FILE*fp=fopen("interi.dat","rb");
	if(fp==NULL)
		printf("Ce qualche problema con il file\n");
	else{
		while(fread(&l,sizeof(int),1,fp)>0){
			n++;
		}
		fclose(fp);
	}
	return n;
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","rb");
	int n,l;
	n=quantiNumeri();
	if(fp==NULL || n==0)
		printf("Ce qualche problema con il file\n");
	else{
		int sequenza[n]; //**** stai dichiarando un array che invece è passato come parametro! -0.5
		int i; //**** i non è inizializzato -0.5
		while(fread(&l,sizeof(int),1,fp)>0){
			sequenza[i]=l;
			i++;
		}
		printf("Lettura eseguita\n");
		fclose(fp);
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE* fp=fopen("interi.dat","wb");
	if(fp==NULL)
		printf("Ce qualche problema con il file\n");
	else{
		fwrite(sequenza,sizeof(int),lunghezza,fp);
		printf("salvataggio eseguito\n");
		fclose(fp);
	}
}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? \n");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: \n");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf("Ogni tripla contiene un numero dispari che e' il minimo \n");
		else
			printf(" Ogni tripla non contiene un numero dispari che e' il minimo \n");

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
			printf(" Ogni tripla contiene un numero dispari che e' il minimo \n");
		else
			printf(" Ogni tripla non contiene un numero dispari che e' il minimo \n \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}