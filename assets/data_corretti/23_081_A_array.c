/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
#include<stdio.h>

/*SPECIFICA
* INPUT: sequenza di interi
* PRE-CONDIZIONE: nessuna
* OUTPUT: multiplo booleano
* POST-CONDIZIONE: multiplo=1 se almeno una elemento di ogni terna adiacente è multiplo di uno degli altri due,0 altrimenti
* TIPO DI PROBLEMA: verifica universale */





/*--------------PROTOTIPO FUNZIONI--------------*/

//restituisce 1 se in ogni ternca c'e almeno un elemento multiplo di uno degli altri,0 altrimenti
int multipli(int vettore[],int l);

//restituisce 1 se almeno un elelmento della terna è multiplo di almeno uno degli altri
int proprietà(int vettore[],int i);



/*--------------PROGRAMMA PRINCIPALE--------------*/

int main(){

	int lunghezza;

	printf("\nQuanti numeri vuoi inserire? ");
	scanf("%d",&lunghezza);

	//dichiaro e inizializzo il vettore
	int vettore[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("\n\tInserisci il %d%c elemento: ",i+1,248);
		scanf("%d",&vettore[i]);
	}

	if(multipli(vettore,lunghezza))
		printf("\n---In ogni terna c'%c almeno un elemento muoltiplo di uno degli altri.\n",138);
	else
		printf("\n---In almeno una terna un elemento non %c multiplo di uno degli altri.\n",138);

}



/*--------------FUNZIONI--------------*/

int multipli(int vettore[],int l){
	int i;
	int multiplo=1;
	//finchè i è minore della lunghezza del vettore-2 e multilpo=1
	for(i=0;i<l-2 && multiplo;i++){
		//se la proprietà non è verificata modifico il valore di multiplo
		if(!proprietà(vettore,i))//******* I CARATTERI ACCENTATI NON SONO AMMESSI -0.5
			multiplo=0;
	}
	return multiplo;
}


int proprietà(int vettore[],int i){
	return vettore[i]%vettore[i+1]==0 || vettore[i+1]%vettore[i]==0 || vettore[i]%vettore[i+2]==0 || vettore[i+2]%vettore[i]==0 || vettore[i+1]%vettore[i+2]==0 || vettore[i+2]%vettore[i+1]==0;
}