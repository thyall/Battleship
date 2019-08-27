#ifndef BP_H
#define BP_H

void criar_tabuleiro(int max_x, int max_y, char **matriz, int n, int m);//cria um tabuleiro 18x18 para n ter problemas com as bordas

void print_tabu_terminal(char **matriz, int n, int m);//printa os tabuleiros no terminal

void print_arq_armada(char type, int n, int m, int vetor);//gera o arquivo armada.txt na pasta datas com as coordendas

void plotar_bt(char **matriz, int n, int m);//plota o battlheshipp no tabuleiro

void plotar_destroyer(char **matriz, int n, int m);//plota o desroyer no tabuleiro

void plotar_cruser(char **matriz, int n, int m);//plota o crusador no tabuleiro

void plotar_sub(char **matriz, int n, int m);//plota o submarino no tabuleiro

int gera_v_ou_h();//essa função retorna 1 ou 2 pseudo aleatoriamente para saber se o barco vai estar na horizontal ou vertical

int gera_coord(int lim, char type_barco);// retorna uma coordenada X ou Y de acordo com o tamanho do barco

#endif


