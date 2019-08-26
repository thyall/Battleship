#CRIANDO MAKE

CC = g++

CPPFLAGS = -Wall

BPG: func_destroyer.o main_destroyer.o 
	@$(CC) $(CPPFLAGS) -std=c++11 func_destroyer.o main_destroyer.o -o BPG
	@echo "Bingo!!! Tabuleiros criados"

main_destroyer.o: main_destroyer.cpp
	@$(CC) $(CPPFLAGS) -std=c++11 -c main_destroyer.cpp
	@echo "Criando seu tabuleiro..."
func_destroyer.o: func_destroyer.cpp
	@$(CC) $(CPPFLAGS) -std=c++11 -c func_destroyer.cpp
	@echo "Chamando as funções meu patrão"
clean:
	@rm -rf *o BPG
	@echo "Diretorio limpo"




