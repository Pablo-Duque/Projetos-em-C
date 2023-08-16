#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define ANDAR 16
#define UNIDADE 8

//Transforma todos os números da matriz em zero
void iniciar(int predio[ANDAR][UNIDADE]){
	int lin,col;
	
	for(lin=0;lin<ANDAR;lin++){
		for(col=0;col<UNIDADE;col++){
			predio[lin][col]=0;
		}
	}
}

void alterarSala(int predio[ANDAR][UNIDADE],int lin,int col,int num){
	predio[lin-1][col-1]=num;
}

void consultarUnidade(int predio[ANDAR][UNIDADE],int col){
	int lin;
	
	printf("Andar\tUnidade %i\n",col);
	
	/*Note que esse decremento serve para inverter a matriz na exibição 
	fazendo com que os andares fiquem de acordo com o que o usuário escolheu*/
	for(lin=ANDAR-1;lin>=0;lin--){
		printf("%i\t %i\n",lin+1,predio[lin][col-1]);
	}
}


//Diferente da anterior, essa consulta todas as unidades
void consultarTodasUnidades(int predio[ANDAR][UNIDADE]){
	int lin,col,soma;
	
	printf("Unidade\tProfissionais\n");
	//Não é necessário inverter aqui, pois os andares não são exibidos
	for(col=0;col<UNIDADE;col++){
		for(lin=0;lin<ANDAR;lin++){
			soma+=predio[lin][col];
		}
			printf("%i\t\t%i\n",col+1,soma);
			soma=0;
	}	
}

void consultarPredio(int predio[ANDAR][UNIDADE]){
	int lin,col;
	
	printf("Andar\t");
	for(col=0;col<UNIDADE;col++){
		printf("Unid %i\t",col+1);
	}
	printf("\n");
	
	//Linhas invertidas
	for(lin=ANDAR-1;lin>=0;lin--){
		printf("%i\t",lin+1);
		for(col=0;col<UNIDADE;col++){
			printf("%i\t",predio[lin][col]);
		}
		printf("\n");
	}
}

void consultarTodosAndares(int predio[ANDAR][UNIDADE]){
	int lin,col,soma;
	
	printf("Andar\t\tProfissionais\n");

	for(lin=ANDAR-1;lin>=0;lin--){
		for(col=0;col<UNIDADE;col++){
			soma+=predio[lin][col];
		}
			printf("%i\t\t%i\n",lin+1,soma);
			soma=0;
	}	
}

void salasVazias(int predio[ANDAR][UNIDADE]){
	int lin, col,lintemp,coltemp;
	
	for(lin=0;lin<ANDAR;lin++){
		printf("Andar\tUnidade\n");
		for(col=0;col<UNIDADE;col++){
			if(predio[lin][col]==0){
				lintemp=lin+1;
				coltemp=col+1;
				printf("%i\t%i\n",lintemp,coltemp);
			}
		}
		printf("\n");
	}
}

//lintemp e coltemp são variáveis que armazenam os valores de lin e col temporáriamente
void maiorNumero(int predio[ANDAR][UNIDADE]){
	int lin, col,lintemp,coltemp,maior=0;
	
	for(lin=0;lin<ANDAR;lin++){
		for(col=0;col<UNIDADE;col++){
			if(maior<predio[lin][col]){
				maior=predio[lin][col];
				lintemp=lin+1;
				coltemp=col+1;
			}
		}
	}
	printf("Andar\tUnidade %i\n",coltemp);
	printf("%i\t%i",lintemp,maior);
}

main(){
	setlocale(LC_ALL,"Portuguese");
	int menu,predio[ANDAR][UNIDADE],lin,col,num;
	
	//Menu
	do{
		system("cls");
		printf("Menu:\n");
		printf("1) Inicializar o prédio\n");
		printf("2) Alterar o número de profissionais de uma sala\n");
		printf("3) Consultar o número de profissionais de uma unidade\n");
		printf("4) Imprimir o número de profissionais de cada unidade\n");
		printf("5) Imprimir o número de profissionais do prédio\n");
		printf("6) Imprimir o número total de profissionais de cada andar\n");
		printf("7) Informar quais salas estão vazias (ou seja, sem locação)\n");
		printf("8) Identificar a unidade com o maior número de profissionais\n");
		printf("9) Finalizar programa.\n");
		printf("\nResposta: ");
		scanf("%i",&menu);
		printf("\n");
		
		//Itens do menu sendo executados
		switch(menu){
			case 1:
				system("cls");
				iniciar(predio);
			break;
			
			case 2:
				printf("Andar escolhido: ");
				scanf("%i",&lin);
				printf("Unidade escolhida: ");
				scanf("%i",&col);
				printf("\n");
				printf("Número para escrever: ");
				scanf("%i",&num);
				alterarSala(predio,lin,col,num);
				printf("\nAlterado com sucesso!");				
				printf("\n\n");
				system("pause");
			break;
		
			case 3:
				printf("Unidade a ser consultada: ");
				scanf("%i",&col);
				printf("\n");
				consultarUnidade(predio,col);
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
}while(menu!=9);

	
}

