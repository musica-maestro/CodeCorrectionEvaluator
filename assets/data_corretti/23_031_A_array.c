/* SPECIFICA (max 1):......2
   TIPO PROBLEMA (max 1):..2
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
#include<stdio.h>
/*pre condizione:n>=3
input:un intero n,un array di n interi
output:un booleano mul
post condizione mul=true se in ogni tripla vi è almeno un elemento divisibile per almeno uno degli
altri 2,mul=false altrimenti

TIPO DI PROBLEMA:problema di verifica universale.

*/
int multipli(int a[],int n){
	int i,j,mul=1,m;
	for(i=2;i<n&&mul==1;i++){
	m=(a[i]%a[i-1]==0)+(a[i]%a[i-2]==0)+(a[i-1]%a[i]==0)+(a[i-2]%a[i]==0)+(a[i-1]%a[i-2]==0)+(a[i-2]%a[i-1]==0);
		if(m==0)mul=0;
	}return mul;
}int main(){
	int n,a[n],i;
	printf("quanti interi ha la sequenza?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
printf("ins valore posizione %d ",i);
scanf("%d",&a[i]);
	}
if(multipli(a,n)==1)
	printf("in tutte le triple vi e' almeno un elemento diviso da almeno uno degli altri 2\n");
else printf("almeno una tripla non ha un elemento diviso da almeno uno degli altri 2");
}