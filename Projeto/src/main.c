#include <stdio.h>

int main(){
    char nome[50];
    int menu;

    printf("Bem vindo ao seu gerenciador de financas e auxiliar de tabelas de investimento.");
    printf("Informe como gostaria de ser chamado: ");
    scanf("%s", &nome);

    printf("Ola, %s. O que gostaria de acessar? \n(1 - gerenciador de financas 2 - tabelas de investimento) \n", nome);
    scanf(" %d", &menu);

    if (menu == 1){
        printf("Direcionando para gerenciador de financas");

    } else if (menu == 2){  
        printf("Direcionando para tabelas de investimento");
        
    } else {
        printf("Comando não encontrado.");
    }

    return 0;
}