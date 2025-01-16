/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1
2pt leggi numeri:..2
TOTALE ............9
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione che verifica se l'elemento massimo di ogni tripla Ã¨ pari */
int massimoPari(int *a,int l){
	int verificato;		//eriabile verifica universale
	if(l<3){	//passo base
		verificato=1;
	}
	else{	//passo ricorsivo
		verificato=((a[0]>a[1] && a[0]>a[2] && a[0]%2==0)||
					(a[1]>a[0] && a[1]>a[2] && a[1]%2==0)||
					(a[2]>a[0] && a[2]>a[1] && a[2]%2==0)) && massimoPari(a+1,l-1);
	}
	return verificato;		//restituisce verificato
}

/*funzione che conta quanti numeri sono presenti nelfile*/
int quantiNumeri(){
	FILE *fp=fopen("massimoPariFile.dat","rb");
	int n;//**** il contatore non è inizializzato -0.5
	if(fp!=NULL){
		while(fread(&n,sizeof(int),1,fp)){
			n++;//**** non puoi usare numero sia per contare, sia per la fread,
				//**** così ad ogni lettura perdi il contatore e in numero acquisisci
				//**** il valore letto dal file (in teoria) -0.5
		}
	}
	else{
		printf("Impossibile recuperare la dimensione.\n");
	}
	fclose(fp);
	return n;
}

/*funzione che legge i numeri presenti nel file*/
void leggiNumeri(int *a,int l){
	FILE *fp=fopen("massimoPariFile.dat","rb");
	if(fp==NULL){
		printf("Impossibile salvare l'array");
	}
	else{
		fread(a,sizeof(int),l,fp);
	}
	fclose(fp);
}

/*funzione che scrive i numeri sul file*/
void scriviNumeri(int *a,int l){
	FILE *fp=fopen("massimoPariFile.dat","wb");
	if(fp==NULL){
		printf("Impossibile aprire il file\n");
	}
	else{
		fwrite(a,sizeof(int),l,fp);
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
			printf("Ogni tripla ha l'elemento massimo pari \n");
		else
			printf("Non tutte le triple hanno elemento massimo pari \n");

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
			printf("Ogni tripla ha l'elemento massimo pari \n");
		else
			printf("Non tutte le triple hanno elemento massimo pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}