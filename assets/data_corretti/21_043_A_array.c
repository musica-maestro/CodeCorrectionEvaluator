/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE..................9.9
*/

/*funzione che verifica se esiste una tripla di elementi consecutivi tale che alemeno due elementi della tripla hanno una somma copresa tra 10 e 20 estremi inclusi
 * ed esattamente due elementi della tripla sono fra loro uguali*/
 /*SPECIFICA
  * input: una sequenza di interi s e la sua lunghezza l
  * pre-condizione: l>=3                  //******* potrbbe essere anche >=0
  * output: un valore booleano 'esiste'
  * post-condizione: verifica se esiste una tripla di elementi consecutivo dove almenno due elementi hanno somma copresa tra 10 e 20 ed ci sono esattamente due interi uguali
  * tipo di problema: verifica esistenziale*/

  //******** POST-CONDIZIONE NON COMPLETA -0.3
#include <stdio.h>

/*funzione che verifica se esiste una tripla di elementi consecutivo dove almenno due elementi hanno somma copresa tra 10 e 20 ed ci sono esattamente due interi uguali*/
int ugualiCompresi(int array[], int n){
	/* pre: n lunghezza dell'array*/
	int i=0;                                  //variabile contatore
	int risultato=0;                        //variabile esistenziale
	while(i<n-2 && !risultato){             //scorri l'array finchè non è finito e risultao uguale 1
		if((array[i]==array[i+1])&&(array[i]==array[i+2]))   //la tripla è composta da tre elementi uguali?
			i++;                                              //passa alssuccessivo
		else{
			if((array[i]==array[i+1])||(array[i]==array[i+2])||(array[i+1]==array[i+2])){                   //ci sono almeno due elemendi uguali?
				if(((array[i]+array[i+1]>=10)&&(array[i]+array[i+1]<=20))||((array[i]+array[i+2]>=10)&&(array[i]+array[i+2]<=20))||((array[i]+array[i+2]>=10)&&(array[i]+array[i+2]<=20)))      // la somma di due elementi è compresa tra 10 20
					risultato=1;                                 // se è vero metti risultato uguale 1
				else
					i++;
			}                                  //incrementa di 1
			else
				i++;                   // incrementa di 1
			}
//******** CONDIZIONE COMPLICATA, MA CORRETTA -0.5
	}
	return risultato;                    //restituisci alla main il valore di risultato
}

/*funzione principale*/
int main(){
	/*input*/
	int lunghezza;
	printf("Inserisci la lunghezza dell'array ");
	scanf("%d", &lunghezza);
	int array[lunghezza];
	int i;
	/*creazione dell'array da tastiera*/
	for(i=0;i<=lunghezza-1;i++){
		printf("Inserisci un elemento dell'array ");
		scanf("%d", &array[i]);
	}
	/*output*/
	if(ugualiCompresi(array, lunghezza))
		printf("Nella sequenza esiste una tripla di elementi consecutivi tale che almeno due elementi hanno la somma compresa tra 10 e 20 ed essattamente due elementi della tripla sono uguali.\n");
	else
		printf("Nella sequenza non esiste una tripla di elementi consecutivi tale che almeno due elementi hanno la somma compresa tra 10 e 20 ed essattamente due elementi della tripla sono uguali.\n");
}
//******** I/O UN PO' POVERO -0.3