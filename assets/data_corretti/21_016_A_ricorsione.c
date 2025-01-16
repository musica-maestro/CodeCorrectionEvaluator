/*
5pt massimo pari:..3.4
1pt scrivi numeri:.0.6
2pt quanti numeri:.0.9
2pt leggi numeri:..1.4
TOTALE ............6.2
*/
#include <stdio.h>

int massimopari(int sequenza[], int lunghezza) {
	int risultato;
	if(sequenza==0)//**** Passo base se lunghezza=1 o 2 , vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
		printf("Sequenza non valida\n\n");
		else if(sequenza==3) //**** lunghezza==3 -0.3
		//**** lunghezza==3 fa parte del passo ricorsivo.
		//**** Così devi ripetere 2 volte la verifica della condizione "massimo tra 3 pari". -0.3
			risultato = (sequenza[0]%2==0 && (sequenza[0]>sequenza[1] && sequenza[0]>sequenza[2]))
			|| (sequenza[1]%2==0 && (sequenza[1]>sequenza[0] && sequenza[1]>sequenza[2]))
			|| (sequenza[2]%2==0 && (sequenza[2]>sequenza[0] && sequenza[2]>sequenza[1]));
			else
				risultato = (sequenza[0]%2==0 && (sequenza[0]>sequenza[1] && sequenza[0]>sequenza[2]))
				|| (sequenza[1]%2==0 && (sequenza[1]>sequenza[0] && sequenza[1]>sequenza[2]))
				|| (sequenza[2]%2==0 && (sequenza[2]>sequenza[0] && sequenza[2]>sequenza[1])) && massimopari(sequenza+1, lunghezza-1);

	return risultato;

}


void scrivinumeri(int *sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "wb");
	if(fp==NULL)
		printf("Impossibile aprire file\n\n");
		else
			fwrite(sequenza, "%d", lunghezza, fp);
			//**** sintassi fwrite (sequenza,sizeof(int),lunghezza,fp)  -0.4
	     printf("Salvataggio effettuato\n\n");
		 fclose(fp);
}

void legginumeri(int *sequenza, int lunghezza) {
	FILE *fp = fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("File vuoto\n\n");
	else
		fread(sequenza, "%d", lunghezza, fp);
		//**** sintassi fread (sequenza,sizeof(int),lunghezza,fp)  -0.4
//**** non chiudi il file -0.2

}

int quantinumeri() {
	int quanti;//**** il contatore non è inizializzato -0.5
	int *sequenza;
	FILE *fp = fopen("interi.dat", "rb");
	if(fp==NULL)
		printf("File vuoto\n\n");
		else {
			while(fread(sequenza, "%d", sizeof(int), fp)!=0)
			//**** sintassi fread (sequenza,sizeof(int),1,fp)  -0.4
				quanti++;
		}
	//**** non chiudi il file -0.2
	return quanti;
}






int main(int argc, char **argv)
{
	int risposta;
	int lung;
	int seq[50];
	printf("Inserire sequenza (1) o prendere da file (2) \n");
	scanf("%d", &risposta);

	if(risposta==1) {
		printf("Quanti interi vuoi inserire?\n");
		scanf("%d", &lung);
		int seq[lung];
		for(int i=0; i<lung; i++) {
			printf("Scrivi un numero intero: \n");
			scanf("%d", &seq[i]);
			}
		if(massimopari(seq, lung))
			printf("Ogni tripla consecutiva ha il numero massimo pari\n\n");
			else
				printf("Esiste almeno una tripla consecutiva che non ha il numero massimo pari\n\n");



	}
		else {
		/* determina la lunghezza della sequenza */
		lung = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		legginumeri(seq,lung);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", seq[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(massimopari(seq,lung))
			printf(" ... \n");  //**** dovevi scrivere il messaggio di output! -0.5
		else
			printf(" ... \n");

		/* salva la sequenza su file */
		scriviNumeri(seq,lung);
	}
}
