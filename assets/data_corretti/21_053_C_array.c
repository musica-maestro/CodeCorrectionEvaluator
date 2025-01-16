/* SPECIFICA (max 1.5):....0.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE..................7.9
*/
/*SPECIFICA
Input: una variabile per la lunghezza della nostra sequenza e la sequenza stessa
//******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
Pre-condizione: sequenza >= 0
Output: mesaggio che informa l'utente se esiste o meno una tripla che soddisfa le esigenze del problema
//******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
Post-Condizione: La variabile esiste ritorna 1 se esisste la tripla che rispetta i criteri altrimenti ritornerà 0
//******** QUALE POST-CONDIZIONE? -0.2
Tipo di Problema: Verifica Esistenziale

 *
 * */
#include <stdio.h>

int compresiMultipli3(int seq[], int lung){
	int i; 			//contatore
	int esiste;		//variabile di ritorno

	i = 1;			//inizializzo le due variabili a  0
	esiste = 0;		//inizialmente non esiste alcuna coppia
	while(i<lung-1 && !esiste){//******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lung-2 -1
		if(((-10<=seq[i]<=10 && -10<=seq[i-1]<=10)
			    //******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA" -1.5
		|| (-10<=seq[i-1]<=10 && -10<=seq[i+1]<=10)
		|| (-10<=seq[i]<=10 && -10<=seq[i+1]<=10) ||
			(-10<=seq[i]<=10 && -10<=seq[i-1]<=10 && -10<=seq[i+1]<=10))
			//******** L'ULTIMA CONDIZIONE NON SERVE
			&& ((seq[i]%3==0 && seq[i-1]%3==0 && seq[i+1]%3!=0) ||
			(seq[i]%3!=0 && seq[i-1]%3==0 && seq[i+1]%3!=0) ||(seq[i]%3==0 && seq[i-1]%3!=0 && seq[i+1]%3!=0)))

			esiste++; //******** BRUTTO!
		else
			i++;
	}
	return esiste;
}

int main(int argc, char **argv)
{
	int lunghezza;
	printf("Inserisci la lunghezza del array: ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Elemento [%d]: ", i);
		scanf("%d", &sequenza);
	}

	/*richiamo la funzione e faccio l'output*/

	if(compresiMultipli3(sequenza,lunghezza))
		printf("Esiste una tripla di elementi consecutivi che contiene almeno due elementi\nil cui valore e' comrpeso fra -10 e 10 e che contiene esattamente \ndue elementi multipli di 3");
	else
		printf("NON Esiste una tripla");
	//******** OUTPUT POVERO -0.3

}
