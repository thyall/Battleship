#include "bibi2.h"
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <fstream>

#define MAX_COL 16
#define MAX_ROW 16
#define MAX_NPUZZLE 100
#define MIN_COL 10
#define MIN_ROW 10
#define MIN_NPUZZLE 1
// valores padrao
#define DEF_COL 10
#define DEF_ROW 10
#define DEF_NPUZZLE MIN_NPUZZLE

void message( std::string msg="" )
{
    if ( msg != "" )
        std::cout << "   bpg ERROR: \"" << msg << "\"\n\n";

    std::cout <<
"   Usage: [<options>] <number_of_puzzles>\n" <<
"   Program options are:\n" <<
"        --rows <num>	Specify the number of rows for the matrix, with `<num>` in the range [10, 16 ]. The default value is 10.\n" <<
"        --cols <num>	Specify the number of columns for the matrix, with `<num>` in the range [10,16]. The default value is 10.\n" <<
"   Requested input is:\n" <<
"       number_of_puzzles	The number of puzzles to be generated, in the range [1,100].\n";

    exit( 0 );
}
/// Converte uma string para minusculas
std::string str_tolower( std::string str )
{
    for ( char & c : str )
        c = std::tolower( c );

    return str;
}

int main(int argc, char const *argv[])
{
	int X, Y, QT;
	char **jogo; // como será uma matriz iremos criar um ponteiro para ponteiro (duas dimensões)

	X = DEF_ROW;
	Y = DEF_COL;

	if ( argc == 1 )
        message();

    if ( argc > 6 )
        message("Too many argumnents!");

	// Processar os argumentos
    for ( auto i{1} ; i < argc ; ++i )
    {
        // convert the current argument to lower case.
        auto s_arg = str_tolower( argv[i] );

        if ( s_arg == "-r" or s_arg == "--row" or s_arg == "-row" or s_arg == "--r"  )
        {
            int colum = 0;
            if ( (i+1) == argc )
                message("Missing number of rows!");

            try {
                colum = std::stoi( argv[++i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for row!");
            }

            if ( colum < MIN_ROW or colum > MAX_ROW )
                message("Number of rows out of the acceptable range!");

            X = colum;
        }
        else if ( s_arg == "-c" or s_arg == "--col" or s_arg == "-col" or s_arg == "--c"  )
        {
            int rols = 0;
			if ( (i+1) == argc )
                message("Missing number of rows!");
            try {
                rols = std::stoi( argv[++i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for columns!");
            }

            if ( rols < MIN_ROW or rols > MAX_ROW )
                message("Number of columns out of the acceptable range!");

            Y = rols;
        }
        else // # of puzzles
        {
            int npuzzles = 1;

            try {
                npuzzles = std::stoi( argv[i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for number of puzzles!");
            }

            if ( npuzzles < MIN_NPUZZLE or npuzzles > MAX_NPUZZLE )
                message("The requested number of puzzles is out of the acceptable range!");

            QT = npuzzles;
        }
	}   

    std::cout << ">>> cols = " << X << ", rows = "  << Y << ", npuzzles = " << QT << std::endl;

    for (int i = 0; i < QT; ++i)
    {
        // aqui estou alocando a primeira dimensão X
	    jogo = new char*[17];

	    // nesse for eu estou alocando a outra dimensão Y para cada ponteira ja alocado assim criando uma matriz de ponteiros
	    for (int i = 0; i < 17; ++i)
	    {
	    	jogo[i] = new char[17];
	    }	    
        //a ideia de passar 17 é para sempre criar uma matriz maior que o limite 16 para poder trabalhar com as bordas dos barcos sem se preocupar com 
        //o uso de memoria de indevido
	    criar_tabuleiro(17, 17, jogo,X , Y);

	    plotar_bt(jogo, X, Y);//plotando o primeiro barco o batlehsip

	    plotar_destroyer(jogo, X, Y);
        plotar_destroyer(jogo, X, Y);

        plotar_cruser(jogo, X, Y);
        plotar_cruser(jogo, X, Y);
        plotar_cruser(jogo, X, Y);

        plotar_sub(jogo, X, Y);
        plotar_sub(jogo, X, Y);
        plotar_sub(jogo, X, Y);
        plotar_sub(jogo, X, Y);

        print_tabu_terminal(jogo, X, Y);
        //print_arq_armada(jogo, X, Y);

        delete jogo;// fechando o jogo para n ter vazamento de memoria        
    }
	return 0;
}