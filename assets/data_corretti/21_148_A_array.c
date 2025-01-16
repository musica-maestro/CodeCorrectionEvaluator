/* SPECIFICA (max 1.5):....0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.4
*/
#include <stdio.h>
/*SPECIFICA DELLA FUNZIONE:
 * input: una sequenza e la sua lunghezza
//******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * pre-condizione: la variabile 'lunghezza' e' la dimensione dell'array 'interi[]'
 * output: una variabile booleana di esistenza 'esiste'
 * post-condizione: la variabile 'esiste' vale 1 se esiste una tripla di elementi consecutivi tale che almeno due elementi della
 * tripla hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono tra loro uguali, vale 0 altrimenti
 * TIPO DI PROBLEMA: verifica esistenziale*/

/*funzione che dato un intero n verifica se questo intero e' compreso tra 20 e 10. La funzione restituisce 1 se tale proprieta'
 * e' rispettata, 0 altrimenti */
int sommaCompresa(int n){
	int verificata; //varaibile booleana di esistenza

	/*inizializzazione di 'somma'*/
	verificata=0;

	/*l'intero n rispetta la proprieta'?*/
	if(n>=10 && n<=20){
		verificata=1;
	}
	return verificata;
}

/*funzione che data una sequenza verifica se esiste una tripla di elementi consecutivi tale che almeno due elementi
  * della tripla hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono tra loro uguali
  * La funzione restituisce 1 se tale proprieta' e' rispettata, 0 altrimenti*/
int ugualiCompresi (int interi[], int lunghezza){
	int i; //variabile contatore
	int esiste; //variabile booleana di esistenza

	/*inizializzazioni*/
	i=0;
	esiste=0;

	/*controllo tutta la sequenza fino a lunghezza-2 perche' sto cercando delle triple, e finche' esiste=0*/
	while(i<lunghezza-2 && !esiste){
		/*la tripla corrente rispetta la proprieta'?*/
		if (((sommaCompresa(interi[i]+interi[i+1])==1)||(sommaCompresa(interi[i+1]+interi[i+2])==1)||
		(sommaCompresa(interi[i]+interi[i+2])==1))&&((interi[i]==interi[i+1] && interi[i]!=interi[i+2])||
		(interi[i+1]==interi[i+2] && interi[i+1]!=interi[i])||(interi[i]==interi[i+2] && interi[i]!=interi[i+1]))){
			esiste=1; //se si esiste=1
		}
		else{ //se no vai avanti
			i++;
		}
	}
	return esiste;
}

/*funzione principale*/
int main(){
	int lunghezza; //lunghezza della sequenza

	/*INPUT*/
	printf("Caro utente sono un programma che data una sequenza verifica se esiste una tripla di elementi consecutivi tale\n");
	printf("che almeno due elementi della tripla hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla\n");
	printf("sono tra loro uguali\n");
	printf("Quanto vuoi che sia lunga la tua sequenza?\n");
	scanf("%d", &lunghezza);

	/*riempio la sequenza*/
	int interi[lunghezza];
	for (int i=0; i<lunghezza; i++){
		printf("Introduci un intero:\n");
		scanf("%d", &interi[i]);
	}

	/*OUTPUT*/
	int esiste = ugualiCompresi(interi, lunghezza); //invoco la funzione ugualiCompresi
	if (esiste==1){
		printf("Nella sequenza esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla\n");
		printf("hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali\n");
	}
	else{
		printf("Nella sequenza non esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla\n");
		printf("hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali\n");

	}
	return 0;
}
