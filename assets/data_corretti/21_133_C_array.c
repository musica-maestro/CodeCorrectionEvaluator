/* SPECIFICA (max 1.5):....0
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......4.1
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................6.4
*/
#include <stdio.h>
/*SPECIFICA
 * Input: una sequenza s e una lunghezza s  //*** TUTTE E DUE CON LO STESSO NOME?
          //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * Pre-condizione: verificare che esista una tripla contenente due valori tra -10 e 10 e due elementi multipli di 3
 //***** QUESTA NON E' LA PRECONDIZIONE -0.5
 * Output: tripla=1 //***** SOLO TRIPLA. DEVI SPECIFICARE IL TIPO -0.3
 * Post-condizione: condizione verificata o meno*/  //****** LA POST CONDIZIONE NON DICE NULLA -0.5

/* problema: verifica universale*/ //******** NO, ESISTENZIALE -1
int compresiMultipli3(int interi[], int len){
	int i, tripla;
	tripla=0;
	i=0;
	while(i<len&&!tripla){ //**** len-2  -1
	if((interi[i]%3==0&&interi[i+1]%3==0||interi[i+1]%3==0&& //*** HAI SCRITTO 2 VOLTE interi[i+1]%3==0 -0.2
	interi[i+2]%3==0||interi[i]%3==0&&interi[i+2]%3==0)&&    //*** HAI SCRITTO 2 VOLTE interi[i+2]%3==0 -0.2
	//****** LA CONDIZIONE SUI MULTIPLI DI 3 NON VA BENE -1
	(interi[i]>-10&&interi[i]<10)&&(interi[i+1]>-10&&interi[i+1]<10)|| //***** ANCHE UGUALE -0.5
	(interi[i+2]>-10&&interi[i+2]<10)&&(interi[i+1]>-10&&interi[i+1]<10)||
	(interi[i]>-10&&interi[i]<10)&&(interi[i+2]>-10&&interi[i+2]<10))
		tripla=1;
	else
		i++;
	}
return tripla;
}

int main(){
	int len;
	printf("Sono un programma che legge una sequenza di interi e determina se ");
	printf("esiste almeno una tripla di elementi contenente 2 valori compresi fra -10 e 10 ");
	printf("e due di questi numeri devono essere multipli di 3\n");
	printf("Quanti interi hai intenzione di introdurre?   ");
	scanf("%d",&len);
	int sequenza[len];
	for(int i=0; i<len; i++){
		printf("Inserisci un intero:  ");
		scanf("%d",&sequenza[i]);
		}
	if(compresiMultipli3(sequenza, len))
		printf("Esistono\n"); //***** OUTPUT UN  PO' POVERO -0.2
	else
		printf("Non esistono\n");
}
