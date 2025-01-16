/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................7.2
*/
#include <stdio.h>

/*SPECIFICA
*Input: un array a e la sua lunghezza l //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY E DELLA LUNGHEZZA -0.6
*Pre-condizione: l è la lunghezza di a
*Output: valore di verità(0 o 1) della variabile verifica. viene stampato un messaggio che comunica se esiste una tripla di elementi consecutivi tale che la somma di due elementi è compresa tra 10 e 20 e due elementi sono uguali fra loro
*Post-condizione: verifica vale 0 o 1                     //******** QUESTO FA PARTE DELLA OST-CONDIZIONE -0.5
*Tipo di problema: verifica esistenziale*/
int ugualiCompresi(int a[], int l){
	int verifica=0;
	int i=0;
	while(i<l-2){ //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
	if((a[i]+a[i+1]>=10 && a[i]+a[i+1]<=20)
	||(a[i]+a[i+2]>=10 && a[i]+a[i+2]<=20)
	||(a[i+1]+a[i+2]>=10 && a[i+1]+a[i+2]<=20 ) &&
	((a[i]==a[i+1]) || (a[i]==a[i+2]) || (a[i+1]==a[i+2])))
	//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
	//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		verifica=1;
			else
				i++;
		}
		return verifica;
	}

	int main(){
		int length;
		int y;
		printf("programma che restituisce 1 se esiste almeno una tripla di interi in cui due elementi hanno somma compresa tra 10 e 20\n");
		printf("quani valori vuoi inserire nell'array?/n");
		scanf("%d", &length);
		int sequenza[length];
	for(int i=0;i<length;i++){
			printf("introduci un intero");
			scanf("%d",&sequenza[i]);
		}

		if(ugualiCompresi(sequenza,length))
		printf("esiste almeno una tripla di elementi tale che la somma di due elementi %c compresa tra 10 e 20", 138);

		else
			printf("non esiste una tripla di elementi tale che la somma di due elementi %c compresa tra 10 e 20", 138);

		//******** I/O UN PO' POVERO -0.2
	}


