/*
5pt massimo pari:..4.5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..1
TOTALE ............9.5
*/
#include <stdio.h>
#include <stdlib.h>

/* funzione ricorsiva che verifica se per ogni tripla il massimo e' pari
 * PRE-CONDIZIONI: la lunghezza iniziale alla prima invocazione deve essere >= 3 !!!!!*/
int massimoPari(int *seq, int lunghezza)
{
	int verificato;//dichiaro la variabile booleana .
	int maxAttuale=seq[0];//pongo inizialmente che il massimo attuale sia il primo elemento della tripla

	//**** Passo base: se lunghezza=1, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array
	//**** devi gestire lunghezza=1, così come fai con lunghezza=2, anche se poni la precondizione -0.5
	if(lunghezza == 2)//caso base
	{
		verificato=1;
	}
	else//passo ricorsivo
	{
		//trovo il massimo della tripla attuale

		//il massimo relativo e' seq[1]??
		if(seq[1] > maxAttuale)
		{
			maxAttuale = seq[1];
		}

		//verifico se il massimo della tripla e' il secondo elemento
		if(seq[2] > maxAttuale)
		{
			maxAttuale = seq[2];
		}
		//arrivati a questo punto ho che in maxAttuale c'e' memorizzato il massimo della triplaattuale, e posso verificare
		//se per questa tripla il massimo e' pari, tale confizione va poi confrontata con l'istanza più piccola attraverso
		//un invocazione della funzione stessa in maniera ricorsiva
		verificato = (maxAttuale % 2 == 0) && massimoPari(seq + 1, lunghezza - 1);
	}
	return verificato; //restituisco il risultato dell'istanza
}

/* funzione che conta il numero di interi presenti nel file */
int quantiNumeri()
{
	FILE *fp =  fopen("interi.dat","rb");//dichiaro un puntatore al file in modalità lettura
	int lunghezza = 0;//dichiaro un contatore che memorizzera' la lunghezza dell'array letto dal file
	int valore; //variabile di appoggio
	if(fp != NULL)//se fp non e' null allora esiste il file desiderato
	{
		while(fread(&valore,sizeof(int),1,fp)>0)//vai avanti finchè fread fornisce un valore positivo , ovvero finchè nel file c'e' qualcosa da leggere
		{
			lunghezza++;//incremento la lunghezza
		}
	}
	fclose(fp); //salvo le azioni fatte sul file
	return lunghezza;//fornisco il risultato
}

/* funzione che legge una sequenza di interi dal file */
void leggiNumeri(int* sequenza, int lunghezza)
{
	FILE *fp =  fopen("interi.dat","rb");//dichiaro un puntatore al file in modalità lettura
	if(fp != NULL)//se fp non e' null allora esiste il file desiderato
	{
		for(int i=0; i<lunghezza;i++)
		{
			fread(&sequenza[i],sizeof(int),1,fp);//leggo il dato attuale
		}
	}
	fclose(fp); //salvo le azioni fatte sul file
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza)
{
	FILE *fp =  fopen("interi.dat","wb");//dichiaro un puntatore al file in modalità scrittura
	if(fp != NULL)//se fp non e' null allora esiste il file desiderato
	{
		for(int i=0; i<lunghezza;i++)
		{
			fwrite(&sequenza[i],sizeof(int),1,fp);//leggo il dato attuale
		}
	}
	fclose(fp); //salvo le azioni fatte sul file
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
	if(scelta==1)
	{
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
			printf(" EVVAI, Ogni tripla ha il massimo che e' pari\n");
		else
			printf("MI DISPIACE, non tutte le triple hanno il massimo che e' pari. \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else
	{
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
			printf(" EVVAI, Ogni tripla ha il massimo che e' pari\n");
		else
			printf("MI DISPIACE, non tutte le triple hanno il massimo che e' pari. \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	return 0;
}