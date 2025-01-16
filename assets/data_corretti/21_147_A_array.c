/* SPECIFICA (max 1.5):....0
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................7
*/
#include <stdio.h>
/* INPUT: Array s  e Lunghezza l //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * PRECONDIZIONE: La lunghezza della sequenza deve essere >=3 ed l è la lunghezza di s
 * OUTPUT: una tripla di elementi consecutivi //******* NO, UN VALORE BOOLEANO -0.5
 * PRECONDIZIONE: la cui somma è compresa tra 10 e 20 e due elementi fra loro uguali //****** SAREBBE POST-CONDIZIONE, MA NON VA BENE -0.4
 * TIPO DI PROBLEMA:  Problemi di verifica esistenziale
    */

int UgualiCompresi(int *c, int lunghezza){
					int i;
					int tripla = 0;
					i = 0;
					while(i<lunghezza-2 && !tripla)
						if(c[i]==c[i+1] && c[i]!=c[i+2]){
							if(c[i]+c[i+2]>=10 && c[i]+c[i+2]<=20)
						 //****** LA CONDIZINE E' GIUSTA MA DOVEVI PROVARE TUTTE LE COMBINAZIONI -2
						tripla = 1;
							else
								i++;
						}
					return tripla;

}

int main() {
		printf("Caro utente ti presentiamo con un problema che verifica se esiste una tripla di elementi ");
		printf("consecutivi\n");
		int Lun;  //****** I NOMI DELLE VARIABILI SI SCRIVONO CON LA PRIMA LETTERA MINUSCOLA
		printf("Quanto deve essere lungo la tua sequenza caro utente\n");
		scanf("%d",&Lun);
		int sequenza[Lun];
		for(int i=0;i<Lun;i++){
			printf("Inserire gentilmente gli interi della sequenza: \n");
			scanf("%d",&sequenza[i]);
		}


		if(UgualiCompresi(sequenza, Lun))
			printf("Bravo e' giusto\n"); //*** DEVI SPIEGARE COSA E' GIUSTO! -0.5
			else
				printf("Non ci siamo\n");


	}