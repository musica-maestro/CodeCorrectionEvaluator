/*
5pt minimo dispari:..5
1pt scrivi numeri:...0.5
2pt quanti numeri:...0
2pt leggi numeri:....1.7
TOTALE ..............7.2
*/
#include <stdio.h>
#include <stdlib.h>

/*funzione che verifica se in un array di numeri interi, ogni tripla di interi consecutivi nella sequenza Ã¨ tale che il minimo tra i tre interi sia dispari*/

int minimoDispari (int sequenza[], int lunghezza)
{
    int esiste;  //variabile da restituire
    if (lunghezza<3)  //passo base
        esiste=1;
        else    //passo ricorsivo
           esiste = (((sequenza[0]<=sequenza[1]) && (sequenza[0]<=sequenza[2]) && (sequenza[0]%2!=0)) ||
                    ((sequenza[1]<=sequenza[0]) && (sequenza[1]<=sequenza[2]) && (sequenza[1]%2!=0)) ||
                    ((sequenza[2]<=sequenza[1]) && (sequenza[2]<=sequenza[0]) && (sequenza[2]%2!=0))) &&
                     minimoDispari (sequenza+1, lunghezza-1);
           return esiste;


}
/*funzione che scrive i valori di un array di interi su di un file*/
void scriviNumeri (int sequenza[], int lunghezza)
{
    FILE*fp = fopen ("interi.dat", "wb");  //apri il file o creane uno in scrittura
    //**** non segnali se l'apertura del file è fallita o se è andata a buon fine if(fp==NULL)...else... -0.5
    for (int i=0; i<lunghezza, i++)
    {
        fwrite (&sequenza[i], sizeof(int), 1, fp);  //scrivi intero per intero nel file

    }
    fclose (fp);  //chiudi il file
}

/*funzione che legge una sequenza di interi da un file*/
void leggiNumeri (int sequenza[], int lunghezza)
{
    FILE*fp= fopen ("interi.dat", "rb");  //apri il file o creane uno in lettura
    if (fp!=NULL)
    {//**** non segnali se l'apertura del file è fallita if(fp==NULL) -0.3
        for (int i=0; i<lunghezza; i++)
        {
        fread = (&sequenza[i], sizeof(int), 1 fp);  //leggi intero per intero dal file

        }
    }
    fclose (fp);  //chiudi il file
}

/*funzione che determina quanit numeri interi sono memorizzati nel file*/
int quantiNumeri ()
{
    int numero;
    if (fp==NULL)
        numero=0;
        else
        {
            numero=
        }
        return numero;
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
		if(minimoDispari(array,lunghezza))
			printf("ogni tripla di interi consecutivi nella sequenza %c tale che il minimo tra i tre interi sia dispari\n", 138);
		else
			printf("ogni tripla di interi consecutivi nella sequenza non %c tale che il minimo tra i tre interi sia dispari\n", 138);
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
		if(minimoDispari(array,lunghezza))
			printf("ogni tripla di interi consecutivi nella sequenza %c tale che il minimo tra i tre interi sia dispari\n", 138);
		else
			printf("ogni tripla di interi consecutivi nella sequenza non %c tale che il minimo tra i tre interi sia dispari\n", 138);

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}