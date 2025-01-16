/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.5
*/
/*programma che chiede di verificare in una sequenza di interi, se in ciascuna terna di elementi adiacenti alla terna ci sia almeno un elemento della terna multiplo di uno degli altri due*/

/*SPECIFICA
Input: una sequenza s ed una lunghezza l.
Pre-condizione: l è la lunghezza di s.
Output: 1 o 0
Post-condizione: la funzione restituisce 1 se in pgni terna della sequenza esiste almeno un elemento multiplo di uno degli altri due
TIPO DI PROBLEMA: verifica universale*/

#include <stdio.h>
int multipli(int s[], int lunghezza){	//s=sequenza
	for (int i = 0; i < lunghezza-2; ++i){
		if (s[i]%s[i+1]==0 || s[i]%s[i+2]==0 || s[i+1]%s[i]==0 || s[i+1]%s[i+2]==0 || s[i+2]%s[i]==0 || s[i+2]%s[i]==0 ){	//controlla se almeno un valore della terna presa in considerazione è multiplo di un altro
			//******** PARTE IF MACANTE (MOLTO BRUTTO) -1
		}
		else{
			return 0;	//appena trova una terna che non rispetta la condizione il for smette di scorrere gli elementi della sequenza
		}
		//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5

	}
	return 1;
}


int main(int argc, char const *argv[]){
	/*input*/
	int l;	//variabile lunghezza
	printf("ciao utente, quanti interi ha la sequenza?\n");
	scanf("%d", &l);

	int s[l];	//una sequenza s di lunghezza l
	printf("per favore, inserisci gli interi della sequenza:\n");
	for (int i = 0; i < l; ++i){
		scanf("%d",&s[i]);
	}
	/*richiamo funzione multi*/
	int risultato;
	risultato=multipli(s,l);
	/*output*/
	if (risultato==1){
		printf("in tutte le terne di elementi adiacenti della sequenza c'%c almeno un elemento multiplo di uno degli altri due\n",138 );

	}
	else{
		printf("non in tutte le terne della sequenza almeno un numero %c multiplo di uno degli altri due \n",138);
	}


}