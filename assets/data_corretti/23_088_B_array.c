/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.6
   TOTALE (10).............7.9
*/
/*Progettare un algoritmo che verifichi che ogni terna di elementi contiene almeno due numeri positivi
*Input: interi,lunghezza
*Pre-condizione:lunghezza=lunghezza della sequenza di interi
*Output: 1:se l'istanza e positiva 0:se l'istanza e negativa
*Post-Condizione:stabilisce se ogni tripla ha almeno due numeri positivi //******** ESATTAMENTE, NON ALMENO -0.2
*TIPO DI PROBLEMA:Verifica Universale
*/

#include<stdio.h>

/*funzione che dati in imput un array di interi e la sua lunghezza
*stabilisce se esistono due numeri positivi per ogni tripla di elementi*/
int duePositivi(int interi[],int lunghezza){
	/*pre:lunghezza>0*/
	int esiste;		//variabile di esistenza della condizione
	int i;            //variabile contatore

	i=0; //variabile contatore parte dall primo elemento della sequenza
	esiste=1; //variabile di esistenza parte da uno

	/*verifico se ogni tripla ha due numeri negativi*/
	while(i<lunghezza-2&&esiste){ //****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
		if((interi[i]<=0&&interi[i+1]<=0)||(interi[i+1]<=0&&interi[i+2]<=0)||(interi[i]<=0&&interi[i+2]<=0))
			esiste=0;		//se non ci sono almeno due interi positivi imposto esiste a 0
		else
			i++;			//altrimenti incremento il contatore di 1
	}
	return esiste;
}

/*funzione main che chiede all utente di inserire la lunghezza della sequenza
* e i suoi interi e stampa se esistono o no due positivi per ogni terna*/
int main(){
	int lunghezza; //lunghezza della sequenza

	printf("Utente sono un programma per verificare \nche in ogni tripla della sequenza \nci siano almeno due numeri positivi\n");
	printf("inserisci la lunghezza della sequenza:");//******* APPICCICATO -0.1
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];		//array sequenza
	printf("\n");

	/*scrivo tutti gli elemnti della sequenza*/
	for(int i=0;i<lunghezza;i++){
		printf("inserisci un intero:"); //******* APPICCICATO -0.1
		scanf("%d",&sequenza[i]);
	}

	/*stampa finale dell risultato*/
	if(duePositivi(sequenza,lunghezza))
		printf("\nogni tripla della sequenza ha almeno due numeri positivi\n");
	else
		printf("\nnon tutte le triple della sequenza ha almeno due numeri positivi\n");
       //*********** ESATTAMENTE, NON ALMENO -0.2
}