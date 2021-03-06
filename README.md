# Trie
**Implementação da estrutura Trie proposta na disciplina de Org. de Estruturas de Arquivos ministrada pelo professor Renato Mauro no CEFET/RJ.**

<hr>
**A trie criada neste repositório é basicamente uma representação de um dicionário.**

Implementamos as seguintes classes:
<br>*Node*: É o nó da árvore. Nela temos as variáveis necessárias para guardar os dados e a função findChild() para andar pelos nós.
<br>*Trie*: É a árvore em si. Ela possui uma instância de Node que é a raiz da árvore, uma função de inserção e outra de busca.

No arquivo *main.cpp*, temos: uma instância de trie; a função que popula essa instância com os dados do arquivo dicionario.txt; uma que trata a entrada do usuário (já que temos que remover os acentos e deixar tudo em maiúscula); e uma outra que, enfim, faz a busca pela palavra desejada.

<hr>
O arquivo utilizado como dicionário para o programa foi encontrado em: http://alcor.concordia.ca/~vjorge/Palavras-Cruzadas/Lista-de-Palavras.txt

**As palavras nesse dicionário estão em maiúscula e não estão acentuadas**

<hr>
**Para executar o programa no Linux basta abrir o terminal no diretório do projeto e dar um ./make**
<br>Obs.: Talvez seja necessário usar chmod +x make por causa da permissão.

<hr>
**Usando o programa**
<br>O programa espera como entrada a palavra a ser buscada e retorna se achou ou não a palavra.
