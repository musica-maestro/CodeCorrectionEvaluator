/* SPECIFICA (max 1.5):....0  //******* MANCANTE
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8
*/
#include <stdio.h>

/*si tratta di un problema di verifica esistenziale*/

int ugualiCompresi(int array[], int lung) {
	int tripla=0;
	for(int i=1;i<lung-1;i++) {  //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1

		int attuale=array[i];
		int precedente=array[i-1];
		int successivo=array[i+1];

		int ugualiAttESucc=(attuale==successivo) && (attuale!=precedente);
		int ugualiAttEPrec=(attuale==precedente) && (attuale!=successivo);
		int ugualiSuccEPrec=(precedente==successivo) && (precedente!=attuale);

		if( ( ugualiAttESucc ) || ( ugualiAttEPrec ) || ( ugualiSuccEPrec ) ) {

			int sommaAttSucc=attuale+successivo;
			int sommaAttPrec=attuale+precedente;
			int sommaSuccPrec=successivo+precedente;

			int compresoAttSucc=(sommaAttSucc>=10 && sommaAttSucc<=20);
			int compresoAttPrec=(sommaAttPrec>=10 && sommaAttPrec<=20);
			int compresoSuccPrec=(sommaSuccPrec>=10 && sommaSuccPrec<=20);

			if(compresoAttSucc || compresoAttPrec || compresoSuccPrec) {
				tripla=1;
			}
		}  //******* COMPLICATISSIMA (MA CORRETTA)!!!! -0.5
	}
	return tripla;
}

int main() {
	int lung;
	printf("inserisci lunghezza array\n");
	scanf("%d", &lung);
	int array[lung];
	for(int i=0;i<lung;i++) {
		printf("inserisci numero dell'array\n");
		scanf("%d", &array[i]);
	}
	if(ugualiCompresi(array, lung)) {
		printf("esiste una tripla che contiene almeno due elementi la cui somma sia compresa tra 10 e 20 e dove esattamente due elementi sono uguali tra loro\n");
	}
	else {
		printf("non esiste una tripla che contiene almeno due elementi la cui somma sia compresa tra 10 e 20 e dove esattamente due elementi sono uguali tra loro");
	}
}
