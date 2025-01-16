/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.5
*/
# include <stdio.h>
/* Specifica del problema:
* Input: una sequenza di interi e la relativa lunghezza ;
* Pre-condizioni:  la sequenza deve essere composta di soli interi, la lunghezza della sequenza deve essere un intero;
* Output: valore intero(1/0) ;
* Post-condizioni: il valore restituito deve essere intero, e deve corrispondere ad 1 in caso l'istanza del problema sia positiva o a 0 se negativa .
* Tipo di problema : verifica universale;*/
int duePositivi(int v[], int n){
	int i=0;       			//dichiaro le variabili ( i=indice elemento sequenza, duePos=varaibile di verifica, p = contatore positivi)
	int duePos =1;
	int p=0;
	if(n<=2)// mi domando se la lunghezza della sequenza (n) sia minore o uguale a due, in tal caso non ha senso controllare dato che non esistono triple
		duePos=0;
	else{
		while(i<n-2&&duePos){			// in caso contrario scorro gli elementi fi a terminare la sequenza e finchè la variabile di verifica è vera
			for(int j=i;j<=i+2;j++){// conto i positivi di una terna
				if(v[j]>0)
					p++;
			}
			if(p!=2)// mi chiedo se non siano esattamente uguali a due, in tal caso pongo la variabile di verifica pari a 0
				duePos=0;
			else {// se invece p==2 allora azzero il contatore per verificare la prossima terna e incrementi l'indice di 1
				p=0;
				i++;
			}
		}
	}
	return duePos;
}
 int main(int argc, char const *argv[])
{
	int n;
	int v[n];  //******** l'array lo devi dichiarare solo dopo aver acquisito la lunghezza -0.5
	printf("inserisci la lunghezza della sequenza:\n");// chiedo all'utente di inserire la lunghezza dell'array
	scanf("%d",&n);
	for(int i=0;i<n;i++){// riempio l'array
		printf("inserisci il %d elemento: \n", i+1);
		scanf("%d",&v[i]);
	}
	if(duePositivi(v,n))//verifico se è vero che ogni tripla della sequenza contiene esattamente 2 positivi
		printf("in tutte le triple di elementi adiacenti  della sequenza ci sono esattamente due positivi\n");
	else
		printf("non in tutte le triple di elementi adiacenti  della sequenza ci sono esattamente due positivi\n");
	return 0;
}