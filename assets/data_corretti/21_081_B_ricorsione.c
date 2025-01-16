/*
5pt minimo dispari:..4.5
1pt scrivi numeri:...1
2pt quanti numeri:...2
2pt leggi numeri:....2
TOTALE ..............9.5
*/
#include <stdio.h>

//PROTOTIPI DI FUNZIONE
int minimoDisp(int *, int dim);
void scriviNumeri(int *, int dim);
int quantiNumeri();
void leggiNumeri(int *, int);

int main() {
	int l;
	int scelta;
	puts("Scegli un opzione:\n"
		 "[1]-Inserimento array\n"
		 "[2]-Recupero array da file");
	printf("-->");
	scanf("%d", &scelta);
	if(scelta == 1) {
		printf("Lunghezza sequenza: ");
		scanf("%d", &l);
		int sequenza[l];
		for(int i = 0; i < l; ++i) {
			printf("Inserisci un intero: ");
			scanf("%d", &sequenza[i]);
		}
		if(minimoDisp(sequenza, l))
			printf("Ogni tripla di interi consecutivi %c tale che il minimo fra i tre interi %c dispari\n", 138, 138);
		else
			printf("Esiste una tripla di intero consecutivi dove il minimo fra i tre interi non %c dispari\n", 138);

		scriviNumeri(sequenza, l);

	}
	else {
		l = quantiNumeri();
		int array[l];
		leggiNumeri(array, l);
		printf("Ecco gli elementi della sequenza:[ ");
		for(int i = 0; i < l; ++i)
			printf("%d ", array[i]);
		puts("]");
		if(minimoDisp(array, l))
			printf("Ogni tripla di interi consecutivi %c tale che il minimo fra i tre interi %c dispari\n", 138, 138);
		else
			printf("Esiste una tripla di intero consecutivi dove il minimo fra i tre interi non %c dispari\n", 138);

		scriviNumeri(array, l);

	}
}


int minimoDisp(int *seq, int dim) {
	int ris = 1;

	//CASO BASE IMPLICITO: dim < 3
	if(dim > 2) {
		int min = seq[0];
		if(seq[1] < min)
			min = seq[1];
		else if(seq[2] < min)
			min = seq[2];

		ris = (min % 3 == 0) && minimoDisp(seq+1, dim-1);
	}          //**** != -0.5

	return ris;
}

void scriviNumeri(int *seq, int dim) {
	FILE *fp = fopen("interi.dat", "wb");
	if(fp == NULL)
		puts("Salvataggio fallito!");
	else {
		//sappiamo già quanti elementi ci sono
		fwrite(seq, sizeof(int), dim, fp);
		fclose(fp);
	}
}

int quantiNumeri() {
	int count = 0;
	FILE *fp = fopen("interi.dat", "rb");
	if(fp == NULL)
		puts("Impossibile leggere il file!");
	else {
		int num;
		while(fread(&num, sizeof(int), 1, fp))
			++count;
		fclose(fp);
	}
	return count;
}

void leggiNumeri(int *seq, int dim) {
	FILE *fp = fopen("interi.dat", "rb");
	if(fp == NULL)
		puts("Imposibile leggere il file!");
	else {
		fread(seq, sizeof(int), dim, fp);
		fclose(fp);
	}
}