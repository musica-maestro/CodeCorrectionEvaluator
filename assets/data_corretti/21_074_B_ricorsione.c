/*
5pt minimo dispari:..3.5
1pt scrivi numeri:...0.8
2pt quanti numeri:...2
2pt leggi numeri:....1.8
TOTALE ..............8.1
*/
#include <stdio.h>

//--------------------funzione ricorsiva--------------------------
/*funzione per trovare il minimo di una tripla*/
int minimo (int a,int b,int c){
	int min;
	if(a<b){
		if(a<c){
			min=a;
		}else{
			min=c;
		}
	}else{
		if(b<c){
			min=b;
		}else{
			min=c;
		}
	}
	return min;
}

/*funzione ricorsiva per studiare la serie*/
int minimoDispar(int serie [],int lun){
	int ver=0;		//variabile di verifica
	/*passo base*/
	if(lun<=1){ //**** Passo base: se lunghezza=2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -0.5
		ver=1;
	/*passo ricorsivo*/
	}else{
		/*chiamata ricorsiva*/
		ver=(((minimo(serie [lun],serie [lun-1],serie [lun-2])%2==1)&&minimoDispar(serie,lun-1)));
	}         //**** serie[lun] non è un elemento dell'array -1
	/*restituzione del risultato*/
	return ver;
}
//----------------------------------------------------------------

//--------------------funzione di salvataggio---------------------
void salva (int serie [],int lun){
	/*apertura del file in scrittura*/
	FILE* file=fopen("interi.txt","w");
	/*caso di memoria non trovata*/
	if(file==NULL){
		printf("\n\t\t\t\t\t---------------------------------------\n");
		printf("\t\t\t\t\terrore durante il salvataggio\n");
		printf("\t\t\t\t\t---------------------------------------\n");
	/*caso di memoria trovata*/
	}else{
		/*stampa degli interi sul file*/
		for(int i=0;i<lun;i++){
			fprintf(file,"%d",serie [i]);
			if(i+1<lun){
				fprintf(file," ");
			}
		}
		/*chusura del file*/
		fclose(file);
		printf("\n\t\t\t\t\t----------------------------------\n");
		printf("\t\t\t\t\t     salvataggio completatato\n");
		printf("\t\t\t\t\t----------------------------------\n");
	}
}
//----------------------------------------------------------------

//-------------------conta numeri file----------------------------
/*funzione che conta i numeri presenti nel file*/
int quantiNumeri (){
	int lun=0;		//numero di interi
	/*apertura del file in lettura*/
	FILE* file=fopen("interi.txt","r");
	/*caso di file non trovato*/
	if(file==NULL){
		printf("\t\t\t\t\tfile non trovato\n");
	/*caso di file trovato*/
	}else{
		int temp;
		while(fscanf(file,"%d",&temp)!=EOF){
			lun++;
		}
	}//**** non chiudi il file -0.2
	/*restituzione*/
	return lun;
}
//----------------------------------------------------------------

//---------------------acquisizione da file-----------------------
/*funzione cheassegna alla serie gli interi del file*/
void leggiNumeri (int serie [],int lun){
	/*apertura del file in lettura*/
	FILE* file=fopen("interi.txt","r");
	/*caso di file non trovato*/
	if(file==NULL){
		printf("\t\t\t\t\tfile non trovato\n");
	/*caso di file trovato*/
	}else{
		for(int i=0;i<lun;i++){
			/*assegnazione*/
			fscanf(file,"%d",&serie [i]);
		}
	}//**** non chiudi il file -0.2
}
//----------------------------------------------------------------

int main(int argc, char **argv)
{
	printf("1: inserisci una nuova serie\n");
	printf("2: acquisisci la serie salvata su file testuale\n");
	int scelta;		//scelta della funzione
	/*validazione inserimento*/
	do{
		printf("\nscegli: ");
		scanf("%d",&scelta);
		if(scelta!=1&&scelta!=2){
			printf("\t\t\t\t\t-----attenzione inserimento non valido-----\n");
		}
	}while(scelta!=1&&scelta!=2);
	if(scelta==1){
		int lunghezza;		//lunghezza della serie
		/*validazione inserimento*/
		do{
			printf("quanti numeri vuoi inserire? ");
			scanf("%d",&lunghezza);
			if(lunghezza<=0){
				printf("\t\t\t\t\t-----attenzione lunghezza non valida-----\n");
			}
		}while(lunghezza<=0);
		/*riempimento della serie*/
		int vett [lunghezza];
		printf("----------------\n");
		for(int i=0;i<lunghezza;i++){
			printf("insersci: ");
			scanf("%d",&vett [i]);
		}
		printf("----------------\n");
		/*invocazione ricorsiva*/
		if(minimoDispar(vett,lunghezza-1)){
			printf("\ntutte le triple della serie inserita rispettano la condizione\n");
		}else{
			printf("\nle triple della serie inserita non rispettano la condizione\n");
		}
		/*funzione di falvataggio su file txt*/
		salva (vett,lunghezza);
	}else{
		/*assegnazione lunghezza*/
		int lunghezza=quantiNumeri ();
		if(lunghezza==0){
			printf("nessun intero salvato\n");
		}else{
			int vett [lunghezza];
			/*assegnazione serie*/
			leggiNumeri (vett,lunghezza);
			printf("\necco la serie: ");
			for(int i=0;i<lunghezza;i++){
				printf("%d ",vett [i]);
			}
			printf("\n");
			/*invocazione ricorsiva*/
			if(minimoDispar(vett,lunghezza-1)){
				printf("\ntutte le triple della serie inserita rispettano la condizione\n");
			}else{
				printf("\nle triple della serie inserita non rispettano la condizione\n");
			}
			/*funzione di falvataggio su file txt*/
			salva (vett,lunghezza);
		}
	}
	return 0;
}
