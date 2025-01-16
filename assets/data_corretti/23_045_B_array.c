/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.5
*/
/*
SPECIFICA
*INPUT:UNA SEQUENZA DI INTERI(SEQUENZA[]) E LA SUA LUNGHEZZA
*PRE-CONDIZIONE:L>=3
*OUTPUT:UNA BOOLEAN VERIFICATO
*POST-CONDIZIONE:VERIFICATO VALE 1 SE OGNI TRIPLA DELLA SEQUENZA CONTIENE ESATTAMENTE 2 POSITIVI; 0 ALTRIMENTI
*TIPO PROBLEMA:VERIFICA UNIVERSALE*/









#include<stdio.h>
int duePositivi(int sequenza[],int l){  //f che legge tre interi e restituisce 1 se ce ne sono esattamente 2 maggiori di 0, 0 altrimenti
	int i;
	i=0;
	int verifica=1;//inizializzo a 1 in quanto verifica universale
	while(i<=l-2&&verifica){
		if(!(((sequenza[i]>0&&sequenza[i+1]>0)&&(sequenza[i]<=0))||((sequenza[i]>0&&sequenza[i+2]>0)&&(sequenza[i+1]<=0))||((sequenza[i+2]>0&&sequenza[i+1]>0)&&(sequenza[i]<=0))))
			verifica=0;
		else
			i++;
	}
	return verifica;
}
int main(){//funzione main che chiede all'utente quanti interi vuole inserire e li memorizza per poi invocare la funzione duePositivi
	int l;
	int i=0;
	printf("quanti interi vuoi inserire?\n");
	scanf("%d",&l);
	int sequenza[l];
	for(i=0;i<l;i++){
		printf("inserisci un intero.\n");
	scanf("%d",&sequenza[i]);
	}

	if(duePositivi(sequenza,l))
		printf("verificato.\n");//************ OUTPUT NON ESPLICATIVO -0.5

	else
		printf("non verificato");

}
