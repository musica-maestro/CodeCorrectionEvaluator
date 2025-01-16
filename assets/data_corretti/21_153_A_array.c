/* SPECIFICA (max 1.5):....0
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................5
*/
/*Specifica
 * input : tre interi della sequennza  //******* NO!
 * pre-condizione : due interi devono esssere consecutivi e la loro somma è compresa tra 10 e 20 //******* NO!
 * output : 1 se soddisfa la pre-condizione, altrimenti 0
 * post-condizione : visuallizazzione ddel risultato  //******* NO!
 * Tipo di Problema: Verifica Essistenziale
 */
#include <stdio.h>

int  UgualiCompresi(int intero[], int lunghezza){
int valore; // valore in output
int somma; // somma della tripla di interi
for(int i=0; i<lunghezza-2;i++){
if(intero[i]== intero[i+1] && intero[i+2] == intero[i+2]){ //******* intero[i+2] == intero[i+2] NON HA SENSO -0.5
//****** DEVI VERIFICARE CHE IL TERZO VALORE SIA DIVERSO DAI DUE PRECEDENTI -1.5
//****** INOLTRE DEVI VERIFICARLO PER TUTTE LE COMBINAZIONI DELLA TERNA -1.5
	somma=intero[i]+intero[i+1]+intero[i+2];
	if(somma<=20){   //******* STAI DICENDO: SE IL PRIMO INTERO E' UGUALE AL SECONDO E IL TERZO E' UGUALE A SE STESSO
      if(somma>=10){  //****** SE LA SOMMA DEI TRE INTERI E' COMPRESA TRA 10 E 20 valore=1
		valore=1;
	  }
	}
}
else {
i++;
}
}
return valore;
}


int main(){
int l; // lungheza della sequenza
printf("Utente inserici la lunghezza della sequenza\n");
scanf("%d", &l);
int intero[l];
printf("inserici gli interi all'interno della sequenza\n");
for(int i=0; i<l; i++){
scanf(" %d ", &intero[i]); // inserimento algli interno nella sequenza
}
printf("la sequenza inserita ha valore %d ", UgualiCompresi(intero,l)); // visualizzazione ddel valore richiesto
}  //******* DEVI ESSERE MOLTO PIU' ESPLICITO, CHI ESEGUE IL PROGRAMMA NON SA COSA STA FACENDO! -1