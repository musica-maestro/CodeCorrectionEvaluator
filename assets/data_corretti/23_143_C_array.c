/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............5.3
*/
/*SPECIFICA
*iNPUT: s interi e lung
*pRE-CONDIZIONE: una sequenza di s interi e di lunghezza lung e lung>=3 //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*oUTPUT:1 o 0
*pOST-cONDIZIONE:1 se ogni trpila di interi consecutivi adiacenti ha uno e un solo valore a due cifre, 0 se almeno una tripla di interi consecutivi non ha un intero a due cifre oppure ha piu di un intero a due cifre
*Tipo di Problema: Verifica Universale
*/


#include <stdio.h>




int dueUnaCifra(int seq[], int dim){
int i; //contatore
	for(i=0;i<dim-2;i++){ //comtrollo in ogni tripla se esiste un solo numero composto da due cifre
		if((seq[i]<=9 && seq[i+1]<=9 && seq[i+2]>9) ||
		   (seq[i]<=9 && seq[i+1]>9 && seq[i+2]<=9) ||
		   (seq[i]>9 && seq[i+1]<=9 && seq[i+2]<=9)){
			return 1; // restituisce l se la verifica universale è vera
		} //****** COSI' VERIFICHI SE CI SONO ESATTAMENTE DUE DI UNA CIFRA, NON ALMENO DUE -1.5
          //****** INOLTRE, RESTITUISCI IL VALORE CALCOLATO SULLA PRIMA TERNA, VISTO CHE CON IL
          //****** RETURN ESCI SUBITO DALL'ITERAZIONE. -2
		else
			return 0; // restituisce 0 se la verifica universale è falsa
}
}



int main()
{
	int i;
	int lung;
	int numeri[lung]; //******** L'ARRAY LO DEVI DICHIARARE SOLO DOPO AVER ACQUISITO LA LUNGHEZZA -0.5












	printf("Sono un programma che verifica se in tutte le triple di adiacenti esiste un numero a due cifre" );
	printf("Inserisci quanti interi vuoi mettere in una sequenza da verificare ");
	//input della lunghezza dell'array
	scanf("%d", &lung);



	for(i=0;i<lung; i++){
		printf("\ndammi un numero ");
		//input dei numeri dell'array
		scanf("%d", &numeri[i]);
	}
	//output
	if(dueUnaCifra(numeri, lung)){
		printf("La verifica e' positiva");  //************ OUTPUT NON ESPLICATIVO -0.5
	}
else
	printf("La verifica e' negativa non tutte le terne hanno un numero di due cifre");


}