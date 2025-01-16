/*
5pt massimo pari:..5
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............10
*/
#include <stdio.h>

int massimoPari(int v[], int n){
	/*Variabile per la ricerca universale*/
	int esiste=1;

	//pre: n>=3
	if(n<3)
		esiste=1;
	/*PASSO RICORSIVO*/
	else
		esiste=((v[0]>v[1] && v[0]>v[2] && v[0]%2==0)
		|| (v[1]>v[0] && v[1]>v[2] && v[1]%2==0)
		|| (v[2]>v[0] && v[2]>v[1] && v[2]%2==0)) && massimoPari(v+1,n-1);

	return esiste;
}

void scriviNumeri(int v[], int n){


	FILE *fp=fopen("numeri.dat","wb");
	/*Verifico se il file esiste, in caso non esista restituisce al puntatore NULL. */
	if(fp==NULL)
		printf("Impossibile aprire il file! \n");
	else
		for(int i=0; i<n;i++)
			/*Scrivo i numeri su di un file.*/
			fwrite(&(v[i]),sizeof(int),1,fp);

		fclose(fp);
}

int quantiNumeri(){

	int numero,cont=0;

	FILE *fp=fopen("numeri.dat","rb");
	if(fp==NULL)
		printf("Impossibile aprire il file! \n");
	else
		/*Fino a quando legge un valore incremento "cont".*/
		while(fread(&(numero),sizeof(int),1,fp)>0)
			cont++;

	fclose(fp);

	return cont;
}

void leggiNumeri(int v[], int n){

	/*Apertuna del file binario con accesso in sola lettura.*/
	FILE *fp=fopen("numeri.dat","rb");
	/*Verifico se il file esiste, in caso non esista restituisce al puntatore NULL. */
	if(fp==NULL)
		printf("Impossibile aprire il file! \n");
	else
		for(int i=0; i<n; i++)
			/*Leggo i numeri....*/
			fread(&(v[i]),sizeof(int),1,fp);

	fclose(fp);
}


int main()
{

	int massimoPari(int v[], int n);
	void scriviNumeri(int v[], int n);
	int quantiNumeri();
	void leggiNumeri(int v[], int n);
	int scelta=-1;//	scelta dell'utente
    int lunghezza; 		//	lunghezza dell'array

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
			printf(" Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari. Val: %d\n",138,138,massimoPari(array,lunghezza));
		else
			printf(" Esiste almeno una tripla di interi consecutivi tale che il massimo fra i tre interi NON %c pari.  Val: %d \n",138,massimoPari(array,lunghezza));

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
			printf(" Ogni tripla di interi consecutivi nella sequenza %c tale che il massimo fra i tre interi %c pari. Val: %d\n",138,138,massimoPari(array,lunghezza));
		else
			printf(" Esiste almeno una tripla di interi consecutivi tale che il massimo fra i tre interi NON %c pari.  Val: %d \n",138,massimoPari(array,lunghezza));

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
  }
