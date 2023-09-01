#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void decimalParaBinario(int num){
	int resto,resultado;

	resultado=num/2;	
	resto=num%2;

	printf("Divisao: %i/2\n",num);
	printf("Resto: %i\n",resto);
	printf("Resultado: %i\n\n",resultado);
	
	if(num==0){
		printf("0");
		return;
	}	
	
	else if(resultado==0){
		printf("1");
		return;
	}
		
	decimalParaBinario(resultado);
	printf("%i",resto);	
}

void decimalParaOctal(int num, int temp){
	int resto,resultado;
	
	resultado=num/8;	
	resto=num%8;
		
	printf("Divisao: %i/8\n",num);
	printf("Resto: %i\n",resto);
	printf("Resultado: %i\n\n",resultado);
	
	if(resultado!=0){
	temp=resultado;
	}
	
	else{
		printf("%i",temp);
	return;
	}

	decimalParaOctal(resultado, temp);
	printf("%i",resto);	
}

void decimalParaHexadecimal(int num, int temp){
	int resto,resultado;
	
	resultado=num/16;	
	resto=num%16;
		
	printf("Divisao: %i/16\n",num);
	printf("Resto: %i\n",resto);
	printf("Resultado: %i\n\n",resultado);
	
	if(resultado!=0){
		temp=resultado;
	}

	else if(resultado==0 && temp>=10){
		temp+=55;
		printf("%c",temp);
		return;
	}
	else{
		printf("%i",temp);
		return;
	}

	decimalParaHexadecimal(resultado, temp);
	
	if(resto>=10){
		resto+=55;
		printf("%c",resto);
	}
	else{
		printf("%i",resto);	
	}

}

int binarioParaDecimal(char paraDecimal[]){
	int num[20],tamanho,i,soma=0,resultado;
	char conv[2];
	
	tamanho=strlen(paraDecimal);
	
	for(i=0;i<tamanho;i++){
		conv[0]=paraDecimal[i];
		num[i]=atoi(conv);
		
		if(num[i]!=0 && num[i]!=1){
			printf("Numero invalido!\n");
			return;
		}
	}
	
	for(i=0;i<tamanho;i++){
		resultado=num[tamanho-i-1]*pow(2,i);	
		printf("%i * 2^%i = %i\n",num[tamanho-i-1],i,resultado);
		soma+=resultado;
	}
	printf("\n%i(10)\n\n",soma);
	return soma;
}

int main(){
	int menuDe,menuPara,num,ponte;
	char paraDecimal[20];
	
	do{
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
			case 1:
				do{
					printf("Converter de binario para: \n");
					printf("1: Octal\n");
					printf("2: Decimal\n");
					printf("3: Hexadecimal\n");
					printf("4: Voltar\n");
					printf("Resposta: ");
					scanf("%i",&menuPara);
					
					switch(menuPara){
						case 1:
						printf("\nNumero para converter: ");
						scanf("%s",paraDecimal);
						system("cls");
						printf("Converter %s(2) para octal:\n\n",paraDecimal);
						printf("Binario para decimal:\n\n");
						ponte=binarioParaDecimal(paraDecimal);
						printf("--------------\n\n");
						printf("Decimal para octal:\n\n");
						decimalParaOctal(ponte,ponte);
						printf("(8)\n\n");
						system("pause");
						system("cls");
						break;
						
						case 2:
						printf("\nNumero para converter: ");
						scanf("%s",paraDecimal);
						system("cls");
						printf("Converter %s(2) para decimal:\n\n",paraDecimal);
						printf("Binario para decimal:\n\n");
						binarioParaDecimal(paraDecimal);
						system("pause");
						system("cls");
						break;
						
						case 3:
						printf("\nNumero para converter: ");
						scanf("%s",paraDecimal);
						system("cls");
						printf("Converter %s(2) para hexadecimal:\n\n",paraDecimal);
						printf("Binario para decimal:\n\n");
						ponte=binarioParaDecimal(paraDecimal);
						printf("--------------\n\n");
						printf("Binario para hexadecimal:\n\n");
						decimalParaHexadecimal(ponte,ponte);
						printf("(16)\n\n");
						system("pause");
						system("cls");
						break;
					}
					system("cls");
				}while(menuPara!=4);
			break;
			
			case 3:
				do{
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
						printf("\nNumero para converter: ");
						scanf("%i",&num);
						system("cls");
						printf("Converter %i(10) para octal:\n\n",num);
						decimalParaOctal(num,num);
						printf("(8)\n\n");
						system("pause");
						system("cls");
						break;
						
						case 3:
						printf("\nNumero para converter: ");
						scanf("%i",&num);
						system("cls");
						printf("Converter %i(10) para hexadecimal:\n\n",num);
						decimalParaHexadecimal(num,num);
						printf("(16)\n\n");
						system("pause");
						system("cls");
						break;
					}
					system("cls");
				}while(menuPara!=4);
			break;		
		}
	}while(menuDe!=5);
	return 0;
}
