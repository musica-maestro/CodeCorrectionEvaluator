/*
5pt massimo pari:..1.3
1pt scrivi numeri:.1
2pt quanti numeri:.2
2pt leggi numeri:..2
TOTALE ............6.3
*/
/* Funzione ricorsiva che prende in input una sequenza di interi e verifica se
 * per ogni tripla di interi consecutivi nella sequenza Ã¨ tale che il massimo
 * fra i tre interi Ã¨ pari */
#include <stdio.h>

/* Funzione ricorsiva */
int massimoPari(int array[], int l) {
    int max;                               //variabile massimo
    /* caso base */
    //**** lunghezza==3 fa parte del passo ricorsivo.
	//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.2
	//**** Passo base se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
   if(l==3)
        max = (array[0]%2==0 || array[1]%2==0 || array[2]%2==0);//**** così verifichi che almeno uno sia pari,
    /* passo ricorsivo */                                       //**** non che il massimo sia pari
   else {                                                       //**** verifichi un'altra proprietà -1.5
       if((array[0]%2==0 || array[1]%2==0 || array[2]%2==0)>massimoPari(array+1,l-1))
                                //**** stai confrontando un'espressione booleana con il risultato della funzione ricorsiva -1
           max = (array[0]%2==0 || array[1]%2==0 || array[2]%2==0);
        else
            max = massimoPari(array+1,l-1);
   }
   return max;
}

/* Funzione che verifica la lunghezza della sequenza */
int quantiNumeri() {
    int quanti = 0;                             //inizialmente 0
    int valore;                                 //variabile valore
    FILE *fp = fopen("Array.dat", "rb");
    if(fp==NULL)
        printf("Niente da leggere");
    else {
        while(fread(&valore, sizeof(int), 1, fp))
            quanti++;
    }
    fclose(fp);
    return quanti;
}

/* Salvataggio su file */
/* scrittura */
void scriviNumeri(int array[], int l) {
    FILE *fp = fopen("Array.dat", "wb");
    if(fp==NULL)
        printf("Errore\n");
    else {
        for(int i=0; i<l; i++)
            fwrite(&array[i], sizeof(int), 1, fp);
    }
    fclose(fp);
}

/* lettura */
void leggiNumeri(int array[], int l) {
    FILE *fp = fopen("Array.dat", "rb");
    if(fp==NULL)
        printf("Niente da leggere\n");
    else {
        for(int i=0; i<l; i++)
            fread(&array[i], sizeof(int), 1, fp);
    }
    fclose(fp);
}

/* funzione principale */
int main() {
    int l; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente
    int i;       //variabile contatore

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&l);

		/* crea l'array e leggine i valori degli elementi */
		int array[l];
		printf("Scrivi %d elementi \n",l);
		for(i=0;i<l;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,l))
			printf("VERIFICATO\n");
		else
			printf("NON VERIFICATO\n");

		/* salva la sequenza su file */
		scriviNumeri(array,l);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		l = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[l];
		leggiNumeri(array,l);
		printf("Ecco la sequenza recuperata\n");
		for(i=0;i<l;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimoPari(array,l))
			printf("VERIFICATO\n");
		else
			printf("NON VERIFICATO\n");

		/* salva la sequenza su file */
		scriviNumeri(array,l);
	}
}