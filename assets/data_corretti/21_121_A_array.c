/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8.2
*/
#include <stdio.h>
/*programma che riceve una sequenza di numeri e verifica che al suo interno esista una tripla di elementi consecutivi dei quali 2 siano esattamente uguali e la somma di almeno 2 di loro sia compresa fra 10 e 20*/
/*input: una sequenza S di interi e la sua lunghezza l
 * precondizione: l è la lunghezza di S
 * output: ugualiCompresi  //******** MANCA IL TIPO -0.3
 * postcondizione: ugualiCompresi è pari a 1 se esiste una tripla con esattamente 2 elementi uguali fra loro e almeno due elementi che sommati danno come risultato un numero fra 10 e 20, 0 se non esiste
 * Tipo di problema: verifica esistenziale*/

 //funzione che analizza le triple
 int ugualiCompresi (int s[], int l){
	 int i=0;
	 int positiva=0;
	 while(s[i]<l-2){ //finchè la sequenza non arriva all'ultima tripla   //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		 if(((s[i]==s[i+1]) && (s[i+1]!=s[i+2])) || ((s[i+1]==s[i+2])  && (s[i]!=s[i+2])) || ((s[i]==s[i+2]  && (s[i+1]!=s[i]))))
			 if (((10>=s[i]+s[i+1]<=20) || (10>=s[i]+s[i+2]<=20) || (10>=s[i+1]+s[i+2]<=20)))
			    //******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA"
			    //******** A PARTE CHE DOVREBBE ESSERE 10<=s[i]+s[i+1]<=20
			    //******** MA IL C CALCOLA ALTRO (((10>=s[i])+ s[i+1]) <=20) -1.5
				positiva=1; //ho trovato la tripla esatta
			 else
			 i++;} //passo all'elemento successivo
return positiva;}

//funzione principale
int main(int argc, char **argv)
{
	int l;
	printf("caro utente inserisci la lunghezza della tua sequenza\n");
	scanf("%d", &l);
	int sequenza[l];
	printf("inserisci uno alla volta gli elementi della tua sequenza\n");
	for(int i=0;i<l;i++)
		scanf("%d", &sequenza[i]);
		if (ugualiCompresi(sequenza, l)){
		printf("esiste una tripla di elementi consecutivi di cui esattamente 2 sono uguali e la somma di almeno 2 di loro e' compresa tra 10 e 20\n");}
		else{
		printf("NON esiste una tripla di elementi consecutivi di cui esattamente 2 sono uguali e la somma di almeno 2 di loro e' compresa tra 10 e 20\n");
		}

}
