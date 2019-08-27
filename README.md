# Battleship
Battleship puzzles board generator 


## Objetivo
- Esse programa tem como objetivo geração de puzzles do jogo Batalha Naval onde você poderá aprender e entender um pouco das regras desse jogo aqui nesse [site](https://en.wikipedia.org/wiki/Battleship_(puzzle)). Esse programa irá gerar de 0 a 100 puzzles e os seus tabuleiros terão dimensões compreendidas de 10x10 a 16x16.

## Programa & limitações
- Para poder rodar o codigo basta apenas o comando de **_g++ -Wall -std=c++11 -Iinclude source/main.cpp source/func.cpp_** como linha de comando no seu terminal
ou apenas o comando **_make_**. Para gerar os puzzles o usuario pode apenas dar o comando **_./bpg 10 -r 10 -c 10_**, nesse exemplo o programa irá gerar 10 puzzles de dimensão 10 por 10, não colocando as linhas e colunas "-r 10 e -c 10" o programa por padrão irão gerar tabuleiros 10x10. Na pasta "datas" terá um arquivo armada.txt onde nele tera as coordenadas dos barcos gerados, na pasta "source" terá os arquivos _.cpp_ e na pasta "include" terá o arquivo _.h_, por fim um otimo comando no terminal para limpar seu diretório é o comando **_make clean_**.

### exemplos de comandos:
* **_./bpg 10 -r 10 -c 10_** aqui ele gera 10 puzzles de dimesões (10x10)
* **_./bpg 50 -r 10 -c 10_** aqui ele gera 50 puzzles de dimesões (10x10)
* **_./bpg 20 -r 15 -c 15_** aqui ele gera 20 puzzles de dimesões (15x15)
* **_./bpg 10_** aqui ele gera 10 puzzles de dimensões padrão (10x10).

### Limitações:
- O programa não gera tabuleiros menores que 9x9 devido ao uso da biblioteca **_ramdom_** para mais estudos você pode olhar aqui as [referências](http://www.cplusplus.com/reference/random/). Acredito que com dimensões menores que 9x9 nessa forma de abordagem, o problema faz com que a gerações de coordenadas vá para o infinito,pois não só os barcos como também suas bordas preenchem o tabuleiro logo a probabilidade de achar uma coordenada correta para o barco se torna menor para cada barco plotado uma boa possibilidade de mudança é que para tabuleiros menores que 10x10 as funções geradores de barcos sejam feitas de forma sistematica e não randomicas.

## Pré requisitos & guia de instalação
- A distribuição utilizada pelo projeto foi [Ubuntu 18.04 LTS](https://ubuntu.com/download/desktop).
- O compilador foi o G++ e caso não o tenha em sua máquina aqui tem um bom [tutorial para descobrir como instalar o G++.](https://stackoverflow.com/questions/46254629/how-can-install-cpp-compiler-on-ubuntu-terminal) mas aqui eu dsponibilizo uma ajuda para caso sua distribuição do Linux seja Ubuntu **_sudo apt install g++_**
- Também há o **Make** caso não queira compilar com a linha de comando a cima. Também se faz necessário uma instalação e aqui vai uma [ajuda](https://www.cyberciti.biz/faq/howto-installing-gnu-c-compiler-development-environment-on-ubuntu/).

## Dúvidas??? sugestões???
- email para contato **thyall96@gmail.com**

### Autor
  - Thyall D'greville
