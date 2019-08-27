#CRIANDO MAKE
############ meu primeiro makefile##################

CC = g++ #compilador

CPPFLAGS = -Wall #flags

#executavel
BPG: func.o main.o 
	@$(CC) $(CPPFLAGS) -Iinclude -std=c++11 func.o main.o -o BPG
	@echo "Bingo!!! Tabuleiros criados"
# o -I include diz que a biblioteca está nessa pasta

main.o: source/main.cpp
	@$(CC) $(CPPFLAGS) -std=c++11 -c -Iinclude source/main.cpp
	@echo "Criando seu tabuleiro..."

func.o: source/func.cpp
	@$(CC) $(CPPFLAGS) -std=c++11 -c -Iinclude source/func.cpp
	@echo "Chamando as funções meu patrão"
clean:
	@rm -rf *o BPG
	@echo "Diretorio limpo"




