/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/* SPECIFICA:
 *  input: array di interi di lunghezza l
 *  pre-condizione : lunghezza (l) >= 3
 * 	output : un intero risultato
 *  post-condizione : risultato = 1 se esiste una tripla in cui due elementi hanno somma
								  compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali, altrimenti risultato = 0

 * PROBLEMA DI VERIFICA ESISTENZIALE
 * */
#include <stdio.h>

int somma10_20(int x, int y){   //funzione che ritorna 1 se i due interi x e y hanno somma compresa tra 10 e 20
	int risultato = 0; //inizializzazione risultato
	if(x+y <=20 && x+y>=10) //se x+y compreso tra 10 e 20
		risultato = 1; //risultato positivo
	return risultato;    //*********BASTAVA SCRIVERE return (x+y <=20 && x+y>=10); MA VA BENE ANCHE COSI'
}

int ugualiCompresi(int array[], int l){
	int risultato = 0;  //variabile risultato
	int i; //variabile contatore
	for(i=0;i<(l-2)&&(!risultato);i++){  //scorrendo l'array  (se il risultato è stato modificato ad uno il for loop si ferma)
		if(somma10_20(array[i],array[i+1]) || somma10_20(array[i], array[i+2])|| somma10_20(array[i+1],array[i+2]))  //se ci sono due elementi con somma compresa tra 10 e 20
			if((array[i] == array[i+1] && array[i+2]!=array[i])||(array[i+2] == array[i+1] && array[i+2]!=array[i])||(array[i] == array[i+2] && array[i+1]!=array[i]))  //se esattamente due elementi sono uguali
				risultato = 1;  //allora esiste la terna -> risultato = 1
	}
	return risultato;
}

int main()
{
	int l; //inizializzazione lunghezza dell'array
	printf("Inserisci la lunghezza della sequenza: ");
	scanf("%d", &l); //input della lunghezza dell'array
	int array[l]; //inizializzazione array di lunghezza data
	for(int i=0; i<l;i++){
		printf("Inserisci l'elemento n.%d: ", i+1);
		scanf("%d", &array[i]); //input dei singoli elementi dell'array
	}

	if(ugualiCompresi(array, l)) //se la funzione ritorna 1
		printf("Esiste una tripla che ha due elementi la cui somma %c compresa tra 10 e 20 ed\nesattamente due elementi di tale tripla sono uguali.\n\n",138);
	else //altrimenti
		printf("Non esiste una tripla che ha due elementi la cui somma %c compresa tra 10 e 20 ed\nesattamente due elementi di tale tripla sono uguali.\n\n",138);
}
