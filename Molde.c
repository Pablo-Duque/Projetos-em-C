#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void criarMolde (char molde [50][50], int comprimento, int largura, char estampa){
    int lin, col;

    for(lin = 0; lin < largura; lin++){
        for(col = 0; col < comprimento; col++){
            if(lin%2 == 0 || col%2 == 0){
                molde[lin][col] = estampa;
            }
            
            else{
            	molde[lin][col] = ' ';
			}
        }
    }
}

void alternarMolde (char molde [50][50], int comprimento, int largura, char estampa){
    int lin, col;

    for(lin = 0; lin < largura; lin++){
        for(col = 0; col < comprimento; col++){
            if(molde[lin][col] == estampa){
                molde[lin][col] = ' ';
            }

            else{
                molde[lin][col] = estampa;
            }
        }
    }
}

void mostrarMolde (char molde[50][50], int comprimento, int largura){
    int lin, col;

	printf("\nSeu molde:\n\n");
	
    for(lin = 0; lin < largura; lin++){
        for(col = 0; col < comprimento; col++){
            printf("%c ", molde[lin][col]);
        }
        printf("\n");
    }
}

int main(){
    int menu[2], largura, comprimento, lin, col;
    char molde[50][50], estampa[2], moldesalvo[255];
    bool criou, alternou;

    FILE *txtmolde;

    do{
    	system("cls");
    	
        printf("Menu: \n\n");
        printf("1: Ver molde\n");
        printf("2: Opcoes do molde\n");
        printf("3: Sair\n");
        printf("\nResposta: ");
        scanf("%i", &menu[0]);
        
        switch(menu[0]){
            case 1:
                do{
                    system("cls");
                    printf("Ver molde: \n\n");
                    printf("1: Ver molde atual\n");
                    printf("2: Ver moldes salvos\n");
                    printf("3: Voltar\n");
                    printf("\nResposta: ");
                    scanf("%i", &menu[1]); 
                    
                        switch(menu[1]){
                            case 1:
                                if(criou == true){
                                mostrarMolde(molde, comprimento, largura);
                                }

                                else{
                                    printf("\nO molde ainda nao foi criado!");
                                }
                                
                                printf("\n\n");
                                system("pause");
                                system("cls");
                            break;
                            
                            case 2:
                                txtmolde = fopen("./Moldes.txt", "r");

                                if(txtmolde == NULL){
                                    printf("\nVoce nao tem nenhum molde salvo!");
                                    printf("\n\n");
                                }

                                else{
                                    printf("\n");
                                    while (!feof(txtmolde)){
                                    fgets(moldesalvo, 255, txtmolde);
                                    printf("%s", moldesalvo);
                                    }
                                    fclose(txtmolde);
                                }

                                system("pause");
                                system("cls");
                            break;
                        }
                }while(menu[1] != 3);
            break;

            case 2:
                do{
                    system("cls");
                    printf("Opcoes do molde: \n\n");
                    printf("1: Criar molde\n");
                    printf("2: Salvar molde\n");
                    printf("3: Mudar estampa\n");
                    printf("4: Alternar molde\n");
                    printf("5: Voltar\n");
                    printf("\nResposta: ");
                    scanf("%i", &menu[1]); 

                    switch(menu[1]){
                            case 1:
                                printf("\nComprimento do molde: ");
                                scanf("%i", &comprimento);
                                printf("Largura do molde: ");
                                scanf("%i", &largura);
                                printf("Estampa do molde: ");
                                scanf("%s", estampa);

                                criarMolde(molde, comprimento, largura, estampa[0]);
                                criou = true;

                                mostrarMolde(molde, comprimento, largura);

                                printf("\n\n");
                                system("pause");
                                system("cls");
                            break;
                            
                            case 2:
                                if(criou == true){
                               		txtmolde = fopen("./Moldes.txt", "a");
                                
	                                for(lin = 0; lin < largura; lin++){
	                                    for(col = 0; col < comprimento; col++){
	                                        fprintf(txtmolde, "%c ", molde[lin][col]);
	                                    }
	                                    fprintf(txtmolde, "\n");
	                                }
	                                    fprintf(txtmolde, "\n\n");
	                                    printf("\nMolde salvo com sucesso!");
	                                    fclose(txtmolde);
                                }

                                else{
                                    printf("\nO molde ainda nao foi criado!");
                                }

                                printf("\n\n");
                                system("pause");
                                system("cls");
                            break;
                            
                            case 3:
                            if(criou == true){
                                printf("\nEstampa nova: ");
                                scanf("%s", estampa);

                                if(alternou == true){
                                    criarMolde(molde, comprimento, largura, estampa[0]);
                                    alternarMolde(molde, comprimento, largura, estampa[0]);
                                }
                                
                                else{
                                    criarMolde(molde, comprimento, largura, estampa[0]);
                                }

                                mostrarMolde(molde, comprimento, largura);
                            }
                                
                            else{
                                printf("\nO molde ainda nao foi criado!");
                            }

                                printf("\n\n");
                                system("pause");
                                system("cls");
                            break;
                            
                            case 4:                        
                                    if(criou == true){
                                    alternarMolde(molde, comprimento, largura, estampa[0]);

                                    alternou = true;

                                    mostrarMolde(molde, comprimento, largura);
                                }

                            else{
                                printf("\nO molde ainda nao foi criado!");
                            }

                                printf("\n\n");
                                system("pause");
                                system("cls");
                            break;
                    }
                }while(menu[1] != 5);
            break;
        }
    }while(menu[0] != 3);

    return 0;
}
