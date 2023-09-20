#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void decimalParaBinario(int num){
	int resto, resultado;
	
	//Ja que nao converte numeros negativos
	if(num < 0){
		printf("Numero invalido!");
		return;
	}
	
	resultado = num/2;	
	resto = num%2;

	//Mostra a conta efetuada pelo programa
	printf("Divisao: %i/2\n", num);
	printf("Resto: %i\n", resto);
	printf("Resultado: %i\n\n", resultado);
	
	//Se o num for 0 nao tem porque continuar a conta
	if(num == 0){
		printf("0");
		return;
	}	
	
	//Se um numero binario for diferente de 0 ele sempre comeca com 1
	else if(resultado == 0){
		printf("1");
		return;
	}
		
	decimalParaBinario(resultado);
	
	/*Mostrar resultado invertido, pois na conversao de outras bases para decimal voce 
	vai do ultimo resultado das divisoes ate o primeiro*/
	printf("%i", resto);	
}

void decimalParaOctal(int num, int temp){
	int resto, resultado;

	if(num < 0){
		printf("Numero invalido!");
		return;
	}
	
	//Mudanca de base, novos valores
	resultado = num/8;	
	resto = num%8;
		
	printf("Divisao: %i/8\n", num);
	printf("Resto: %i\n", resto);
	printf("Resultado: %i\n\n", resultado);
	
	/*Armazena o resultado da ultima divisao para nao se perder durante
	a recursividade*/
	if(resultado != 0){
		temp = resultado;
	}
	
	/*Escreve o ultimo resultado na tela ou o proprio numero de entrada se
	nao for divisivel por 8*/
	else{
		printf("%i", temp);
		return;
	}

	decimalParaOctal(resultado, temp);
	printf("%i", resto);	
}

void decimalParaHexadecimal(int num, int temp){
	int resto, resultado;
	
	if(num < 0){
		printf("Numero invalido!");
		return;
	}
	
	resultado = num/16;	
	resto = num%16;
		
	printf("Divisao: %i/16\n", num);
	printf("Resto: %i\n", resto);
	printf("Resultado: %i\n\n", resultado);
	
	if(resultado != 0){
		temp = resultado;
	}

	/*Para o ultimo resultado ser letra, o A (10) por exemplo equivale
	ao 65 na tabela ASCII*/
	else if(resultado == 0 && temp >= 10){
		temp += 55;
		printf("%c", temp);
		return;
	}
	
	else{
		printf("%i", temp);
		return;
	}

	decimalParaHexadecimal(resultado, temp);
	
	//Para os resultados intermediarios serem letras se necessario
	if(resto >= 10){
		resto += 55;
		printf("%c", resto);
	}
	
	else{
		printf("%i", resto);	
	}
}

int binarioParaDecimal(char paraDecimal[]){
	int num[20], tamanho, i, soma=0, resultado;
	char conv[2];
	
	//Descobrir o tamanho do numero digitado
	tamanho=strlen(paraDecimal);
	
	//Converte a string em inteiro
	for(i = 0; i < tamanho; i++){
		conv[0] = paraDecimal[i];
		num[i] = atoi(conv);
		
		//Protecao contra numeros que nao fazem parte da base
		if(num[i] != 0 && num[i] != 1){
			printf("Numero invalido!(2)\n\n");
			return soma;
		}
	}
	
	//Conta de exponenciacao
	for(i = 0; i < tamanho; i++){
		resultado = num[tamanho-i-1]*pow(2,i);	
		printf("%i * 2^%i = %i\n", num[tamanho-i-1], i, resultado);
		soma += resultado;
	}
	
	printf("\n%i(10)\n\n", soma);
	return soma;
}

int octalParaDecimal(char paraDecimal[]){
	int num[20], tamanho, i, soma=0, resultado;
	char conv[2];
	
	tamanho = strlen(paraDecimal);
	
	for(i = 0; i < tamanho; i++){
		conv[0] = paraDecimal[i];
		num[i] = atoi(conv);
		
		if(num[i] > 7){
			printf("Numero invalido!(8)\n\n");
			return soma;
		}
	}
	
	for(i = 0; i < tamanho; i++){
		resultado = num[tamanho-i-1]*pow(8,i);	
		printf("%i * 8^%i = %i\n", num[tamanho-i-1], i, resultado);
		soma += resultado;
	}
	
	printf("\n%i(10)\n\n", soma);
	return soma;
}

int hexadecimalParaDecimal(char paraDecimal[]){
	int num[20], tamanho, i, soma=0, resultado;
	char conv[2];
	
	tamanho = strlen(paraDecimal);
	
	/*Converter as letras digitadas para numeros, caso contrario
	o atoi atribuiria 0 no lugar*/
	for(i = 0; i < tamanho; i++){
		if(paraDecimal[i] == 'A' || paraDecimal[i] == 'a'){
			num[i] = 10;
		}
		
		else if(paraDecimal[i] == 'B' || paraDecimal[i] == 'b'){
			num[i] = 11;
		}

		else if(paraDecimal[i] == 'C' || paraDecimal[i] == 'c'){
			num[i] = 12;
		}

		else if(paraDecimal[i] == 'D' || paraDecimal[i] == 'd'){
			num[i] = 13;
		}

		else if(paraDecimal[i] == 'E' || paraDecimal[i] == 'e'){
			num[i] = 14;
		}

		else if(paraDecimal[i] == 'F' || paraDecimal[i] == 'f'){
			num[i] = 15;
		}

		else{
			conv[0] = paraDecimal[i];
			num[i] = atoi(conv);
		}	
	}
	
	for(i = 0; i < tamanho; i++){
		resultado = num[tamanho-i-1] * pow(16, i);	
		printf("%i * 16^%i = %i\n", num[tamanho-i-1], i, resultado);
		soma += resultado;
	}
	
	printf("\n%i(10)\n\n", soma);
	return soma;
}

int main(){
	int menu[2], num, ponte;
	char input[50], paraDecimal[20];
	
	do{
		printf("Converter de: \n\n");
		printf("1: Binario\n");
		printf("2: Octal\n");
		printf("3: Decimal\n");
		printf("4: Hexadecimal\n");
		printf("5: Sair\n");
		printf("\nResposta: ");
		fgets(input, 50, stdin);
		sscanf(input, "%i", &menu[0]);
		system("cls");
		
		switch(menu[0]){
			case 1:
				do{
					printf("Converter de binario para: \n");
					printf("1: Octal\n");
					printf("2: Decimal\n");
					printf("3: Hexadecimal\n");
					printf("4: Voltar\n");
					printf("\nResposta: ");
					fgets(input, 50, stdin);
					sscanf(input, "%i", &menu[1]);
					
					switch(menu[1]){
						case 1:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(2) para octal:\n\n", paraDecimal);
							printf("Binario para decimal:\n\n");
							ponte = binarioParaDecimal(paraDecimal);
							printf("--------------\n\n");
							printf("Decimal para octal:\n\n");
							decimalParaOctal(ponte, ponte);
							printf("(8)\n\n");
							system("pause");
							system("cls");
						break;
						
						case 2:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(2) para decimal:\n\n", paraDecimal);
							binarioParaDecimal(paraDecimal);
							system("pause");
							system("cls");
						break;
						
						case 3:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(2) para hexadecimal:\n\n", paraDecimal);
							printf("Binario para decimal:\n\n");
							ponte = binarioParaDecimal(paraDecimal);
							printf("--------------\n\n");
							printf("Decimal para hexadecimal:\n\n");
							decimalParaHexadecimal(ponte, ponte);
							printf("(16)\n\n");
							system("pause");
							system("cls");
						break;
					}
					system("cls");
				}while(menu[1] != 4);
			break;
			
			case 2:
				do{
					printf("Converter de octal para: \n");
					printf("1: Binario\n");
					printf("2: Decimal\n");
					printf("3: Hexadecimal\n");
					printf("4: Voltar\n");
					printf("Resposta: ");
					fgets(input, 50, stdin);
					sscanf(input, "%i", &menu[1]);
					
					switch(menu[1]){
						case 1:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(8) para binario:\n\n", paraDecimal);
							printf("Octal para decimal:\n\n");
							ponte = octalParaDecimal(paraDecimal);
							printf("--------------\n\n");
							printf("Decimal para binario:\n\n");
							decimalParaBinario(ponte);
							printf("(2)\n\n");
							system("pause");
							system("cls");
						break;
						
						case 2:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(8) para decimal:\n\n", paraDecimal);
							octalParaDecimal(paraDecimal);
							system("pause");
							system("cls");
						break;
						
						case 3:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(8) para hexadecimal:\n\n", paraDecimal);
							printf("Octal para decimal:\n\n");
							ponte = octalParaDecimal(paraDecimal);
							printf("--------------\n\n");
							printf("Decimal para hexadecimal:\n\n");
							decimalParaHexadecimal(ponte, ponte);
							printf("(16)\n\n");
							system("pause");
							system("cls");
						break;
					}
					system("cls");
				}while(menu[1] != 4);
			break;
			
			case 3:
				do{
					printf("Converter de decimal para: \n");
					printf("1: Binario\n");
					printf("2: Octal\n");
					printf("3: Hexadecimal\n");
					printf("4: Voltar\n");
					printf("Resposta: ");
					fgets(input, 50, stdin);
					sscanf(input, "%i", &menu[1]);
					switch(menu[1]){
						case 1:
							printf("\nNumero para converter: ");
							fgets(input, 50, stdin);
							sscanf(input, "%i", &num);
							system("cls");
							printf("Converter %i(10) para binario:\n\n", num);
							decimalParaBinario(num);
							printf("(2)\n\n");
							system("pause");
							system("cls");
						break;
						
						case 2:
							printf("\nNumero para converter: ");
							fgets(input, 50, stdin);
							sscanf(input, "%i", &num);
							system("cls");
							printf("Converter %i(10) para octal:\n\n", num);
							decimalParaOctal(num, num);
							printf("(8)\n\n");
							system("pause");
							system("cls");
						break;
						
						case 3:
							printf("\nNumero para converter: ");
							fgets(input, 50, stdin);
							sscanf(input, "%i", &num);
							system("cls");
							printf("Converter %i(10) para hexadecimal:\n\n", num);
							decimalParaHexadecimal(num, num);
							printf("(16)\n\n");
							system("pause");
							system("cls");
						break;
					}
					system("cls");
				}while(menu[1] != 4);
			break;	
			
			case 4:
				do{
					printf("Converter de hexadecimal para: \n");
					printf("1: Binario\n");
					printf("2: Octal\n");
					printf("3: Decimal\n");
					printf("4: Voltar\n");
					printf("Resposta: ");
					fgets(input, 50, stdin);
					sscanf(input, "%i", &menu[1]);
					
					switch(menu[1]){
						case 1:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(16) para binario:\n\n", paraDecimal);
							printf("Hexadecimal para decimal:\n\n");
							ponte = hexadecimalParaDecimal(paraDecimal);
							printf("--------------\n\n");
							printf("Decimal para binario:\n\n");
							decimalParaBinario(ponte);
							printf("(2)\n\n");
							system("pause");
							system("cls");
						break;
						
						case 2:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(16) para octal:\n\n", paraDecimal);
							printf("Hexadecimal para decimal:\n\n");
							ponte = hexadecimalParaDecimal(paraDecimal);
							printf("--------------\n\n");
							printf("Decimal para octal:\n\n");
							decimalParaOctal(ponte, ponte);
							printf("(8)\n\n");
							system("pause");
							system("cls");
						break;
						
						case 3:
							printf("\nNumero para converter: ");
							fgets(paraDecimal, 50, stdin);
							system("cls");
							printf("Converter %s(16) para decimal:\n\n", paraDecimal);
							hexadecimalParaDecimal( paraDecimal);
							system("pause");
							system("cls");
						break;
					}
					system("cls");
				}while(menu[1] != 4);
			break;	
		}	
	}while(menu[0] != 5);
	
	return 0;
}
