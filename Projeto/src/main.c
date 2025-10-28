#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Variaveis globais
char *nomeCompleto = NULL;  // alocado dinamicamente
char *primeiroNome = NULL;  // alocado dinamicamente
float saldoAtual = 0;

// Tabela de desafios (matriz: meses x 20 depositos por mes)
#define MAX_MESES 12
#define DEPOSITOS_POR_MES 20
float tabelaDesafio[MAX_MESES][DEPOSITOS_POR_MES];
int mesesDesafio = 0;

// -------- FUNCOES --------
void mostrarSaldo(float *saldo){
    printf("Saldo atual: R$ %.1f\n", *saldo);
}

void atualizarRendimento(float *saldo){
    float rendimento;
    printf("Digite o valor do rendimento diario: ");
    while(scanf("%f", &rendimento) != 1){
        printf("Entrada invalida! Digite um numero: ");
        while(getchar() != '\n');
    }
    *saldo += rendimento;  // ponteiro altera o valor diretamente
    printf("Rendimento adicionado. Novo saldo: R$ %.1f\n", *saldo);
}

void atualizarDespesa(float *saldo){
    float despesa;
    printf("Digite o valor da despesa diaria: ");
    while(scanf("%f", &despesa) != 1){
        printf("Entrada invalida! Digite um numero: ");
        while(getchar() != '\n');
    }
    *saldo -= despesa;  // ponteiro altera o valor diretamente
    printf("Despesa registrada. Novo saldo: R$ %.1f\n", *saldo);
}

void verTabelaDesafio(){
    if(mesesDesafio == 0){
        printf("Nenhum desafio criado ainda. Crie um desafio primeiro.\n");
        return;
    }

    printf("\nTabela do desafio:\n");
    printf("Mes\tDeposito\tValor a depositar\tTotal acumulado\n");
    float acumulado = 0;
    for(int i = 0; i < mesesDesafio; i++){
        for(int j = 0; j < DEPOSITOS_POR_MES; j++){
            if(tabelaDesafio[i][j] > 0){
                acumulado += tabelaDesafio[i][j];
                printf("%d\t%d\t\t%.1f\t\t\t%.1f\n", i+1, j+1, tabelaDesafio[i][j], acumulado);
            }
        }
    }
    printf("Total acumulado: %.1f\n", acumulado);
}

void criarDesafioAutomatico(){
    float metaTotal;
    printf("Digite a meta total anual: ");
    while(scanf("%f", &metaTotal) != 1 || metaTotal <= 0){
        printf("Entrada invalida! Digite um numero positivo: ");
        while(getchar() != '\n');
    }

    mesesDesafio = 12;

    // Zera a tabela antiga
    for(int i = 0; i < MAX_MESES; i++)
        for(int j = 0; j < DEPOSITOS_POR_MES; j++)
            tabelaDesafio[i][j] = 0;

    float depositoMes = ceil((metaTotal / mesesDesafio) * 10) / 10.0;
    float depositoDiario = ceil((depositoMes / DEPOSITOS_POR_MES) * 10) / 10.0;
    float acumulado = 0;

    printf("\nDesafio automatico:\n");
    printf("Mes\tDeposito\tValor a depositar\tTotal acumulado\n");
    for(int i = 0; i < mesesDesafio; i++){
        for(int j = 0; j < DEPOSITOS_POR_MES; j++){
            tabelaDesafio[i][j] = depositoDiario;
            acumulado += depositoDiario;
            printf("%d\t%d\t\t%.1f\t\t\t%.1f\n", i+1, j+1, depositoDiario, acumulado);
        }
    }
    printf("Meta anual: %.1f, Total acumulado: %.1f\n", metaTotal, acumulado);
}

void criarDesafioPersonalizado(){
    float metaTotal;
    int meses;
    printf("Digite a meta total: ");
    while(scanf("%f", &metaTotal) != 1 || metaTotal <= 0){
        printf("Entrada invalida! Digite um numero positivo: ");
        while(getchar() != '\n');
    }

    printf("Em quantos meses deseja juntar (max 12): ");
    while(scanf("%d", &meses) != 1 || meses <= 0 || meses > MAX_MESES){
        printf("Entrada invalida! Digite 1-%d: ", MAX_MESES);
        while(getchar() != '\n');
    }

    mesesDesafio = meses;
    int totalDepositos = meses * DEPOSITOS_POR_MES;

    // Zera tabela antiga
    for(int i = 0; i < MAX_MESES; i++)
        for(int j = 0; j < DEPOSITOS_POR_MES; j++)
            tabelaDesafio[i][j] = 0;

    float valorBase = metaTotal / totalDepositos;
    float acumulado = 0;
    float incremento = valorBase * 0.1;
    float valorAtual = valorBase;

    printf("\nDesafio personalizado:\n");
    printf("Mes\tDeposito\tValor a depositar\tTotal acumulado\n");

    for(int i = 0; i < mesesDesafio; i++){
        for(int j = 0; j < DEPOSITOS_POR_MES; j++){
            tabelaDesafio[i][j] = ceil(valorAtual * 10) / 10.0;
            acumulado += tabelaDesafio[i][j];
            printf("%d\t%d\t\t%.1f\t\t\t%.1f\n", i+1, j+1, tabelaDesafio[i][j], acumulado);

            valorAtual += incremento;

            if(acumulado >= metaTotal){
                for(int ii = i; ii < mesesDesafio; ii++){
                    for(int jj = (ii == i ? j+1 : 0); jj < DEPOSITOS_POR_MES; jj++){
                        tabelaDesafio[ii][jj] = 0;
                    }
                }
                break;
            }
        }
        if(acumulado >= metaTotal) break;
    }

    printf("Meta desejada: %.1f, Total acumulado: %.1f\n", metaTotal, acumulado);
}

// -------- FUNCAO PRINCIPAL --------
int main(){
    int menu, continuar = 1;

    // Alocacao dinamica do nome
    nomeCompleto = (char*) malloc(200 * sizeof(char));
    if(nomeCompleto == NULL){
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Bem vindo ao FinancasPro, seu gerenciador de financas!\n");
    printf("Informe seu nome completo: ");
    fgets(nomeCompleto, 200, stdin);
    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    // Alocacao dinamica para o primeiro nome
    char *token = strtok(nomeCompleto, " ");
    primeiroNome = (char*) malloc((strlen(token)+1) * sizeof(char));
    if(primeiroNome == NULL){
        printf("Erro ao alocar memoria.\n");
        free(nomeCompleto);
        return 1;
    }
    strcpy(primeiroNome, token);

    while(continuar){
        printf("\nOla, %s. O que gostaria de acessar?\n", primeiroNome);
        printf("1 - Gerenciador de financas\n2 - Desafio da tabela de investimento\n3 - Sair\nEscolha: ");

        while(scanf("%d", &menu) != 1 || menu < 1 || menu > 3){
            printf("Entrada invalida! Digite 1, 2 ou 3: ");
            while(getchar() != '\n');
        }

        if(menu == 1){
            int subMenu, gerenciador = 1;
            while(gerenciador){
                printf("\nMenu do Gerenciador:\n");
                printf("1 - Ver saldo atual\n2 - Adicionar rendimento diario\n3 - Registrar despesa diaria\n4 - Voltar\nEscolha: ");
                while(scanf("%d", &subMenu) != 1 || subMenu < 1 || subMenu > 4){
                    printf("Entrada invalida! Digite 1, 2, 3 ou 4: ");
                    while(getchar() != '\n');
                }
                if(subMenu == 1) mostrarSaldo(&saldoAtual);
                else if(subMenu == 2) atualizarRendimento(&saldoAtual);
                else if(subMenu == 3) atualizarDespesa(&saldoAtual);
                else if(subMenu == 4) gerenciador = 0;
            }

        } else if(menu == 2){
            int subMenu, desafio = 1;
            while(desafio){
                printf("\nMenu do Desafio da tabela de investimento:\n");
                printf("1 - Ver tabela do desafio\n2 - Criar desafio automatico\n3 - Criar desafio personalizado\n4 - Voltar\nEscolha: ");
                while(scanf("%d", &subMenu) != 1 || subMenu < 1 || subMenu > 4){
                    printf("Entrada invalida! Digite 1, 2, 3 ou 4: ");
                    while(getchar() != '\n');
                }
                if(subMenu == 1) verTabelaDesafio();
                else if(subMenu == 2) criarDesafioAutomatico();
                else if(subMenu == 3) criarDesafioPersonalizado();
                else if(subMenu == 4) desafio = 0;
            }

        } else if(menu == 3){
            printf("Saindo do programa. Ate logo, %s!\n", primeiroNome);
            continuar = 0;
        }
    }

    // Libera memoria alocada dinamicamente
    free(nomeCompleto);
    free(primeiroNome);

    return 0;
}

