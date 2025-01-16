/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.5
*/
/*
SPECIFICA
Input: un array di interi v[] di lunghezza len e un intero len
Pre-condizione:  //****** MANCA -0.2
Output: un valore intero 1 o 0
Post-condizione:  //****** MANCA -0.2
TIPO DI PROBLEMA: verifica universale
Controllo che la condizione si verifichi PER OGNI tripla dell'array

*/


#include <stdio.h>

//funzione di supporto; controlla se, dati due interi, uno dei due è multiplo dell'altro
int unMultiplo(int a, int b){
	int si=0;
	if ((a%b==0)||(b%a==0)){
		si =1;
	}
	return si;
}

int multipli(int v[], int len){
	//variabile contatore di posizione
	int i =0;

	//variabile di verifica universale
	int verificato=1;

	//esamino le triple dell'array finché non trovo un'istanza positiva oppure la fine dell'array
	while(i<(len-2) && verificato==1){

		//nella tripla corrente almeno un valore è multiplo di un altro
		//procedo nella verifica
		if ((unMultiplo(v[i],v[i+1])) || (unMultiplo(v[i], v[i+2])) || (unMultiplo(v[i+1], v[i+2]))){
			i++;
		}

		//nessuna istanza positiva, la verifica universale ha esito negativo
		else{
			verificato=0;
		}
	}
	return verificato;
}

int main(){
	int l;
	printf("Ciao user, creiamo una sequenza di interi. Di quanti elementi la vuoi creare?\n");
	scanf("%d", &l);
	int v[l];
	printf("Ok, ora inserisci %d valori interi.\n",l);
	int i  =0;
	while(i<l){
		scanf("%d", &v[i]);
		i++;
	}


	//stampa di prova
	printf("Ecco la tua sequenza:\n");
	int lun=0;
	while (lun<l){
		printf("%d", v[lun]);
		lun++;
	}
	printf("\n");

	printf("Ok, ora controllo se, per ogni tripla di consecutivi, \nc'è almeno una coppia dividendo-divisore.\n");
	if(multipli(v,l)==1){                               //****** è NON E' ASCII -0.1
		printf("A quanto pare si!\n");
	}
	else if(multipli(v,l)==0){
		printf("A quanto pare no...\n");
	}


}