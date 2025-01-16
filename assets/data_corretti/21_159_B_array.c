/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/* SPECIFICA
 * Input: s e l
 * Pre-condizioni: s è una sequenza di interi e l è la lunghezza di tale sequenza
 * Output: Vero(1) o Falso(0)
 * Post-condizioni: Vero(1) se in ogni tripla di elementi esistono due elementi che sono maggiori o uguali a 5, Falso(0) altrimenti
 * Tipo di problema: Verifica Universale
 */
 #include <stdio.h>
 int maggiori5Pari (int s[], int l){
	 int verificata;
	 verificata =1;
	 int i=0;
	 while(i<l-2 && verificata){
		 if((((s[i]%2==0)&&(s[i+1]%2==0))
		 ||((s[i]%2==0)&&(s[i+2]%2==0))
		 ||((s[i+2]%2==0)&&(s[i+1]%2==0)))
		 && ((((s[i]>=5)&&(s[i+1]>=5)&&(s[i+2]<5))
		 ||((s[i]>=5)&&(s[i+2]>=5)&&(s[i+1]<5))||((s[i+1]>=5)&&(s[i+2]>=5)&&(s[i]<5)))))
			 i++;
		else
			verificata=0;
	 }
	 return verificata;
 }

 /*funzione principale*/
 int main(){
	 int dimensione;
	 printf("Caro utente, sono un programma che verifica se in una sequenza, in ogni tripla ci siano esattamente 2 elementi maggiori o uguali a 5 ");
	 printf("e almeno 2 di ordine pari.\n\n");
	 printf("Quanti elementi desidera inserire?   ");
	 scanf("%d", &dimensione);
	 int sequenza[dimensione];
	 for(int i=0; i<dimensione; i++){
		 printf("Inserisci un bel numero:    ");
		 scanf("%d", &sequenza[i]);
	 }

	 if(maggiori5Pari(sequenza, dimensione))
		 printf("Ogni tripla di elementi soddisfa la propriet%c.\n\n", 133);
	else
		printf("Esiste almeno una tripla che non soddisfa la propriet%c.\n\n",133);
 }