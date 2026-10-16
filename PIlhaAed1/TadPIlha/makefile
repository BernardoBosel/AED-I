# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Alvo principal (executado por padrão ao rodar apenas 'make')
all: programa

# Como gerar o executável a partir do arquivo .c
programa: main.c pilha.c pilha.h
	$(CC) $(CFLAGS) -o programa main.c pilha.c

# Alvo para limpar os arquivos gerados
clean:
	rm -f programa
