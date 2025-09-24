#include "../include/academia.h"

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

void obter_data_atual(char *data) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(data, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void obter_hora_atual(char *hora) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(hora, "%02d:%02d", tm.tm_hour, tm.tm_min);
}

void calcular_data_vencimento(char *data_inicio, int meses, char *data_vencimento) {
    int dia, mes, ano;
    sscanf(data_inicio, "%d/%d/%d", &dia, &mes, &ano);

    // Adicionar meses
    mes += meses;

    // Ajustar ano se necessário
    while (mes > 12) {
        mes -= 12;
        ano++;
    }

    // Verificar se o dia é válido no mês de destino
    int dias_no_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verificar ano bissexto
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) {
        dias_no_mes[1] = 29;
    }

    if (dia > dias_no_mes[mes - 1]) {
        dia = dias_no_mes[mes - 1];
    }

    sprintf(data_vencimento, "%02d/%02d/%04d", dia, mes, ano);
}

int calcular_dias_restantes(char *data_vencimento) {
    time_t t = time(NULL);
    struct tm tm_atual = *localtime(&t);

    int dia_venc, mes_venc, ano_venc;
    sscanf(data_vencimento, "%d/%d/%d", &dia_venc, &mes_venc, &ano_venc);

    struct tm tm_venc = {0};
    tm_venc.tm_mday = dia_venc;
    tm_venc.tm_mon = mes_venc - 1; // tm_mon é 0-11
    tm_venc.tm_year = ano_venc - 1900; // tm_year é anos desde 1900

    time_t t_venc = mktime(&tm_venc);
    time_t t_atual = mktime(&tm_atual);

    double diferenca = difftime(t_venc, t_atual);
    int dias = (int)(diferenca / (24 * 60 * 60));

    return dias;
}

int validar_email(char *email) {
    // Validação básica de email
    size_t len = strlen(email);
    if (len < 5) return 0;

    int tem_arroba = 0;
    int tem_ponto = 0;

    for (size_t i = 0; i < len; i++) {
        if (email[i] == '@') {
            if (tem_arroba) return 0; // Mais de um @
            tem_arroba = 1;
        }
        if (email[i] == '.' && tem_arroba) {
            tem_ponto = 1;
        }
    }

    return tem_arroba && tem_ponto;
}

int validar_telefone(char *telefone) {
    // Validação básica de telefone (apenas números, parênteses e hífen)
    size_t len = strlen(telefone);
    if (len < 8) return 0;

    for (size_t i = 0; i < len; i++) {
        char c = telefone[i];
        if (!(c >= '0' && c <= '9') && c != '(' && c != ')' && c != '-' && c != ' ') {
            return 0;
        }
    }

    return 1;
}

int gerar_proximo_id_membro() {
    int maior_id = 0;
    for (int i = 0; i < total_membros; i++) {
        if (membros[i].id > maior_id) {
            maior_id = membros[i].id;
        }
    }
    return maior_id + 1;
}

int gerar_proximo_id_plano() {
    int maior_id = 0;
    for (int i = 0; i < total_planos; i++) {
        if (planos[i].id > maior_id) {
            maior_id = planos[i].id;
        }
    }
    return maior_id + 1;
}

int gerar_proximo_id_pagamento() {
    int maior_id = 0;
    for (int i = 0; i < total_pagamentos; i++) {
        if (pagamentos[i].id > maior_id) {
            maior_id = pagamentos[i].id;
        }
    }
    return maior_id + 1;
}

int gerar_proximo_id_frequencia() {
    int maior_id = 0;
    for (int i = 0; i < total_frequencias; i++) {
        if (frequencias[i].id > maior_id) {
            maior_id = frequencias[i].id;
        }
    }
    return maior_id + 1;
}

void salvar_dados() {
    FILE *arquivo;
    
    // Salvar membros
    arquivo = fopen("data/membros.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_membros, sizeof(int), 1, arquivo);
        fwrite(membros, sizeof(Membro), total_membros, arquivo);
        fclose(arquivo);
    }
    
    // Salvar planos
    arquivo = fopen("data/planos.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_planos, sizeof(int), 1, arquivo);
        fwrite(planos, sizeof(Plano), total_planos, arquivo);
        fclose(arquivo);
    }
    
    // Salvar pagamentos
    arquivo = fopen("data/pagamentos.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_pagamentos, sizeof(int), 1, arquivo);
        fwrite(pagamentos, sizeof(Pagamento), total_pagamentos, arquivo);
        fclose(arquivo);
    }
    
    // Salvar frequências
    arquivo = fopen("data/frequencias.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_frequencias, sizeof(int), 1, arquivo);
        fwrite(frequencias, sizeof(RegistroFrequencia), total_frequencias, arquivo);
        fclose(arquivo);
    }
}

void carregar_dados() {
    FILE *arquivo;
    
    // Carregar membros
    arquivo = fopen("data/membros.dat", "rb");
    if (arquivo != NULL) {
        fread(&total_membros, sizeof(int), 1, arquivo);
        fread(membros, sizeof(Membro), total_membros, arquivo);
        fclose(arquivo);
    }
    
    // Carregar planos
    arquivo = fopen("data/planos.dat", "rb");
    if (arquivo != NULL) {
        fread(&total_planos, sizeof(int), 1, arquivo);
        fread(planos, sizeof(Plano), total_planos, arquivo);
        fclose(arquivo);
    }
    
    // Carregar pagamentos
    arquivo = fopen("data/pagamentos.dat", "rb");
    if (arquivo != NULL) {
        fread(&total_pagamentos, sizeof(int), 1, arquivo);
        fread(pagamentos, sizeof(Pagamento), total_pagamentos, arquivo);
        fclose(arquivo);
    }
    
    // Carregar frequências
    arquivo = fopen("data/frequencias.dat", "rb");
    if (arquivo != NULL) {
        fread(&total_frequencias, sizeof(int), 1, arquivo);
        fread(frequencias, sizeof(RegistroFrequencia), total_frequencias, arquivo);
        fclose(arquivo);
    }
}

void inicializar_planos_padrao() {
    // Plano Basico
    planos[0].id = 1;
    strcpy(planos[0].nome, "Basico");
    strcpy(planos[0].descricao, "Acesso à musculação e cardio");
    planos[0].preco = 89.00;
    planos[0].duracao_meses = 1;
    planos[0].ativo = 1;
    
    // Plano Premium
    planos[1].id = 2;
    strcpy(planos[1].nome, "Premium");
    strcpy(planos[1].descricao, "Acesso completo + aulas em grupo + 2 sessões personal");
    planos[1].preco = 149.00;
    planos[1].duracao_meses = 1;
    planos[1].ativo = 1;
    
    // Plano VIP
    planos[2].id = 3;
    strcpy(planos[2].nome, "VIP");
    strcpy(planos[2].descricao, "Acesso completo + personal ilimitado + consultoria nutricional");
    planos[2].preco = 249.00;
    planos[2].duracao_meses = 1;
    planos[2].ativo = 1;
    
    total_planos = 3;
}

void verificar_vencimentos_proximos() {
    printf("\n===========================================\n");
    printf("           VENCIMENTOS PROXIMOS\n");
    printf("===========================================\n\n");

    int vencimentos_encontrados = 0;

    printf("%-5s %-25s %-12s %-15s %-10s\n",
           "ID", "Nome", "Vencimento", "Plano", "Dias Rest.");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < total_membros; i++) {
        if (membros[i].ativo && strlen(membros[i].data_vencimento_plano) > 0) {
            int dias_restantes = calcular_dias_restantes(membros[i].data_vencimento_plano);

            // Mostrar se vence em até 7 dias ou já venceu
            if (dias_restantes <= 7) {
                char nome_plano[MAX_NOME] = "Nao encontrado";
                for (int j = 0; j < total_planos; j++) {
                    if (planos[j].id == membros[i].plano_id) {
                        strcpy(nome_plano, planos[j].nome);
                        break;
                    }
                }

                char status_dias[20];
                if (dias_restantes < 0) {
                    sprintf(status_dias, "VENCIDO (%d)", abs(dias_restantes));
                } else if (dias_restantes == 0) {
                    strcpy(status_dias, "VENCE HOJE");
                } else {
                    sprintf(status_dias, "%d dias", dias_restantes);
                }

                printf("%-5d %-25s %-12s %-15s %-10s\n",
                       membros[i].id,
                       membros[i].nome,
                       membros[i].data_vencimento_plano,
                       nome_plano,
                       status_dias);

                vencimentos_encontrados++;
            }
        }
    }

    if (vencimentos_encontrados == 0) {
        printf("Nenhum vencimento proximo encontrado!\n");
    } else {
        printf("\nTotal de vencimentos proximos: %d\n", vencimentos_encontrados);
    }

    printf("\n");
}
