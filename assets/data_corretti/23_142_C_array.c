/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............7
*/
#include<stdio.h>

/*SPECIFICA DEL PROBLEMA
dati ingresso: una sequenza e una lunghezza. //******** MANCA IL TIPO -0.2
pre condizioni: lunghezza è la dimensione della sequenza.//******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
dati uscita: un intero presenti.
post condizioni: presenti=1 se in ogni tripla di elementi adiacenti della sequenza
                siano presenti almeno due nueri composti da una sola cifra altrimenti =0.
TIPO DI PROBLEMA: verifica universale.*/




int dueUnaCifra (int seq[], int lung){
int i=0;                //variabile contatore
int presenti=1;

while(i<=lung-3  && presenti){
if (!(seq[i]>='0' && seq[i]<='9') &&    //******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5
	 (seq[i+1]>='0' && seq[i+1]<='9') ) //******* CONDIZIONE INCOMPLETA mancano altre due combinazioni -1
   presenti = 0;
else
   i++;

}
return presenti;

}



int main(){
	int lung;
	int i;
	printf("quanti interi vuoi inserire?"); //****** APPICCICATO -0.1
	scanf("%d", &lung);

	/*input*/
	int seq[lung];
    for(i=0;i<lung;i++){
    	printf("inserisci una valore: ");
        scanf("%d", &seq[i]);
    }

    /*output*/
        if(dueUnaCifra(seq,lung))
          printf("ogni tripla contiene almeno deu numeri composti da una sola cifra");

        else
        	printf(" ogni tripla non contiene almeno due numeri composti da una sola cifra");


}
