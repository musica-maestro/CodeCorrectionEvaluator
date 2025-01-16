/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.6
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................5.3
*/
/*SPECIFICA
 *INPUT: elementi dell'array e lunghezza dell'array //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 *Pre-condizione: l è la lunghezza della sequenza
 *OUTPUT: un intero 'compresi'
 *Post-condizione: la funzione restituisce 1 se la sequenza è tale che almeno due elementi della tripla
 *hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali tra loro
 *PROBLEMA DI VERIFICA ESISTENZIALE*/     //******** POST-CONDIZIONE NON COMPLETA (0, altrimenti) -0.2




#include <stdio.h>


/*funzione che riceve come parametri un array di interi e un intero che rappresenta la lunghezza dell'array*/
	int ugualiCompresi (int array[], int l){
	int ugualisomma=0;  //variabile di esistenza

	int i;      //variabile contatore
	/*verifica fintanto che non termina la sequenza e vale ugualisomma*/
	while(i<l-2 &&!ugualisomma){

		/*la sequenza contiene almeno una tripla richiesta?*/
		if((array[i]+array[i+1]>=10&&<=20) || (array[i]+array[i+2]>=10&&<=20) || (array[i+1]+array[i+2]>=10&&<=20))
		//********** QUESTO CALCOLA ALTRO! -1.5
	    if(array[i]==array[i+1] || array[i]==array[i+2] || array[i+1]==array[i+2])
	    //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		somma=1;
		uguali=1;  //**** SOMMA E UGUALI NON SONO DICHIARATE E NON SERVONO -1
		else
		i++   //******* MANCA ; -0.2
		//******** MANCA LA CHIUSURA DEL WHILE -0.2
	return ugualisomma;





/*FUNZIONE PRINCIPALE*/
int main(){
	int l;   //lunghezza dell'array
	int ugualisomma;
	/*INPUT*/
	printf("Programma che verifica l'esistenza di una tripla all'interno della sequenza ");
	printf("tale che la tripla contenga due elementi con somma compresa tra 10 e 20 ");
	printf("e due elementi tra loro uguali\n");
	printf("Inserire la lunghezza dell'array\n");
	scanf("%d",&l);
	int array[l];
	/*CARICAMENTO DELL'ARRAY*/
	for(int i=0;i<l;i++){
		printf("Inserire gli elementi che compongono l'array\n");
		scanf("%d",&array[i]);
	}


	/*OUTPUT*/
	ugualisomma=ugualiCompresi(array, l);
	if(ugualisomma==1)
		printf("La sequenza inserita rispetta le condizioni\n");
		else
		printf("La sequenza inserita non rispetta le condizioni\n");

		return 0;  //******** OUTPUT MOLTO POVERO -0.5

}




}
