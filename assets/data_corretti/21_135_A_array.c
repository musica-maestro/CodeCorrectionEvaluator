
/* SPECIFICA (max 1.5):....0.1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2.5):.0
   TOTALE..................1.1
*/
// somma di 2 n interi deve fare almeno tra 10-20 e max 2 elementi sono uguali
/*
  tipo di problema = problema di verifica esistenziale, conteggio //****** LA PRIMA!
  descrizione del problema: input= numero di interi nell'array  //******** MANCA LA SEQUENZA E IL TIPO DI ELEMENTI  -0.4
   * lettura degli interi
   * output= 1 se almeno 2 interi sommati hanno un valore compreso tra 10-20 && almeno 2 di loro sono uguali
   *         0 se non rispettano le due condizioni
   */                                          //****** MANCANO PRE E POST CONDIZIONI -1
   #include <stdio.h>
   int main           //******** ERA RICHIESTO DI SCRIVERE UNA FUNZIONE
   {                  //******** ERA RICHISTO DI ACQUISIRE DA INPUT UNA SEQUENZA DI INTERI, NON DI DECIDERLA PRIMA DELLA COMPILAZIONE

	   int sequenza [5]=(7,7,3,2,1);

	 printf("ecco la sequenza di interi:");

	 printf("\n\n %d %d %d %d %d", &int sequenza[0], &int sequenza[1], &int sequenza[2], &int sequenza[3], &int sequenza[4]);

	 if{  //******** NON DEVI DICHIARARE IL TIPO OGNI VOLTA CHE USI UNA VARIABILE
	 (int sequenza[0]+int sequenza[1] >= 10 && int sequenza[0]+int sequenza[1]<=20)
		 printf("\n\n1 la prima condizione della sequenza è accettata\n");

		 if(int sequenza[1]+int sequenza[2] >= 10 && int sequenza[1]+int sequenza[2]<=20)
		 printf("\n\n1 la prima condizione della sequenza è accettata\n");

		 if(int sequenza[2]+int sequenza[3] >= 10 && int sequenza[2]+int sequenza[3]<=20)
		 printf("\n\n1 la prima condizione della sequenza è accettata\n");

		 if(int sequenza[3]+int sequenza[4] >= 10 && int sequenza[3]+int sequenza[4]<=20)
		 printf("\n\n1 la prima condizione della sequenza è accettata\n");
	 }
      else {
		  printf("\n\nla prima condizione della sequenza (e di conseguenza anche la sequenza stessa) non è accettata\n");
	  }

	 if {
	 (int sequenza[0]==int sequenza[1])
		 printf("la seconda condizione della sequenza è accettata");

		if (int sequenza[1]==int sequenza[2])
		 printf("la seconda condizione della sequenza è accettata");

		if (int sequenza[2]==int sequenza[3])
		 printf("la seconda condizione della sequenza è accettata");

		if (int sequenza[3]==int sequenza[4])
		 printf("la seconda condizione della sequenza è accettata");
	 }
	 else {
		 printf("\n\n la seconda condizione della sequenza (e di conseguenza anche la sequenza stessa) non è accettata");
	 }

	}

	//********** TUTTO DA RIVEDERE






