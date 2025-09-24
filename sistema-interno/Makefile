# Makefile para o Sistema CoreVita Fit

# Detectar sistema operacional
ifeq ($(OS),Windows_NT)
    # Windows
    CC = gcc
    TARGET = corevita_system.exe
    MKDIR = if not exist $(DATADIR) mkdir $(DATADIR)
    RM = del /Q
    RMDIR = rmdir /S /Q
else
    # Linux/macOS
    CC = gcc
    TARGET = corevita_system
    MKDIR = mkdir -p $(DATADIR)
    RM = rm -f
    RMDIR = rm -rf
endif

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Diretórios
SRCDIR = src
INCDIR = include
DATADIR = data

# Arquivos fonte
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/membros.c $(SRCDIR)/planos.c $(SRCDIR)/frequencia.c $(SRCDIR)/utils.c

# Regra principal
all: $(TARGET)

# Compilar o programa
$(TARGET): $(SOURCES)
	@echo "Compilando Sistema CoreVita Fit..."
	@$(MKDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) $(SOURCES) -o $(TARGET)
	@echo "Compilação concluída! Execute com: $(TARGET)"

# Limpar arquivos compilados
clean:
	@echo "Limpando arquivos compilados..."
	@$(RM) $(TARGET)
	@echo "Limpeza concluída!"

# Limpar dados salvos
clean-data:
	@echo "Limpando dados salvos..."
ifeq ($(OS),Windows_NT)
	@if exist $(DATADIR)\*.dat del /Q $(DATADIR)\*.dat
else
	@$(RM) $(DATADIR)/*.dat
endif
	@echo "Dados limpos!"

# Limpar tudo
clean-all: clean clean-data
ifeq ($(OS),Windows_NT)
	@if exist $(DATADIR) rmdir /Q $(DATADIR) 2>nul || echo "Pasta data removida ou não existe"
else
	@$(RMDIR) $(DATADIR) 2>/dev/null || echo "Pasta data removida ou não existe"
endif

# Executar o programa
run: $(TARGET)
ifeq ($(OS),Windows_NT)
	$(TARGET)
else
	./$(TARGET)
endif

# Instalar dependências (se necessário)
install:
	@echo "Verificando dependências..."
ifeq ($(OS),Windows_NT)
	@where gcc >nul 2>&1 || (echo "GCC não encontrado! Instale MinGW-w64 ou Visual Studio." && exit 1)
else
	@which gcc > /dev/null || (echo "GCC não encontrado! Instale o GCC para compilar." && exit 1)
endif
	@echo "Todas as dependências estão instaladas!"

# Ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make          - Compila o programa"
	@echo "  make run      - Compila e executa o programa"
	@echo "  make clean    - Remove arquivos compilados"
	@echo "  make clean-data - Remove dados salvos"
	@echo "  make clean-all  - Remove tudo"
	@echo "  make install  - Verifica dependências"
	@echo "  make help     - Mostra esta ajuda"

.PHONY: all clean clean-data clean-all run install help
