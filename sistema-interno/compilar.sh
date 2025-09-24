#!/bin/bash

echo "=========================================="
echo "    COMPILADOR SISTEMA COREVITA FIT"
echo "=========================================="
echo

# Verificar se o GCC está instalado
if ! command -v gcc &> /dev/null; then
    echo "ERRO: GCC não encontrado!"
    echo
    echo "Para instalar o GCC:"
    echo "Ubuntu/Debian: sudo apt install build-essential"
    echo "CentOS/RHEL: sudo yum install gcc"
    echo "macOS: xcode-select --install"
    echo
    exit 1
fi

echo "GCC encontrado! Compilando..."
echo

# Criar pasta data se não existir
mkdir -p data

# Compilar o programa
gcc -Wall -Wextra -std=c99 -Iinclude src/main.c src/membros.c src/planos.c src/frequencia.c src/utils.c -o corevita_system

if [ $? -eq 0 ]; then
    echo
    echo "=========================================="
    echo "    COMPILAÇÃO CONCLUÍDA COM SUCESSO!"
    echo "=========================================="
    echo
    echo "Execute o programa com: ./corevita_system"
    echo "Ou execute este script novamente e escolha a opção 2"
    echo
    
    # Dar permissão de execução
    chmod +x corevita_system
else
    echo
    echo "=========================================="
    echo "         ERRO NA COMPILAÇÃO!"
    echo "=========================================="
    echo
    echo "Verifique se todos os arquivos estão presentes:"
    echo "- include/academia.h"
    echo "- src/main.c"
    echo "- src/membros.c"
    echo "- src/planos.c"
    echo "- src/frequencia.c"
    echo "- src/utils.c"
    echo
    exit 1
fi

echo
echo "Opções:"
echo "1. Sair"
echo "2. Executar o programa"
echo
read -p "Escolha uma opção (1 ou 2): " opcao

if [ "$opcao" = "2" ]; then
    if [ -f "corevita_system" ]; then
        echo
        echo "Executando o Sistema CoreVita Fit..."
        echo
        ./corevita_system
    else
        echo
        echo "Programa não encontrado! Compile primeiro."
        exit 1
    fi
fi

echo
