/* SPECIFICA (max 1):......0
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............3
*/
/*programma data una sequenza di interi positivi verifica se in ogni tripla di elemetni adiacenti della sequenza siano presenti almeno due numeri composi da una sola cifra
SPECIFICA
input:viene messo come input la lunchezza dell'array, i componenti dell'array //******** MANCA IL TIPO -0.2
Precondizione: data una stringa di lunghezza l verficarne le triple //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
output:vengono stampate le domande da porre all'utente, i numeri dall'utente inseriti, e se ci sono coppie di numeri singoli nelle terne. //**** NO! -0.3
post-condizione:s //***** MANCA -0.3

problema di tipo verifica esistenziale  //***** E' UNIVERSALE -1
*/
#include <stdio.h>


int DueUnaCifra (int stringa[], int len) {
int d = 0;

for(int i=0; i<len;i = i+3){ //******** NON DEVI SALTARE DI 3 IN 3! -2
	if(stringa[i] >= 0 && stringa[i] <= 9) {
		if (stringa[i+1] >= 0 && stringa[i+1] <= 9) {
			d = d+1;
		} else {
			if (stringa[i+2] >= 0 && stringa[i+2] <= 9) {
				d = d + 1;
			} //******** CONDIZIONE PARZIALE -1
	}

	}

	}

	if (d > 1)//**** NO! SE LO TRATTAVI COME UN PROBL. DI CONTEGGIO POTEVI SCRIVERE if(d==len-2) -1
	{
		return 1;//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
	} else
		return 0;


}


int main() {

	int len = 5;

	//input

	printf("quanti numeri ha la sequenza?: ");

	scanf("%d",&len);

	int stringa[len];

	printf("inserire i relativi  %d  numeri\n", len);

	for(int i=0; i<len; i++) {

		scanf("%d",&stringa[i]);

	}


	//output

	printf("la nostra stringa: ");

	for(int j=0; j<len; j++) {

		printf("%d 	",stringa[j]);

	}


	int c =DueUnaCifra(stringa,len);

	if (c == 1){
		printf("\nla condizione da vera, ci sono due coppie di numeri infeririori a 9 nelle triple");
	} else {
		printf("\nla condizione è falsa, non ci sono due coppie di numeri infeririori a 9 nelle triple");
	} //****** NON E' ESISTENZIALE -0.5

	return 0;

	} //else
	//printf("il risultato è positivo e quindi ci sono ",c);

