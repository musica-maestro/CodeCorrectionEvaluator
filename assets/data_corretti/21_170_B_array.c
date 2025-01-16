/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................10
*/
/*SPECIFICA
 * INPUT: Una sequenza di interi di lunghezza l
 * PRE-CONDIZIONE:l è la lunghezza di sequenza
 * OUTPUT: vero o falso a seconada se la proprietà è verificata
 * POST-CONDIZIONE: 0 o 1 sono interi //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: VERIFICA UNIVERSALE
 * */



#include <stdio.h>


int maggiori5pari(int sequenza[], int l){
	int verificato=1;
	int i=0;
	//inizio a leggere la sequenza da indice 0
	while(i<l-2 && verificato){
		//ogni tripla rispetta la proprietà? Altrimenti verificato=0;
		if(		((sequenza[i]>=5 && sequenza[i+1]>=5 && sequenza[i+2]<5) ||
				(sequenza[i]>=5 && sequenza[i+2]>=5 && sequenza[i+1]<5) ||
				(sequenza[i+1]>=5 && sequenza[i+2]>=5 && sequenza[i]<5)) &&
				((sequenza[i]%2==0 && sequenza[i+1]%2==0) ||
				(sequenza[i]%2==0 && sequenza[i+2]%2==0) ||
				(sequenza[i+1]%2==0 && sequenza[i+2]%2==0))){
				i++;
			}
		else
			verificato=0;
	}
}

int main(){
	int l; //lunghezza della sequenza
	printf("Salve utente, sono un programma che data una sequenza di interi, \n");
	printf(" verifica che  ogni tripla di elementi ne ha almeno 2 >= a 5 e 2 elementi pari!\n ");
	//Input lunghezza
	printf("Inserisci la lunghezza della sequenza: ");
	scanf("%d", &l);
	int sequenza[l];
	//input sequenza
	printf("Prego ora inserire gli elementi della sequenza: \n");
	for(int i=0; i<l; i++){
	scanf("%d", &sequenza[i]);} //******* LE PARENTESI NON SERVONO

	//invocazione della funzione e output!
	if(maggiori5pari(sequenza, l))
		printf("\nLa sequenza rispetta la proprietà! \n");
	else
		printf("\nLa sequenza non rispetta la proprietà! \n");
    //******** OUTPUT MOLTO POVERO -0.5
}


