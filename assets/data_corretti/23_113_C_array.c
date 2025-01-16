
/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8
*/
/*SPECIFICA
 *INPUT: una sequenza di interi e l sua lunghezza
 *PRE CONDIZIONI : la sequenza deve essere di tutti interi positivi
 *OUTPUT : valorre booleano che restituisce o 1 o 0;
 *POST CONDIZIONI:il valore restituisce 1 se in ogi tripla di elementi adiacenti della sequenza soono presenti almeno due numeri composti da una sola cifra e 0 altrimenti ;

 *TIPO DI PROBLEMA :VERIFICA UNIVERSALE  */


#include <stdio.h>

/*funzone per capire seil numero è ad una cifra o no */
int isUnaCifra(int x){
	int risultato;
	if(x>=0 && x<=9)
		risultato=1;
	else
		risultato=0;

return risultato;

}

/*funzione che riceve una sequenza e la sua lunghezza e restituisce 1 se in ogi tripla di elementi adiacenti della sequenza soono presenti almeno due numeri composti da una sola cifra, altrimenti 0*/
int dueUnaCifra(int* seq, int l){
	int i=0; // per scorrere nella sequenza
	int tutte=1; // variabile universalità che assumiamo ce sia true all'inizio del problema

/*guarda tutti gli elementi della sequenza */
	while(i<l-3 && tutte){  //******* i<=l-3 -0.5
		/*guardo i casi in cui dover cambiare il valore della variabile di uiversalià*/
		if((isUnaCifra(seq[i])) &&  (!isUnaCifra(seq[i+1])) && (!isUnaCifra(seq[i+2]))   ||
		   (isUnaCifra(seq[i+1])) &&  (!isUnaCifra(seq[i+2])) && (!isUnaCifra(seq[i])) ||
		   (isUnaCifra(seq[i+2])) &&  (!isUnaCifra(seq[i])) && (!isUnaCifra(seq[i+1])))
			tutte=0;  //****** SE SONO TUTTI NUMERI DI PIU' DI UNA CIFRA LA CONDIZIONE E' VERIFICATA! -1.5
		else
			i++;

	return tutte;

	}



}

int main(){

	/*fase di input*/

	int lunghezza;
	printf("Ciao utente, inserisci la lunghezza della tua stringa : ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	for(int i=0; i<lunghezza ; i++){
		printf("inserisci un valore da mettere nella sequenza : ");
		scanf("%d", &sequenza[i]);
	}

	/*output*/

	if(dueUnaCifra(sequenza,lunghezza))
		printf("CI SONO almeno due numeri composti da solo una cifra in ogni tripla di elementi adiacenti nella tua sequenza !");
	else
		printf("NON CI SONO  almeno due numeri composti da solo una cifra in ogni tripla di elementi adiacenti nella tua sequenza !");

}
