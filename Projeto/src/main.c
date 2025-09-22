#include <stdio.h>

// Variaveis globais (cobre todo o programa)
int mesestabela = 0, i;
float tabelainvestimento[100];

// -------- FUNÇÕES --------
void mostrarSaldo(float saldo){
    printf("Saldo atual: R$ %.2f\n", saldo);
}

float atualizarRendimento(float saldo){
    float rendimento;
    printf("Digite o valor do rendimento diario: ");
    scanf("%f", &rendimento);
    saldo += rendimento;
    printf("Rendimento adicionado. Novo saldo: R$ %.2f\n", saldo);
    return saldo;
}

float atualizarDespesa(float saldo){
    float despesa;
    printf("Digite o valor da despesa diaria: ");
    scanf("%f", &despesa);
    saldo -= despesa;
    printf("Despesa registrada. Novo saldo: R$ %.2f\n", saldo);
    return saldo;
}

void criarTabelaInvestimento(){
    float objetivo, parcela;

    printf("Digite o valor que deseja juntar: ");
    scanf("%f", &objetivo);

    printf("Digite em quantos meses deseja juntar: ");
    scanf("%d", &mesestabela);

    float tabela[mesestabela];
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
    char nome[50];
    int menu, retornar = 1;
    float saldoatual=0;

    printf("Bem vindo ao seu gerenciador de financas e auxiliar de tabelas de investimento!\n");
    printf("Informe como gostaria de ser chamado: ");
    scanf("%s", nome);

    while (retornar == 1) {
        printf("\nOla, %s. O que gostaria de acessar?\n", nome);
        printf("1 - Gerenciador de financas\n2 - Tabelas de investimento\n3 - Sair\nEscolha: ");
        scanf("%d", &menu);

        // validação
        while (menu < 1 || menu > 3) {
            printf("Comando nao encontrado. Escolha outra opcao: ");
            scanf("%d", &menu);
        }

        if (menu == 1) {
            // --- GERENCIADOR ---
            int menugerenciador, continuarGerenciador = 1;
            while (continuarGerenciador == 1) {
                printf("\nMenu do Gerenciador de Financas:\n");
                printf("1 - Ver saldo atual\n2 - Adicionar rendimento diario\n3 - Registrar despesa diaria\n4 - Voltar ao menu principal\nEscolha: ");
                scanf("%d", &menugerenciador);

                while (menugerenciador < 1 || menugerenciador > 4) {
                    printf("Comando nao encontrado. Escolha outra opcao: ");
                    scanf("%d", &menugerenciador);
                }

                if (menugerenciador == 1) {
                    mostrarSaldo(saldoatual);
                } else if (menugerenciador == 2) {
                    saldoatual = atualizarRendimento(saldoatual);
                } else if (menugerenciador == 3) {
                    saldoatual = atualizarDespesa(saldoatual);
                } else if (menugerenciador == 4) {
                    continuarGerenciador = 0; // volta para o menu principal
                }
            }

        } else if (menu == 2) {
            // --- TABELAS ---
            int menutabela, continuarTabela = 1;
            while (continuarTabela == 1) {
                printf("\nMenu das Tabelas de Investimento:\n");
                printf("1 - Verificar tabela atual\n2 - Criar nova tabela\n3 - Voltar ao menu principal\nEscolha: ");
                scanf("%d", &menutabela);

                while (menutabela < 1 || menutabela > 3) {
                    printf("Comando nao encontrado. Escolha outra opcao: ");
                    scanf("%d", &menutabela);
                }

                if (menutabela == 1) {
                    mostrarTabelaInvestimento();
                } else if (menutabela == 2) {
                    criarTabelaInvestimento();
                } else if (menutabela == 3) {
                    continuarTabela = 0; // volta para o menu principal
                }
            }

        } else if (menu == 3) {
            // --- SAIR ---
            printf("Saindo do programa. Ate logo, %s!\n", nome);
            retornar = 0; // encerra laço principal
        }
    }

    return 0;
}
