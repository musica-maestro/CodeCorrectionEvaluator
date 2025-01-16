/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA
 INPUT: un valore intero x; una sequenza di x valori //**** MANCA LA LUNGHEZZA -0.2
 PRE-COND: i valori della sequenza sono interi; x>=3
 OUTPUT: un valore r
 POST-CON:il valore r risulta pari ad uno se esiste almeno una tripla nella sequenza di cui uno dei valori è il resto della divisione tra gli altri due, r è pari a zero altrimenti*/

 /*il problema è di tipo verifica esistenziale*/

#include <stdio.h>


/* funzione che verifica l'esistenza di una tripla di cui uno dei valori sia il resto della
   divisione tra gli altri due. restituisce 1 se la tripla esiste, 0 altrimenti */
int restoDivisione(int seq[], int l){

int risultato=0;    //risultato della verifica esistenziale
int i=0;            //variabile contatore

/*nella tripla uno dei valori è il resto della divisione degli altri?*/
while(i<l-2 && risultato!=1){
	/*se si. aggiorno il risultato*/
	if((seq[i]==seq[i+1]%seq[i+2]) || (seq[i]==seq[i+2]%seq[i+1]) ||
	   (seq[i+1]==seq[i]%seq[i+2]) || (seq[i+1]==seq[i+2]%seq[i]) ||
	   (seq[i+2]==seq[i]%seq[i+1]) || (seq[i+2]==seq[i+1]%seq[i]))
		risultato=1;
	/*altrimenti passo alla tripla successiva*/
	else
		i++;
}

/*restituisce il risultato*/
return risultato;
}





/* funzione principale */
int main(){

int x;   //lunghezza dell'array
int r;   //per il risultato
/*chiede la lunghezza ed i valori dell'array*/
printf("caro utente, di quanti interi e' composta la tua sequenza?\n");
scanf("%d", &x);
int seq[x];
printf("dammi pure i valori della sequenza\n");
for(int i=0;i<x;i++)
	scanf("%d", &seq[i]);

/*invoca la funzione*/
r=restoDivisione(seq,x);

/*stampa il risultato*/
if(r==1){
	printf("\nnella sequenza esiste almeno una tripla di cui uno dei valori e' il resto della divisione");
    printf(" tra gli altri due\n");}
if(r==0){
	printf("\nnella sequenza non esistono triple in cui uno dei valori e' il resto della divisione");
    printf(" tra gli altri due\n");}
}