/* SPECIFICA (max 1):......0  //******** MANCANTE
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7
*/
/*Il seguente programma calcola se in un insieme di valori interi all'interno di un array
dato in input dall'utente, ogni terna di valori consecutivi contiene almeno un multiplo
degli altri due numeri. Tramite una funzione esterna al main viene effettuato il check su
tutti i valori dell'array a coppie di tre e viene restituito un valore di verita'
corrispondente ad 1 in caso di esito positivo, o un valore 0 in caso di esito negativo */

#include <stdio.h>

//funzione di calcolo per le terne sull'array
int multipli(int arr[],int len){
	int i,j=0;   //variabili contatore
	int TrueFalse;      //variabile che restituisce il valore 'vero' o 'falso'
	//ciclo di check sulle terne di interi consecutive
	for(i=0;i<len;i++){  //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<l-2 -1
		if (arr[i]%arr[i+1]==0 || arr[i]%arr[i+2]==0 || arr[i+1]%arr[i]==0 || arr[i+1]%arr[i+2]==0 || arr[i+2]%arr[i]==0 || arr[i]%arr[i+1]==0 ){
			j++;
		}
	}
	//se il contatore j si è implementato ad ogni istanza positiva del check,
	//allora assegna a TrueFalse il valore 1 che sta per 'vero'
	if (j==len){
		TrueFalse = 1;
	}
	//altrimenti assegna a TrueFalse 0 che sta per 'falso'
	else {
		TrueFalse = 0;
	}
	return TrueFalse; //****** OK, hai trattato la verifica univarsale come problema di conteggio
}

int main(){
	int i;      //variabile contatore
	int len;    //lunghezza array
	int TrueFalse;       //variabile di veridicità //**** di verità

	printf("Programma che prende in input un array di interi e restituisce un valore positivo\n");
	printf("se in tutte le terne di elementi adiacenti vi e' almeno un multiplo degli altri due elementi\n");
	printf("inserisci la lunghezza dell'array : ");
	//l'utente inserisce la lunghezza della sequenza di interi
	scanf("%d",&len);
	int arr[len];
	printf("ora inserisci i valori : ");
	//ciclo for per l'inserimento dei valori nella sequenza
	for(i=0;i<len;i++){
		scanf("%d",&arr[i]);
	}
	//stampa valori a schermo
	for(i=0;i<len;i++){
		printf("valore [%d]: %d\n",i,arr[i]);
	}
	//invoco la funzione 'multipli' e restituisco un messaggio sulla base del risultato
	TrueFalse = multipli(arr,len);
	if (TrueFalse==1){
		printf("Tutte le terne contengono alemno un multiplo\n");
	}
	if (TrueFalse==0){
		printf("non tutte le terne contengono almeno un multiplo\n");
	}
	return 0;
}