/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.4
*/
/*SPECIFICA
*Input: una sequenza array e la sua lunghezza
*pre-condizione:i valori della sequenza devono essere interi
*Output: valore 0 se vero e 1 se falso
*post-condizione: se è vero avremo una sequenza di tre numeri dei quali due se divisi danno come resto della divisione il terzo
																							//********** FALSO, ALTRIMENTI -0.1

*TIPO PROBLEMA: problema di verifica esistenziale*/


#include <stdio.h>

void RestoDivisione (int array[], int lun){
	int contatore=0;
	for(int i=0; i<lun; i++){ //**** lun-2 -1
		if((array[i]%array[i+1]==array[i+2]) || (array[i+1]%array[i+2]==array[i]) || (array[i]%array[i+2]==array[i+1]))
		//******** CONDIZIONE INCOMPLETA mancano altre tre combinazioni -1
			contatore=1;
		else
			i++;
	}
//***** COSA RESTITUISCE LA FUNZIONE? NON PUO' ESSERE VOID -1.5
}

int main(){
	int lun;
	printf("Ciao, inserisci la lunghezza della sequenza che vuoi inserire: ");    //lunghezza sequenza
	scanf("%d", &lun);

	int array[lun];
	for(int i=0; i<lun; i++){             //scelta valori sequenza
		printf("\nInserisci un valore: ");
		scanf("%d", &lun);
	}

	if(RestoDivisione(array))
		printf("\nla tua terna ha una sequenza di tre numeri dei quali due se divisi danno come resto della divisione il terzo");

	else
		printf("\nla tua terna non ha una sequenza di tre numeri dei quali due se divisi danno come resto della divisione il terzo");
}
