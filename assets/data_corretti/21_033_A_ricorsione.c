/*
5pt massimo pari:..5
1pt scrivi numeri:.0
2pt quanti numeri:.0
2pt leggi numeri:..1
TOTALE ............6
*/
/*
 * problema di tipo: ricerca universale finalizzata alla verifica di condizione matematica
 *
 * */
 /// RICORSIONI
#include <stdio.h>

/* funzione ricorsiva che verifica ... */
int massimoPari(int a[], int s){
	int good;
	if(s<3) //passo base
		good = 1; //se arriviamo qua vuol dire che è verificata
	else {
		if ((a[0]>a[1] && a[0]>a[2] && a[0]%2==0) ||
			(a[1]>a[0] && a[1]>a[2] && a[1]%2==0) ||
			(a[2]>a[0] && a[2]>a[1] && a[2]%2==0))
				good = 1 && massimoPari(a+1, s-1); //istanza per ora positiva, ma controlla tripla spostata di un indice in avanti
		else
			good = 0; //istanza negativa
	}
	return good; //returna l'istanza
}

/* funzione che conta ... */
int quantiNumeri() {

}

/* funzione che legge ... */
void leggiNumeri(int* arr[], int n) {
	int numeri;
	FILE * fp = fopen("interi.dat", "rb");
	if(fp==NULL) //se non c'è niente notificalo all'utente sullo schermo
		printf("non c'è niente da leggere!\n");
	else {
		arr[n];//**** che vuol dire? arrn] non è nemmeno una componente dell'array -0.5
		fread(numeri, sizeof(int), n, fp); //fread(arr,, sizeof(int), n, fp); -0.5
	}
	fclose(fp);
}

/* funzione che scrive ... */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb"); //**** manca tutto! -1

	fclose(fp);

}

/* funzione principale */
int main() {
    int size; 		//	lunghezza dell'array
	int menu;				//	scelta dell'utente
	int i;                          //contatore per iterazioni

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&menu);

	/* introduzione sequenza da input */
	if(menu==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&size);
		/* crea l'array e leggine i valori degli elementi */
		int arr[size];
		//iterazione per acquisizione
		for(i=0;i<size;i++) {
			printf("Scrivi elemento in cella %d: \n", i);
			scanf("%d",&arr[i]);
		}

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(arr,size))
			printf(" istanza positiva! \n");
		else
			printf(" istanza negativa! \n");

		/* salva la sequenza su file */
		scriviNumeri(arr,size);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		size = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int arr[size];
		leggiNumeri(arr, size);
		printf("Ecco la sequenza recuperata\n");
		for(i=0;i<size;i++)
			printf("%d ", arr[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(arr,size))
			printf(" istanza positiva! \n");
		else
			printf(" istanza negativa! \n");

		/* salva la sequenza su file */
		scriviNumeri(arr,size);
	}
}