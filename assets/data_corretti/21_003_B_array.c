/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................7,2
*/
#include <stdio.h>

/*SPECIFICA
 * INPUT: una sequenza numerica di lunghezza l //******** I TIPI DEGLI ELEMENTI DELL'ARRAY NON SONO CHIARI -0.3
 * PRE-CONDIZIONE: lunghezza l>0
 * OUTPUT: valore 'tripla'
 * POST-CONDIZIONE: 'tripla' restituisce1 se ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uaguali a 5 e almeno due pari, altrimenti 0
 * TIPO DI PROBLEMA: verifa universale
 * */


//FUNZIONE PRINCIPALE CHE RESTITUISCE 1 SE OGNI TRIPLA DI ELEMENTI CONSECUTIVE CONTIENE ESATTAMENTE DUE ELEMENTI MAGGIORI O UGAULI A 5
// ED ALMENO DUE ELEMENTI PARI, RESTITUISCE 0 ALTRIMENTI
int maggiori5Pari(int interi[], int lunghezza){
	int i=0;   // CONTATORE SEQUENZA
	int tripla;
	int uguali;
	int pari;
	tripla=0;  //******** INIZIALIZZAZIONE SBAGLIATA -1
	while(i<lunghezza-2 && !tripla){ //****** && tripla	-1
		if(((interi[i]>=5) && (interi[i+1]>=5) && (interi[i+2]<5)) ||               //CONDIZIONE PER LA QUALE IN UNA TRIPLA CI SIANO
		    ((interi[i+1]>=5) && (interi[i+2]>=5) && (interi[i]<5)) ||             //ESATTAMENTE DUE NUMERI MAGGIORI O UGUALI A 5
			 ((interi[i]>=5) && (interi[i+2]) && (interi[i+1])<5)){
				 uguali=1;

				 if(((interi[i]%2==0) && (interi[i+1]%2==0) && (interi[i+2]%2!=0))||
				   ((interi[i+1]%2==0) && (interi[i+2]%2==0) && (interi[i]%2!=0)) ||  //CONDIZIONI PER LA QUALE NELLA TRIPLA CI SIANO
				   ((interi[i]%2==0) && (interi[i+2]%2==0) && (interi[i+1]%2!=0))||   // ALMENO DUE NUMERI PARI
				   ((interi[i]%2==0) && (interi[i+1]%2==0) && (interi[i+2]%2==0))){
					//******** POTEVI FARLA PIU' SEMPLICE
					   pari=1;

					   if((uguali=1) && (pari=1))
						   tripla=1; //****** SE tripla==1 QUANDO RIENTRI NEL WHILE LA COND. NON E' PIU' VERIFICATA -1
				   }
//******* HAI IMPLEMENTATO UNA VERIFICA EISTENZIALE, NON UNIVERSALE
			 }

		i++;     //AUMENT LA POSIZIONE DI I ALL'INTERNO DELLA SEQUENZA PARTE DA 0
	}
	return tripla;       // MI RITORNA 1 o 0 RISPETTO ALLE CONDIZIONI DATE
}

int main()
{    //INPUT
	int lunghezza;
	printf("quanti numeri vuoi inserire nella sequenza\n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("quali numeri vuoi inserire?\n");       //RIEMPIO LA SEQUENZA
		scanf("%d", &sequenza[i]);

	}
	//OUTPUT
	int tripla;
	tripla=maggiori5Pari(sequenza, lunghezza);
	if(tripla)
		printf("tutte le triple inserite rispettano le condizioni date\n");
		else
			printf("non tutte le triple rispettano le condizioni date\n");
//******** OUTPUT MOLTO POVERO -0.5
}
