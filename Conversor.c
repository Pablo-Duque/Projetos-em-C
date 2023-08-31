#include <stdio.h>

void decimalParaBinario(int num){
	int resto,resultado;

	resultado=num/2;	
	resto=num%2;
	
	if(resultado==0){
		printf("1");
	return;
}

	printf("Divisao: %i/2\n",num);
	printf("Resto: %i\n",resto);
	printf("Resultado: %i\n\n",resultado);
		
	decimalParaBinario(resultado);
	printf("%i",resto);	
}

void decimalParaOctal(int num, int temp){
	int resto,resultado;
	
	resultado=num/8;	
	resto=num%8;
		
	if(resultado!=0){
	temp=resultado;
	}
	
	if(resultado==0){
		printf("%i",temp);
	return;
}

	printf("Divisao: %i/8\n",num);
	printf("Resto: %i\n",resto);
	printf("Resultado: %i\n\n",resultado);

	decimalParaOctal(resultado, temp);
	printf("%i",resto);	
}

void decimalParaHexadecimal(int num, int temp){
	int resto,resultado;
	
	resultado=num/16;	
	resto=num%16;
		
	if(resultado!=0){
	temp=resultado;
	}
	
	if(resultado==0){
		printf("%i",temp);
	return;
}
	printf("Divisao: %i/16\n",num);
	printf("Resto: %i\n",resto);
	printf("Resultado: %i\n\n",resultado);

	decimalParaHexadecimal(resultado, temp);
	if(resto==10){
		resto=65;
		printf("%c",resto);
	}
	else if(resto==11){
		resto=66;
		printf("%c",resto);
	}
	else if(resto==12){
		resto=67;
		printf("%c",resto);
	}
	else if(resto==13){
		resto=68;
		printf("%c",resto);
	}
	else if(resto==14){
		resto=69;
		printf("%c",resto);
	}
	else if(resto==15){
		resto=70;
		printf("%c",resto);
	}
	else{
		printf("%i",resto);	
	}
}

main(){
	int menuDe,menuPara,num;
	
	while(menuDe!=5){
		printf("Converter de: \n");
		printf("1: Binario\n");
		printf("2: Octal\n");
		printf("3: Decimal\n");
		printf("4: Hexadecimal\n");
		printf("5: Sair\n");
		printf("Resposta: ");
		scanf("%i",&menuDe);
		system("cls");
		
		switch(menuDe){
			case 3:
				while(menuPara!=4){
					printf("Converter de decimal para: \n");
					printf("1: Binario\n");
					printf("2: Octal\n");
					printf("3: Hexadecimal\n");
					printf("4: Voltar\n");
					printf("Resposta: ");
					scanf("%i",&menuPara);
					switch(menuPara){
						case 1:
						printf("\nNumero para converter: ");
						scanf("%i",&num);
						system("cls");
						printf("Converter %i(10) para binario:\n\n",num);
						decimalParaBinario(num);
						printf("(2)\n\n");
						system("pause");
						system("cls");
						break;
						
						case 2:
						system("cls");
						printf("Converter %i(10) para Octal:\n\n",num);
						decimalParaOctal(num,0);
						printf("(8)\n\n");
						system("pause");
						system("cls");
						break;
						
						case 3:
						system("cls");
						printf("Converter %i(10) para Hexadecimal:\n\n",num);
						decimalParaHexadecimal(num,0);
						printf("(16)\n\n");
						system("pause");
						system("cls");
						break;
					}
					system("cls");
				}
			break;		
		}
	}
}
