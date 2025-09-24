#include "../include/academia.h"

// Variáveis globais
Membro membros[MAX_MEMBROS];
Plano planos[MAX_PLANOS];
Pagamento pagamentos[MAX_PAGAMENTOS];
RegistroFrequencia frequencias[MAX_FREQUENCIA];

int total_membros = 0;
int total_planos = 0;
int total_pagamentos = 0;
int total_frequencias = 0;

int main() {
    printf("===========================================\n");
    printf("    SISTEMA DE GERENCIAMENTO COREVITA FIT\n");
    printf("===========================================\n\n");
    
    // Carregar dados salvos
    carregar_dados();
    
    // Se nao há planos cadastrados, criar planos padrão
    if (total_planos == 0) {
        inicializar_planos_padrao();
    }
    
    menu_principal();
    
    // Salvar dados antes de sair
    salvar_dados();
    
    printf("\nObrigado por usar o Sistema CoreVita Fit!\n");
    return 0;
}

void menu_principal() {
    int opcao;
    
    do {
        limpar_tela();
        printf("===========================================\n");
        printf("           COREVITA FIT - MENU PRINCIPAL\n");
        printf("===========================================\n\n");
        printf("1. Gerenciar Membros\n");
        printf("2. Gerenciar Planos\n");
        printf("3. Gerenciar Pagamentos\n");
        printf("4. Controle de Frequencia\n");
        printf("5. Relatorios\n");
        printf("6. Verificar Vencimentos Proximos\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                menu_membros();
                break;
            case 2:
                menu_planos();
                break;
            case 3:
                menu_pagamentos();
                break;
            case 4:
                menu_frequencia();
                break;
            case 5:
                menu_relatorios();
                break;
            case 6:
                verificar_vencimentos_proximos();
                pausar();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nopcao invalida! Pressione Enter para continuar...");
                getchar();
                getchar();
        }
    } while(opcao != 0);
}

void menu_membros() {
    int opcao;
    
    do {
        limpar_tela();
        printf("===========================================\n");
        printf("           GERENCIAMENTO DE MEMBROS\n");
        printf("===========================================\n\n");
        printf("1. Cadastrar Membro\n");
        printf("2. Listar Membros\n");
        printf("3. Buscar Membro\n");
        printf("4. Editar Membro\n");
        printf("5. Renovar Plano\n");
        printf("6. Remover Membro\n");
        printf("0. Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrar_membro();
                break;
            case 2:
                listar_membros();
                break;
            case 3:
                buscar_membro();
                break;
            case 4:
                editar_membro();
                break;
            case 5:
                renovar_plano_membro();
                break;
            case 6:
                remover_membro();
                break;
            case 0:
                break;
            default:
                printf("\nopcao invalida! Pressione Enter para continuar...");
                getchar();
                getchar();
        }
    } while(opcao != 0);
}

void menu_planos() {
    int opcao;
    
    do {
        limpar_tela();
        printf("===========================================\n");
        printf("           GERENCIAMENTO DE PLANOS\n");
        printf("===========================================\n\n");
        printf("1. Cadastrar Plano\n");
        printf("2. Listar Planos\n");
        printf("3. Editar Plano\n");
        printf("4. Remover Plano\n");
        printf("0. Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrar_plano();
                break;
            case 2:
                listar_planos();
                break;
            case 3:
                editar_plano();
                break;
            case 4:
                remover_plano();
                break;
            case 0:
                break;
            default:
                printf("\nopcao invalida! Pressione Enter para continuar...");
                getchar();
                getchar();
        }
    } while(opcao != 0);
}

void menu_pagamentos() {
    int opcao;
    
    do {
        limpar_tela();
        printf("===========================================\n");
        printf("           GERENCIAMENTO DE PAGAMENTOS\n");
        printf("===========================================\n\n");
        printf("1. Registrar Pagamento\n");
        printf("2. Listar Pagamentos\n");
        printf("3. Verificar Pendencias\n");
        printf("0. Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                registrar_pagamento();
                break;
            case 2:
                listar_pagamentos();
                break;
            case 3:
                verificar_pendencias();
                break;
            case 0:
                break;
            default:
                printf("\nopcao invalida! Pressione Enter para continuar...");
                getchar();
                getchar();
        }
    } while(opcao != 0);
}

void menu_frequencia() {
    int opcao;
    
    do {
        limpar_tela();
        printf("===========================================\n");
        printf("           CONTROLE DE FREQUENCIA\n");
        printf("===========================================\n\n");
        printf("1. Registrar Entrada\n");
        printf("2. Registrar Saida\n");
        printf("3. Listar Frequencia\n");
        printf("0. Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                registrar_entrada();
                break;
            case 2:
                registrar_saida();
                break;
            case 3:
                listar_frequencia();
                break;
            case 0:
                break;
            default:
                printf("\nopcao invalida! Pressione Enter para continuar...");
                getchar();
                getchar();
        }
    } while(opcao != 0);
}

void menu_relatorios() {
    int opcao;
    
    do {
        limpar_tela();
        printf("===========================================\n");
        printf("                RELATORIOS\n");
        printf("===========================================\n\n");
        printf("1. Membros Ativos\n");
        printf("2. Receita Mensal\n");
        printf("3. Frequencia por Membro\n");
        printf("0. Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                relatorio_membros_ativos();
                break;
            case 2:
                relatorio_receita_mensal();
                break;
            case 3:
                relatorio_frequencia_membro();
                break;
            case 0:
                break;
            default:
                printf("\nopcao invalida! Pressione Enter para continuar...");
                getchar();
                getchar();
        }
    } while(opcao != 0);
}
