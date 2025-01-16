/* SPECIFICA (max 1):......0.1
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............1.9
*/
/*SPECIFICA:
 *Dati in input: n,l,v[],i,j,k;  //**** QUANTI DATI IN INPUT? MANCANO I TIPI -0.3
 *Pre-Condizione:in ogni tripla devono essere presenti almeno due numeri da una sola cifra //***NO: I NUMERI DEVONO ESSERE POSITIVI -0.3
 *Output:se il risultato è positivo restituisce 1 se non è positivo restituisce 0
 *Post-Condizione: //*** CONFONDI OUTPUT E POSTCONDIZIONE -0.3
 *Problema di verifica esistenziale */  //******** NO, E' UNIVERSALE 0

//inizio del programma
#include<stdio.h>

//dichiaro la funzione
int dueUnaCifra(int v[],int l){

	//dichiaro delle variabili d'appoggio utilizzate peri cicli
	int j;
	int k=0;
	int i=0;

	//primo ciclo per la lettura dell'array
	while(v[j]!='\0'){   //******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5

		//ciclo che prende in considerazione fino a 3 numeri
		for(i=0;i%4==0;i++){

			//la variabile di appoggio incrementa
			k++; //**** AL CICLO SUCCESSIVO k E' ANDATO AVANTI DI 3 POSIZIONI -1

			//condizione da rispettare ai fini del problema
			if((v[k]<='9'&&v[k+1]<='9'&&v[k+2]>'9')||(v[k]>'9'&&v[k+1]<='9'&&v[k+2]<='9')||(v[k]<='9'&&v[k+1]>'9'&&v[k+2]<='9')){
				//******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5
				//****** COSI' VERIFICHI SE CI SONO ESATTAMENTE DUE DI UNA CIFRA, NON ALMENO DUE -1.5
				//se la condizione viene rispettata il programma restituisce un messaggio di successo
				printf("%d",1);

			//se la condizione non viene rispettata il programma restituisce un messaggio
			}else{
				printf("%d",0);//******* IL TESTO RICHIEDE CHE LA STAMPA VENGA FATTA NEL MAIN, NON NELLA FUNZIONE -1.5
			}
		}
	}//****** J NON INCREMENTA MAI? -1
}

int main(){

	//dichiaro le variabili
	int n,l;

	//dichiaro variabile di appoggio
	int i;

	//permette di inserire una luunghezza da noi stabilita del array
	printf("inserire dimensioni array:"); //**** APPICCICATO -0.1
	scanf("%d",&l);

	//crea l'array
	int v[l];

	//ciclo che permette di inserire dei valori finche è presente spazio all'interno del array
	for(i=0;i<l;i++){
		printf("inserire valore:"); //**** APPICCICATO -0.1
		scanf("%d",&n);
	}

	//richiamo della funzione presente al di fuori del main
	dueUnaCifra(v,l);
}
//fine del programma