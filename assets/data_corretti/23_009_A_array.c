/* SPECIFICA (max 1):......0    //******** MANCA
   TIPO PROBLEMA (max 1):..0    //******** MANCA
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.5
*/
#include<stdio.h>

int verifica(int n1, int n2, int n3){
//restituisce la condizione vera o falsa. potrei usare or booleano ma così è più facile da vedere
int risultatoVerifica=0;
if(n1%n2==0)
	risultatoVerifica = 1;
else if(n1%n3==0)
	risultatoVerifica = 1;
else if(n2%n1==0)
	risultatoVerifica = 1;
else if(n2%n3==0)
	risultatoVerifica = 1;
else if(n3%n1==0)
	risultatoVerifica = 1;
else if(n3%n2==0)
	risultatoVerifica = 1;

return risultatoVerifica;
}

int multipli(int array[], int lunghezza){
//la funzione multipli restituisce 1 se in tutte le terne ci sono almeno due multipli. sennò zero
int i=0;
int risultatoMultipli = 1; // lo inizializzo a 1 così che possa uscire dal ciclo appeno è 0

for(i=0; i<lunghezza-2 && risultatoMultipli!=0; i++){
//lunghezza-2 perchè avendo un elemento i+2 uscirei dalla lunghezza totale
 if(verifica(array[i], array[i+1], array[i+2]) == 1)
 	risultatoMultipli = 1; //***** NON SERVE, E GIA' 1, TI SALVI PERCHE'NELLA CONDIZIONE DEL FOR
 else                      //***** HAI MESSO ANCHE IL CONTROLLO SULLA VARIABILE BOOLEANA, MA E' PERICOLOSO -0.5
 	risultatoMultipli = 0;
}

return risultatoMultipli;
}

int main(){
//l'utente inserisce la lunghezza dell'array
int lunghezza;
printf("inserisci la lunghezza dell'array: ");
scanf("%d", &lunghezza);

//vengono introdotti gli interi nella sequenza e memorizzati in un array con un ciclo for
int array[lunghezza];
int i;
for(i=0; i<lunghezza; i++){
	printf("inserisci l'elemento in [%d]: ", i);
	scanf("%d", &array[i]);
}

//invoco la funzione multipli e salvo il risultato
int risultato = multipli(array, lunghezza);

//stampo il risultato
if(risultato == 1)
	printf("in tutte le terne di elementi adiacenti della sequenza C'E' un elemento multiplo di uno degli altri due\n");
else
	printf("NON in tutte le terne di elementi adiacenti della sequenza c'e' un elemento multiplo di uno degli altri due\n");
}

/*SPECIFICA DEL PROBLEMA
Input: array (lunghezza introdotta dall'utente)
pre-condizione:i=0 e risultatoMultipli=1
output: 1 o 0
post condizione: n1%n2==0 || n1%n3==0 || n2%n1==0 || n2%n2==0 || n3%n1==0 || n3%n2


è un problema di verifica universale
*/