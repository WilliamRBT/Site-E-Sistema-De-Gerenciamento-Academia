#include "../include/academia.h"

void cadastrar_membro() {
    if (total_membros >= MAX_MEMBROS) {
        printf("\nLimite maximo de membros atingido!\n");
        pausar();
        return;
    }
    
    Membro novo_membro;
    
    limpar_tela();
    printf("===========================================\n");
    printf("           CADASTRAR NOVO MEMBRO\n");
    printf("===========================================\n\n");
    
    novo_membro.id = gerar_proximo_id_membro();
    
    printf("Nome completo: ");
    getchar(); // Limpar buffer
    fgets(novo_membro.nome, MAX_NOME, stdin);
    novo_membro.nome[strcspn(novo_membro.nome, "\n")] = 0; // Remover \n
    
    do {
        printf("Email: ");
        fgets(novo_membro.email, MAX_EMAIL, stdin);
        novo_membro.email[strcspn(novo_membro.email, "\n")] = 0;
        
        if (!validar_email(novo_membro.email)) {
            printf("Email invalido! Tente novamente.\n");
        }
    } while (!validar_email(novo_membro.email));
    
    do {
        printf("Telefone: ");
        fgets(novo_membro.telefone, MAX_TELEFONE, stdin);
        novo_membro.telefone[strcspn(novo_membro.telefone, "\n")] = 0;
        
        if (!validar_telefone(novo_membro.telefone)) {
            printf("Telefone invalido! Tente novamente.\n");
        }
    } while (!validar_telefone(novo_membro.telefone));
    
    printf("Endereco: ");
    fgets(novo_membro.endereco, MAX_ENDERECO, stdin);
    novo_membro.endereco[strcspn(novo_membro.endereco, "\n")] = 0;
    
    printf("Idade: ");
    scanf("%d", &novo_membro.idade);
    
    printf("Sexo (M/F): ");
    scanf(" %c", &novo_membro.sexo);
    
    // Mostrar planos disponiveis
    printf("\nPlanos disponiveis:\n");
    for (int i = 0; i < total_planos; i++) {
        if (planos[i].ativo) {
            printf("%d. %s - R$ %.2f/mes\n", planos[i].id, planos[i].nome, planos[i].preco);
        }
    }
    
    printf("Escolha o plano (ID): ");
    scanf("%d", &novo_membro.plano_id);
    
    // Verificar se o plano existe e obter duração
    int plano_encontrado = 0;
    int duracao_plano = 1;
    for (int i = 0; i < total_planos; i++) {
        if (planos[i].id == novo_membro.plano_id && planos[i].ativo) {
            plano_encontrado = 1;
            duracao_plano = planos[i].duracao_meses;
            break;
        }
    }

    if (!plano_encontrado) {
        printf("Plano invalido! Cadastro cancelado.\n");
        pausar();
        return;
    }

    obter_data_atual(novo_membro.data_cadastro);
    calcular_data_vencimento(novo_membro.data_cadastro, duracao_plano, novo_membro.data_vencimento_plano);
    novo_membro.ativo = 1;
    
    membros[total_membros] = novo_membro;
    total_membros++;
    
    printf("\nMembro cadastrado com sucesso!\n");
    printf("ID do membro: %d\n", novo_membro.id);
    pausar();
}

void listar_membros() {
    limpar_tela();
    printf("===========================================\n");
    printf("           LISTA DE MEMBROS\n");
    printf("===========================================\n\n");
    
    if (total_membros == 0) {
        printf("Nenhum membro cadastrado.\n");
        pausar();
        return;
    }
    
    printf("%-5s %-20s %-20s %-12s %-8s %-12s %-10s\n",
           "ID", "Nome", "Email", "Telefone", "Idade", "Vencimento", "Dias Rest.");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < total_membros; i++) {
        char dias_restantes_str[15] = "---";

        if (strlen(membros[i].data_vencimento_plano) > 0) {
            int dias_restantes = calcular_dias_restantes(membros[i].data_vencimento_plano);
            if (dias_restantes < 0) {
                sprintf(dias_restantes_str, "VENCIDO");
            } else if (dias_restantes == 0) {
                sprintf(dias_restantes_str, "HOJE");
            } else {
                sprintf(dias_restantes_str, "%d dias", dias_restantes);
            }
        }

        printf("%-5d %-20s %-20s %-12s %-8d %-12s %-10s\n",
               membros[i].id,
               membros[i].nome,
               membros[i].email,
               membros[i].telefone,
               membros[i].idade,
               strlen(membros[i].data_vencimento_plano) > 0 ? membros[i].data_vencimento_plano : "---",
               dias_restantes_str);
    }
    
    pausar();
}

void buscar_membro() {
    limpar_tela();
    printf("===========================================\n");
    printf("           BUSCAR MEMBRO\n");
    printf("===========================================\n\n");
    
    int opcao;
    printf("Buscar por:\n");
    printf("1. ID\n");
    printf("2. Nome\n");
    printf("3. Email\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1: {
            int id;
            printf("Digite o ID: ");
            scanf("%d", &id);
            
            for (int i = 0; i < total_membros; i++) {
                if (membros[i].id == id) {
                    printf("\nMembro encontrado:\n");
                    printf("ID: %d\n", membros[i].id);
                    printf("Nome: %s\n", membros[i].nome);
                    printf("Email: %s\n", membros[i].email);
                    printf("Telefone: %s\n", membros[i].telefone);
                    printf("Endereco: %s\n", membros[i].endereco);
                    printf("Idade: %d\n", membros[i].idade);
                    printf("Sexo: %c\n", membros[i].sexo);
                    printf("Plano ID: %d\n", membros[i].plano_id);
                    printf("Data de cadastro: %s\n", membros[i].data_cadastro);
                    printf("Vencimento do plano: %s\n", membros[i].data_vencimento_plano);

                    if (strlen(membros[i].data_vencimento_plano) > 0) {
                        int dias_restantes = calcular_dias_restantes(membros[i].data_vencimento_plano);
                        if (dias_restantes < 0) {
                            printf("Status do plano: VENCIDO há %d dias\n", abs(dias_restantes));
                        } else if (dias_restantes == 0) {
                            printf("Status do plano: VENCE HOJE\n");
                        } else {
                            printf("Status do plano: %d dias restantes\n", dias_restantes);
                        }
                    }

                    printf("Status: %s\n", membros[i].ativo ? "Ativo" : "Inativo");
                    pausar();
                    return;
                }
            }
            printf("Membro nao encontrado.\n");
            break;
        }
        case 2: {
            char nome[MAX_NOME];
            printf("Digite o nome: ");
            getchar();
            fgets(nome, MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = 0;
            
            int encontrados = 0;
            for (int i = 0; i < total_membros; i++) {
                if (strstr(membros[i].nome, nome) != NULL) {
                    if (encontrados == 0) {
                        printf("\nMembros encontrados:\n");
                        printf("%-5s %-25s %-25s %-15s\n", "ID", "Nome", "Email", "Telefone");
                        printf("-----------------------------------------------------------------------\n");
                    }
                    printf("%-5d %-25s %-25s %-15s\n",
                           membros[i].id, membros[i].nome, membros[i].email, membros[i].telefone);
                    encontrados++;
                }
            }
            
            if (encontrados == 0) {
                printf("Nenhum membro encontrado.\n");
            }
            break;
        }
        case 3: {
            char email[MAX_EMAIL];
            printf("Digite o email: ");
            getchar();
            fgets(email, MAX_EMAIL, stdin);
            email[strcspn(email, "\n")] = 0;
            
            for (int i = 0; i < total_membros; i++) {
                if (strcmp(membros[i].email, email) == 0) {
                    printf("\nMembro encontrado:\n");
                    printf("ID: %d\n", membros[i].id);
                    printf("Nome: %s\n", membros[i].nome);
                    printf("Email: %s\n", membros[i].email);
                    printf("Telefone: %s\n", membros[i].telefone);
                    printf("Status: %s\n", membros[i].ativo ? "Ativo" : "Inativo");
                    pausar();
                    return;
                }
            }
            printf("Membro nao encontrado.\n");
            break;
        }
        default:
            printf("opcao inválida!\n");
    }
    
    pausar();
}

void editar_membro() {
    limpar_tela();
    printf("===========================================\n");
    printf("           EDITAR MEMBRO\n");
    printf("===========================================\n\n");
    
    int id;
    printf("Digite o ID do membro: ");
    scanf("%d", &id);
    
    int indice = -1;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == id) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        printf("Membro nao encontrado.\n");
        pausar();
        return;
    }
    
    printf("\nDados atuais do membro:\n");
    printf("Nome: %s\n", membros[indice].nome);
    printf("Email: %s\n", membros[indice].email);
    printf("Telefone: %s\n", membros[indice].telefone);
    printf("Endereco: %s\n", membros[indice].endereco);
    
    int opcao;
    printf("\nO que deseja editar?\n");
    printf("1. Nome\n");
    printf("2. Email\n");
    printf("3. Telefone\n");
    printf("4. Endereco\n");
    printf("5. Plano\n");
    printf("6. Status (Ativo/Inativo)\n");
    printf("0. Cancelar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            printf("Novo nome: ");
            getchar();
            fgets(membros[indice].nome, MAX_NOME, stdin);
            membros[indice].nome[strcspn(membros[indice].nome, "\n")] = 0;
            break;
        case 2:
            do {
                printf("Novo email: ");
                getchar();
                fgets(membros[indice].email, MAX_EMAIL, stdin);
                membros[indice].email[strcspn(membros[indice].email, "\n")] = 0;
                
                if (!validar_email(membros[indice].email)) {
                    printf("Email invalido! Tente novamente.\n");
                }
            } while (!validar_email(membros[indice].email));
            break;
        case 3:
            do {
                printf("Novo telefone: ");
                getchar();
                fgets(membros[indice].telefone, MAX_TELEFONE, stdin);
                membros[indice].telefone[strcspn(membros[indice].telefone, "\n")] = 0;
                
                if (!validar_telefone(membros[indice].telefone)) {
                    printf("Telefone invalido! Tente novamente.\n");
                }
            } while (!validar_telefone(membros[indice].telefone));
            break;
        case 4:
            printf("Novo Endereco: ");
            getchar();
            fgets(membros[indice].endereco, MAX_ENDERECO, stdin);
            membros[indice].endereco[strcspn(membros[indice].endereco, "\n")] = 0;
            break;
        case 5:
            printf("\nPlanos disponiveis:\n");
            for (int i = 0; i < total_planos; i++) {
                if (planos[i].ativo) {
                    printf("%d. %s - R$ %.2f/mes\n", planos[i].id, planos[i].nome, planos[i].preco);
                }
            }
            printf("Novo plano (ID): ");
            scanf("%d", &membros[indice].plano_id);
            break;
        case 6:
            printf("Status (1-Ativo, 0-Inativo): ");
            scanf("%d", &membros[indice].ativo);
            break;
        case 0:
            printf("Edicao cancelada.\n");
            pausar();
            return;
        default:
            printf("opcao inválida!\n");
            pausar();
            return;
    }
    
    printf("Membro editado com sucesso!\n");
    pausar();
}

void remover_membro() {
    limpar_tela();
    printf("===========================================\n");
    printf("           REMOVER MEMBRO\n");
    printf("===========================================\n\n");
    
    int id;
    printf("Digite o ID do membro: ");
    scanf("%d", &id);
    
    int indice = -1;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == id) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        printf("Membro nao encontrado.\n");
        pausar();
        return;
    }
    
    printf("\nMembro encontrado: %s\n", membros[indice].nome);
    
    char confirmacao;
    printf("Tem certeza que deseja remover este membro? (s/n): ");
    scanf(" %c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        // Mover todos os membros uma posição para trás
        for (int i = indice; i < total_membros - 1; i++) {
            membros[i] = membros[i + 1];
        }
        total_membros--;
        
        printf("Membro removido com sucesso!\n");
    } else {
        printf("Remocao cancelada.\n");
    }
    
    pausar();
}

void renovar_plano_membro() {
    limpar_tela();
    printf("===========================================\n");
    printf("           RENOVAR PLANO DO MEMBRO\n");
    printf("===========================================\n\n");

    int id;
    printf("Digite o ID do membro: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Membro nao encontrado.\n");
        pausar();
        return;
    }

    printf("\nMembro: %s\n", membros[indice].nome);
    printf("Plano atual: ID %d\n", membros[indice].plano_id);
    printf("Vencimento atual: %s\n", membros[indice].data_vencimento_plano);

    if (strlen(membros[indice].data_vencimento_plano) > 0) {
        int dias_restantes = calcular_dias_restantes(membros[indice].data_vencimento_plano);
        if (dias_restantes < 0) {
            printf("Status: VENCIDO há %d dias\n", abs(dias_restantes));
        } else if (dias_restantes == 0) {
            printf("Status: VENCE HOJE\n");
        } else {
            printf("Status: %d dias restantes\n", dias_restantes);
        }
    }

    printf("\nOpcoes de renovação:\n");
    printf("1. Renovar com o mesmo plano\n");
    printf("2. Trocar de plano\n");
    printf("0. Cancelar\n");
    printf("Escolha uma opcao: ");

    int opcao;
    scanf("%d", &opcao);

    if (opcao == 0) {
        printf("Renovação cancelada.\n");
        pausar();
        return;
    }

    int novo_plano_id = membros[indice].plano_id;
    int duracao_plano = 1;

    if (opcao == 2) {
        // Mostrar planos disponíveis
        printf("\nPlanos disponíveis:\n");
        for (int i = 0; i < total_planos; i++) {
            if (planos[i].ativo) {
                printf("%d. %s - R$ %.2f/mês (%d meses)\n",
                       planos[i].id, planos[i].nome, planos[i].preco, planos[i].duracao_meses);
            }
        }

        printf("Escolha o novo plano (ID): ");
        scanf("%d", &novo_plano_id);

        // Verificar se o plano existe
        int plano_encontrado = 0;
        for (int i = 0; i < total_planos; i++) {
            if (planos[i].id == novo_plano_id && planos[i].ativo) {
                plano_encontrado = 1;
                duracao_plano = planos[i].duracao_meses;
                break;
            }
        }

        if (!plano_encontrado) {
            printf("Plano inválido! Renovação cancelada.\n");
            pausar();
            return;
        }

        membros[indice].plano_id = novo_plano_id;
    } else {
        // Buscar duração do plano atual
        for (int i = 0; i < total_planos; i++) {
            if (planos[i].id == novo_plano_id) {
                duracao_plano = planos[i].duracao_meses;
                break;
            }
        }
    }

    // Calcular nova data de vencimento
    char data_base[11];

    // Se o plano ainda não venceu, usar a data de vencimento atual como base
    if (strlen(membros[indice].data_vencimento_plano) > 0) {
        int dias_restantes = calcular_dias_restantes(membros[indice].data_vencimento_plano);
        if (dias_restantes >= 0) {
            strcpy(data_base, membros[indice].data_vencimento_plano);
        } else {
            obter_data_atual(data_base);
        }
    } else {
        obter_data_atual(data_base);
    }

    calcular_data_vencimento(data_base, duracao_plano, membros[indice].data_vencimento_plano);

    printf("\nPlano renovado com sucesso!\n");
    printf("Novo vencimento: %s\n", membros[indice].data_vencimento_plano);

    // Calcular dias até o novo vencimento
    int dias_total = calcular_dias_restantes(membros[indice].data_vencimento_plano);
    printf("Dias até o vencimento: %d\n", dias_total);

    pausar();
}
