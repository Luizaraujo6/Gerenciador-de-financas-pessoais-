#include <stdio.h>

// Variáveis globais (acessíveis em todo o programa)
int mesestabela = 0, i;                  // quantidade de meses da tabela e índice para laços
float tabelainvestimento[100];           // vetor global que guarda os valores da tabela de investimento

// -------- FUNÇÕES --------

// Função para mostrar o saldo atual
void mostrarSaldo(float saldo){
    printf("Saldo atual: R$ %.2f\n", saldo);
}

// Função para adicionar rendimento diário ao saldo
float atualizarRendimento(float saldo){
    float rendimento;
    printf("Digite o valor do rendimento diario: ");
    scanf("%f", &rendimento);
    saldo += rendimento; // soma rendimento ao saldo
    printf("Rendimento adicionado. Novo saldo: R$ %.2f\n", saldo);
    return saldo; // retorna o novo saldo atualizado
}

// Função para registrar uma despesa e descontar do saldo
float atualizarDespesa(float saldo){
    float despesa;
    printf("Digite o valor da despesa diaria: ");
    scanf("%f", &despesa);
    saldo -= despesa; // subtrai a despesa do saldo
    printf("Despesa registrada. Novo saldo: R$ %.2f\n", saldo);
    return saldo; // retorna o novo saldo atualizado
}

// Função para criar uma nova tabela de investimento
void criarTabelaInvestimento(){
    float objetivo, parcela;

    printf("Digite o valor que deseja juntar: ");
    scanf("%f", &objetivo);

    printf("Digite em quantos meses deseja juntar: ");
    scanf("%d", &mesestabela);

    parcela = objetivo / mesestabela; // valor fixo a depositar por mês

    printf("\nTabela sugerida para atingir o objetivo:\n");
    for(i=0; i<mesestabela; i++){
        tabelainvestimento[i] = parcela; // armazena no vetor global
        printf("Mes %d: Depositar R$ %.2f\n", i+1, tabelainvestimento[i]);
    }
}

// Função para mostrar a tabela já criada
void mostrarTabelaInvestimento(){
    if(mesestabela == 0){ // verifica se já foi criada uma tabela
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
    char nome[50];              // armazena o nome do usuário
    int menu, retornar = 1;     // menu principal e controle de repetição
    float saldoatual=0;         // saldo inicial do usuário

    // Mensagem de boas-vindas
    printf("Bem vindo ao FinancasPro, seu gerenciador de financas e auxiliar de tabelas de investimento!\n");
    printf("Informe como gostaria de ser chamado: ");
    scanf("%s", nome);

    // Laço principal do programa (só termina quando usuário escolhe sair)
    while (retornar == 1) {
        printf("\nOla, %s. O que gostaria de acessar?\n", nome);
        printf("1 - Gerenciador de financas\n2 - Tabelas de investimento\n3 - Sair\nEscolha: ");
        scanf("%d", &menu);

        // Validação da escolha
        while (menu < 1 || menu > 3) {
            printf("Comando nao encontrado. Escolha outra opcao: ");
            scanf("%d", &menu);
        }

        // --- GERENCIADOR DE FINANÇAS ---
        if (menu == 1) {
            int menugerenciador, continuarGerenciador = 1;
            while (continuarGerenciador == 1) { // mantém menu até usuário voltar
                printf("\nMenu do Gerenciador de Financas:\n");
                printf("1 - Ver saldo atual\n2 - Adicionar rendimento diario\n3 - Registrar despesa diaria\n4 - Voltar ao menu principal\nEscolha: ");
                scanf("%d", &menugerenciador);

                // Validação da escolha
                while (menugerenciador < 1 || menugerenciador > 4) {
                    printf("Comando nao encontrado. Escolha outra opcao: ");
                    scanf("%d", &menugerenciador);
                }

                // Chama a função correspondente
                if (menugerenciador == 1) {
                    mostrarSaldo(saldoatual);
                } else if (menugerenciador == 2) {
                    saldoatual = atualizarRendimento(saldoatual);
                } else if (menugerenciador == 3) {
                    saldoatual = atualizarDespesa(saldoatual);
                } else if (menugerenciador == 4) {
                    continuarGerenciador = 0; // volta ao menu principal
                }
            }

        // --- TABELAS DE INVESTIMENTO ---
        } else if (menu == 2) {
            int menutabela, continuarTabela = 1;
            while (continuarTabela == 1) { // mantém menu até usuário voltar
                printf("\nMenu das Tabelas de Investimento:\n");
                printf("1 - Verificar tabela atual\n2 - Criar nova tabela\n3 - Voltar ao menu principal\nEscolha: ");
                scanf("%d", &menutabela);

                // Validação da escolha
                while (menutabela < 1 || menutabela > 3) {
                    printf("Comando nao encontrado. Escolha outra opcao: ");
                    scanf("%d", &menutabela);
                }

                // Executa a ação correspondente
                if (menutabela == 1) {
                    mostrarTabelaInvestimento();
                } else if (menutabela == 2) {
                    criarTabelaInvestimento();
                } else if (menutabela == 3) {
                    continuarTabela = 0; // volta ao menu principal
                }
            }

        // --- SAIR ---
        } else if (menu == 3) {
            printf("Saindo do programa. Ate logo, %s!\n", nome);
            retornar = 0; // encerra laço principal
        }
    }

    return 0;
}
