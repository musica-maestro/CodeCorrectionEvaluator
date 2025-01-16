/*
5pt massimo pari:..5
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.8
2pt leggi numeri:..1.6
TOTALE ............9.2
*/
#include <stdio.h>
#include <stdlib.h>

/*Funzione che restituisce il massimo nella prima tripla in una sequenza lunga almeno 3*/
int massimo3(int *seq)
{
	int max=seq[0]; //inizializzo il massimo
	for(int i=0; i<3; i++) { //Confronto il massimo con gli altri numeri della tripla
		if (seq[i]>max) { //Aggiorno il valore se ne trovo uno maggiore
			max=seq[i];
		}
	}
	return max;
}

/* funzione ricorsiva che verifica che in ogni tripla della sequenza il massimo dei tre sia pari */
int massimoPari(int *seq, int lunghezza)
{
	//pre: len>=3
	int res=0; //valore da restituire
	int max; //massimo della tripla
	if (lunghezza==3) { //caso base
		/*Trovo il massimo della tripla*/
		max=massimo3(seq);
		/*Controllo che il massimo sia pari e restituisco*/
		res=(max%2)==0;
	} else if (lunghezza>3) { //Passo ricorsivo
		/*Trovo il massimo della sequenza*/
		max=massimo3(seq);
		/*Controllo che il massimo di questa sia tripla sia pari
		 * e che valga lo stesso per ogni altra tripla della sequenza*/
		res=((max%2)==0)&&massimoPari(seq+1,lunghezza-1);
	}

	return res; //restituisco il valore
}

/* funzione che conta quanti interi sono memorizzati nel file "interi.dat" */
int quantiNumeri()
{
	int res=0; //Il valore da restituire
	FILE*fp=fopen("interi.dat","rb"); //Il puntatore al file
	if (fp==NULL) printf("Non ho potuto aprire il file per leggere quanti interi ci sono.\n"); //Se il file non esiste lo dico all'utente
	else {
		int temp; //Una variabile temporanea per leggere i numeri
		while(fread(&temp,sizeof(int),1,fp)>0) //Conto quanti numeri ci sono
			res++;
	}
	//**** non chiudi il file -0.2
	return res;
}

/* funzione che legge i numeri salvati nel file "interi.dat" e li salva nell'array ricevuto coma parametro */
void leggiNumeri(int* sequenza, int lunghezza)
{
	FILE*fp=fopen("interi.dat","rb"); //Il puntatore al file
	if (fp==NULL) printf("Non ho potuto aprire il file per leggere gli interi.\n"); //Se il file non esiste lo dico all'utente
	else {
		while(fread(sequenza,sizeof(int),1,fp)>0 && lunghezza>0) { //Leggo gli interi nell'array finché c'è spazio o finché non finiscono
		//**** complicata! se conosci la lunghezza non c'è bisogno del while
		//**** fread(sequenza,sizeof(int),lunghezza,fp); -0.2
			sequenza++;
			lunghezza--;
		}
	}
	//**** non chiudi il file -0.2
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza)
{
	FILE*fp=fopen("interi.dat","wb"); //Il puntatore al file
	if(fp==NULL) printf("C'è stato un errore nel salvataggio"); //Se il file non si è aperto/creato lo dico all'utente
	else {
		fwrite(sequenza,sizeof(int),lunghezza,fp); //salvo la sequenza
	}
	//**** non chiudi il file -0.2
}

/* funzione principale */
int main()
{
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
		for(int i=0; i<lunghezza; i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf("Il massimo di ogni tripla nell'array %c pari \n",138);
		else
			printf("Non tutti i massimi di ogni tripla sono pari \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/*Se ho trovato un file con i numeri dentro vado avanti, altrimenti no*/
		if (lunghezza!=0) {
			/* crea l'array e leggine i valori degli elementi da file */
			int array[lunghezza];
			leggiNumeri(array,lunghezza);
			printf("Ecco la sequenza recuperata\n");
			for(int i=0; i<lunghezza; i++)
				printf("%d ", array[i]);
			printf("\n");

			/* invoca la funzione ricorsiva e stampa il risultato */
			if(massimoPari(array,lunghezza))
				printf("Il massimo di ogni tripla nell'array %c pari \n",138);
			else
				printf("Non tutti i massimi di ogni tripla sono pari \n");

			/* salva la sequenza su file */
			scriviNumeri(array,lunghezza);
		}
	}
}
