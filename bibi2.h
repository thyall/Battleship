#ifndef BP_H
#define BP_H

void criar_tabuleiro(int max_x, int max_y, char **matriz, int n, int m);

void print_tabu_terminal(char **matriz, int n, int m);

void plotar_bt(char **matriz, int n, int m);

void plotar_destroyer(char **matriz, int n, int m);

void plotar_cruser(char **matriz, int n, int m);

void plotar_cruser1(char **matriz, int n, int m);

void plotar_sub(char **matriz, int n, int m);

void print_arq_armada(char type, int n, int m, int vetor);

int gera_v_ou_h();

#endif

//para compilar g++ -Wall -std=c++11 "programas".cpp