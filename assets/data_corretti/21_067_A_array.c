/* SPECIFICA (max 1.5):....1,5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA
 * Input:sequenza di interi e la sua lunghezza
 * Pre-condizione: l è la sua lunghezza e l>=3
 * Output: 1 o 0
 * Post-condizione:la funzione resitituisce 1 se esiste una tripla
 * di elementi consecutivi tale che almeno due elementi della tripla
 * hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente
 * due elementi della tripola sono fra loro uguali, resituisce 0 altrimenti
 * TIPO DI PROBLEMA: verifica esistenziale */
 #include <stdio.h>
  /*funzione che data una sequenza di interi e la sua lunghezza verifica
  * se esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla
 * hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente
 * due elementi della tripola sono fra loro uguali*/
/*funzione che calcola se un intero è compreso tra 10 e 20*/
 int tra10e20(int c){
	 int risultato;
	 if(c>=10 && c<=20)  //****** BASTAVA SCRIVERE return (c>=10 && c<=20);
		 risultato=1;
	 else
		 risultato=0;
	return risultato;
 }

 int ugualiCompresi(int sequenza[], int lunghezza){
	 int esiste=0; //variabile esistenza
	 int i=0; //variabile contatore
	 while(i<lunghezza-2 && !esiste){
		if(((tra10e20(sequenza[i]+sequenza[i+1])==1)
		|| (tra10e20(sequenza[i]+sequenza[i+2])==1)
		|| (tra10e20(sequenza[i+1]+sequenza[i+2])==1)) &&
		((sequenza[i]==sequenza[i+1] && sequenza[i+2]!=sequenza[i])
		|| (sequenza[i]==sequenza[i+2]&& sequenza[i+1]!=sequenza[i]) ||
		(sequenza[i+1]==sequenza[i+2] && sequenza[i]!=sequenza[i+1])))
			esiste=1;
		else
			i++;
	 }
	 return esiste;
}

 /*funzione principale*/
 int main(){
	 int risultato; // variabile attesa 1 o 0
	 int l; //lunghezza array
	 int i=0; //variabile contatore
	 printf("caro utente sono una funzione che data una sequenza di interi e la sua lunghezza verifica ");
	 printf("se esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla ");
	 printf("hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente");
	 printf("due elementi della tripla sono fra loro uguali\n");
	 /*INPUT*/
	 printf("caro utente quanti elementi ha la tripla?\n");
	 scanf("%d",&l);
	 int interi[l]; //dichiarazione array
	 printf("caro utente digiti gli elementi dell'array\n");
	 for(i=0;i<l;i++){
		 printf("introduca un intero");
		 scanf("%d",&interi[i]);
	 }
	 /*OUTPUT*/
	 risultato=ugualiCompresi(interi,l);
	 if(risultato==1){
		printf("esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla ");
		printf("hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente ");
		printf("due elementi della tripla sono fra loro uguali\n");
	 }
	 else{
		printf("non esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla ");
		printf("hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente ");
		printf("due elementi della tripla sono fra loro uguali\n");

	 }


 }