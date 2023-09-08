#include <stdio.h>
#include <stdlib.h>

//Tamanho do predio
#define ANDAR 16
#define UNIDADE 8

//Transforma todos os numeros da matriz em zero
void iniciar(int predio[ANDAR][UNIDADE]){
	int andar, unid;
	
	for(andar = 0; andar < ANDAR; andar++){
		for(unid = 0; unid < UNIDADE; unid++){
			predio[andar][unid] = 0;
		}
	}
}

void alterarSala(int predio[ANDAR][UNIDADE], int andar, int unid, int num){
	predio[andar-1][unid-1] = num;
}

void consultarUnidade(int predio[ANDAR][UNIDADE], int unid){
	int andar;
	
	printf("Andar\tUnidade %i\n", unid);

	/*Note que esse decremento serve para inverter a matriz na exibicao 
	fazendo com que os andares fiquem de acordo com o que o usuario escolheu*/
	for(andar = ANDAR-1; andar >= 0; andar--){
		printf("%i\t %i\n", andar+1, predio[andar][unid-1]);
	}
}

//Diferente da anterior, essa consulta todas as unidades
void consultarTodasUnidades(int predio[ANDAR][UNIDADE]){
	int andar, unid, soma;
	
	printf("Unidade\tProfissionais\n");

	//Nao e necessario inverter aqui, pois os andares nao sao exibidos
	for(unid = 0; unid < UNIDADE; unid++){
		for(andar = 0; andar < ANDAR; andar++){
			soma += predio[andar][unid];
		}
			printf("%i\t\t%i\n", unid+1, soma);
			soma = 0;
	}	
}

void consultarPredio(int predio[ANDAR][UNIDADE]){
	int andar, unid;
	
	printf("Andar\t");
	for(unid = 0; unid < UNIDADE; unid++){
		printf("Unid %i\t", unid+1);
	}
	printf("\n");

	//andarhas invertidas
	for(andar = ANDAR-1; andar >= 0; andar--){
		printf("%i\t", andar+1);
		for(unid = 0; unid < UNIDADE; unid++){
			printf("%i\t", predio[andar][unid]);
		}
		printf("\n");
	}
}

void consultarTodosAndares(int predio[ANDAR][UNIDADE]){
	int andar, unid, soma;
	
	printf("Andar\t\tProfissionais\n");

	for(andar = ANDAR-1; andar >= 0; andar--){
		for(unid = 0; unid < UNIDADE; unid++){
			soma += predio[andar][unid];
		}
			printf("%i\t\t%i\n", andar+1, soma);
			soma = 0;
	}	
}

void salasVazias(int predio[ANDAR][UNIDADE]){
	int andar, unid, andartemp, unidtemp;
	
	for(andar = 0; andar < ANDAR; andar++){
		printf("Andar\tUnidade\n");
		for(unid = 0; unid < UNIDADE; unid++){
			if(predio[andar][unid] == 0){
				andartemp = andar+1;
				unidtemp = unid+1;
				printf("%i\t%i\n", andartemp, unidtemp);
			}
		}
		printf("\n");
	}
}

//andartemp e unidtemp sao variaveis que armazenam os valores de andar e unid temporariamente
void maiorNumero(int predio[ANDAR][UNIDADE]){
	int andar, unid, andartemp, unidtemp, maior = 0;
	
	for(andar = 0; andar < ANDAR; andar++){
		for(unid = 0; unid < UNIDADE; unid++){
			if(maior < predio[andar][unid]){
				maior = predio[andar][unid];
				andartemp = andar+1;
				unidtemp = unid+1;
			}
		}
	}
	printf("Andar\tUnidade %i\n", unidtemp);
	printf("%i\t%i", andartemp, maior);
}

int main(){
	int menu, predio[ANDAR][UNIDADE], andar, unid, num;

	//Menu
	do{
		system("cls");
		printf("Menu: \n\n");
		printf("1) Inicializar o predio\n");
		printf("2) Alterar o numero de profissionais de uma sala\n");
		printf("3) Consultar o numero de profissionais de uma unidade\n");
		printf("4) Imprimir o numero de profissionais de cada unidade\n");
		printf("5) Imprimir o numero de profissionais do predio\n");
		printf("6) Imprimir o numero total de profissionais de cada andar\n");
		printf("7) Informar quais salas estao vazias (ou seja, sem locacao)\n");
		printf("8) Identificar a unidade com o maior numero de profissionais\n");
		printf("9) Finalizar programa.\n");
		printf("\nResposta: ");
		scanf("%i", &menu);
		printf("\n");
		
		//Itens do menu sendo executados
		switch(menu){
			case 1:
				system("cls");
				iniciar(predio);
			break;
			
			case 2:
				printf("Andar escolhido: ");
				scanf("%i", &andar);
				printf("Unidade escolhida: ");
				scanf("%i", &unid);
				printf("\n");
				printf("Numero para escrever: ");
				scanf("%i", &num);
				alterarSala(predio, andar, unid, num);
				printf("\nAlterado com sucesso!");				
				printf("\n\n");
				system("pause");
			break;
		
			case 3:
				printf("Unidade a ser consultada: ");
				scanf("%i", &unid);
				printf("\n");
				consultarUnidade(predio, unid);
				printf("\n");
				system("pause");
			break;
		
			case 4:
				consultarTodasUnidades(predio);
				printf("\n");
				system("pause");
			break;
		
			case 5:
				consultarPredio(predio);
				printf("\n");
				system("pause");
			break;
		
			case 6:
				consultarTodosAndares(predio);
				printf("\n");
				system("pause");
			break;
		
			case 7:
				salasVazias(predio);
				system("pause");
			break;
		
			case 8:
				maiorNumero(predio);
				printf("\n\n");
				system("pause");
			break;
		}
	}while(menu != 9);

	return 0;
}

