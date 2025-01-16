/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1 (LA CONDIZIONE E' SCRITTA MALE, MA E' GIUSTA)
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE..................5.2
*/
/*Specifica
 * Input: array contenente numeri interi e la sua relativa lunghezza
 * Precondizione: lunghezza array >= 3
 * Output: variabile booleana
 * Postcondizione: la variabile vale 1 se il problema è verificato, 0 se invece è sbagliato
 //******** LA POST-CONDIZIONE NON DICE NULLA, DEVI SPECIFICAREA QUANDO E' VERA E  QUANDO E' FALSA -0.5
 * Tipo di problema: verifica universale //******** NO, VERIFICA ESISTENZIALE -1
 */

#include <stdio.h>

int compresiMultipli3(int s[], int l)
{
	int i;
	int f; //******** VARIABILE NON INIZIALIZZATA -1
	 for(i=0; i<l-2; i++)
	 {  //********** GLI INTERI NON SONO NE' CARATTERI, NE' STRINGHE IN QUESTO CASO -2.5
		 if(((s[i]>='-10' && s[i]<='10')&&(s[i+1]>='-10' && s[i+1]<="10"))||
		 ((s[i+1]>='-10' && s[i+1]<='10')&&(s[i+2]>='-10' && s[i+2]<="10"))||
		 ((s[i]>='-10' && s[i]<='10')&&(s[i+2]>='-10' && s[i+2]<="10")))
			 {
			  f=1;
		     }
		 else
			{
			f=0; //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	 }
	 }
	 if(f==1){
	 for(i=0; i<l-2; i++){
		  if(((s[i])%3==0 && (s[i+1])%3==0 && (s[i+2])%3!=0)||
		  ((s[i+1])%3==0 && (s[i+2])%3==0 && (s[i])%3!=0)||
		  ((s[i])%3==0 && (s[i+2])%3==0 && (s[i+1])%3!=0))
			  {
			    f;
			}
		  else
		  {
			  f=0;//******** COME SOPRA

		  }
	  }
	}
	return f;
}

int main()
{
	int l;
	printf("Questo e' un programma che verifica se in una sequenza di interi sono presenti almeno due numeri compresi\n");
	printf("tra -10 e +10 e se in questa sequenza sono presenti solo due multipli di 3\n");
	printf("Quanti numeri vuoi inserire?\n");
	scanf("%d",&l);
	int s[l];
	for(int i=0; i<l; i++)
	{
		printf("Inserisci un numero: ");
		scanf("%d", &s[i]);
	}
	int f=compresiMultipli3(s,l);
	if(f==1)
	{
		printf("La sequenza rispetta la regola iniziale\n");
	}
	else
	{
		printf("La sequenza non rispetta la regola iniziale\n");
	}   //******** OUTPUT UN PO' POVERO -0.3
}
