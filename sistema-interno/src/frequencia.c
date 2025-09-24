#include "../include/academia.h"

void registrar_entrada() {
    if (total_frequencias >= MAX_FREQUENCIA) {
        printf("\nLimite maximo de registros de frequencia atingido!\n");
        pausar();
        return;
    }
    
    RegistroFrequencia novo_registro;
    
    limpar_tela();
    printf("===========================================\n");
    printf("           REGISTRAR ENTRADA\n");
    printf("===========================================\n\n");
    
    novo_registro.id = gerar_proximo_id_frequencia();
    
    printf("ID do membro: ");
    scanf("%d", &novo_registro.membro_id);
    
    // Verificar se o membro existe e está ativo
    int membro_encontrado = 0;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == novo_registro.membro_id && membros[i].ativo) {
            membro_encontrado = 1;
            printf("Membro: %s\n", membros[i].nome);
            break;
        }
    }
    
    if (!membro_encontrado) {
        printf("Membro nao encontrado ou inativo!\n");
        pausar();
        return;
    }
    
    // Verificar se já há uma entrada sem saida hoje
    char data_hoje[11];
    obter_data_atual(data_hoje);
    
    for (int i = 0; i < total_frequencias; i++) {
        if (frequencias[i].membro_id == novo_registro.membro_id &&
            strcmp(frequencias[i].data, data_hoje) == 0 &&
            strlen(frequencias[i].hora_saida) == 0) {
            printf("Atencao: Este membro já possui uma entrada registrada hoje sem saida!\n");
            printf("Hora de entrada anterior: %s\n", frequencias[i].hora_entrada);
            pausar();
            return;
        }
    }
    
    obter_data_atual(novo_registro.data);
    obter_hora_atual(novo_registro.hora_entrada);
    strcpy(novo_registro.hora_saida, ""); // saida vazia inicialmente
    
    frequencias[total_frequencias] = novo_registro;
    total_frequencias++;
    
    printf("\nEntrada registrada com sucesso!\n");
    printf("Data: %s\n", novo_registro.data);
    printf("Hora: %s\n", novo_registro.hora_entrada);
    pausar();
}

void registrar_saida() {
    limpar_tela();
    printf("===========================================\n");
    printf("           REGISTRAR saida\n");
    printf("===========================================\n\n");
    
    int membro_id;
    printf("ID do membro: ");
    scanf("%d", &membro_id);
    
    // Verificar se o membro existe
    int membro_encontrado = 0;
    char nome_membro[MAX_NOME];
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == membro_id) {
            membro_encontrado = 1;
            strcpy(nome_membro, membros[i].nome);
            break;
        }
    }
    
    if (!membro_encontrado) {
        printf("Membro nao encontrado!\n");
        pausar();
        return;
    }
    
    printf("Membro: %s\n", nome_membro);
    
    // Buscar entrada sem saida para hoje
    char data_hoje[11];
    obter_data_atual(data_hoje);
    
    int registro_encontrado = -1;
    for (int i = 0; i < total_frequencias; i++) {
        if (frequencias[i].membro_id == membro_id &&
            strcmp(frequencias[i].data, data_hoje) == 0 &&
            strlen(frequencias[i].hora_saida) == 0) {
            registro_encontrado = i;
            break;
        }
    }
    
    if (registro_encontrado == -1) {
        printf("nao foi encontrada uma entrada sem saida para hoje!\n");
        pausar();
        return;
    }
    
    char hora_atual[6];
    obter_hora_atual(hora_atual);
    strcpy(frequencias[registro_encontrado].hora_saida, hora_atual);
    
    printf("\nsaida registrada com sucesso!\n");
    printf("Hora de entrada: %s\n", frequencias[registro_encontrado].hora_entrada);
    printf("Hora de saida: %s\n", frequencias[registro_encontrado].hora_saida);
    pausar();
}

void listar_frequencia() {
    limpar_tela();
    printf("===========================================\n");
    printf("           LISTA DE frequencia\n");
    printf("===========================================\n\n");
    
    if (total_frequencias == 0) {
        printf("Nenhum registro de frequencia encontrado.\n");
        pausar();
        return;
    }
    
    int opcao;
    printf("Filtrar por:\n");
    printf("1. Todos os registros\n");
    printf("2. Por membro específico\n");
    printf("3. Por data específica\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    printf("\n%-5s %-10s %-25s %-12s %-10s %-10s\n", 
           "ID", "Membro", "Nome", "Data", "Entrada", "saida");
    printf("---------------------------------------------------------------------------------\n");
    
    switch(opcao) {
        case 1: {
            // Listar todos
            for (int i = 0; i < total_frequencias; i++) {
                char nome_membro[MAX_NOME] = "nao encontrado";
                for (int j = 0; j < total_membros; j++) {
                    if (membros[j].id == frequencias[i].membro_id) {
                        strcpy(nome_membro, membros[j].nome);
                        break;
                    }
                }
                
                printf("%-5d %-10d %-25s %-12s %-10s %-10s\n",
                       frequencias[i].id,
                       frequencias[i].membro_id,
                       nome_membro,
                       frequencias[i].data,
                       frequencias[i].hora_entrada,
                       strlen(frequencias[i].hora_saida) > 0 ? frequencias[i].hora_saida : "---");
            }
            break;
        }
        case 2: {
            // Por membro específico
            int membro_id;
            printf("ID do membro: ");
            scanf("%d", &membro_id);
            
            int registros_encontrados = 0;
            for (int i = 0; i < total_frequencias; i++) {
                if (frequencias[i].membro_id == membro_id) {
                    char nome_membro[MAX_NOME] = "nao encontrado";
                    for (int j = 0; j < total_membros; j++) {
                        if (membros[j].id == frequencias[i].membro_id) {
                            strcpy(nome_membro, membros[j].nome);
                            break;
                        }
                    }
                    
                    printf("%-5d %-10d %-25s %-12s %-10s %-10s\n",
                           frequencias[i].id,
                           frequencias[i].membro_id,
                           nome_membro,
                           frequencias[i].data,
                           frequencias[i].hora_entrada,
                           strlen(frequencias[i].hora_saida) > 0 ? frequencias[i].hora_saida : "---");
                    
                    registros_encontrados++;
                }
            }
            
            if (registros_encontrados == 0) {
                printf("Nenhum registro encontrado para este membro.\n");
            }
            break;
        }
        case 3: {
            // Por data específica
            char data_busca[11];
            printf("Data (DD/MM/AAAA): ");
            scanf("%s", data_busca);
            
            int registros_encontrados = 0;
            for (int i = 0; i < total_frequencias; i++) {
                if (strcmp(frequencias[i].data, data_busca) == 0) {
                    char nome_membro[MAX_NOME] = "nao encontrado";
                    for (int j = 0; j < total_membros; j++) {
                        if (membros[j].id == frequencias[i].membro_id) {
                            strcpy(nome_membro, membros[j].nome);
                            break;
                        }
                    }
                    
                    printf("%-5d %-10d %-25s %-12s %-10s %-10s\n",
                           frequencias[i].id,
                           frequencias[i].membro_id,
                           nome_membro,
                           frequencias[i].data,
                           frequencias[i].hora_entrada,
                           strlen(frequencias[i].hora_saida) > 0 ? frequencias[i].hora_saida : "---");
                    
                    registros_encontrados++;
                }
            }
            
            if (registros_encontrados == 0) {
                printf("Nenhum registro encontrado para esta data.\n");
            }
            break;
        }
        default:
            printf("opcao invalida!\n");
    }
    
    pausar();
}

void relatorio_membros_ativos() {
    limpar_tela();
    printf("===========================================\n");
    printf("           RELATORIO - MEMBROS ATIVOS\n");
    printf("===========================================\n\n");
    
    int membros_ativos = 0;
    int membros_inativos = 0;
    
    printf("%-5s %-25s %-25s %-15s %-12s\n", 
           "ID", "Nome", "Email", "Telefone", "Plano");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].ativo) {
            char nome_plano[MAX_NOME] = "nao encontrado";
            for (int j = 0; j < total_planos; j++) {
                if (planos[j].id == membros[i].plano_id) {
                    strcpy(nome_plano, planos[j].nome);
                    break;
                }
            }
            
            printf("%-5d %-25s %-25s %-15s %-12s\n",
                   membros[i].id,
                   membros[i].nome,
                   membros[i].email,
                   membros[i].telefone,
                   nome_plano);
            
            membros_ativos++;
        } else {
            membros_inativos++;
        }
    }
    
    printf("\n===========================================\n");
    printf("RESUMO:\n");
    printf("Membros ativos: %d\n", membros_ativos);
    printf("Membros inativos: %d\n", membros_inativos);
    printf("Total de membros: %d\n", total_membros);
    
    pausar();
}

void relatorio_receita_mensal() {
    limpar_tela();
    printf("===========================================\n");
    printf("           RELATORIO - RECEITA MENSAL\n");
    printf("===========================================\n\n");
    
    char mes_ano[8];
    printf("Digite o mes/ano (MM/AAAA): ");
    scanf("%s", mes_ano);
    
    float receita_total = 0;
    int pagamentos_mes = 0;
    
    printf("\n%-5s %-10s %-25s %-10s %-12s\n", 
           "ID", "Membro", "Nome", "Valor", "Data");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < total_pagamentos; i++) {
        // Extrair mes/ano da data de pagamento
        char data_pagamento[11];
        strcpy(data_pagamento, pagamentos[i].data_pagamento);
        
        char mes_ano_pagamento[8];
        sprintf(mes_ano_pagamento, "%c%c/%c%c%c%c", 
                data_pagamento[3], data_pagamento[4],
                data_pagamento[6], data_pagamento[7], 
                data_pagamento[8], data_pagamento[9]);
        
        if (strcmp(mes_ano_pagamento, mes_ano) == 0 && pagamentos[i].status == 1) {
            char nome_membro[MAX_NOME] = "nao encontrado";
            for (int j = 0; j < total_membros; j++) {
                if (membros[j].id == pagamentos[i].membro_id) {
                    strcpy(nome_membro, membros[j].nome);
                    break;
                }
            }
            
            printf("%-5d %-10d %-25s R$%-7.2f %-12s\n",
                   pagamentos[i].id,
                   pagamentos[i].membro_id,
                   nome_membro,
                   pagamentos[i].valor,
                   pagamentos[i].data_pagamento);
            
            receita_total += pagamentos[i].valor;
            pagamentos_mes++;
        }
    }
    
    printf("\n===========================================\n");
    printf("RESUMO DO mes %s:\n", mes_ano);
    printf("Total de pagamentos: %d\n", pagamentos_mes);
    printf("Receita total: R$ %.2f\n", receita_total);
    
    pausar();
}

void relatorio_frequencia_membro() {
    limpar_tela();
    printf("===========================================\n");
    printf("           RELATORIO - frequencia POR MEMBRO\n");
    printf("===========================================\n\n");
    
    int membro_id;
    printf("ID do membro: ");
    scanf("%d", &membro_id);
    
    // Verificar se o membro existe
    char nome_membro[MAX_NOME] = "nao encontrado";
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id == membro_id) {
            strcpy(nome_membro, membros[i].nome);
            break;
        }
    }
    
    if (strcmp(nome_membro, "nao encontrado") == 0) {
        printf("Membro nao encontrado!\n");
        pausar();
        return;
    }
    
    printf("Membro: %s (ID: %d)\n\n", nome_membro, membro_id);
    
    char mes_ano[8];
    printf("Digite o mes/ano (MM/AAAA) ou 'todos' para ver tudo: ");
    scanf("%s", mes_ano);
    
    printf("\n%-5s %-12s %-10s %-10s\n", 
           "ID", "Data", "Entrada", "saida");
    printf("-----------------------------------------------\n");
    
    int total_visitas = 0;
    
    for (int i = 0; i < total_frequencias; i++) {
        if (frequencias[i].membro_id == membro_id) {
            int mostrar = 0;
            
            if (strcmp(mes_ano, "todos") == 0) {
                mostrar = 1;
            } else {
                // Extrair mes/ano da data
                char data_freq[11];
                strcpy(data_freq, frequencias[i].data);
                
                char mes_ano_freq[8];
                sprintf(mes_ano_freq, "%c%c/%c%c%c%c", 
                        data_freq[3], data_freq[4],
                        data_freq[6], data_freq[7], 
                        data_freq[8], data_freq[9]);
                
                if (strcmp(mes_ano_freq, mes_ano) == 0) {
                    mostrar = 1;
                }
            }
            
            if (mostrar) {
                printf("%-5d %-12s %-10s %-10s\n",
                       frequencias[i].id,
                       frequencias[i].data,
                       frequencias[i].hora_entrada,
                       strlen(frequencias[i].hora_saida) > 0 ? frequencias[i].hora_saida : "---");
                
                total_visitas++;
            }
        }
    }
    
    printf("\n===========================================\n");
    printf("Total de visitas: %d\n", total_visitas);
    
    pausar();
}
