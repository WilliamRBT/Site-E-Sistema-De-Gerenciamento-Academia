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
    git clone <URL_DO_SEU_REPOSITORIO>
    cd gym-landing-page
    ```
    *(Substitua `<URL_DO_SEU_REPOSITORIO>` pela URL real do seu repositório Git.)*

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