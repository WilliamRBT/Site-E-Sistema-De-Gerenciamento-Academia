#ifndef ACADEMIA_H
#define ACADEMIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOME 100
#define MAX_EMAIL 100
#define MAX_TELEFONE 20
#define MAX_ENDERECO 200
#define MAX_MEMBROS 1000
#define MAX_PLANOS 10
#define MAX_PAGAMENTOS 5000
#define MAX_FREQUENCIA 10000

// Estruturas de dados
typedef struct {
    int id;
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
    char endereco[MAX_ENDERECO];
    int idade;
    char sexo;
    int plano_id;
    char data_cadastro[11]; // DD/MM/AAAA
    char data_vencimento_plano[11]; // DD/MM/AAAA
    int ativo; // 1 = ativo, 0 = inativo
} Membro;

typedef struct {
    int id;
    char nome[MAX_NOME];
    char descricao[200];
    float preco;
    int duracao_meses;
    int ativo; // 1 = ativo, 0 = inativo
} Plano;

typedef struct {
    int id;
    int membro_id;
    int plano_id;
    float valor;
    char data_pagamento[11]; // DD/MM/AAAA
    char data_vencimento[11]; // DD/MM/AAAA
    int status; // 1 = pago, 0 = pendente, -1 = atrasado
} Pagamento;

typedef struct {
    int id;
    int membro_id;
    char data[11]; // DD/MM/AAAA
    char hora_entrada[6]; // HH:MM
    char hora_saida[6]; // HH:MM
} RegistroFrequencia;

// Variáveis globais
extern Membro membros[MAX_MEMBROS];
extern Plano planos[MAX_PLANOS];
extern Pagamento pagamentos[MAX_PAGAMENTOS];
extern RegistroFrequencia frequencias[MAX_FREQUENCIA];

extern int total_membros;
extern int total_planos;
extern int total_pagamentos;
extern int total_frequencias;

// Protótipos das funções

// Funções de menu
void menu_principal();
void menu_membros();
void menu_planos();
void menu_pagamentos();
void menu_frequencia();
void menu_relatorios();

// Funções de membros
void cadastrar_membro();
void listar_membros();
void buscar_membro();
void editar_membro();
void renovar_plano_membro();
void remover_membro();

// Funções de planos
void cadastrar_plano();
void listar_planos();
void editar_plano();
void remover_plano();

// Funções de pagamentos
void registrar_pagamento();
void listar_pagamentos();
void verificar_pendencias();

// Funções de frequência
void registrar_entrada();
void registrar_saida();
void listar_frequencia();

// Funções de relatórios
void relatorio_membros_ativos();
void relatorio_receita_mensal();
void relatorio_frequencia_membro();

// Funções auxiliares
void limpar_tela();
void pausar();
void obter_data_atual(char *data);
void obter_hora_atual(char *hora);
void calcular_data_vencimento(char *data_inicio, int meses, char *data_vencimento);
int calcular_dias_restantes(char *data_vencimento);
int validar_email(char *email);
int validar_telefone(char *telefone);
int gerar_proximo_id_membro();
int gerar_proximo_id_plano();
int gerar_proximo_id_pagamento();
int gerar_proximo_id_frequencia();
void verificar_vencimentos_proximos();

// Funções de persistência
void salvar_dados();
void carregar_dados();
void inicializar_planos_padrao();

#endif
