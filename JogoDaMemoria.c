#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct jogoMemoria{
	char frente[4][4], verso[4][4];
};

//Funcao abaixo do main devido ao seu tamanho
struct jogoMemoria gerarJogo(struct jogoMemoria tabela, int jogo);

void exibirFrente(struct jogoMemoria tabela, int tempo){
	int i, linha, coluna;
	
	for(i = 0; i < tempo; i++){
		printf("   Voce tem %i segundos para memorizar!\n\n", tempo-i);
		for(linha = 0; linha < 4; linha++){
			printf("\n\t\t");
			for(coluna = 0; coluna < 4; coluna++){
				printf("%c ", tabela.frente[linha][coluna]);
			}
			printf("\n");
		}
	sleep(1);
	system("cls");
	}
}

void exibirVerso(struct jogoMemoria tabela){
	int i, linha, coluna;
	
	printf("\t Que comece os jogos!\n\n");
	printf("\t        1 2 3 4\n");
		for(linha = 0; linha < 4; linha++){
			printf("\n\t    %i   ", linha+1);
			for(coluna = 0; coluna < 4; coluna++){
				printf("%c ", tabela.verso[linha][coluna]);
			}
			printf("\n");
		}
}

struct jogoMemoria escolherPar(struct jogoMemoria tabela){
	int linha1, linha2, coluna1, coluna2;
		
		printf("\n\t Escolha o primeiro lugar:\n\n");
		printf("\t Linha: ");
		scanf("%i", &linha1);
		printf("\t Coluna: ");
		scanf("%i", &coluna1);
		
		if (linha1 < 1 || linha1 > 4 || coluna1 < 1 || coluna1 > 4){
			printf("\n\n   Apenas numeros de 1 a 4 sao permitidos!\n\n");
			printf("   ");
			system("pause");
			system("cls");
			exibirVerso(tabela);
			escolherPar(tabela);
		}
		
		printf("\n\t Escolha o segundo lugar:\n\n");
		printf("\t Linha: ");
		scanf("%i", &linha2);
		printf("\t Coluna: ");
		scanf("%i", &coluna2);
		
		if (linha2 < 1 || linha2 > 4 || coluna2 < 1 || coluna2 > 4){
			printf("\n\n   Apenas numeros de 1 a 4 sao permitidos!\n\n");
			printf("   ");
			system("pause");
			system("cls");
			exibirVerso(tabela);
			escolherPar(tabela);
		}
		
		if(linha1 == linha2 && coluna1 == coluna2){
			printf("\n\n   Voce nao pode escolher a mesma posicao!\n\n");
			printf("   ");
			system("pause");
			system("cls");
			exibirVerso(tabela);
			escolherPar(tabela);
		}
		
		else if(tabela.verso[linha1-1][coluna1-1] != '#' || tabela.verso[linha2-1][coluna2-1] != '#'){
			printf("\n\n   Essa posicao ja foi escolhida!\n\n");
			printf("   ");
			system("pause");
			system("cls");
			exibirVerso(tabela);
			escolherPar(tabela);
		}
		
		tabela.verso[linha1-1][coluna1-1] = tabela.frente[linha1-1][coluna1-1];
		tabela.verso[linha2-1][coluna2-1] = tabela.frente[linha2-1][coluna2-1];
		
		system("cls");
		exibirVerso(tabela);
		
		if(tabela.frente[linha1-1][coluna1-1] == tabela.frente[linha2-1][coluna2-1]){
			printf("\n\t   Voce acertou!\n\n");
			printf("   ");
			system("pause");
		}
		
		else{
			printf("\n\t    Voce errou!\n\n");
			printf("   ");
			system("pause");
			tabela.verso[linha1-1][coluna1-1] = '#';
			tabela.verso[linha2-1][coluna2-1] = '#';
		}
	system("cls");
	
	return tabela;
}

bool fimJogo(struct jogoMemoria tabela){
		int linha, coluna;
		
		for(linha = 0; linha < 4; linha++){
			for(coluna = 0; coluna < 4; coluna++){
				if(tabela.verso[linha][coluna] == '#'){
					return true;
				}
			}
		}
		
		return false;
}

int main(){
	int dificuldade;
	
	struct jogoMemoria tabela;
	
	srand(time(NULL));
		
	tabela = gerarJogo(tabela, rand()%20);

	printf("   Selecione a dificuldade antes de jogar (qualquer outro valor o tempo sera de 15 Seg):\n");
	printf("\n   1: Facil   (20 Seg)");
	printf("\n   2: Medio   (15 Seg)");
	printf("\n   3: Dificil (10 Seg)\n");
	printf("\n   Resposta: ");
	
	scanf("%i", &dificuldade);
	
	system("cls");
	
	if(dificuldade == 1){
		exibirFrente(tabela, 20);
	}
	
	else if(dificuldade == 3){
		exibirFrente(tabela, 10);
	}
	
	else{
		exibirFrente(tabela, 15);
	}

	do{
		exibirVerso(tabela);
		tabela = escolherPar(tabela);
	}while(fimJogo(tabela));
	
	exibirVerso(tabela);
	printf("\n\tParabens, voce venceu!\n");

	return 0;
}

struct jogoMemoria gerarJogo(struct jogoMemoria tabela, int jogo){
	int linha, coluna;
	
	for(linha = 0; linha < 4; linha++){
		for(coluna = 0; coluna < 4; coluna++){
			tabela.verso[linha][coluna] = '#';
		}
	}
	
	switch(jogo){
		case 0:
		    tabela.frente[0][0] = '5'; tabela.frente[0][1] = '3'; tabela.frente[0][2] = '3'; tabela.frente[0][3] = '8';
		    tabela.frente[1][0] = '2'; tabela.frente[1][1] = '1'; tabela.frente[1][2] = '9'; tabela.frente[1][3] = '4';
		    tabela.frente[2][0] = '7'; tabela.frente[2][1] = '9'; tabela.frente[2][2] = '7'; tabela.frente[2][3] = '5';
		    tabela.frente[3][0] = '1'; tabela.frente[3][1] = '4'; tabela.frente[3][2] = '8'; tabela.frente[3][3] = '2';
		break;
		
		case 1:
		    tabela.frente[0][0] = '1'; tabela.frente[0][1] = '5'; tabela.frente[0][2] = '3'; tabela.frente[0][3] = '8';
		    tabela.frente[1][0] = '7'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '5'; tabela.frente[1][3] = '6';
		    tabela.frente[2][0] = '1'; tabela.frente[2][1] = '2'; tabela.frente[2][2] = '7'; tabela.frente[2][3] = '4';
		    tabela.frente[3][0] = '8'; tabela.frente[3][1] = '3'; tabela.frente[3][2] = '6'; tabela.frente[3][3] = '2';
		break;
		
		case 2:
		    tabela.frente[0][0] = '0'; tabela.frente[0][1] = '9'; tabela.frente[0][2] = '1'; tabela.frente[0][3] = '7';
		    tabela.frente[1][0] = '5'; tabela.frente[1][1] = '6'; tabela.frente[1][2] = '5'; tabela.frente[1][3] = '1';
		    tabela.frente[2][0] = '6'; tabela.frente[2][1] = '0'; tabela.frente[2][2] = '3'; tabela.frente[2][3] = '8';
		    tabela.frente[3][0] = '3'; tabela.frente[3][1] = '9'; tabela.frente[3][2] = '8'; tabela.frente[3][3] = '7';
		break;
		
		case 3:
		    tabela.frente[0][0] = '0'; tabela.frente[0][1] = '8'; tabela.frente[0][2] = '4'; tabela.frente[0][3] = '0';
		    tabela.frente[1][0] = '1'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '2'; tabela.frente[1][3] = '1';
		    tabela.frente[2][0] = '6'; tabela.frente[2][1] = '2'; tabela.frente[2][2] = '7'; tabela.frente[2][3] = '6';
		    tabela.frente[3][0] = '5'; tabela.frente[3][1] = '7'; tabela.frente[3][2] = '8'; tabela.frente[3][3] = '5';
		break;
		
		case 4:
		    tabela.frente[0][0] = '4'; tabela.frente[0][1] = '8'; tabela.frente[0][2] = '3'; tabela.frente[0][3] = '0';
		    tabela.frente[1][0] = '2'; tabela.frente[1][1] = '8'; tabela.frente[1][2] = '9'; tabela.frente[1][3] = '1';
		    tabela.frente[2][0] = '5'; tabela.frente[2][1] = '9'; tabela.frente[2][2] = '1'; tabela.frente[2][3] = '5';
		    tabela.frente[3][0] = '3'; tabela.frente[3][1] = '2'; tabela.frente[3][2] = '0'; tabela.frente[3][3] = '4';
		break;
		
		case 5:
		    tabela.frente[0][0] = '8'; tabela.frente[0][1] = '0'; tabela.frente[0][2] = '1'; tabela.frente[0][3] = '3';
		    tabela.frente[1][0] = '6'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '7'; tabela.frente[1][3] = '0';
		    tabela.frente[2][0] = '2'; tabela.frente[2][1] = '3'; tabela.frente[2][2] = '8'; tabela.frente[2][3] = '2';
		    tabela.frente[3][0] = '1'; tabela.frente[3][1] = '7'; tabela.frente[3][2] = '6'; tabela.frente[3][3] = '4';
		break;
		
		case 6:
		    tabela.frente[0][0] = '3'; tabela.frente[0][1] = '0'; tabela.frente[0][2] = '4'; tabela.frente[0][3] = '9';
		    tabela.frente[1][0] = '2'; tabela.frente[1][1] = '9'; tabela.frente[1][2] = '0'; tabela.frente[1][3] = '8';
		    tabela.frente[2][0] = '1'; tabela.frente[2][1] = '6'; tabela.frente[2][2] = '1'; tabela.frente[2][3] = '6';
		    tabela.frente[3][0] = '8'; tabela.frente[3][1] = '2'; tabela.frente[3][2] = '3'; tabela.frente[3][3] = '4';
		break;
		
		case 7:
		    tabela.frente[0][0] = '5'; tabela.frente[0][1] = '8'; tabela.frente[0][2] = '6'; tabela.frente[0][3] = '5';
		    tabela.frente[1][0] = '2'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '7'; tabela.frente[1][3] = '6';
		    tabela.frente[2][0] = '1'; tabela.frente[2][1] = '9'; tabela.frente[2][2] = '1'; tabela.frente[2][3] = '7';
		    tabela.frente[3][0] = '9'; tabela.frente[3][1] = '2'; tabela.frente[3][2] = '8'; tabela.frente[3][3] = '4';
		break;
		
		case 8:
		    tabela.frente[0][0] = '7'; tabela.frente[0][1] = '6'; tabela.frente[0][2] = '6'; tabela.frente[0][3] = '1';
		    tabela.frente[1][0] = '5'; tabela.frente[1][1] = '8'; tabela.frente[1][2] = '9'; tabela.frente[1][3] = '3';
		    tabela.frente[2][0] = '0'; tabela.frente[2][1] = '7'; tabela.frente[2][2] = '0'; tabela.frente[2][3] = '8';
		    tabela.frente[3][0] = '3'; tabela.frente[3][1] = '5'; tabela.frente[3][2] = '1'; tabela.frente[3][3] = '9';
		break;
		
		case 9:
		    tabela.frente[0][0] = '7'; tabela.frente[0][1] = '2'; tabela.frente[0][2] = '8'; tabela.frente[0][3] = '4';
		    tabela.frente[1][0] = '0'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '1'; tabela.frente[1][3] = '3';
		    tabela.frente[2][0] = '5'; tabela.frente[2][1] = '0'; tabela.frente[2][2] = '7'; tabela.frente[2][3] = '2';
		    tabela.frente[3][0] = '1'; tabela.frente[3][1] = '8'; tabela.frente[3][2] = '3'; tabela.frente[3][3] = '5';
		break;
		
		case 10:
		    tabela.frente[0][0] = '0'; tabela.frente[0][1] = '1'; tabela.frente[0][2] = '2'; tabela.frente[0][3] = '3';
		    tabela.frente[1][0] = '4'; tabela.frente[1][1] = '5'; tabela.frente[1][2] = '7'; tabela.frente[1][3] = '6';
		    tabela.frente[2][0] = '6'; tabela.frente[2][1] = '7'; tabela.frente[2][2] = '0'; tabela.frente[2][3] = '1';
		    tabela.frente[3][0] = '2'; tabela.frente[3][1] = '3'; tabela.frente[3][2] = '4'; tabela.frente[3][3] = '5';
		break;
		
		case 11:
		    tabela.frente[0][0] = '1'; tabela.frente[0][1] = '2'; tabela.frente[0][2] = '6'; tabela.frente[0][3] = '8';
		    tabela.frente[1][0] = '7'; tabela.frente[1][1] = '5'; tabela.frente[1][2] = '1'; tabela.frente[1][3] = '7';
		    tabela.frente[2][0] = '9'; tabela.frente[2][1] = '8'; tabela.frente[2][2] = '0'; tabela.frente[2][3] = '2';
		    tabela.frente[3][0] = '0'; tabela.frente[3][1] = '9'; tabela.frente[3][2] = '5'; tabela.frente[3][3] = '6';
		break;
		
		case 12:
		    tabela.frente[0][0] = '1'; tabela.frente[0][1] = '4'; tabela.frente[0][2] = '0'; tabela.frente[0][3] = '6';
		    tabela.frente[1][0] = '9'; tabela.frente[1][1] = '8'; tabela.frente[1][2] = '6'; tabela.frente[1][3] = '3';
		    tabela.frente[2][0] = '5'; tabela.frente[2][1] = '0'; tabela.frente[2][2] = '5'; tabela.frente[2][3] = '4';
		    tabela.frente[3][0] = '3'; tabela.frente[3][1] = '1'; tabela.frente[3][2] = '9'; tabela.frente[3][3] = '8';
		break;
		
		case 13:
		    tabela.frente[0][0] = '8'; tabela.frente[0][1] = '3'; tabela.frente[0][2] = '4'; tabela.frente[0][3] = '1';
		    tabela.frente[1][0] = '6'; tabela.frente[1][1] = '7'; tabela.frente[1][2] = '0'; tabela.frente[1][3] = '2';
		    tabela.frente[2][0] = '1'; tabela.frente[2][1] = '0'; tabela.frente[2][2] = '4'; tabela.frente[2][3] = '8';
		    tabela.frente[3][0] = '2'; tabela.frente[3][1] = '7'; tabela.frente[3][2] = '6'; tabela.frente[3][3] = '3';
		break;
		
		case 14:
		    tabela.frente[0][0] = '4'; tabela.frente[0][1] = '6'; tabela.frente[0][2] = '2'; tabela.frente[0][3] = '6';
		    tabela.frente[1][0] = '0'; tabela.frente[1][1] = '2'; tabela.frente[1][2] = '5'; tabela.frente[1][3] = '3';
		    tabela.frente[2][0] = '9'; tabela.frente[2][1] = '7'; tabela.frente[2][2] = '0'; tabela.frente[2][3] = '4';
		    tabela.frente[3][0] = '3'; tabela.frente[3][1] = '9'; tabela.frente[3][2] = '7'; tabela.frente[3][3] = '5';
		break;
		
		case 15:
		    tabela.frente[0][0] = '6'; tabela.frente[0][1] = '7'; tabela.frente[0][2] = '0'; tabela.frente[0][3] = '2';
		    tabela.frente[1][0] = '8'; tabela.frente[1][1] = '0'; tabela.frente[1][2] = '3'; tabela.frente[1][3] = '4';
		    tabela.frente[2][0] = '9'; tabela.frente[2][1] = '2'; tabela.frente[2][2] = '8'; tabela.frente[2][3] = '9';
		    tabela.frente[3][0] = '4'; tabela.frente[3][1] = '6'; tabela.frente[3][2] = '7'; tabela.frente[3][3] = '3';
		break;
		
		case 16:
		    tabela.frente[0][0] = '2'; tabela.frente[0][1] = '4'; tabela.frente[0][2] = '0'; tabela.frente[0][3] = '8';
		    tabela.frente[1][0] = '1'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '7'; tabela.frente[1][3] = '9';
		    tabela.frente[2][0] = '3'; tabela.frente[2][1] = '9'; tabela.frente[2][2] = '3'; tabela.frente[2][3] = '0';
		    tabela.frente[3][0] = '8'; tabela.frente[3][1] = '2'; tabela.frente[3][2] = '1'; tabela.frente[3][3] = '7';
		break;
		
		case 17:
		    tabela.frente[0][0] = '7'; tabela.frente[0][1] = '6'; tabela.frente[0][2] = '1'; tabela.frente[0][3] = '2';
		    tabela.frente[1][0] = '8'; tabela.frente[1][1] = '2'; tabela.frente[1][2] = '4'; tabela.frente[1][3] = '3';
		    tabela.frente[2][0] = '0'; tabela.frente[2][1] = '1'; tabela.frente[2][2] = '0'; tabela.frente[2][3] = '8';
		    tabela.frente[3][0] = '3'; tabela.frente[3][1] = '7'; tabela.frente[3][2] = '6'; tabela.frente[3][3] = '4';
		break;
		
		case 18:
		    tabela.frente[0][0] = '2'; tabela.frente[0][1] = '1'; tabela.frente[0][2] = '7'; tabela.frente[0][3] = '1';
		    tabela.frente[1][0] = '0'; tabela.frente[1][1] = '4'; tabela.frente[1][2] = '7'; tabela.frente[1][3] = '5';
		    tabela.frente[2][0] = '8'; tabela.frente[2][1] = '6'; tabela.frente[2][2] = '0'; tabela.frente[2][3] = '2';
		    tabela.frente[3][0] = '6'; tabela.frente[3][1] = '8'; tabela.frente[3][2] = '5'; tabela.frente[3][3] = '4';
		break;
		
		case 19:
		    tabela.frente[0][0] = '1'; tabela.frente[0][1] = '3'; tabela.frente[0][2] = '7'; tabela.frente[0][3] = '2';
		    tabela.frente[1][0] = '9'; tabela.frente[1][1] = '0'; tabela.frente[1][2] = '4'; tabela.frente[1][3] = '0';
		    tabela.frente[2][0] = '8'; tabela.frente[2][1] = '2'; tabela.frente[2][2] = '1'; tabela.frente[2][3] = '3';
		    tabela.frente[3][0] = '4'; tabela.frente[3][1] = '8'; tabela.frente[3][2] = '9'; tabela.frente[3][3] = '7';
		break;
	
	}
	
	return tabela;
}
