/*
5pt massimo pari:..5
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.8
2pt leggi numeri:..1.5
TOTALE ............9.1
*/
#include <stdio.h>
#include <stdlib.h>

/*Funzione che in una terna calcola il massimo*/

int massimo(int n1,int n2, int n3) {
	int massimo;
	if (n1>n2 && n1>n3)
		massimo=n1;			//il massimo è il primo elemento
	else if (n2>n1 && n2>n3)
		massimo=n2;			//il massimo è il second elemento
		else if (n3>n1 && n3>n2)
			massimo=n3;		//il massimo è il terzo elemento
	return massimo;		//assumo il valore di massimo
}

/* funzione ricorsiva che verifica se in un array di numeri, ogni tripla di interi consecutivi è tale che il massimo fra i tre interi è pari */

int massimoPari(int *seq, int lunghezza){
	//pre:lunghezza è la lunghezza di seq
	//pre: la sequenza deve avere al minimo 3 elementi
	//Verifica universale

	int verificato;			//intero per la verifica universale

	/*Passo base*/

	if (lunghezza<3)		//non ho abbastanza elementi per negare la proprietà
		verificato=1;		//verificato è positivo

	/*Passo ricorsivo*/
		else			//ho elementi da controllare
			verificato=(massimo(seq[0],seq[1],seq[2])%2==0)&&massimoPari(seq+1,lunghezza-1);		//verifico la sequenza sul massimo della prima terna e rinvoco la funzione sulla sequenza modificata //ricorsione 3 metodo
	return verificato;		//assumo il valore di verificato

}

/* funzione che conta il numero di interi presenti nel file */
int quantiNumeri() {
	int numero;			//un intero
	int quanti=0;		//un intero che servirà da contatore

	FILE *fp=fopen ("interi.dat","rb");		//per apertura di file binari

if (fp==NULL)			//file vuoto o inaccessibile
		printf("Impossibile apprire il file\n");
else {		//posso aprire il file
	while (fread(&numero,sizeof(int),1,fp))		//finche leggo valori
	quanti++;					//incremento la variabile contatore

	}
	return quanti;		//assumo quanti numeri ho
}//**** non chiudi il file -0.2


/* funzione che legge i numeri da file */
void leggiNumeri(int* sequenza, int lunghezza) {
	int numero;		//un intero

	FILE*fp=fopen("interi.dat","rb");		//per apertura di file binari

		if (fp==NULL)								//file vuoto o inaccessibile
		printf("Impossibile aprire il file");
		else{		//si può accedere al file
			while(fread(sequenza,sizeof(int),lunghezza,fp))		//finche leggo numeri
			numero++;		//vado al prossimo numero
			}//**** il while non serve, con la fread carichi tutto l'array. Infatti numero non la usi -0.3
			 //**** funziona ugualmente perché la seconda fread restituisce 0
}//**** non chiudi il file -0.2

/* funzione che scrive la sequenza di numeri su file */
void scriviNumeri(int* sequenza, int lunghezza) {

	FILE*fp=fopen("interi.dat","wb");			//apertura di file binari per la scrittura

	if (fp==NULL)								//impossibile salvare su file
		printf("Impossibile salvare il file\n\n");
		else				//si può aprire il file e salvarci sora
		{
			fwrite(sequenza,sizeof(int),lunghezza,fp);		//cio' che scrivo è una sequenza
			printf("salvataggio effettuato\n\n");			//funzione di stampa che verifica ilo salvataggio
			}
}//**** non chiudi il file -0.2

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
			printf("Si, nella sequenza ogni tripla ha il massimo elemento che %c pari\n",138);		//stampa in caso di risposta positiva
		else
			printf("No,  nella sequenza NON ogni tripla ha il massimo elemento che %c pari\n",138);		//stampa in caso di risposta negativa

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
			printf("Si, nella sequenza ogni tripla ha il massimo elemento che %c pari\n",138);		//stampa in caso di risposta positiva
		else
			printf("No,  nella sequenza NON ogni tripla ha il massimo elemento che %c pari\n",138);		//stampa in caso di risposta negativa

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}
