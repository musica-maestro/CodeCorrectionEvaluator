/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1
   MAIN PROGRAM (max 2.5):.1.9
   TOTALE..................4.2
*/
#include <stdio.h>
/*Specifica
 * input: un array di n interi.
 *
 * pre-condizione: gli elementi dell'array sono interi.
 *
 * output: un valore booleano.
 *
 * post-condizione :un valore booleano che indica se esiste una tripla di interi consecutivi tale che almeno
 * due elementi della tripla hanno una somma compresa fra 10 e 20()estremi inclusi, ed esattamente due
 * elementi della tripla sono uguali fra loro.*/  //******** POST-CONDIZIONE NON COMPLETA DEVI DIRE QUANDO E' VERO E QUANDO E' FALSO -0.2

 /* TIPO DI PROBLEMA: Verifica Universale*/ //********** VERIFICA ESISTENZIALE! -1

 int ugualiCompresi(int array[], int l){

	 int esiste;
	 esiste = 1; //***** esiste = 0; -1

	 int i = 0;
	 while(!esiste && i<l){
		 if(){
			 //************** MANCA TUTTA LA CONDIZIONE -3
			 esiste = 0;  //****** esiste = 1;


		 }
		 else
			 i++;
	 }
	 return esiste;
 }


int main() {

	int n;
	printf("Caro utente quanti interi ha la sequenza:\n");
	scanf("%d",&n);
	int array[n];
	printf("Introduciamo gli interi della sequenza:\n");
	for(int i=0;i<n;i++){
		printf("Introduci il %d%c intero: ",i+1,167);
		scanf("%d",&array[i]);
	}

	if(ugualiCompresi(array,n))
		printf("Nella sequenza esiste una tripla di interi con le condizioni descritte nella post-condizione\n");
		else
			printf("Non esiste una tripla di questo genere\n");
	//******** CONSIDERA CHE L'UTENTE VEDE SOLO UNA DELLE DUE STAMPE, NON PUOI SCRIVERE "DI QUESTO GENERE" -0.6
}
