/* SPECIFICA (max 1.5):....0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................9.3
*/
#include <stdio.h>

/*Tipo di problema: Verifica Esistenziale
 * Input: un array e la sua lunghezza //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * Output: Variabile int ex (se ritorna 1, istanza positiva, se ritorna 0, istanza negativa)*/
//******* METTI INSIEME OUTPUT E POST-COND. -0.3 //******** MANCA LA PRECONDIZIONE -0.3
int compresiMultipli3(int seq[], int length){
	int i = 0;
	int ex = 0;  /*Inizializzo la variabile di esistenza a 0, siccome si tratta di una verifica esistenziale*/
	while(i < length - 2 && !ex){  /*Siccome stiamo lavorando con triple, lunghezza - 2 perche ci interessa quante triple ci sono*/
		if((((seq[i] <= 10 && seq[i] >= -10) && (seq[i+1] <= 10 && seq[i+1] >= -10))
		|| ((seq[i+1] <= 10 && seq[i+1] >= -10) && (seq[i+2] <= 10 && seq[i+2] >= -10))
		|| ((seq[i] <= 10 && seq[i] >= -10) && (seq[i+2] <= 10 && seq[i+2] >= -10)))
		&& (((seq[i] %3 == 0) && (seq[i+1] %3 == 0) && (seq[i+2] %3 != 0))
		|| ((seq[i] %3 == 0) && (seq[i+1] %3 != 0) && (seq[i+2] %3 == 0))
		|| ((seq[i] %3 != 0) && (seq[i+1] %3 == 0) && (seq[i+2] %3 == 0)))){
			ex = 1;  /*Se esiste una tripla che contiene almeno 2 elementi il cui valore è compreso tra -10 e 10 e che contiene esattamente 2 elementi multipli di 3. La variabile esistenziale diventa istanza positiva*/
		}
		else{
			i++;  /*se ancora non si trova una tale tripla, vai avanti*/
		}
	}
	return ex;
}

int main(int argc, char **argv){
	int length2 = 0;
	printf("Quanto sarà lungo l'array?: ");
	scanf("%d", &length2);

	int seq2[length2];

	for(int s = 0; s < length2; s++){
		printf("Inserisci un numero: ");
		scanf("%d", &seq2[s]);
	}

	if(compresiMultipli3(seq2,length2)){
		printf("Esiste una tripla che rispetta le condizioni");
	}
	else{
		printf("Non esiste una tripla che rispetta le condizioni");
	}//******** OUTPUT MOLTO POVERO -0.5
}