/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.8
*/
//e' un problema di verifica esistenziale
//input: array,lung(lunghezza array)
//pre condizione: un array di interi,con lung la sua lunghezza >=0
//output variabile: una variabile di tipo booleana trovato
//post condizione : se trovato =1 esiste una terna di elementi adiacenti nell array  in cui uno dei tre elementi dell array e' il resto  della divisione degli altri due.Se trovato=0 non esiste una terna di elementi adiacenti nell array  in cui uno dei tre elementi dell array e' il resto  della divisione degli altri due
#include <stdio.h>  //******* NO "se trovato =1 esiste...", MA IL CONTRARIO: "trovato =1 se esiste..." -0.2
int RestoDivisione(int lung,int array[]){
	int i=0;
	int trovato=0;
do {
if((array[i]%array[i+1]==array[i+2])||(array[i+1]%array[i]==array[i+2])||
   (array[i+1]%array[i+2]==array[i])||(array[i+2]%array[i+1]==array[i])||
   (array[i]%array[i+2]==array[i+1])||(array[i+2]%array[i]==array[i+1])){
	trovato=1;
}else{
	i++;
} //***** CON IL DO WHILE CI DEVE ESSERE IL CONTROLLO SULLA LUNGHEZZA DELL'ARRAY, PERCHE' SE CI SONO SOLO DUE COMPONENTI ACCEDE A MEMORIA CHE
  //***** NON FA PARTE DELL'ARRAY. AVRESTI DOVUTO SPECIFICARE NELLE PRECONDIZIONI LUNGHEZZA>=3. -1
}while(i<lung-2&&trovato==0);// &&!trovato -1
return trovato;
}
int main(){
	int lung,i,risultato;
	printf("inserire la lunghezza dell array\n");
	scanf("%d",&lung);
	printf("la lunghezza dell array e' %d \n",lung);
	int array[lung];
	for( i=0;i<lung;i++){
		printf("inserire un numero\n");
	scanf("%d",&array[i]);
	}
	printf("i numeri presenti nell array sono:\n");
	for( i=0;i<lung;i++){
		printf("%d\n",array[i]);
	}
	risultato=RestoDivisione(lung,array);
	if(risultato==1){
		printf("esiste una terna di elementi adiacenti nell array  in cui uno dei tre elementi dell array e' il resto  della divisione degli altri due\n");
	}else{
		printf("  non esiste una terna di elementi adiacenti nell array  in cui uno dei tre elementi dell array e' il resto  della divisione degli altri due\n");
	}
}