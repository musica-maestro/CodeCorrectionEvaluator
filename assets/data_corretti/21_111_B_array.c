/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.3
*/
#include <stdio.h>
/*INPUT : una sequenza di interi array[] e la sua lunghezza l;
 * Pre - condizione : l deve eseere la lungezza esatta di array[];
 * OUTPUT : variabile booleana c;
 * Post -Condizione : c vale 1 se in ogni tripla nella sequenza sono presenti esattamente 2 elementi maggiori o uguali a 5 e almeno due elementi pari;
 * */                //******** POST-CONDIZIONE NON COMPLETA (0, ALTRIMENTI) -0.2
 //Verifica Universale
/*Funzione che verifica se ogni tripla di elementi contiene esattamente due elementi maggiori o uguali a 5 ed almeno
due elementi pari
 * */
int maggiori5Pari(int array[],int l){
	int i;  //vaiabile contatore
	int c=1; //variabile boolena inizzializzata a vero
	//itero la sequenza tranne gli ultimi 2 elementi e se c diventa falsa esci dal ciclo
	for(i=0;i<=l-3&&c!=0;i++){
		//se non ci sono elementi consecutivi che contengono esattamente 2 elementi maggiori o uguali a 5 imposta c a o
		if(!((array[i]>=5&&array[i+1]>=5)
		||(array[i+1]>=5&&array[i+2]>=5)
		||(array[i+2]>=5&&array[i]>=5))||(array[i+1]>=5&&array[i+2]>=5&&array[i]>=5)){
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			c=0;
		}//imposta c a 0 anche se non ci sono minimo due elementi pari
			else if(!((array[i]%2==0 && array[i+1]%2==0)
			||(array[i+1]%2==0 &&array[i+2]%2==0)
			||(array[i+2]%2==0&&array[i]%2==0)
			||(array[i]%2==0&&array[i+1]%2==0&&array[i+2]%2==0))){
				//******* L'ULTIMA CONDIZIONE NON SERVE
				c=0;
			}

	}
	return c;
}
int main()
{
	int lunghezza;//variabile lunghezza
	int i;//variabile contatore
	int risultato;//varaibile contentente output
printf("Ciao utente quanto %c lunga la tua sequenza?\n",138);
//prendo le iformazioni emesse dall'utente e le memorizzo in lunghezza
scanf("%d",&lunghezza);
//inizzializzo l'array sequenza
int sequenza[lunghezza];
//inserisco un intero per ogni indice dell array
for(i=0;i<lunghezza;i++){
	printf("Introduci l'intero all'indice %d\n",i);
	scanf("%d",&sequenza[i]);
}
//memorizzo dentro rislutato l'output della funzione maggiori5Pari();
risultato=maggiori5Pari(sequenza,lunghezza);
if(risultato){
	printf("La tua sequenza contiene esattemente due elementi maggiori o uguali a 5 ed almeno due elementi pari!!");

}
else{
	printf("La tua sequenza NON contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari!!");
}
}
