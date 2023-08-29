#include <stdio.h>


void decimalParaBinario(int num){
	int resto,resultado;
	
	resultado=num/2;
	if(resultado==0){
		printf("1");
	return;
}
	resto=num%2;
	decimalParaBinario(resultado);
	printf("%i",resto);	

}


main(){
	int num;
	
	printf("Converta um numero inteiro para sua forma binaria: ");
	scanf("%i",&num);
	decimalParaBinario(num);
}
