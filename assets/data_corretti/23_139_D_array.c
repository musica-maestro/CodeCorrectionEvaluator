/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA
* Input: una sequenza 'seq' e una lunghezza 'lungh'  //******** MANCA IL TIPO -0.2
* Pre-condizione: 'lungh' è la lunghezza di seq
* Output: un intero 'risultato'
* Post-condizione: 'risultato' vale 1 se esiste almeno una tripla di elementi
* adiacenti in cui uno dei tre è il resto della divisione (tra elementi di tipo int)
* degli altri due, altrimenti 0
* TIPO DI PROBLEMA: VERIFICA ESISTENZIALE */

#include <stdio.h>

int restoDivisione(int seq[], int lungh){
int risultato = 0;
int i = 0;
while(i<lungh-2 && !risultato){
	if((seq[i]%seq[i+1]==seq[i+2]) ||
		(seq[i+1]%seq[i]==seq[i+2]) ||
		(seq[i]%seq[i+2]==seq[i+1])	||
		(seq[i+2]%seq[i]==seq[i+1]) ||
		(seq[i+1]%seq[i+2]==seq[i]) ||
		(seq[i+2]%seq[i+1]==seq[i]))

		risultato = 1;
	else
		i++;
}
return risultato;
}


int main(){
int lungh;
printf("Caro utente, verifico se in una sequenza esiste ");
printf("almeno una terna di elementi adiacenti in cui uno ");
printf("dei tre %c il resto della divisione (tra elementi di tipo int) ", 138);
printf("degli altri due\n");

printf("Quanti elementi contiene la tua sequenza?\n");
scanf("%d", &lungh);
int seq[lungh];

for(int i=0; i<lungh; i++){
	printf("Introduci un intero\n");
	scanf("%d", &seq[i]);
}

if(restoDivisione(seq, lungh)){

printf("Nella sequenza inserita esiste ");
printf("almeno una terna di elementi adiacenti in cui uno ");
printf("dei tre %c il resto della divisione (tra elementi di tipo int) ", 138);
printf("degli altri due\n");}

else{

printf("Nella sequenza inserita non esiste ");
printf("nessuna terna di elementi adiacenti in cui uno ");
printf("dei tre %c il resto della divisione (tra elementi di tipo int) ", 138);
printf("degli altri due\n");
}
}