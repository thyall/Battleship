#include <iostream>
#include <vector>
#include "bibi2.h"
#include <random>
#include <fstream>

void criar_tabuleiro(int max_x, int max_y,char **matriz, int n, int m)
{
	for (int i = 0; i < max_x; ++i)
	{
		for (int j = 0; j < max_y; ++j)
		{
			matriz[i][j] = '~';						
		}
	}	
}

void print_tabu_terminal(char **matriz, int n, int m)
{
   for(int i= 1; i < n+1; ++i){
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  for (int i = 1; i < n+1; ++i)
  {
    for (int j = 1; j < m+1; ++j)
    {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << i << std::endl ;
  }
  std::cout << std::endl;
}

int gera_coord(int lim, char type_barco)
{
	int x;
  //nessa linha estou colocando o intervalo de quanto até quanto eu quero que o varie
  // estou usando n - 4, porque n é um dos lados sendo passado da matriz menos o tamanho do Batleship, para não correr o risco 
  // o risco de "passar" da matriz*/ 

  std::random_device rd;
 
 	std::mt19937_64 gen(rd()); 	// esse objeto deixa o ramdom mais "pseudo aleatorio possivel"

  if(type_barco == 'B')
  {  	
  	std::uniform_int_distribution < unsigned long long > var(1,lim - 3);
		x = var(gen);
	}

	else if(type_barco == 'D')
	{		
		std::uniform_int_distribution < unsigned long long > var(1,lim-2);
		x = var(gen);
	}

  else if(type_barco == 'C')
  {
    std::uniform_int_distribution < unsigned long long > var(1,lim-1);
    x = var(gen);
  }

   else if(type_barco == 'S')
  {    
    std::uniform_int_distribution < unsigned long long > var(1,lim);
    x = var(gen);
  }
  	return x;
}

int gera_v_ou_h()
{
 
 int posi;

 std::random_device rd;
 
 std::mt19937_64 gen(rd());;

 std::uniform_int_distribution<unsigned long long> batata(1,2);

 posi = batata(gen);

 return posi;

}
void plotar_bt(char **matriz, int n, int m)
{
	int coord_X, coord_y, coord_vertical_horizontal;	

  	coord_X = gera_coord(n, 'B');

  	coord_y = gera_coord(m, 'B');

  	coord_vertical_horizontal = gera_v_ou_h();

  	//1 para horizontal 2 para vertical
  	if(coord_vertical_horizontal == 1)
  	{
  		matriz[coord_X][coord_y] = 'B';
  		matriz[coord_X][coord_y + 1] = 'B';
  		matriz[coord_X][coord_y + 2] = 'B';
  		matriz[coord_X][coord_y + 3] = 'B';

      //agora marcando as areas ao redor do batleship
      matriz[coord_X +1][coord_y] = '+';
      matriz[coord_X +1][coord_y + 1] = '+';
      matriz[coord_X+1][coord_y + 2] = '+';
      matriz[coord_X+1][coord_y + 3] = '+';

      matriz[coord_X -1][coord_y] = '+';
      matriz[coord_X -1][coord_y + 1] = '+';
      matriz[coord_X- 1][coord_y + 2] = '+';
      matriz[coord_X -1][coord_y + 3] = '+';

      matriz[coord_X-1 ][coord_y-1] = '+';
      matriz[coord_X][coord_y-1] = '+';
      matriz[coord_X+1][coord_y-1] = '+';

      matriz[coord_X-1][coord_y+4] = '+';
      matriz[coord_X][coord_y+4] = '+';
      matriz[coord_X+1][coord_y+4] = '+'; 

  	}

  	else
  	{
  		matriz[coord_X][coord_y] = 'B';
  		matriz[coord_X + 1][coord_y ] = 'B';
  		matriz[coord_X + 2][coord_y ] = 'B';
  		matriz[coord_X + 3][coord_y] = 'B';

      //agora marcando as areas ao redor do batleship
      matriz[coord_X][coord_y+1] = '+';
      matriz[coord_X+1][coord_y+1 ] = '+';
      matriz[coord_X+2][coord_y+1] = '+';
      matriz[coord_X+3][coord_y+1] = '+';

      matriz[coord_X ][coord_y-1] = '+';
      matriz[coord_X+1][coord_y-1] = '+';
      matriz[coord_X+2][coord_y-1] = '+';
      matriz[coord_X+3][coord_y-1] = '+';

      matriz[coord_X-1 ][coord_y-1] = '+';
      matriz[coord_X-1][coord_y] = '+';
      matriz[coord_X-1][coord_y+1] = '+';

      matriz[coord_X+4][coord_y-1] = '+';
      matriz[coord_X+4][coord_y] = '+';
      matriz[coord_X+4][coord_y+1] = '+';  
  	}
    print_arq_armada('B',coord_X, coord_y, coord_vertical_horizontal);
}

void plotar_destroyer(char **matriz, int n, int m)
{
	int coord_X, coord_y, coord_vertical_horizontal;

  bool l;

 	coord_X = gera_coord(n, 'D');

  coord_y = gera_coord(m, 'D');

  coord_vertical_horizontal = gera_v_ou_h();

  l = false;

  if(coord_vertical_horizontal == 1)//para horizontal
  {
    while(l == false)
    {
      if(matriz[coord_X][coord_y] == '~' and matriz[coord_X][coord_y + 1] == '~' and matriz[coord_X][coord_y + 2] == '~' )
      { 
        matriz[coord_X][coord_y] = 'D';
        matriz[coord_X][coord_y + 1] = 'D';
        matriz[coord_X][coord_y + 2] = 'D';
        // agora marcando as areas ao redor do destroyer
        matriz[coord_X+1][coord_y] = '+';
        matriz[coord_X+1][coord_y + 1] = '+';
        matriz[coord_X+1][coord_y + 2] = '+';

        matriz[coord_X-1][coord_y] = '+';
        matriz[coord_X-1][coord_y + 1] = '+';
        matriz[coord_X-1][coord_y + 2] = '+';

        matriz[coord_X-1 ][coord_y-1] = '+';
        matriz[coord_X][coord_y-1] = '+';
        matriz[coord_X+1][coord_y-1] = '+';

        matriz[coord_X-1][coord_y+3] = '+';
        matriz[coord_X][coord_y+3] = '+';
        matriz[coord_X+1][coord_y+3] = '+';

        l = true;       
      }

      else//pegando nova posiçao
      {
        //gerando novas coordenadas e direção
        coord_X = gera_coord(n, 'D');
        coord_y = gera_coord(m, 'D'); 
        coord_vertical_horizontal = gera_v_ou_h();
        l = false;            
      } 
    }
  }

  else//para vertical
  {
    while(l == false)
    {
      if(matriz[coord_X][coord_y] == '~' and matriz[coord_X+1][coord_y ] == '~' and matriz[coord_X+2][coord_y ] == '~' )
      { 
        matriz[coord_X][coord_y] = 'D';
        matriz[coord_X + 1][coord_y ] = 'D';
        matriz[coord_X + 2][coord_y ] = 'D';

        //marcando as bordas do barco na vertical
        matriz[coord_X][coord_y+1] = '+';
        matriz[coord_X+1][coord_y+1 ] = '+';
        matriz[coord_X+2][coord_y+1] = '+';

        matriz[coord_X ][coord_y-1] = '+';
        matriz[coord_X+1][coord_y-1] = '+';
        matriz[coord_X+2][coord_y-1] = '+';
        
        matriz[coord_X-1 ][coord_y-1] = '+';
        matriz[coord_X-1][coord_y] = '+';
        matriz[coord_X-1][coord_y+1] = '+';

        matriz[coord_X+3][coord_y-1] = '+';
        matriz[coord_X+3][coord_y] = '+';
        matriz[coord_X+3][coord_y+1] = '+';

        l = true;       
      }

      else//se n conseguir pega nova posição
      {
          //gerando novas coordenadas e direção
          coord_X = gera_coord(n, 'D');
          coord_y = gera_coord(m, 'D'); 
          coord_vertical_horizontal = gera_v_ou_h();
          l = false;             
        } 
      }            
    }
  print_arq_armada('D',coord_X, coord_y, coord_vertical_horizontal); 
}

void plotar_cruser(char **matriz, int n, int m)
{
  int coord_X, coord_y, coord_vertical_horizontal;

  bool l;

  coord_X = gera_coord(n, 'C');

  coord_y = gera_coord(m, 'C');

  coord_vertical_horizontal = gera_v_ou_h();

  l = false;

  if(coord_vertical_horizontal == 1)//para horizontal
  {
    while(l == false)
    {
      if(matriz[coord_X][coord_y] == '~' and matriz[coord_X][coord_y + 1] == '~')
      { 
        matriz[coord_X][coord_y] = 'C';
        matriz[coord_X][coord_y + 1] = 'C';        

        matriz[coord_X+1][coord_y] = '+';
        matriz[coord_X+1][coord_y + 1] = '+';        

        matriz[coord_X-1][coord_y] = '+';
        matriz[coord_X-1][coord_y + 1] = '+';       

        matriz[coord_X-1 ][coord_y-1] = '+';
        matriz[coord_X][coord_y-1] = '+';
        matriz[coord_X+1][coord_y-1] = '+';

        matriz[coord_X-1][coord_y+2] = '+';
        matriz[coord_X][coord_y+2] = '+';
        matriz[coord_X+1][coord_y+2] = '+';

        l = true;       
      }

      else//pegando nova posiçao
      {
          coord_X = gera_coord(n, 'C');
          coord_y = gera_coord(m, 'C');
          coord_vertical_horizontal = gera_v_ou_h(); 
          l = false;
      }
    }            
  }

  else//para vertical
  {
    while(l == false)
    {
      if(matriz[coord_X][coord_y] == '~' and matriz[coord_X+1][coord_y ] == '~')
      { 
        matriz[coord_X][coord_y] = 'C';
        matriz[coord_X + 1][coord_y ] = 'C';
        
        //marcando as bordas do barco na vertical
        matriz[coord_X][coord_y+1] = '+';
        matriz[coord_X+1][coord_y+1 ] = '+';        

        matriz[coord_X ][coord_y-1] = '+';
        matriz[coord_X+1][coord_y-1] = '+';        
        
        matriz[coord_X-1 ][coord_y-1] = '+';
        matriz[coord_X-1][coord_y] = '+';
        matriz[coord_X-1][coord_y+1] = '+';

        matriz[coord_X+2][coord_y-1] = '+';
        matriz[coord_X+2][coord_y] = '+';
        matriz[coord_X+2][coord_y+1] = '+';

        l = true;       
      }

      else//se n conseguir pega nova posição
      {
          coord_X = gera_coord(n, 'C');
          coord_y = gera_coord(m, 'C');
          coord_vertical_horizontal = gera_v_ou_h();
          l = false;
      }
    }            
  }
  print_arq_armada('C',coord_X, coord_y, coord_vertical_horizontal);    
}

void plotar_sub(char **matriz, int n, int m)
{
  int coord_X, coord_y;

  bool l;
  
    coord_X = gera_coord(n, 'S');

    coord_y = gera_coord(m, 'S');

    l = false;

    while(l == false)
    {
    	if(matriz[coord_X][coord_y] == '~')
    	{
      		matriz[coord_X][coord_y] = 'S';
          // agora marcando as areas ao redor do submarino
      		matriz[coord_X][coord_y-1] = '+';
      		matriz[coord_X+1][coord_y] = '+';
     		  matriz[coord_X+1][coord_y+1] = '+';
     	  	matriz[coord_X+1][coord_y-1] = '+';
      		matriz[coord_X][coord_y+1] = '+';
      		matriz[coord_X-1][coord_y+1] = '+';
      		matriz[coord_X-1][coord_y] = '+';
      		matriz[coord_X-1][coord_y-1] = '+';

      		l = true;
    	}
    	else
    	{
    		coord_X = gera_coord(n, 'S');

        coord_y = gera_coord(m, 'S');

        l =false;
    	}
    }
   print_arq_armada('S',coord_X, coord_y, 2);
}
/*void plotar_cruser1(char **matriz, int n, int m)
{
  int coord_vertical_horinzontal;

  coord_vertical_horinzontal = gera_v_ou_h();

  if(coord_vertical_horinzontal == 1)
  {
    for(int i = 1; i < n-1; ++i)
    {
        for(int j = 1; j < m-1; ++j)
        { 
          if(matriz[i][j] == '~' and matriz[i][j+1] == '~')
          {
                matriz[i][j] = 'C';
                matriz[i][j+1] = 'C';

                //plotando bordas
                matriz[i+1][j] = '+';
                matriz[i+1][j + 1] = '+';        

                matriz[i-1][j] = '+';
                matriz[i-1][j + 1] = '+';       

                matriz[i-1 ][j-1] = '+';
                matriz[i][j-1] = '+';
                matriz[i+1][j-1] = '+';

                matriz[i-1][j+2] = '+';
                matriz[i][j+2] = '+';
                matriz[i+1][j+2] = '+';
                i = n;
                j = m;
            }
          }
        }
    print_arq_armada('S', n, m, 2);
   } 

    else
    {
      for(int i = 1; i < n-1; ++i)
      {
        for(int j = 1; j < m-1; ++j)
        { 
          if(matriz[i][j+1] == '~' and matriz[i][j] == '~')
          {
                matriz[i][j] = 'C';
                matriz[i+1][j] = 'C';

                //plotando bordas
                matriz[i][j+1] = '+';
                matriz[i+1][j + 1] = '+';        

                matriz[i][j-1] = '+';
                matriz[i+1][j -1] = '+';       

                matriz[i-1 ][j-1] = '+';
                matriz[i-1][j] = '+';
                matriz[i-1][j+1] = '+';

                matriz[i+2][j-1] = '+';
                matriz[i+2][j] = '+';
                matriz[i+2][j+1] = '+';
                i = n;
                j = m;
            }
          }
        }      
      }
}*/

void print_arq_armada(char type, int n, int m, int vetor)
{
  char direcao;

  std:: ofstream tabu_armada;
  tabu_armada.open("Armada_arq.txt",std:: ofstream::app);

  if(vetor == 1)
    direcao = 'H';
  else
    direcao = 'V';

  if(type == 'S')
    tabu_armada << type << " " << n << " " << m << " " << std::endl;

  else
    tabu_armada << type << " " << n << " " << m << " " << direcao  << std::endl; 
 
  tabu_armada.close();
}


  	 	




	
