/* SPECIFICA (max 1.5):....0  //********* MANCANTE
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.1
   TOTALE..................3.5
*/
#include <stdio.h>
#include <string.h>

//verifica esistenziale


//funzione che vede se il numero è compreso tra -10 e 10
int compreso (int valore)
{
		int risultato;
		if(valore>=-10 && valore<=10) //**** BASTAVA SCRIVERE return (valore>=-10 && valore<=10);
		{
			risultato=1;
		}
		else
		{
		risultato=0;
		}

		return risultato;
}



int compresiMultipli3 (int array[], int lunghezza)
{
		int esiste=0;
		int conteggioMultipli=0;
		int conteggioCompresi=0;
		int contatoregenerale=0;
		for(int i=0;i<lunghezza;i++)
        //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lunghezza-2 -1
		{
			int j=i;
				while(contatoregenerale<3)//******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
				{
					printf("%d\n", array[j]);
					printf("aaa\n");
						if(compreso(array[j]))
						{
								printf("compreso\n");

								conteggioCompresi++;
						}
						if(array[j]%3==0)
						{
							printf("multiplo\n");
								conteggioMultipli++;
						}
						j++;
						contatoregenerale++;
				}

				if(conteggioCompresi>=2 && conteggioMultipli>=2)
				{//********* conteggioMultipli DEVE ESSERE ESATTAMENTE UGUALE A 2 -1.5

					printf("conteggio compreso= %d\n", conteggioCompresi);
					printf("conteggio multipli= %d\n", conteggioMultipli);
					printf("%d\n", array[j]);
					esiste=1;
					printf("variebile esiste %d ", esiste);
					break;//******** BREAK NON PERVENUTO! -0.5
				}
				//******* ESTREMAMENTE MACCHINOSO -0.5

				contatoregenerale=0;
				conteggioCompresi=0;
				conteggioMultipli=0;
		}

	//	return esiste;
}


int main(int argc, char **argv)
{
	int x;
	printf("quanto voui lungo il vettore ?");
	scanf("%d",&x);
	int vett[x];

	for(int i=0;i<x;i++)
	{
			printf("inserisci il valore in posizione %d ",i);
			scanf("%d", &vett[i]);
	}

	compresiMultipli3(vett,x); //**** NON SERVE A NIENTE RICHIAMARLA COSI' LA DEVI METTERE NELLA
	                           //**** CONDIZIONE DELL'IF -1
	if(compresiMultipli3==1)
	{
			printf("verificato");

	}
	else
	{
			printf("non verificato");//******** OUTPUT MOLTO POVERO -0.5
	}
	return 0;
}
