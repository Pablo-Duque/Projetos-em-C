#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 5

int topo= -1;

//Verifica se a pilha esta vazia
bool vazia(){
	if(topo == -1){
		return true;
	}
	
	else{
		return false;
	}
}

//Verifica se a pilha esta cheia
bool cheia(){
	if(topo == TAMANHO-1){
		return true;
	}
	
	else{
		return false;
	}
}

//Atribui 0 a todas as posicoes
void inicializarPilha(int pilha[]){
	int i;
	
	for(i = 0; i < TAMANHO; i++){
		pilha[i] = 0;
	}
}

//Escreve o valor digitado na pilha
void escreverPilha(int pilha[]){
	int valor;
	char input[50];
	
	printf("\nValor a ser escrito na pilha: ");
	fgets(input, 50, stdin);
	sscanf(input, "%i", &valor);
	
	topo++;
	
	pilha[topo] = valor;
}

//Retira um valor da pilha e mostra ao usuario
void retirarPilha(int pilha[]){
	
	printf("\nValor retirado: %i\n", pilha[topo]);
	
	pilha[topo] = 0;
	
	topo--;
}

//Exibe a pilha inteira
void imprimirPilha(int pilha[]){
	int i;
	
	printf("\nA pilha: ");
	for(i = 0; i < TAMANHO; i++){
		printf("%i ", pilha[i]);
	}
	
	printf("\n");
}

int main(){
	int pilha[TAMANHO], menu;
	char input[50];
	
	inicializarPilha(pilha);
	
	do{
		printf("Menu\n\n");
		printf("1: Ver pilha\n");
		printf("2: Escrever na pilha\n");
		printf("3: Retirar da pilha\n"); 
		printf("4: Sair\n");
		printf("\nResposta: ");
		fgets(input, 50, stdin);
		sscanf(input, "%i", &menu);
		
		switch(menu){
			case 1:
				if(vazia()){
					printf("\nA pilha esta vazia!\n");
				}
				
				else{
					imprimirPilha(pilha);
				}

			break;
			
			case 2:
				if(cheia()){
					printf("\nA pilha esta cheia!\n");
				}
				
				else{
					escreverPilha(pilha);
				}
					
			break;
			
			case 3:
				if(vazia()){
					printf("\nA pilha esta vazia!\n");
				}
				
				else{
					retirarPilha(pilha);
				}

			break;
		}
		
		printf("\n");
		system("pause");
		system("cls");
		
	}while(menu != 4);
	
	return 0;
}



































