#include <stdio.h>
#include <string.h> 

// Variaveis globais
int mesestabela = 0, i;
float tabelainvestimento[100];

// -------- FUNÇÕES --------
void mostrarSaldo(float saldo){
    printf("Saldo atual: R$ %.2f\n", saldo);
}

float atualizarRendimento(float saldo){
    float rendimento;
    printf("Digite o valor do rendimento diario: ");
    while (scanf("%f", &rendimento) != 1) {  
        printf("Entrada invalida! Digite um numero: ");
        while(getchar() != '\n'); // limpa o buffer, descartando caracteres inválidos
    }
    saldo += rendimento;
    printf("Rendimento adicionado. Novo saldo: R$ %.2f\n", saldo);
    return saldo;
}

float atualizarDespesa(float saldo){
    float despesa;
    printf("Digite o valor da despesa diaria: ");
    while (scanf("%f", &despesa) != 1) {  
        printf("Entrada invalida! Digite um numero: ");
        while(getchar() != '\n'); 
    }
    saldo -= despesa;
    printf("Despesa registrada. Novo saldo: R$ %.2f\n", saldo);
    return saldo;
}

void criarTabelaInvestimento(){
    float objetivo, parcela;

    printf("Digite o valor que deseja juntar: ");
    while (scanf("%f", &objetivo) != 1) {  
        printf("Entrada invalida! Digite um numero: ");
        while(getchar() != '\n'); 
    }

    printf("Digite em quantos meses deseja juntar: ");
    while (scanf("%d", &mesestabela) != 1 || mesestabela <= 0 || mesestabela > 100) {
        printf("Entrada invalida! Digite um numero de meses valido (1 a 100): ");
        while(getchar() != '\n'); 
    }

    parcela = objetivo / mesestabela;

    printf("\nTabela sugerida para atingir o objetivo:\n");
    for(i=0; i<mesestabela; i++){
        tabelainvestimento[i] = parcela;
        printf("Mes %d: Depositar R$ %.2f\n", i+1, tabelainvestimento[i]);
    }
}

void mostrarTabelaInvestimento(){
    if(mesestabela == 0){
        printf("Nenhuma tabela criada ainda. Va no menu e selecione 'criar nova tabela'.\n");
    } else{
        printf("Tabela de investimento:\n");
        for(i=0; i<mesestabela; i++){
            printf("Mes %d: Depositar R$ %.2f\n", i+1, tabelainvestimento[i]);
        }
    }
}

// -------- FUNÇÃO PRINCIPAL --------
int main(){
    char nomeCompleto[100]; 
    char primeiroNome[50];  // armazena apenas o primeiro nome
    int menu, retornar = 1;
    float saldoatual=0;

    printf("Bem vindo ao FinancasPro, seu gerenciador de financas e auxiliar de tabelas de investimento!\n");
    printf("Informe seu nome completo: ");
    while(getchar() != '\n'); // limpa caracteres anteriores do buffer
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin); // lê espaços

    // Remove o '\n' do final da string (causado pelo Enter)
    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    // Extrai o primeiro nome usando strtok
    strcpy(primeiroNome, strtok(nomeCompleto, " ")); 

    while (retornar == 1) {
        printf("\nOla, %s. O que gostaria de acessar?\n", primeiroNome);
        printf("1 - Gerenciador de financas\n2 - Tabelas de investimento\n3 - Sair\nEscolha: ");
        
        while (scanf("%d", &menu) != 1 || menu < 1 || menu > 3) {
            printf("Entrada invalida! Digite 1, 2 ou 3: ");
            while(getchar() != '\n');
        }

        if (menu == 1) {
            int menugerenciador, continuarGerenciador = 1;
            while (continuarGerenciador == 1) {
                printf("\nMenu do Gerenciador de Financas:\n");
                printf("1 - Ver saldo atual\n2 - Adicionar rendimento diario\n3 - Registrar despesa diaria\n4 - Voltar ao menu principal\nEscolha: ");

                while (scanf("%d", &menugerenciador) != 1 || menugerenciador < 1 || menugerenciador > 4) {
                    printf("Entrada invalida! Digite 1, 2, 3 ou 4: ");
                    while(getchar() != '\n');
                }

                if (menugerenciador == 1) {
                    mostrarSaldo(saldoatual);
                } else if (menugerenciador == 2) {
                    saldoatual = atualizarRendimento(saldoatual);
                } else if (menugerenciador == 3) {
                    saldoatual = atualizarDespesa(saldoatual);
                } else if (menugerenciador == 4) {
                    continuarGerenciador = 0;
                }
            }

        } else if (menu == 2) {
            int menutabela, continuarTabela = 1;
            while (continuarTabela == 1) {
                printf("\nMenu das Tabelas de Investimento:\n");
                printf("1 - Verificar tabela atual\n2 - Criar nova tabela\n3 - Voltar ao menu principal\nEscolha: ");

                while (scanf("%d", &menutabela) != 1 || menutabela < 1 || menutabela > 3) {
                    printf("Entrada invalida! Digite 1, 2 ou 3: ");
                    while(getchar() != '\n');
                }

                if (menutabela == 1) {
                    mostrarTabelaInvestimento();
                } else if (menutabela == 2) {
                    criarTabelaInvestimento();
                } else if (menutabela == 3) {
                    continuarTabela = 0;
                }
            }

        } else if (menu == 3) {
            printf("Saindo do programa. Ate logo, %s!\n", primeiroNome);
            retornar = 0;
        }
    }

    return 0;
}

