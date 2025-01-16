/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.9
*/
//SPECIFICA DEL PROBLEMA
//INPUT: lunghezza della sequenza, valori della sequenza
//PRECONDIZIONE: valore intero positivo, valori interi //****** ANDREBERO SOPRA 0.1
//OUTPUT: variabile booleana "Verificato"
//POSTCONDIZIONE: 1 se per ogni terna di valori consecutivi tra quelli inseriti dall'utente esiste un valore multiplo di uno degli altri due, 0 altrimenti

//TIPO DI PROBLEMA: verifica universale

#include <stdio.h>

//FUNZIONE CHE DETERMINA SE IN OGNI TERNA DI VALORI CONSECUTIVI NELLA SEQUENZA ESISTE UN ELEMENTO UGUALE AL MULTIPLO DI UNO DEGLI ALTRI DUE
int multipli(int s[], int l){
	int u=1;	//variabile di universalità

	//Analisi della sequenza di input
	for(int i=1; i<l-1&&u==1; i++){
		int somma=(s[i-1]%s[i]==0)+(s[i-1]%s[i+1]==0)+(s[i]%s[i-1]==0)+(s[i]%s[i+1]==0)+(s[i+1]%s[i-1]==0)+(s[i+1]%s[i]==0);	//somma delle condizioni di molteplicità tra i valori
		//Se la somma è uguale a 0, nessuna condizione è verificata...
		if(somma==0)
			u=0;	//...dunque esiste almeno una terna in cui la proprietà non vale
	}

	//OUTPUT: variabile booleana "verificato"
	return u;
}

//FUNZIONE PRINCIPALE
int main(){
	int n;	//lunghezza della sequenza
	int u;	//variabile di universalità

	//INPUT: lunghezza della sequenza
	printf("Ciao utente, inserisci la lunghezza della tua sequenza\n");
	scanf("%d", &n);

	int s[n];	//sequenza

	//INPUT: valori della sequenza
	printf("Ora inserisci i valori della sequenza\n");
	for(int i=0; i<n; i++){
		scanf("%d", &s[i]);
	}

	//Aggiornamento della variabile di universalità
	u=multipli(s, n);

	//OUTPUT: messaggio che comunica all'utente l'universalità o meno della proprietà nella sequenza di valori da lui inserita
	if(u)
		printf("Per ogni terna di valori che hai inserito esiste un elemento multiplo di uno degli altri due\n");
	else
		printf("C'%c almeno una terna tra i valori che hai inserito che non contiene alcun elemento multiplo di uno degli altri due\n", 138);
}