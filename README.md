# GYM TESTE - Landing Page

<div align="center">
  <img width="1200" height="475" alt="Demonstração da Landing Page" src="demonstracao.png" />
</div>

## Sobre o Projeto

Este é o repositório da landing page da **GYM TESTE**, uma academia moderna e vibrante. O objetivo desta página é apresentar os diferenciais da academia, seus planos de adesão, depoimentos de clientes satisfeitos e informações de contato, incentivando novos usuários a se juntarem. A aplicação é construída com React, TypeScript e Tailwind CSS, focando em uma experiência de usuário fluida e um design responsivo.

## Tecnologias Utilizadas

*   **React:** Biblioteca JavaScript para construção de interfaces de usuário.
*   **TypeScript:** Superset do JavaScript que adiciona tipagem estática.
*   **Tailwind CSS:** Framework CSS utilitário para estilização rápida e responsiva.
*   **React Router DOM:** Para gerenciamento de rotas e navegação na aplicação.
*   **Lucide React:** Biblioteca de ícones leves e personalizáveis.
*   **React Hot Toast:** Para notificações de feedback ao usuário.
*   **Vite:** Ferramenta de build rápida para desenvolvimento front-end.

## Funcionalidades

*   **Seção Hero:** Uma introdução impactante com uma chamada à ação clara.
*   **Seção de Diferenciais (Features):** Destaca os pontos fortes da academia, como equipamentos modernos, aulas coletivas e nutrição esportiva.
*   **Seção de Planos (Pricing):** Apresenta os diferentes planos de adesão (Básico, Plus, Premium) com seus respectivos benefícios e preços.
*   **Página de Detalhes do Plano:** Uma página dedicada para cada plano, exibindo todos os benefícios de forma clara e com uma opção para assinar.
*   **Seção de Depoimentos (Testimonials):** Mostra o feedback positivo de membros reais da academia.
*   **Chamada para Ação (Call to Action):** Incentiva os visitantes a dar o próximo passo e explorar os planos.
*   **Página de Contato:** Formulário de contato e informações detalhadas para que os usuários possam entrar em contato.
*   **Navegação Suave:** Rolagem suave para as seções da página inicial.
*   **Design Responsivo:** Layout adaptável para diferentes tamanhos de tela (desktops, tablets e celulares).
*   **Notificações Toast:** Feedback visual para ações do usuário (ex: ao selecionar um plano).

## Como Rodar o Projeto Localmente

Siga estas instruções para configurar e executar o projeto em sua máquina local.

### Pré-requisitos

Certifique-se de ter o Node.js instalado em seu sistema. Você pode baixá-lo em [nodejs.org](https://nodejs.org/).

### Instalação

1.  **Clone o repositório:**
    ```bash
    git clone <URL_DO_REPOSITORIO>
    cd gym-landing-page
    ```
    *(Substitua `<URL_DO_REPOSITORIO>` pela URL real do repositório Git.)*

2.  **Instale as dependências:**
    ```bash
    npm install
    # ou
    yarn install
    ```

3.  **Execute o aplicativo:**
    ```bash
    npm run dev
    # ou
    yarn dev
    ```

O aplicativo será iniciado em `http://localhost:3000` (ou outra porta disponível). Abra seu navegador e acesse este endereço para ver a landing page em funcionamento.

## Estrutura do Projeto

A estrutura principal do projeto é organizada da seguinte forma:

```
.
├── public/                 # Arquivos estáticos (imagens, etc.)
├── src/
│   ├── components/         # Componentes reutilizáveis da UI
│   │   ├── icons/          # Ícones (se houver)
│   │   ├── CallToAction.tsx
│   │   ├── Features.tsx
│   │   ├── Footer.tsx
│   │   ├── Header.tsx
│   │   ├── Pricing.tsx
│   │   ├── Testimonials.tsx
│   │   └── ToastProvider.tsx
│   ├── pages/              # Páginas principais da aplicação
│   │   ├── ContactPage.tsx
│   │   └── PlanDetailsPage.tsx
│   ├── utils/              # Funções utilitárias e dados
│   │   ├── planData.ts
│   │   └── stringUtils.ts
│   ├── App.tsx             # Componente principal da aplicação e rotas
│   └── index.tsx           # Ponto de entrada do React
├── index.html              # Arquivo HTML principal
├── package.json            # Dependências e scripts do projeto
├── tsconfig.json           # Configurações do TypeScript
├── vite.config.ts          # Configurações do Vite
└── README.md               # Este arquivo
```

## 4. Sistema Interno em C

### 4.1 Objetivo do Sistema
Desenvolver um sistema de gerenciamento interno para a academia, permitindo o cadastro e controle de membros, planos, pagamentos e frequência.

### 4.2 Tecnologias Utilizadas
- **Linguagem:** C (padrão C99)
- **Compilador:** GCC
- **Armazenamento:** Arquivos binários (.dat)

### 4.4 Funcionalidades Implementadas

#### 4.4.1 Gerenciamento de Membros
- Cadastrar novo membro
- Listar todos os membros
- Buscar membro por ID, nome ou email
- Editar dados do membro
- Remover membro

#### 4.4.2 Gerenciamento de Planos
- Cadastrar novo plano
- Listar todos os planos
- Editar plano existente
- Remover plano (com verificação de uso)

#### 4.4.3 Gerenciamento de Pagamentos
- Registrar pagamento
- Listar todos os pagamentos
- Verificar pendências

#### 4.4.4 Controle de Frequência
- Registrar entrada do membro
- Registrar saída do membro
- Listar frequência por período

#### 4.4.5 Relatórios
- Relatório de membros ativos
- Relatório de receita mensal
- Relatório de frequência por membro

### 4.5 Validações Implementadas
- Validação de email (formato básico)
- Validação de telefone (apenas números e caracteres permitidos)
- Verificação de existência de membros e planos
- Controle de limites máximos de registros

### 4.6 Persistência de Dados
Os dados são salvos em arquivos binários na pasta `data/`:
- `membros.dat`: Dados dos membros
- `planos.dat`: Dados dos planos
- `pagamentos.dat`: Dados dos pagamentos
- `frequencias.dat`: Dados de frequência

Sistema-Interno/
├── README.md
├── website/
│   ├── index.html
│   ├── css/
│   │   └── style.css
│   └── js/
│       └── script.js
├── sistema-interno/
│   ├── Makefile
│   ├── include/
│   │   └── academia.h
│   ├── src/
│   │   ├── main.c
│   │   ├── membros.c
│   │   ├── planos.c
│   │   └── utils.c
│   └── data/
│       └── (arquivos .dat gerados automaticamente)
└── documentacao/
    └── documentacao-projeto.md
	
## 7. Considerações Técnicas

### 7.1 Limitações do Sistema
- Máximo de 1000 membros
- Máximo de 10 planos
- Máximo de 5000 pagamentos
- Máximo de 10000 registros de frequência

### 7.2 Melhorias Futuras
- Implementação de banco de dados SQLite
- Interface gráfica
- Sistema de backup automático
- Relatórios mais avançados
- Integração com sistema de pagamento
