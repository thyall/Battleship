#CRIANDO MAKE
############ meu primeiro makefile##################

CC = g++ #compilador

CPPFLAGS = -Wall #flags

#executavel
BPG: func.o main.o 
	@$(CC) $(CPPFLAGS) -Iinclude -std=c++11 func.o main.o -o BPG
	@echo "#####################################################################"
	@echo "#####################################################################\n"
	@echo ">>>>>>>>>>>>>>>> Battleship Puzzles Version 1.0 <<<<<<<<<<<<<<<<<<<<<\n"
	@echo "Autor: Thyall D'greville\n"
	@echo "Para mais informações digite o comando --> ./BPG\n"
	@echo "#####################################################################"
	@echo "#####################################################################\n"
# o -I include diz que a biblioteca está nessa pasta

main.o: source/main.cpp
	@$(CC) $(CPPFLAGS) -std=c++11 -c -Iinclude source/main.cpp
	@echo "Aguarde..."
	@echo "Pronto!!!"

func.o: source/func.cpp
	@$(CC) $(CPPFLAGS) -std=c++11 -c -Iinclude source/func.cpp
	@echo "Instalando..."
clean:
	@rm -rf *o BPG
	@echo "Diretorio limpo"




