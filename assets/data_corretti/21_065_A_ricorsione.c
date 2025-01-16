/*
5pt massimo pari:..2.2
1pt scrivi numeri:.1.7
2pt quanti numeri:.2
2pt leggi numeri:..1.7
TOTALE ............7.1
*/
#include <stdio.h>
#include <stdlib.h>
int triplamax(int array[]){
	int c,max=array[0];
	for(c=0;c<2;c++)
	{
		if(array[c]<array[c+1])
		{
			max=array[c+1];//***** errore nel calcolo del massimo! -1.5
                            //***** esempio: (5,3,4) max=4!
		}
	}
	return max;
}
int massimoPari(int array[], int lung)
{
	int vero=1;
	//**** Passo base: se lunghezza=1 o 2, vai nel passo ricorsivo e
	//**** accedi a valori che non fanno parte dell'array -1
	if(lung==3)
	{
		if(triplamax(array)%2!=0)
			vero=0;
	}
	else{
		if(triplamax(array)%2!=0 || !massimoPari(array+1,lung-1)) //**** molto contorta! -0.3
			vero=0;
	}
	return vero;
}
void scriviNumeri(int vet[],int lung){
	FILE *fp=fopen("interi.dat","wb");//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	int c;
	for(c=0;c<lung;c++)
		fwrite(&vet[c],sizeof(int),1,fp);
		fclose(fp);
}
int quantiNumeri()
{
	int lung;
	int prova;
	FILE *fp=fopen("interi.dat","rb");
	if(fp==NULL)
		printf("file non aperto o vuoto \n");
	else
	{
	while(fread(&prova,sizeof(int),1,fp))
		lung++;
	}
	return lung;
	fclose(fp);
}
void leggiNumeri(int vet[],int lunghezza)
{
	FILE *fp=fopen("interi.dat","rb");//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
	fread(vet,sizeof(int),lunghezza,fp);
	fclose(fp);
}
/* funzione principale */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? \n");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: \n");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,lunghezza))
			printf("ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari \n",138,138);
		else
			printf("non %c vero che ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari \n",138,138,138);

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
			printf("ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari \n",138,138);
		else
			printf("non %c vero che ogni tripla di interi consecutivi %c tale che il massimo fra i tre interi %c pari \n",138,138,138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}