/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE..................4.7
*/
/*SPECIFICA
 * input: una sequenza di interi 'array' e un intero 'dimensione'
 * precondizione: l'intero dimensione indica la dimensione della sequenza di interi 's'
 * output: un intero 'risultato'
 * postcondizione: l'intero 'risultato' varrà 1 se la seuqenza di interi rispettano la condizione iniziale , altrimenti 0
//******** LA POST-CONDIZIONE NON DICE NULLA -0.5
TIPO DI PROBLEMA: Ricerca universale*/  //******** VERIFICA ESISTENZIALE! -1


#include <stdio.h>
int UgualiCompresi(int vettore[], int lunghezza){
	int i;
	int risultato=0;
	for(i=0;i<lunghezza-2;i++){
		if((vettore[i]+vettore[i+1]>=10||vettore[i+1]+vettore[i+2]>=10||vettore[i]+vettore[i+2]>=10)&&(vettore[i]+vettore[i+1]<=20||vettore[i+1]+vettore[i+2]<=20)||(vettore[i]+vettore[i+2]<=20)){
		//******** CONDIZIONE ERRATA: LA SOMMA DEGLI STESSI DUE ELEMENTI DEVE ESSERE COMPRESA TRA 10 E 20
		//******** NEL TUO CASO, [6,22,0] 6+22>=10 (ma non e' <=20) e 6+0<=20 (ma non è >=10) e la tua cond. sarebbe vera -1.5
			if(vettore[i]==vettore[i+1]||vettore[i+1]==vettore[i+2]||vettore[i]==vettore[i+2]){
			//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
			//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
				risultato=1;
			}

		}else
		risultato=0; //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	}
	return risultato;

}




int main(int argc, char **argv)
{	int i;   //variabile contatore
	int dimensione; //dimensione dell'array
	int uguali;  //variabile dedicata a richiamare la funzione e a prenderne il risultato
	printf("inserisci il numero di interi che vuoi verificare: ");    //******** I/O UN PO' POVERO -0.3
	scanf("%d",&dimensione);   //acquisisco la lunghezza dell'array
	int array[dimensione];  //dichiaro l'array della dimensione precedentemente inserita
	printf("inserisci %d interi:  ", dimensione);
	for(i=0;i<dimensione;i++){
		scanf("%d",&array[i]);   //ciclo per acquisire gli elementi dell'array
	}
	uguali=UgualiCompresi(array,dimensione);   //richiamo la funzione
	if(uguali==1){
		printf("nella sequenza di interi inserita, ci sono due interi la cui somma e' compresa tra 10 e 20 e un'intero della sequenza e' uguale ad un altro");
	}
	else("nella sequenza di interi inserita,  non ci sono due interi la cui somma è compresa tra 10 e 20 e un'intero della sequenza è uguale ad un altro");

	return 0;
}
