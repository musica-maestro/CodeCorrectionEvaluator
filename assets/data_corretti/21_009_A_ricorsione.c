/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>
#include <stdlib.h>


/*funzione che calcola il massimo tra 3 interi*/
int max(int k, int j, int z) {
	int max=k;
	if(j>max)
		max=j;
	if(z>max)
		max=z;
	return max;
}

/*funzione che restituisce 1 se il massimo di ogni tripla della seq e' pari e 0 altrimenti*/
int massimoPari(int seq[], int lu) {
	//pre: lu>=3
	int tutte; //booleano per la verifica universale
	/*passo base*/
	if(lu==3) {
		if(max(seq[0],seq[1],seq[2])%2==0)
			tutte=1;
	}
	/* passo ric*/
	else
		tutte=max(seq[0],seq[1],seq[2])%2==0 && massimoPari(seq+1,lu-1);

	return tutte;
 }
 /*funzione che restituisce il numero di interi memorizzati in un file binario*/
 int quantiNumeri() {
	 FILE* fp=fopen("interi.dat","rb"); //apro file per lettura
	 int num; //tipo di dato da leggere nel file
	 int quanti=0; //conta quanti numeri leggo nel file

	 if(fp!=NULL) {
	   while(fread(&num,sizeof(int),1,fp)>0)
		  quanti++;
	   fclose(fp);
	}

	 return quanti;
 }
 void leggiNumeri(int* seq, int lu) {
	 FILE* fp=fopen("interi.dat","rb"); //apro file per lettura
	 /*so gia quanti interi contiene il file quindi li leggo*/
	 if(fp!=NULL)  //se il file esiste
		 fread(seq,sizeof(int),lu,fp);
	 else
		printf("Recupero dati non riuscito.\n");

	 fclose(fp);
 }

 void scriviNumeri(int* seq,int lu) {
	 FILE* fp=fopen("interi.dat","wb"); //apro in scrittura binaria
	 if(fp!=NULL) {
		 fwrite(seq,sizeof(int),lu,fp);
		 fclose(fp);
		 printf("Salvataggio riuscito!\n");
	}
	else
		printf("Salvataggio non riuscito.\n");
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
			printf("Nella sequenza che hai inserito tutte le triple hanno numero massimo pari! \n");
		else
			printf("Mi dispiace ma nella tua sequenza non tutte le triple hanno massimo pari.\n");

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
			printf("Nella sequenza recuperata tutte le triple hanno numero massimo pari! \n");
		else
			printf("Mi dispiace ma nella sequenza recuperata non tutte le triple hanno massimo pari.\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
