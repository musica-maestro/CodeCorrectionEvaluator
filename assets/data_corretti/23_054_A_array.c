/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1.2
   MAIN PROGRAM (max 2):...0.3
   TOTALE (10).............2.1
*/
/* SPECIFICA
* Input: sequenza di N elementi
* Pre-condizione: l>0   //*** ERA N, CHI E' l? -0.2
* Output: programma che verifica se nella terna introdotta dall'utente
ci sia almeno un elemento multiplo degli altri due. //**** RESTITUISCE UN BOOLEANO -0.2
* Post-condizione: Funzione restituisce 1 se almeno un elemento della
della terna è un multiplo ddegli altri due altrimenti restituisce 0.
* Tipo di problema: verifica esistenziale */  //******* E' UNA VERIFICA UNIVERSALE -1

#include <stdio.h>

void main(){ //******* NON E' IL MAIN, DEVE ESSERE UNA FUNZIONE -1
int x;
int y;
int z;
int l;

for(int i=0; i<=l; i++){
int verifica=0; //******* A COSA SERVE, I COMMENTI! -0.3

	if(x%y==0 || x%z==0 || y%z==0) //**** x, y E z NON SONO INIZIALIZZATE -1
	//***** SE QUESTA E' LA CONDIZIONE PER VERIFICARE I MULTIPLI, E' INCOMPLETA -1
	verifica=1;
else
	return verifica;
	}
}

int multipli(int a[]; int l){ //***** , NON ; -0.5
int multiplo;

for(int i=0; i<=l; i++)
	if(multiplo(a[i],a[i+1],a[i+2])){ //****** MULTIPLO E' UN INTERO O UNA FUNZIONE? -1.5
	multiplo=0;
	}
	return multiplo;
}

int main(){
int a;

printf("Caro utente dimmi la lunghezza della tua sequenza\n");
scanf("%d",&l);
int seq[l];

printf("Adesso introduci la tua sequenza di %d elementi\n", &l[a]);//**** NO &l[a] -0.5
scanf("%d", &seq[a]); //**** SERVE UN CICLO PER LEGGERE n ELEMENTI -1

if(multiplo(a, l))
	printf("La tua terna contiene almeno un elemento que %c un multiplo delle altre due\n", 138);
else        //*** UNA SOLA TERNA? -0.2
	printf("Mi dispiace ma nessun elemento %c un multiplo degli altri due\n", 138);
}







