#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5


void crescente(int alpha[TAMANHO]){
	int temp,i,j;
	for(i=0;i<TAMANHO;i++){
		for(j=i;j<TAMANHO;j++){
			if(alpha[i]<alpha[j]){
				temp=alpha[j];
				alpha[j]=alpha[i];
				alpha[i]=temp;
			}
		}
	}
}

void decrescente(int alpha[TAMANHO]){
	int temp,i,j;
	for(i=0;i<TAMANHO;i++){
		for(j=i;j<TAMANHO;j++){
			if(alpha[i]>alpha[j]){
				temp=alpha[j];
				alpha[j]=alpha[i];
				alpha[i]=temp;
			}
		}
	}
}

void especial(int alpha[TAMANHO]){
	int maior=0,menor=100000,i,meio,temp,placemaior,placemenor;
	for(i=0;i<TAMANHO;i++){
		if(maior<alpha[i]){
			maior=alpha[i];
			placemaior=i;
		}
		if(menor>alpha[i]){
			menor=alpha[i];
			placemenor=i;
		}
	}
	
	meio=TAMANHO/2;
	if(TAMANHO%2!=0){
	}
	temp=alpha[meio];
	alpha[meio]=alpha[placemaior];
	alpha[placemaior]=temp;
	temp=alpha[TAMANHO-1];
	alpha[TAMANHO-1]=alpha[placemenor];
	alpha[placemenor]=temp;
}

void escrever(int alpha[TAMANHO]){
	int i;
		printf("\nNumeros na ordem desejada: \n\n");
		for(i=0;i<TAMANHO;i++){
			printf("%i",alpha[i]);
			printf("\n");
		}
		printf("\n");
		system("pause");
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	int i,x,alpha[TAMANHO];
	
	do{
		printf("Primeiro digite os numeros\n\n");
		for(i=0;i<TAMANHO;i++){
			printf("Digite o valor de Alpha[%i]: ",i+1);
			scanf("%i",&alpha[i]);	
		}
		
		printf("Menu\n");
		printf("1: Ordenar em ordem crescente\n");
		printf("2: Ordenar em ordem decrescente\n");
		printf("3: Maior numero no meio e menor no final\n");
		printf("4: Sair\n");
		printf("Resposta: ");
		scanf("%i",&x);
		
		switch(x){
			case 1:{
				crescente(alpha);
				escrever(alpha);
				break;
			}
			case 2:{
				decrescente(alpha);
				escrever(alpha);
				break;
			}
			case 3:{
				especial(alpha);
				escrever(alpha);
				break;
			}
			default:{
				x=4;
				break;
			}
		}
		
		system("cls");
		}while(x!=4);
	
	return 0;
}

