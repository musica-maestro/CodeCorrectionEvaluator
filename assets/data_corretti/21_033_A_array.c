/* SPECIFICA (max 1.5):....0
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.1
   TOTALE..................4
*/
#include <stdio.h>
#include <stdlib.h>
/* SPECIFICA
Input: array di grandezza e valori scelti dall'utente //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
Output: valore intero o 1 o 0 per la verifica delle condizioni  //******** LA PRE-CONDIZIONE MANCA -0.5
																//******** LA POST-CONDIZIONE MANCA -0.5
TIPO DI PROBLEMA:Inserito un vettore con elementi variabili, verificare se esiste una tripla di valori
del vettore con esattamente due valori uguali e la somma dei valori della tripla compreso tra 10 e 20 */
//******** NO: DOVEVI DIRE CHE TIPO DI VERIFICA ERA (ESISTENZIALE IN QUESTO CASO) -1
 int UgualiCompresi(int Vettore[], int len);

int main(){
	int i,Verifica,M;    //******** I NOMI DELLE VARIABILI DI SOLITO INIZIANO CON LA LETTERA MINUSCOLA
	printf("inserire quanti valori si vuole inserire: ");
	scanf("%d", & M);
	int V[M-1];
	printf("\nInserire i valori dell'array: ");
	for(i=0;i<M-1;i++){  //******** NON LEGGI L'ULTIMA COMPONENTE: DOVEVA ESSERE i<M -1
		scanf("%d\n", & V[i]);
		}
		Verifica = UgualiCompresi(V, M);
		if(Verifica==1){
			printf("E' presente una tripla che soddisfa i requisiti");
			}         													 //******** I/O MOLTO POVERO -0.5
		else{
			printf("Non e' presente una tripla di elementi che soddisfa i requisiti");
			}
			system("pause");
			return 0;
	}
int UgualiCompresi(int Vettore[], int len){

	int j=0,verifica=0;
	while(j<len-2){  //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if(Vettore[j]==Vettore[j+1] || Vettore[j+1]==Vettore[j+2] || Vettore[j+2]==Vettore[j]){
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			if(Vettore[j]+Vettore[j+1]>=10 && Vettore[j]+Vettore[j+1]<=20){
				verifica=1;
				break;   //******** BREAK NON PERVENUTO! -0.5
				}
			else if(Vettore[j+2]+Vettore[j+1]>=10 && Vettore[j+2]+Vettore[j+1]<=20){
				verifica=1;
				break;  //******** BREAK NON PERVENUTO!
				}
			else if(Vettore[j]+Vettore[j+2]>=10 && Vettore[j]+Vettore[j+2]<=20){
				verifica=1;
				break;  //******** BREAK NON PERVENUTO!
				}
			}
			else
				j++;
		}
		return verifica;
}

