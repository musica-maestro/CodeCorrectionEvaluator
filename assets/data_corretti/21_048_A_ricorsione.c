/*
5pt massimo pari:..2
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............7
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
/*funzione che verifica il massimo elemento*/
int maxElementi(int *array){
	int res=array[0];
	if(array[0]>array[1]){
		if(array[0]>array[2])
			res=array[0];
		else{  //**** se vai qui è perché array[0]>array[1] e array[0]<=array[2]
			if(array[2]>array[0]) //**** quindi questa cond. non serve -0.5
			res=array[2];
		}
	}
	else{
		if(array[1]>array[2])
			res=array[1];
		else
			res=array[2];
	}
	return res;
}

/* funzione ricorsiva che verifica se i ogni tripla di interi consecutivi nella sequenza Ã¨ tale che il massimo fra i tre interi Ã¨ pari */

int massimoPari(int *seq, int lunghezza){
	int ogni; //variabile di verifica universale
	/*CASO BASE*/
	if(lunghezza<=2)
		ogni=1;
	/*PASSO RICORSIVO*/
	else{
		if(maxElementi(seq)>=0 && massimoPari(seq+1,lunghezza-1)) //**** non esprimi la cond. "essere pari", ma "essere positivio" -0.5
			ogni=maxElementi(seq) && massimoPari(seq+1,lunghezza-1);
		//**** chiami due volte la funzione ricorsivamente, ma non assegni mai 0 nel caso in cui la condizioe non sia soddisfatta -2
	}
	return ogni;
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0; //variabile contatore
	int valore;
	FILE *fp=fopen("interi.dat","rb");
	if(fp==NULL)
		printf("errore\n");
	else{
		while(fread(&valore,sizeof(int),1,fp))
			quanti++;
	}
	return quanti;
	fclose(fp);
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {
		FILE *fp=fopen("interi.dat","rb");
	if(fp==NULL)
		printf("nessun numero da leggere\n");
	else{
		for(int i=0;i<lunghezza;i++){
			fread(&sequenza[i],sizeof(int),1,fp);
		}
	}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
			FILE *fp=fopen("interi.dat","wb");
	if(fp==NULL)
		printf("nessun numero da salvare\n");
	else{
		for(int i=0;i<lunghezza;i++){
			fwrite(&sequenza[i],sizeof(int),1,fp);
		}
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
			printf("ogni tripla di interi consecutivi della sequenza ha il massimo dei tre pari \n");
		else
			printf("ogni tripla di interi consecutivi della sequenza  NON ha il massimo dei tre pari \n");

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
			printf("ogni tripla di interi consecutivi della sequenza ha il massimo dei tre pari\n");
		else
			printf("ogni tripla di interi consecutivi della sequenza ha il massimo dei tre pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
