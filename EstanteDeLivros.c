#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Para evitar erros utilize apenas casas decimais
#define TAMANHO 50

typedef struct estante{
	char isbn[50], titulo[100];
	float preco;
}Estante;

typedef struct pilha{
	Estante livro[TAMANHO];
	int topo;
}Pilha;

Pilha p;

bool vazia(){
	if(p.topo == -1){
		return true;
	}
	
	else{
		return false;
	}
}

bool cheia(){
	if(p.topo == TAMANHO-1){
		return true;
	}
	
	else{
		return false;
	}
};

void gravarPilha(){
	char input[50];
	
	p.topo++;

	printf("\nTitulo do livro: ");
	fgets(p.livro[p.topo].titulo, 100, stdin);
	printf("\nISBN do livro: ");
	fgets(p.livro[p.topo].isbn, 50, stdin);
	printf("\nPreco do livro: ");
	fgets(input, 50, stdin);
	sscanf(input, "%f", &p.livro[p.topo].preco);

}

void retirarPilha(){
	
	printf("\nLivro retirado com sucesso!\n");

	strcpy(p.livro[p.topo].titulo, " ");
 	strcpy(p.livro[p.topo].isbn, " ");
	p.livro[p.topo].preco = 0;
	
	p.topo--;
}

void imprimirPilha(){
	int i, cont = p.topo/10+1;

		for(i = p.topo; i >= 0; i--){
			if(i == p.topo || ((i+1)%10 == 0 && i != 0)){
				printf("\n\nPrateleira %i:\n\n", cont);
				printf("----------------------------------\n\n");
				cont--;
			}
	
			printf("\nTitulo:\t%s", p.livro[i].titulo);
			printf("\nISBN:\t%s", p.livro[i].isbn);
			printf("\nPreco:\tR$ %.2f", p.livro[i].preco);
			printf("\n\n\n\n");
		}
	
	printf("\n");

}

int main(){
	int menu;
	char input[50];
	
	p.topo = -1;
	
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
					imprimirPilha();
				}

			break;
			
			case 2:
				if(cheia()){
					printf("\nA pilha esta cheia!\n");
				}
				
				else{
					gravarPilha();
				}
					
			break;
			
			case 3:
				if(vazia()){
					printf("\nA pilha esta vazia!\n");
				}
				
				else{
					retirarPilha();
				}

			break;
		}
		
		printf("\n");
		system("pause");
		system("cls");
		
	}while(menu != 4);
	
	return 0;
}



































