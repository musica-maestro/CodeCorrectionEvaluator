/* SPECIFICA (max 1.5):....0 //***** MANCANTE
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................6.5
*/
#include <stdio.h>

/*Funzione UgualiCompresi: la funzione restituisce 1 se nella sequenza esiste
 * una tripla di elementi consecutivi dove 2 elementi sono uguali tra loro e
 * almeno 2 elementi hanno somma compresa tra 10 e 20. Altrimenti 0.
 * Problema di esistenza*/ //*********VERIFICA ESISTENZIALE
int UgualiCompresi(int num[],int lun){
	//input:
	int ugualicompresi=0; //variabile di esistenza inizializzata a 0
	int somma1, somma2, somma3, somma4;
	for(int i=0; i<lun-2; i++){   //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if(((num[i]==num[i+1])&&(num[i]!=num[i+2]))||((num[i+1]==num[i+2])&&(num[i]!=num[i+2]))){
			somma1=num[i]+num[i+1];
			somma2=num[i]+num[i+2];
			somma3=num[i+1]+num[i+2];
			somma4=somma3+num[i]; //******** A CHE SERVE QUESTA? I COMMENTI!!! -0.5
			if((somma1>=10&&somma1<=20)||(somma2>=10&&somma2<=20)||(somma3>=10&&somma3<=20)||(somma4>=10&&somma4<=20)){
				ugualicompresi=1;                                                        //****** QUESTA NON SERVE -0.5
				}
			}
		}
	return ugualicompresi;
	}
//Funzione principale
int main(){
	//Pre-condizioni: elementi interi
	int lunghezza; // Lunghezza dell'Array
	printf("Salve sono un programma che legge una sequenza di numeri.\n");
	printf("Verifico se nella sequenza degli elementi %c presente \nuna tripla con due elementi uguali",138);
	printf("e la somma di almeno 2 \nelementi %c compresa tra 10 e 20 inclusi\n\n",138);
	printf("Quanti interi ha la sequenza? ");
	scanf("%d", lunghezza); //******* &lunghezza -0.5
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisca un numero: ");
		scanf("%d", sequenza[i]);  //******* &sequenza[i] -0.5
		}
		/*output: esistenza o meno di una tripla di elementi consecutivi dove 2 elementi sono uguali tra loro e
		 * almeno 2 elementi hanno somma compresa tra 10 e 20. Altrimenti 0.*/
	if(UgualiCompresi(sequenza, lunghezza)==1){
		printf("Nella sequenza esiste una tripla di elementi consecutivi dove 2 elementi sono uguali tra loro e almeno 2 elementi hanno somma compresa tra 10 e 20 ");
		}
	else{
		printf("Nella sequenza non esiste una tripla di elementi consecutivi dove 2 elementi sono uguali tra loro e almeno 2 elementi hanno somma compresa tra 10 e 20 ");
		}
}
