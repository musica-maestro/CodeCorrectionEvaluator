/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
/*SPECIFICA DEL PROBLEMA
Dati di Input: un array interi[], un numero n
Pre-condizioni: gli elementi dell'array sono interi, n è un intero positivo pari alla lunghezza dell'array
Dati di Output: isUgualeCompreso
Post-condizioni: isUgualeCompreso = 1 se esiste una tripla di elementi consecutivi tale che
esattamente due elementi della tripla sono fra loro uguali, e che almeno due elementi hanno somma
compresa tra 10 e 20 inclusi, 0 altrimenti
TIPO DI PROBLEMA: verifica esistenziale*/
#include <stdio.h>
/*funzione che verifica se esiste una tripla di elementi consecutivi tale che
esattamente due elementi della tripla sono fra loro uguali, e che almeno due elementi hanno somma
compresa tra 10 e 20 inclusi*/
int ugualiCompresi (int interi[], int n) {
	int i=0; //variabile contatore
	int isUgualeCompreso=0; //variabile d'esistenza inizializzata a 0 in quanto non ho trovato elemento che rispetta la proprietà (non avendone ancora esaminato nessuno)
	//Controllo ogni tripla
	while (i<n-2&&!isUgualeCompreso) {
		 /*Controllo la proprietà.
		 * Se è verificata pongo la variabile d'esistenza = 1*/
		if (((interi[i]+interi[i+1]<=20&&interi[i]+interi[i+1]>=10)
		||(interi[i]+interi[i+2]<=20&&interi[i]+interi[i+2]>=10)
		||(interi[i+2]+interi[i+1]<=20&&interi[i+2]+interi[i+1]>=10))
		&&((interi[i]==interi[i+1]&&interi[i]!=interi[i+2])
		||(interi[i]==interi[i+2]&&interi[i]!=interi[i+1])
		||(interi[i+1]==interi[i+2]&&interi[i+1]!=interi[i])))
			isUgualeCompreso=1;
		//altrimenti controllo la tripla successiva
		else
			i++;
	}
	/*restituisco la variabile d'esistenza*/
	return isUgualeCompreso;
}
/*funzione principale*/
int main () {
	int n; //lunghezza array
	/*Input*/
	printf("Ciao utente, sono un programma che verifica se\n");
	printf("esiste una tripla di elementi consecutivi tale che\n");
	printf("esattamente due elementi della tripla sono fra loro uguali,\n");
	printf("e che almeno due elementi hanno somma compresa tra 10 e 20 inclusi.\n");
	printf("Quanti numeri vuoi inserire?\n");
	scanf("%d",&n);
	/*Dichiarazione array*/
	int interi[n];
	/*Acquisizione array*/
	for (int i=0; i<n; i++) {
		printf("Inserisci il %d%c elemento.\n",i+1,248);
		scanf("%d",&interi[i]);
	}
	/*Output con invocazione della funzione che verifica la proprietà*/
	if (ugualiCompresi(interi,n))
		printf("Esiste una tripla di elementi consecutivi che soddisfa tale propriet%c!\n",133);
	else
		printf("Non esiste una tripla di elementi consecutivi che soddisfa tale propriet%c!\n",133);
}