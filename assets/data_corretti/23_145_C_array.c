/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............4.5
*/
/*SPECIFICA
 input: una sequenza di interi x
 pre-condizione:lung>=3   //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
 output:un valore booleano risultato
 post-condizione:la funzione restituisce 1 se è verificata altrimenti 0 //******* LA POST CONDIZIONE NON DICE NULLA -0.3
 Tipo di verifica: verifica universale */
 #include <stdio.h>
/*la funzione restituisce 1 se verificata altrimenti 0*/
int dueunacifra(int arr[],int lung){
int verifica=1;//dichiarazione variabile
/*verifica che nella sequenza ci siano due numeri composti da un cifra */
for (int i = 0; i < lung; ++i){ //**** INDICE FUORI DAI LIMITI -1
	if(arr[i]<=9 && arr[i+1]<=9 && arr[i+2]<=9 && arr[i-1]>=0 ||  //**** ESAMINI UNA QUADRUPLA?? -1
	 	arr[i]<=9 && arr[i+1]<=9 && arr[i+2]>=0 && arr[i-1]<=9  ||
	 	arr[i]<=9 && arr[i+1]>=0 && arr[i+2]<=9 && arr[i-1]<=9  ||
		 arr[i]>=0 && arr[i+1]<=9 && arr[i+2]<=9 && arr[i-1]<=9 ){
		 //******** CONDIZIONE SBAGLIATA -1.5
		return verifica;
	}else{
		return verifica=0;//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
	}
	}

}
/*funzione principale*/
int main(){
	int lung;
	printf("quanti numeri vuoi inserie:\n");
	scanf("%d", &lung);
	int arr[lung];
	printf("inserisci i numeri:\n");
	for (int i = 0; i < lung; ++i){
		scanf("%d", &arr[i]);
	}
	int risultato=dueunacifra(arr,lung);
	/*output*/
printf("1 se la condizione e' verificata altrimenti 0 : %d", risultato);
}  //************ OUTPUT NON DICE NULLA -1

