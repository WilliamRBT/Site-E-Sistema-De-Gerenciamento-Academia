@echo off
echo ==========================================
echo    COMPILADOR SISTEMA COREVITA FIT
echo ==========================================
echo.

REM Verificar se o GCC está instalado
gcc --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ERRO: GCC nao encontrado!
    echo.
    echo Para instalar o GCC no Windows:
    echo 1. Baixe e instale MinGW-w64 de: https://www.mingw-w64.org/
    echo 2. Ou instale via MSYS2: https://www.msys2.org/
    echo 3. Adicione o GCC ao PATH do sistema
    echo.
    echo Alternativamente, use o Visual Studio com suporte a C
    pause
    exit /b 1
)

echo GCC encontrado! Compilando...
echo.

REM Criar pasta data se não existir
if not exist "data" mkdir data

REM Compilar o programa
gcc -Wall -Wextra -std=c99 -Iinclude src/main.c src/membros.c src/planos.c src/frequencia.c src/utils.c -o corevita_system.exe

if %errorlevel% equ 0 (
    echo.
    echo ==========================================
    echo    COMPILACAO CONCLUIDA COM SUCESSO!
    echo ==========================================
    echo.
    echo Execute o programa com: corevita_system.exe
    echo Ou execute este arquivo novamente e escolha a opcao 2
    echo.
) else (
    echo.
    echo ==========================================
    echo         ERRO NA COMPILACAO!
    echo ==========================================
    echo.
    echo Verifique se todos os arquivos estao presentes:
    echo - include/academia.h
    echo - src/main.c
    echo - src/membros.c
    echo - src/planos.c
    echo - src/frequencia.c
    echo - src/utils.c
    echo.
)

echo.
echo Opcoes:
echo 1. Sair
echo 2. Executar o programa (se compilado com sucesso)
echo.
set /p opcao="Escolha uma opcao (1 ou 2): "

if "%opcao%"=="2" (
    if exist "corevita_system.exe" (
        echo.
        echo Executando o Sistema CoreVita Fit...
        echo.
        corevita_system.exe
    ) else (
        echo.
        echo Programa nao encontrado! Compile primeiro.
        pause
    )
)

echo.
pause
