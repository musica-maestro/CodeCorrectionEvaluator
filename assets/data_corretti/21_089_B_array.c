/* SPECIFICA (max 1.5):....0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.4
*/
//Specifica
//input : Lunghezza Array e elementi dell'Array
//Pre-Condizione :  La lunghezza dell'Array deve essere un numero positivo
//Output : Esistenza di 2 numeri maggiori o uguali a 5 ed almeno due elementi pari per ogni tripla
//Post-Condizioine :  //****** L'OUTPUT E' UN BOOLEANO, QUELLO CHE HAI SCRITTO SOPRA E' PIU' O MENO LA POST-CONDIZIONE -0.6

//Problema di verifica Universale

#include <stdio.h>

int maggiori5Pari(int Array[],int Length);

int main(int argc, char **argv)
{
	int Length; // dichiaro variabile che rappresenta lunghezza array
	printf("Inserire Lunghezza Array : ");
	scanf("%d",&Length); // inserisco la lunghezza dell'array
	int Array[Length]; // inizializzo Array
	for(int i = 0;i < Length;i++){
		printf("Inserire Elemento Array[%d] : ",i);
		scanf("%d",&Array[i]); // vado a inserire ogni elemento dell'array
	}
	if(maggiori5Pari(Array,Length)) // chiamo la funzione come paramentro stringa
		printf("Ogni tripla di elementi dell'array contiene esattamente due maggiori o uguali a 5 ed almeno due elementi pari");
	else
		printf("Una o ogni tripla di elementi dell'array non contiene esattamente due maggiori o uguali a 5 ed almeno due elementi pari");
	return 0;
}

int maggiori5Pari(int Array[],int Length){
	int i ;                           //dichiaro variabile contatore
	int Esiste;                       //dichiaro variabile di esistenza
	int Numeri_Maggiori_Uguali_5;     //dichiaro variabile che conta quanti numeri sono maggiori uguali a 5 per ogni tripla
	int Numeri_Pari;                  //dichiaro variabile che conta quanti numeri sono pari per ogni tripla
	i = 2;                            // inizializzo la variabile i  a 2
	Esiste = 1;                       //inizializzo la variabile i a 1
	while(i < Length && Esiste){
		Numeri_Maggiori_Uguali_5 = 0; //inizializzo variabile che conta quanti numeri sono maggiori uguali a 5 per ogni tripla
		Numeri_Pari = 0;              //variabile che conta quanti numeri sono pari per ogni tripla
		for(int j = i - 2;j <= i;j++){
			if(Array[j] >= 5) // controlla se elemento attuale è maggiore o uguale a 5
				Numeri_Maggiori_Uguali_5++;
			if(Array[j] % 2 == 0) // controlla se elemento attuale è pari
				Numeri_Pari++;
		}
		if(Numeri_Pari < 2 && Numeri_Maggiori_Uguali_5 != 2) // se non sono soddisfatte le condizioni allora la tripla attuale è un esito negativo
			Esiste = 0;
		i++; // incremento la variabile i per passare alla prossima tripla
	}
	return Esiste; //******** I NOMI DELLE VARIABILI VANNO SCRITTI CON LA PRIMA LETTERA MINUSCOLA!
}
