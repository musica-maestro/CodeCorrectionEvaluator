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

// calcolo il massimo tra i tre numeri della tripla
int calcMassimo(int s1, int s2, int s3){
int ritorno;

     if(s1>=s2)         {
		 if (s1>s3)
			 ritorno=s1;
		 else
			 ritorno=s3; }
      else {
		  if (s2>s3)
			  ritorno=s2;
		  else
			  ritorno=s3;
		   }

return ritorno;
	}

int massimoPari(int *seq, int lunghezza){
int ritorno;
int massimo;

	//Passo base
	if(lunghezza<3)
		ritorno=1;
	else {
		  massimo=calcMassimo(seq[0],seq[1],seq[2]);
		  ritorno=(massimo%2==0) && massimoPari(seq+1, lunghezza-1);
		  }

return ritorno;
}

/* funzione che conta ... */
int quantiNumeri() {
	int conta=0;
	int temp;  //la uso di appoggio
	FILE *fp=fopen("interi.dat", "rb");
	if (fp==NULL)
		printf("il file non esiste\n");
	else {
		while((fread(&temp,sizeof(int),1,fp))>0)
			conta++;
		fclose(fp);
	     }
 	return conta;

}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza) {

	FILE *fp=fopen("interi.dat", "rb");
	if (fp==NULL)
		printf("Problemi sul file non posso leggere i dati\n");
	else {
		for (int i=0;i<lunghezza;i++)
			fread(&sequenza[i],sizeof(int),1,fp);
	printf("array caricato \n");
	fclose(fp);
	     }

}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {

	FILE *fp=fopen("interi.dat", "wb");
	if (fp==NULL)
		printf("Problemi sul file non posso salvare i dati\n");
	else {
		fwrite(sequenza,sizeof(int),lunghezza,fp);
		printf("Salvataggio effettuato\n");
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
		if(massimoPari(array,lunghezza))
			printf("per ogni tripla di elementi che hai inserito il numero massimo  e' paro\n");
		else
			printf("per ogni tripla di elementi che hai inserito non sempre il numero massimo e' paro\n");

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
			printf("per ogni tripla di elementi che hai inserito il numero massimo  e' paro\n");
		else
			printf("per ogni tripla di elementi che hai inserito non sempre il numero massimo e' paro\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}