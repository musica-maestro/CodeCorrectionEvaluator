/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA
* Input: Una sequenza di interi positivi (x_1,...,x_n) e la sua lunghezza;
*Precondizione: nessuna; //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*Output: una variabile booleana verificata;
*Post Condizione: verificata vale 1 se in tutte le triple di elementi adiacenti della sequenza
		sono presenti almeno due numeri composti da una sola cifra, vale 0 altrimenti.
* Tipo di problema: Verifica universale */

#include <stdio.h>

/*funzione che verifica se un numero è composto da una sola cifra (compreso tra 0 e 9)*/
int IsUnaCifra(int num){
	return (num>=0 &&num<=9);
}

/* Funzione che data una sequenza di interi postivi e la sua lunghezza,
	restituisce 1 se in tutte le triple di elementi adiacenti della sequenza
	sono presenti almeno due numeri composti da una sola cifra, vale 0 altrimenti.*/
int dueUnaCifra(int* array,int len){
	int verificata=1;// variabile di univeralità
	int i=0; // variabile contatore che scorre la sequenza
	/* scorro la sequenza per verificare che soddisfi la proprietà*/
	while(i<len-2 && verificata){
    /*se trovo un elemento che non soddisfa la condizione interrompo il ciclo*/
		if(!((IsUnaCifra(array[i])&& IsUnaCifra(array[i+1]))||
			(IsUnaCifra(array[i])&& IsUnaCifra(array[i+2]))||
			(IsUnaCifra(array[i+1])&& IsUnaCifra(array[i+2]))
			))
			verificata=0;
		/* altrimenti vado avanti*/
		else
			i++;
	}
	return verificata; // ritorno la variabile di universalità

}

int main(){
	/*input*/
	int len; //lunghezza array
	printf("Ciao, questo programma verifica se ");
	printf("in ogni tripla di interi positivi adiacenti della sequenza sono presenti\n ");
	printf("almeno due numeri composti da una sola cifra\n\n");
	printf("--------------------------------------------------------------------------\n\n");
	printf("Quanti interi vuoi inserire? ");
	scanf("%d",&len);
	int array[len]; //dichiaro l'array
	/*istruzione condizionale per chiedere all'utente di inserire l'n-esimo elemento nell'array*/
	for(int i=0;i<len;i++){
		printf("Inserisci il %d intero: ",i+1);
		scanf("%d",&array[i]);
	}
	/*output*/
	if(dueUnaCifra(array,len)){
		printf("In ogni tripla di elementi adiacenti della sequenza sono presenti ");
		printf("almeno due numeri composti da una sola cifra");}
	else{
		printf("Non in ogni tripla di elementi adiacenti della sequenza sono presenti ");
		printf("almeno due numeri composti da una sola cifra");
	}

}