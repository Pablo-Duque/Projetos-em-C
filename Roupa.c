#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	char modelo[50];
	char cor[15];
	char tamanho[2];
	struct no *anterior;
}No;

typedef struct pilha{
	No *topo;
}Pilha;

Pilha p;

void inicializar(){
	p.topo = NULL;
}

int verificarVazia(){
	if(p.topo == NULL)
		return 1;
	
	else
		return 0;
}

void push(char modelo[50], char cor[15], char tamanho[2]){
	No *newNo = (No *) malloc(sizeof(No));
	
	if(newNo != NULL){
		strcpy(newNo->modelo, modelo);
		strcpy(newNo->cor, cor);
		strcpy(newNo->tamanho, tamanho);
		newNo->anterior = p.topo;
		p.topo = newNo;
		printf("\nAdicionado com sucesso!");
	}
	
	else
		printf("\nA pilha está cheia!");
} 

void pop(){		
		printf("\nRoupa retirada:\n");
		printf("%s", p.topo->modelo);
		printf("%s", p.topo->cor);
		printf("%s", p.topo->tamanho);
		p.topo = p.topo->anterior;
}

void print(){
	if(!verificarVazia()){

		No *aux;
		
		aux = p.topo;
		
		while(aux != NULL){
			printf("\n%s", aux->modelo);
			printf("%s", aux->cor);
			printf("%s", aux->tamanho);
			printf("\n\n");			
			aux = aux->anterior;
		}	
	}
	
	else
		printf("\nA pilha esta vazia!");
}

int main(){
	int menu, op;
	char input[50], modelo[50], cor[15], tamanho[2];
	
	inicializar();
	
	do{
		printf("Menu:\n\n");
		printf("1: Ver pilha\n");
		printf("2: Adicionar na pilha\n");
		printf("3: Retirar da pilha\n");
		printf("4: Sair\n");
		printf("\nResposta: ");
		fgets(input, 50, stdin);
		sscanf(input, "%d", &menu);
		
		switch(menu){
			case 1:
				print();
				
			break;
			
			case 2:
				
				printf("\nNome do modelo: ");
				fgets(modelo, 50, stdin);
				printf("Cor da roupa: ");
				fgets(cor, 15, stdin);
				printf("Tamanho:\n\n");
				printf("1: P\n");
				printf("2: M\n");
				printf("3: G\n");
				printf("\nResposta: ");
				fgets(input, 10, stdin);
				sscanf(input, "%d", &op);
				switch(op){
					case 1:
						strcpy(tamanho, "P");
						push(modelo, cor, tamanho);
						
					break;
					
					case 2:
						strcpy(tamanho, "M");
						push(modelo, cor, tamanho);
						
					break;
					
					case 3:
						strcpy(tamanho, "G");
						push(modelo, cor, tamanho);
						
					break;
					
					default:
						printf("\nOpcao invalida!");
						
					break;
				}
				
			break;
			
			case 3:
				if(!verificarVazia())
					pop();
				
				else
					printf("\nA pilha esta vazia!");

			break;
		}
				
		printf("\n\n");
		system("pause");
		system("cls");
		
	}while(menu != 4);
	
	return 0;
}
