/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................6-9
*/
/*SPECIFICA
 * input: lunghezza vettore; //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * pre-condizione: lunghezza dell'array;		// ***** ?
 * output: se l'array contiene una tripla di elementi consecutivi contiene due elementi maggiori o uguali a 5
 * ed almeno due elementi pari  //******* MISCHI OUTPUT E POST CONDIZIONI -0.5
 * post-condizione: la funzione restituisce 1 se l'istanhza è positiva, altrimenti zero;
 * TIPOLOGIA
 * verifica Universale */
#include <stdio.h>
#include <stdlib.h>
int maggiori5Pari(int v[],int l){
	int verifica=1; // variabile che conferma che tutti i valori rendono positiva l'istanza
	int i =0;
	while(i<l-3&&verifica){ //per ogni tripla di elementi //******** i<l-2  -0.5
		if(!((v[i-1]>=5&&v[i]>=5)&&(v[i]%2==0&&v[i-1]%2==0))) //se non soddisfa la condizione
		//***** DEVI PROVARE TUTTE LE COMBINAZIONI DELLA TRIPLA
		//***** INOLTRE PER VERIFICARE CHE SIANO ESATTAMENTE 2 >=5 DEVI ANCHE SPECIFICARE CHE IL
		//***** TERZO ELELMENTO E' MINORE -3
			verifica=0; //restituisce 0
		else //altrimenti continua il ciclo
			i++;
	}
	return verifica;
}
int main()
{
	int n;
	printf("Caro utente sono un programma che ti conferma se in ogni tripla di valori\n");
	printf("Esistono due valori che sono maggiori o uguali a 5 , e se due dei valori sono pari\n");
	printf("inserisci la dimensione della sequenza : \n");
	scanf("%d",&n);
	int sequenza[n];
	for(int i=0;i<n;i++){
		printf("inserisci il %d valore :",i);
		scanf("%d",&sequenza[i]);
	}
	if(maggiori5Pari(sequenza,n))
		printf("l'istanza %c positiva !",138);
		else
			printf("l'istanza %c negativa !",138);
	return 0;
}
