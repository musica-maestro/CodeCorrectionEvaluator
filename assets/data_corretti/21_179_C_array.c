/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................4.9
*/
/*Specifica del problema*/
/*pre-cond:lunghezza sequenza>=3,*/
/*input:x....xn*/   //******** MANCA IL TIPO DELLE VARIABILI -0.6
/*output:un valore booleano*/
/*post-cond:se booleano 1 = vero, se booleano 0= falso*/ //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
/*tipo di problema:verifica esistenziale*/

#include <stdio.h>
/*funzione ausisiliaria*/
int compresiMultipli3(int sequenza[],int lunghezza){
	int i=0; // per scorrere la funzione
	int soluzione=0; //valore booleano

	while (sequenza[i]<lunghezza-2 && !soluzione){ //per scorrere tutta la funzione
		//***** i<lunghezza-2, NON UN ELEMENTO DELL'ARRAY! -1.5
		if (((sequenza[i]+sequenza[i+1]>=-10 && sequenza[i]+sequenza[i+1]<=10) //verifica che almeno due valori
		//******* QUI STAI VERIFICANDO CHE LA LORO SOMMA SIA COMPRESA TRA -10 E 10! -1.5
		||(sequenza[i]+sequenza[i+2]>=-10 && sequenza[i]+sequenza[i+2]<=10) 	//siano compresi tra -10 e 10
		||(sequenza[i+1]+sequenza[i+2]>=-10 && sequenza[i+1]+sequenza[i+2]<=10))
		&&(((sequenza[i]%3==0)&&(sequenza[i+1]%3==0))||((sequenza[i]%3==0)&&(sequenza[i+2]%3==0)) //verifica che esattamente
			||((sequenza[i+1]%3==0)&&(sequenza[i+2]%3==0))))										// siano divisibili per 3
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			soluzione=1;
		else
			i++; //vai avanti

	}


	return soluzione;
}
/*funzione principale*/
int main()
{
	/*input*/
	int lunghezza; //per l'array
	printf("Quanti interi vuoi inserire?\n");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for (int i=0;i<lunghezza;i++){ // per il riempimento dell'array
		printf("Inserisci un intero: ");
		scanf("%d",&sequenza[i]);
	}
	/*output*/
	int soluzione; // per riportare il valore booleano
	soluzione=compresiMultipli3(sequenza,lunghezza); //per invocare la funzione

	if (soluzione==0)
		printf("FALSO"); //******** OUTPUT MOLTO POVERO -0.5
	else
		printf("VERO");
}
