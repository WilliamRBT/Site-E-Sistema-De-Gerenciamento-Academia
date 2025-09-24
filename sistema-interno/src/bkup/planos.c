#include "../include/academia.h"

void cadastrar_plano() {
    if (total_planos >= MAX_PLANOS) {
        printf("\nLimite maximo de planos atingido!\n");
        pausar();
        return;
    }
    
    Plano novo_plano;
    
    limpar_tela();
    printf("===========================================\n");
    printf("           CADASTRAR NOVO PLANO\n");
    printf("===========================================\n\n");
    
    novo_plano.id = gerar_proximo_id_plano();
    
    printf("Nome do plano: ");
    getchar(); // Limpar buffer
    fgets(novo_plano.nome, MAX_NOME, stdin);
    novo_plano.nome[strcspn(novo_plano.nome, "\n")] = 0;
    
    printf("Descricao: ");
    fgets(novo_plano.descricao, 200, stdin);
    novo_plano.descricao[strcspn(novo_plano.descricao, "\n")] = 0;
    
    printf("Preco mensal (R$): ");
    scanf("%f", &novo_plano.preco);
    
    printf("Duracao em meses: ");
    scanf("%d", &novo_plano.duracao_meses);
    
    novo_plano.ativo = 1;
    
    planos[total_planos] = novo_plano;
    total_planos++;
    
    printf("\nPlano cadastrado com sucesso!\n");
    printf("ID do plano: %d\n", novo_plano.id);
    pausar();
}

void listar_planos() {
    limpar_tela();
    printf("===========================================\n");
    printf("           LISTA DE PLANOS\n");
    printf("===========================================\n\n");
    
    if (total_planos == 0) {
        printf("Nenhum plano cadastrado.\n");
        pausar();
        return;
    }
    
    printf("%-5s %-20s %-30s %-10s %-10s %-10s\n", 
           "ID", "Nome", "Descricao", "Preco", "Duracao", "Status");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < total_planos; i++) {
        printf("%-5d %-20s %-30s R$%-7.2f %-10d %-10s\n",
               planos[i].id,
               planos[i].nome,
               planos[i].descricao,
               planos[i].preco,
               planos[i].duracao_meses,
               planos[i].ativo ? "Ativo" : "Inativo");
    }
    
    pausar();
}

void editar_plano() {
    limpar_tela();
    printf("===========================================\n");
    printf("           EDITAR PLANO\n");
    printf("===========================================\n\n");
    
    int id;
    printf("Digite o ID do plano: ");
    scanf("%d", &id);
    
    int indice = -1;
    for (int i = 0; i < total_planos; i++) {
        if (planos[i].id == id) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        printf("Plano nao encontrado.\n");
        pausar();
        return;
    }
    
    printf("\nDados atuais do plano:\n");
    printf("Nome: %s\n", planos[indice].nome);
    printf("Descricao: %s\n", planos[indice].descricao);
    printf("Preco: R$ %.2f\n", planos[indice].preco);
    printf("Duracao: %d meses\n", planos[indice].duracao_meses);
    
    int opcao;
    printf("\nO que deseja editar?\n");
    printf("1. Nome\n");
    printf("2. Descricao\n");
    printf("3. Preco\n");
    printf("4. Duracao\n");
    printf("5. Status (Ativo/Inativo)\n");
    printf("0. Cancelar\n");
    printf("Escolha uma Opcao: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            printf("Novo nome: ");
            getchar();
            fgets(planos[indice].nome, MAX_NOME, stdin);
            planos[indice].nome[strcspn(planos[indice].nome, "\n")] = 0;
            break;
        case 2:
            printf("Nova Descricao: ");
            getchar();
            fgets(planos[indice].descricao, 200, stdin);
            planos[indice].descricao[strcspn(planos[indice].descricao, "\n")] = 0;
            break;
        case 3:
            printf("Novo Preco (R$): ");
            scanf("%f", &planos[indice].preco);
            break;
        case 4:
            printf("Nova Duracao (meses): ");
            scanf("%d", &planos[indice].duracao_meses);
            break;
        case 5:
            printf("Status (1-Ativo, 0-Inativo): ");
            scanf("%d", &planos[indice].ativo);
            break;
        case 0:
            printf("Edicao cancelada.\n");
            pausar();
            return;
        default:
            printf("Opcao inválida!\n");
            pausar();
            return;
    }
    
    printf("Plano editado com sucesso!\n");
    pausar();
}

void remover_plano() {
    limpar_tela();
    printf("===========================================\n");
    printf("           REMOVER PLANO\n");
    printf("===========================================\n\n");
    
    int id;
    printf("Digite o ID do plano: ");
    scanf("%d", &id);
    
    int indice = -1;
    for (int i = 0; i < total_planos; i++) {
        if (planos[i].id == id) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        printf("Plano nao encontrado.\n");
        pausar();
        return;
    }
    
    // Verificar se há membros usando este plano
    int membros_usando = 0;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].plano_id == id && membros[i].ativo) {
            membros_usando++;
        }
    }
    
    if (membros_usando > 0) {
        printf("\nAtençao: Este plano está sendo usado por %d membro(s) ativo(s).\n", membros_usando);
        printf("nao é possível remover o plano. Desative-o ou transfira os membros para outro plano.\n");
        pausar();
        return;
    }
    
    printf("\nPlano encontrado: %s\n", planos[indice].nome);
    
    char confirmacao;
    printf("Tem certeza que deseja remover este plano? (s/n): ");
    scanf(" %c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        // Mover todos os planos uma posição para trás
        for (int i = indice; i < total_planos - 1; i++) {
            planos[i] = planos[i + 1];
        }
        total_planos--;
        
        printf("Plano removido com sucesso!\n");
    } else {
        printf("Remoção cancelada.\n");
    }
    
    pausar();
}

void registrar_pagamento() {
    if (total_pagamentos >= MAX_PAGAMENTOS) {
        printf("\nLimite maximo de pagamentos atingido!\n");
        pausar();
        return;
    }
    
    Pagamento novo_pagamento;
    
    limpar_tela();
    printf("===========================================\n");
    printf("           REGISTRAR PAGAMENTO\n");
    printf("===========================================\n\n");
    
    novo_pagamento.id = gerar_proximo_id_pagamento();
    
    printf("ID do membro: ");
    scanf("%d", &novo_pagamento.membro_id);
    
    // Verificar se o membro existe
    int membro_encontrado = 0;
    int plano_membro = 0;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == novo_pagamento.membro_id && membros[i].ativo) {
            membro_encontrado = 1;
            plano_membro = membros[i].plano_id;
            printf("Membro: %s\n", membros[i].nome);
            break;
        }
    }
    
    if (!membro_encontrado) {
        printf("Membro nao encontrado ou inativo!\n");
        pausar();
        return;
    }
    
    novo_pagamento.plano_id = plano_membro;
    
    // Buscar valor do plano
    float valor_plano = 0;
    for (int i = 0; i < total_planos; i++) {
        if (planos[i].id == plano_membro) {
            valor_plano = planos[i].preco;
            printf("Plano: %s - R$ %.2f\n", planos[i].nome, planos[i].preco);
            break;
        }
    }
    
    printf("Valor a pagar (R$ %.2f): ", valor_plano);
    scanf("%f", &novo_pagamento.valor);
    
    obter_data_atual(novo_pagamento.data_pagamento);
    
    printf("Data de vencimento (DD/MM/AAAA): ");
    scanf("%s", novo_pagamento.data_vencimento);
    
    novo_pagamento.status = 1; // Pago
    
    pagamentos[total_pagamentos] = novo_pagamento;
    total_pagamentos++;
    
    printf("\nPagamento registrado com sucesso!\n");
    printf("ID do pagamento: %d\n", novo_pagamento.id);
    pausar();
}

void listar_pagamentos() {
    limpar_tela();
    printf("===========================================\n");
    printf("           LISTA DE PAGAMENTOS\n");
    printf("===========================================\n\n");
    
    if (total_pagamentos == 0) {
        printf("Nenhum pagamento registrado.\n");
        pausar();
        return;
    }
    
    printf("%-5s %-10s %-10s %-10s %-12s %-12s %-10s\n", 
           "ID", "Membro", "Plano", "Valor", "Pagamento", "Vencimento", "Status");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < total_pagamentos; i++) {
        char status_str[15];
        switch(pagamentos[i].status) {
            case 1: strcpy(status_str, "Pago"); break;
            case 0: strcpy(status_str, "Pendente"); break;
            case -1: strcpy(status_str, "Atrasado"); break;
            default: strcpy(status_str, "Indefinido");
        }
        
        printf("%-5d %-10d %-10d R$%-7.2f %-12s %-12s %-10s\n",
               pagamentos[i].id,
               pagamentos[i].membro_id,
               pagamentos[i].plano_id,
               pagamentos[i].valor,
               pagamentos[i].data_pagamento,
               pagamentos[i].data_vencimento,
               status_str);
    }
    
    pausar();
}

void verificar_pendencias() {
    limpar_tela();
    printf("===========================================\n");
    printf("           VERIFICAR pendenciaS\n");
    printf("===========================================\n\n");
    
    int pendencias = 0;
    
    printf("%-5s %-25s %-10s %-12s %-10s\n", 
           "ID", "Nome do Membro", "Valor", "Vencimento", "Status");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < total_pagamentos; i++) {
        if (pagamentos[i].status != 1) { // nao pago
            // Buscar nome do membro
            char nome_membro[MAX_NOME] = "nao encontrado";
            for (int j = 0; j < total_membros; j++) {
                if (membros[j].id == pagamentos[i].membro_id) {
                    strcpy(nome_membro, membros[j].nome);
                    break;
                }
            }
            
            char status_str[15];
            switch(pagamentos[i].status) {
                case 0: strcpy(status_str, "Pendente"); break;
                case -1: strcpy(status_str, "Atrasado"); break;
                default: strcpy(status_str, "Indefinido");
            }
            
            printf("%-5d %-25s R$%-7.2f %-12s %-10s\n",
                   pagamentos[i].id,
                   nome_membro,
                   pagamentos[i].valor,
                   pagamentos[i].data_vencimento,
                   status_str);
            
            pendencias++;
        }
    }
    
    if (pendencias == 0) {
        printf("Nenhuma pendencia encontrada!\n");
    } else {
        printf("\nTotal de pendencias: %d\n", pendencias);
    }
    
    pausar();
}
