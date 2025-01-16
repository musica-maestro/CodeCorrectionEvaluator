/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................5.4
*/
/*SPECIFICA
 * Input:una sequenza s di lunghezza l. //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * Pre-condizioni: l lunghezza di s.
 * Output: intero num.
 * Post-condizioni: intero num è pari a 0 se la somma di tre interi tra cui due uguali è compresa tra 10 e 20, altrimenti è 1.
 * Tipo di Problema: Verifica di esistenza  //********* NON E' QUESTO CIO' CHE E' RICHIESTO DAL PROBLEMA! -0.5
 * */

#include <stdio.h>

int  ugualiCompresi(int interi[],int lunghezza){
	int num=0;//variabile esistenziale
	int i=0; //variabile contatore
	int somma;
	somma=(interi[i]>=10 && interi[i]<=20);

	while(i<=lunghezza-3 && num){//******** NON ENTRA MAI NEL CICLO! -1


		if(!(interi[i-1]+interi[i]+interi[i+1]==somma)&&(!(interi[i]==interi[i-1])||(interi[i]==interi[i+1])))
		  num=1; //********** SE i PARTE DA 0 NON PUOI CONSIDERARE i-1, MA i, i+1 E i+2 -1
		else     //********** LA CONDIZIONE CHE STAI VERIFICANDO NON E' NEMMENO QUELLA CHE HAI SCRITTO NELLE POST-CONDIZIONI
			i++; //********** PERCHE'HAI DETTO CHE LA SOMMA DEVE ESSERE COMPRESA TA 10 E 20 E TU VERIFICHI SOLO CHE SIA =10
                 //********** -2.5
	}
	return num;
}



int main(){
	int lunghezza;
/*INPUT*/
	printf("Caro utente sono un programma che calcola se in un array ci sono triple di interi con somma compresa tra 10 e 20\n");
	printf("inserisci la lunghezza sella sequenza\n");
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];

	for(int i=0;i<lunghezza;i++){
		printf("Introduci un intero\n");
		scanf("%d",&sequenza[i]);
	}
	/*OUTPUT*/
		if(ugualiCompresi(sequenza,lunghezza))
			printf("Nella sequenza esistono triple la cui somma %c compresa tra 10 e 20\n",138);
		else
			printf("Nella sequenza esistono triple la cui somma %c compresa tra 10 e 20\n",138);
} 		//******** COERENTE CON LE POST-CONDIZIONI