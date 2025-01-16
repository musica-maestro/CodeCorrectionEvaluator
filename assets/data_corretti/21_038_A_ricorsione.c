/*
5pt massimo pari:..3.7
1pt scrivi numeri:.1
2pt quanti numeri:.1.8
2pt leggi numeri:..2
TOTALE ............8.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int *array, int lunghezza){
	int esito = 0; // variabile che restituisce un booleano
	/*PASSO BASE*/

//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1

//**** lunghezza==3 fa parte del passo ricorsivo.
//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3
	if(lunghezza==3){ //caso base la tripla è solo una
		if((array[0]> array[1] && array[0]>array[2]) && (array[0]%2==0)) // se il primo elemento è il massimo e pari
			esito=1;
		else if ((array[1]> array[0] && array[1]>array[2]) && (array[1]%2==0)) //se il secondo elemento è il massimo e pari
			esito=1;
		else if ((array[2]> array[0] && array[2]>array[1]) && (array[2]%2==0)) // se il terzo elemento è il massimo e pari
			esito=1;
	}
	/*PASSO RICORSIVO*/
	else // se la lunghezza è maggiore di 3
		esito= ((((array[0]> array[1] && array[0]>array[2]) && (array[0]%2==0))
		|| ((array[1]> array[0] && array[1]>array[2]) && (array[1]%2==0))
		||((array[2]> array[0] && array[2]>array[1]) && (array[2]%2==0)))
		&& massimoPari(array+1,lunghezza-1)); //verifica se oni tripla ricorsivamente
	return esito; //resituisce un valore booleano
}

/* funzione che conta ... */
int quantiNumeri() {
	int quanti=0; //variabile per il conteggio
	int numero; //variabile appoggio per la lettura
	FILE *fp= fopen("massimoPari.dat","rb"); //dichiarazione file in lettura
	if(fp==NULL) //se l apertura è fallita
		printf("Apertura file non riuscita!\n");
	else{ //se apertura riuscita
		while(fread(&numero,sizeof(int),1,fp)>0) //finche legge un numero
			quanti++; //aumento la variabile conteggio
		fclose(fp); //chiusura file
		printf("lettura completata!\n") //**** manca il ; -0.2
	}
	return quanti; //restituisce il numero di elementi
}

/* funzione che legge ... */
void leggiNumeri(int* sequenza, int lunghezza){
	FILE *fp= fopen("massimoPari.dat","rb"); //dichiarazione file in lettura
	if(fp==NULL) // se apertura non riuscita
		printf("pertura file non riuscita!\n");
	else{ //se apertura riuscita
		fread(sequenza,sizeof(int),lunghezza,fp); //leggiamo i valori dei numeri
		fclose(fp);//chiusura file
		printf("Operazione completata!\n")
	}
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza){
	FILE *fp= fopen("massimoPari.dat","wb"); //dichiarazione file in scrittura
	if(fp==NULL) //se l apertura non è riuscita
		printf("Apertura non riuscita!\n");
	else{ //se l apertura file è riuscita
		fwrite(sequenza,sizeof(int),lunghezza,fp); //scrittura file riuscita
		fclose(fp); //chiusura file
		printf("Scrittura completata!\n")
	}
}

/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? "); //richiesta scela all'utente
    scanf("%d",&scelta); //lettura del valore booleano

	/* introduzione sequenza da input */
	if(scelta==1) { //se l'utente vuole inserire un nuovo array
		do{
		/* determina la lunghezza della sequenza */
			printf("Introduci la lunghezza della sequenza: "); //richiesta della lunghezza della sequenza
			scanf("%d",&lunghezza); //lettura della lunghezza
			if(lunghezza<3) //la lunghezza deve essere almeno di 3 elementi!
				printf("ATTENZIONE: lunghezza deve essere almeno di 3 elementi!\n"); //messaggio all utente se la lunghezza non raggiunge una tripla
		}
		while(lunghezza <3); //la richiesta continua finche la lunghezza dell utente non è almeno di 3 elementi

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza]; //dichiarazione array
		/*riempimento della sequenza*/
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza)==1) //se il la funzione restituisce 1
			printf("In ogni tripla esiste un massimo che e' pari!\n"); //allora esito positivo
		else //se restituisce 0
			printf(" NON esiste in ogni tripla un massimo che e' pari!\n"); //esito negativo!

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else { //se l'utente vuole leggere una sequenza da file
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri(); //lettura della lunghezza

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza]; //dichiarazone array
		leggiNumeri(array,lunghezza); //lettura dei valori degli elementi della sequenza
		printf("Ecco la sequenza recuperata\n");
		/*stampa all utente dei valori*/
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza)==1) //se la funzione resituisce 1
			printf("In ogni tripla esiste un massimo che e' pari!\n"); // esito positivo
		else//se restituisce 0
			printf("In ogni tripla esiste un massimo che e' pari!\n"); // esito negativo


		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}