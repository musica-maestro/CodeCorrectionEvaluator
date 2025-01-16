/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA DEL PROBLEMA:
INPUT: seqeunza di interi "s" e intero "lunghezza"
PRE-CONDIZIONE: intero "lunghezza" indica la lunghezza della sequenza
OUTPUT: variabile booleana "verificato"
POST-CONDIZIONE: la variabile "verificato" assume valore 1 se per ciascuna terna di elementi adiacenti della sequenza
ci sia almeno un elemento della terna multiplo di uno degli altri due, altrimenti assume valore 0.

TIPO DI PROBLEMA: problema di verifica universale*/

#include<stdio.h>

/*funzione che verifica  se per ciascuna terna di elementi adiacenti della sequenza
ci sia almeno un elemento della terna multiplo di uno degli altri due*/
int multipli(int s[], int lunghezza){
	int verificato=1;         //variabile di universalità

	for(int i=0; i<lunghezza-2;i++){
		if(!((s[i]%s[i+1]==0 || s[i]%s[i+2]==0)||(s[i+1]%s[i]==0 || s[i+1]%s[i+2]==0)||(s[i+2]%s[i]==0||s[i+2]%s[i+1]==0)))
			verificato=0;
	}
	return verificato;            //ritorno della funzione
}


//funzione principale
int main(){
	int n;         //variabile che indica la lunghezza della sequenza

	//INPUT
	printf("Utente quanto %c lunga la tua sequenza?\n",138);
	scanf("%d",&n);

    int sequenza[n];
	printf("Utente inserisci ora gli elementi della tua sequenza:\n");
	for(int i=0; i<n; i++)
	scanf("%d",&sequenza[i]);

    int m=multipli(sequenza,n);         //dichiaro variabile 'm' che assume il valore riportato dalla funzione richiamata
    //OUPTUT
    if(m==1)
    	printf("In tutte le terne di elementi adiacenti della sequenza %c presente almeno un elemento multiplo di uno degli altri due\n",138);
    else
    	printf("Non in tutte le terne di elementi adiacenti della sequenza  %c presente almeno un elemento multiplo di uno degli altri due\n",138);

}