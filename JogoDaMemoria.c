#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct jogoMemoria{
	char frente[4][4], verso[4][4];
};

//Funcao abaixo do main devido ao seu tamanho
struct jogoMemoria gerarJogo(struct jogoMemoria tabela, int jogo);

void exibirFrente(struct jogoMemoria tabela){
	int linha, coluna;
	
	printf("Voce tem 10 segundos para memorizar!\n\n");
	for(linha = 0; linha < 4; linha++){
		printf("\t");
		for(coluna = 0; coluna < 4; coluna++){
			printf("%c ", tabela.frente[linha][coluna]);
		}
		printf("\n");
	}
	sleep(10);
}

int main(){
	struct jogoMemoria tabela;
	
	srand(time(NULL));
	
	tabela = gerarJogo(tabela, rand()%20);
	exibirFrente(tabela);
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
