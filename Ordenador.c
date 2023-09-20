#include <stdio.h>
#include <stdlib.h>

//Tamanho da sequencia
#define TAMANHO 5


void crescente(int alpha[TAMANHO]){
	int temp, i, j;
	
	for(i = 0; i < TAMANHO; i++){

		//j=i para nao passar pelo mesmo lugar de novo
		for(j = i; j < TAMANHO; j++){
			if(alpha[i] > alpha[j]){
				//Troca sendo feita
				temp = alpha[j];
				alpha[j] = alpha[i];
				alpha[i] = temp;
			}
		}
	}
}

void decrescente(int alpha[TAMANHO]){
	int temp, i, j;
	
	for(i = 0; i < TAMANHO; i++){
		for(j = i; j < TAMANHO; j++){
			if(alpha[i] < alpha[j]){
				temp = alpha[j];
				alpha[j] = alpha[i];
				alpha[i] = temp;
			}
		}
	}
}

void especial(int alpha[TAMANHO]){
	int maior = alpha[0], menor = alpha[0], i, meio, temp, placemaior, placemenor;
	
	for(i = 0; i < TAMANHO; i++){
		
		//Guarda tanto o maior, o menor, como os seus respectivos lugares
		if(maior <= alpha[i]){
			maior = alpha[i];
			placemaior = i;
		}
		if(menor >= alpha[i]){
			menor = alpha[i];
			placemenor = i;
		}
	}
	
	meio = TAMANHO/2;

	//Troca o maior pelo meio
	temp = alpha[meio];
	alpha[meio] = alpha[placemaior];
	alpha[placemaior] = temp;

	//Troca o menor pelo ultimo
	temp = alpha[TAMANHO-1];
	alpha[TAMANHO-1] = alpha[placemenor];
	alpha[placemenor] = temp;
}

void escrever(int alpha[TAMANHO]){
	int i;
	
	printf("\nNumeros na ordem desejada: \n\n");
	for(i = 0; i < TAMANHO; i++){
		printf("%i ", alpha[i]);
	}
	printf("\n\n");
	system("pause");
}

int main(){
	int i, menu, alpha[TAMANHO];
	char input[50];
	
	printf("Primeiro digite os numeros\n\n");
	for(i = 0; i < TAMANHO; i++){
		printf("Digite o valor de Alpha[%i]: ", i+1);
		fgets(input, 50, stdin);
		sscanf(input, "%i", &alpha[i]);	
	}
		
	do{
		system("cls");

		printf("Menu: \n\n");
		printf("1: Alterar numeros\n");
		printf("2: Ordenar em ordem crescente\n");
		printf("3: Ordenar em ordem decrescente\n");
		printf("4: Maior numero no meio e menor no final\n");
		printf("5: Sair\n");
		printf("\nResposta: ");
		fgets(input, 50, stdin);
		sscanf(input, "%i", &menu);
		
		switch(menu){
			case 1:
				printf("\n");
				for(i = 0; i < TAMANHO; i++){
				printf("Digite o valor de Alpha[%i]: ", i+1);
				fgets(input, 50, stdin);
				sscanf(input, "%i", &alpha[i]);	
				}
			break;
			
			case 2:
				crescente(alpha);
				escrever(alpha);
			break;
			
			case 3:
				decrescente(alpha);
				escrever(alpha);
			break;
			
			case 4:
				especial(alpha);
				escrever(alpha);
			break;
		}
		
		system("cls");
		}while(menu != 5);
	
	return 0;
}

