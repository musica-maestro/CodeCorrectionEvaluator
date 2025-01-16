/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.1.7
2pt leggi numeri:..2
TOTALE ............9.7
*/

#include <stdio.h>
#include <stdlib.h>

/*funzione ricorsiva massimoPari: la funzione verifica se ogni tripla di interi consecutivi nella sequenza è tale che il massimo fra i tre interi è pari; la funzione restituisce il booleano1 se l'istanza è verificata,
 * 0 se non lo è. Problema di verifica universale*/
int massimoPari(int *s,int l) {
	int verificato; //booleano da restituire
	int max; //variabile per contenere il max della tripletta

	/*caso base*/
	if(l<3) //non ho piu una tripla da controllare
		verificato=1;
	/*passo ricorsivo*/
	else{
		//data la tripletta devo controllare qual è il massimo
		max=s[0];
		if(max<s[1] || max<s[2]) {
			if(s[1]>s[2]) {
				max=s[1];
			}
			else
				max=s[2];
		}
		//controllo se il massimo è pari
		verificato = (max%2==0) && massimoPari(s+1,l-1);
	}
	return verificato;
}

/*funzione scriviNumeri*/
void scriviNumeri(int *array, int l) {
	FILE *fp = fopen("interi.dat","wb");

	if(fp==NULL)
		printf("Impossibile salvare la sequenza di interi!\n");
	else {
		fwrite(array,sizeof(int),l,fp);
		fclose(fp);
	}
}

/*funzione quantiNumeri*/
int quantiNumeri() {
	int quanti=0; //variabile che salva quanti numeri ci sono nella sequenza
	int numero; //variabile d'appoggio
	FILE *fp = fopen("interi.dat","rb");
//**** non verifichi che l'apertura del file sia fallita if(fp==NULL) -0.3
	while(fread(&numero,sizeof(int),1,fp)>0) {
		quanti++;
	}
	fclose(fp);
	return quanti;
}

/*funzione leggiNumeri*/
void leggiNumeri(int *array, int l) {
	FILE *fp = fopen("interi.dat","rb");

	if(fp==NULL)
		printf("Impossibile leggere la sequenza di interi!\n");
	else {
		fread(array,sizeof(int),l,fp);
		fclose(fp);
	}
}

/*funzione principale*/
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
			printf("Molto bene, il massimo di ogni tripla consecutiva e' pari.\n");
		else
			printf("Spiacenti, non sempre il massimo di ogni tripla e' pari.\n");

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
			printf("Molto bene, il massimo di ogni tripla consecutiva e' pari.\n");
		else
			printf("Spiacenti, non sempre il massimo di ogni tripla e' pari.\n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
