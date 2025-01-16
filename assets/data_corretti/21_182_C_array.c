/* SPECIFICA (max 1.5):....0  //******* MANCANTE
   TIPO PROBLEMA (max 1):..0  //******* MANCANTE
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2.5):.2.1
   TOTALE..................2.1
*/


#include <stdio.h>

int compresiMultipli3(int vt[], int ll){
	int j;
	int f = 1;      //****** LA IMPOSTI COME VERIFCA UNIVERSALE, MENTRE E' ESISTENZIALE -2
	//***** j NON E' INIZIALIZZATO -1
	int v1 = ((vt[j]<=-10) && (vt[j] <= 10));           //***** (vt[j]>=-10)  -0.5
	int v2 = ((vt[j+1]<= -10) && (vt[j+1] <= 10));
	int v3 = ((vt[j+2]<= -10) && (vt[j+2] <= 10));   //***** DOVEVI METTERE LE TRE ASSEGNAZINI ALL'INTERNO DEL FOR! -1


	for(j=0;j<ll-3;j++){   //********** PERDI L'ULTIMA TRIPLA -1
		if(((v1) && (v2)) || ((v1) && (v3))
		|| ((v2) && (v3))){
		if(!((vt[j]%3==0) && (vt[j+1]%3==0) || (vt[j]%3==0) && (vt[j+2]%3==0) || (vt[j+1]%3==0) && (vt[j+2]%3==0))){
		//****** DEVI SPECIFICARE CHE IL TERZO NON SIA UN MULTIPLO DI TRE -1.5
			f = 0;
		}
		}
		}
	return f;
	}

int main()
{
	int l,i;
	printf("Insercisi la lunghezza dell array\n");
	scanf("%d",&l);
	int v[l];
	for(i = 0; i<l; i++){
		printf("inserisci il numero %d: ",i+1);
		scanf("%d",&v[i]);
		} //******** INDENTATO MALE -0.2
		if(compresiMultipli3(v,l))
			printf("esiste una tiripla di interi vera");
			else  //******** OUTPUT POVERO -0.2
				printf("non esiste un tripla di interi vera");


}

