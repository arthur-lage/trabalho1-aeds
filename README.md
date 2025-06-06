# Trabalho 1 AEDS - Simulação de Incêndio

![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

Aluno: Arthur Batista Lage e Silva

Professor: Michel Pires da Silva

Disciplina: Algoritmos e Estruturas de Dados I

## Introdução

Esse trabalho de aquecimento tem o objetivo de simular a propagação de um incêndio em uma floresta e também a movimentação de um animal que está dentro dela.

Como funciona o programa de forma resumida:
    
    - Possui um arquivo de configurações chamado "config.cpp", localizado na pasta "src", em que podem ser definidas propriedades que afetam a simulação, como o número máximo de iterações e a direção do vento que empurra o fogo.

    - Lê informações da floresta e incêndio de um arquivo de entrada chamado de "input.dat", que está localizado na raiz do projeto.
    
    - Cria uma matriz que representa a floresta.

    - Possui um loop no arquivo "main.cpp", que fará com que a simulação seja executada até uma quantidade máxima de iterações. Além disso, o loop será encerrado caso: o animal tenha sido encurralado pelo fogo, e não consiga escapar com sua segunda chance; ou caso todas as árvores tenham sido queimadas

    - O incêndio só se espalha após a movimentação do animal.

    - O resultado final da simulação fica no arquivo "output.dat", que é gerado após o fim da execução do programa.

## Metodologia

### Fluxograma do funcionamento do projeto

<img src="/assets/diagramasimulacao.png"/>

Explicação a cerca do funcionamento das classes e métodos do programa.

#### <a href="/include/config.hpp">config.hpp</a>

Arquivo que define variáveis de configuração que serão usadas no código:

DIRECTIONS_WIND: Vetor que pode receber as opções ["UP", "DOWN", "LEFT", "RIGHT"] para decidir para onde o vento espalhará o fogo inicialmente. Caso nenhuma opção seja fornecida, o fogo se espalha igualmente para todas as direçoẽs.

ITERATIONS: Quantidade máxima de iterações que o programa pode fazer. (Número inteiro)

DIRS: Vetor de pair<int, int> que armazena os valores das direções de propagação do fogo ou movimentação do animal. Essa variável não deve ser alterada, pois o funcionamento do programa depende dela. As posições desse vetor representam os valores para esquerda, cima, baixo e direita.

#### <a href="/src/config.cpp">config.cpp</a>

Aqui as variáveis criadas anteriormente recebem os valores que o usuário deseja utilizar no programa.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/config.cpp#L10">Linha 10</a> : O vento inicia se espalhando para cima e para baixo da posição inicial do fogo.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/config.cpp#L16">Linha 16</a>: Define que o máximo de iterações do programa será 50, então caso sejam necessárias mais de 50 iterações para terminar a simulação, ela será encerrada na iteração número 50

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/config.cpp#L20">Linha 20</a>: Define as direções que podem ser utilizadas para o fogo se propagar e para o animal se mover na floresta. (Não deve ser alterado)

#### <a href="/src/Animal.cpp">Animal.cpp</a>

Implementa funcionalidades para a classe animal.

Métodos principais:


<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Animal.cpp#L54">Linha 54</a>: Avalia as posições ao redor do animal, representando as casas que são visíveis por ele. O valor das casas são salvos em um vetor "animalsVision" e são utilizadas para a tomada de decisão na movimentação do animal. As casas -1 representam casas que estão fora do mapa da floresta.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Animal.cpp#L114">Linha 114-214</a>: Essa é uma das funções principais no programa. Ela é responsável por analisar as posições em volta do animal e adicionar as possibilidades de movimento em um vetor "possibleSteps", priorizando as posições que animal ainda não explorou. Se não houver posições ainda não exploradas válidas, o animal tenta pelos lugares que ele já passou.

Caso o animal tenha uma posição com água ao seu redor, ele se move para lá imediatamente. Se não, são avaliadas outras opções, como posições seguras ou árvores saudáveis, e em última instância, casas com árvores queimadas.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Animal.cpp#L216">Linha 216-240</a>: Função que mostra informações do animal e também sua posição atual na floresta. O animal será representado por um X na floresta.

#### <a href="/src/FileReader.cpp">FileReader.cpp</a>

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/FileReader.cpp#L16">Linha 16-65</a>: Função "readMap", responsável por ler as informações da floresta no arquivo "input.dat" e retornar uma instância da classe Mapa com as informações da floresta.

#### <a href="/src/FileReader.cpp">FileWriter.cpp</a>

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/FileWriter.cpp#L16">Linha 16-21</a>: Adiciona informações do animal, como o número de passos total e quantas vezes ele achou água, no arquivo "output.dat".

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/FileWriter.cpp#L23">Linha 23-37</a>: Adicionar o estado atual da floresta no "output.dat"

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/FileWriter.cpp#L43">Linha 43-63</a>: Adicionar o estado atual da floresta com o animal representado por um X no "output.dat".

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/FileWriter.cpp#L65">Linha 65-85</a>: Adicionar o estado inicial da floresta com o animal representado por um X no "output.dat".

#### <a href="/src/Map.cpp">Map.cpp</a>

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Map.cpp#L89">Linha 89-112</a>: Função que verifica se o incêndio deve continuar ou não, fazendo isso por meio de uma análise de se ainda existem árvores pegando fogo ou que irão pegar fogo.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Map.cpp#L119">Linha 119-226</a>: Função que espalha o fogo pela floresta. 
Primeira iteração: Caso o usuário tenha especificado nas configurações que o vento deve iniciar em direções específicas, espalha o fogo nessas direções. Se ele não especificar, espalha o fogo em todas as direções ortogonais adjascentes da posição inicial do fogo.

Após isso, são analisadas todas as árvores que possuem fogo em volta e marcadas como true na matriz "willBurn", que armazena quais árvores começarão a pegar fogo. Então, as árvores que já estavam pegando fogo se tornam queimadas, e as que foram marcadas pelo "willBurn" começam a queimar.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Map.cpp#L238">Linha 238-269</a>: Escolhe a posição inicial do animal na floresta, pegando a primeira casa de valor 0 encontrado no mapa.

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Map.cpp#L271">Linha 271-285</a>: Quando o animal chega numa casa de número 4, transforma essa casa em uma área segura, e as áreas adjacentes ortogonalmente em árvores saudáveis.

#### <a href="/src/Simulation.cpp">Simulation.cpp</a>

<a href="https://github.com/arthur-lage/trabalho1-aeds/blob/8760e36f888363afdbe49aee37aa02b62115cf7c/src/Simulation.cpp#L7">Linha 7-83</a>: Função simulate: responsável por iniciar a simulação.

1. Inicializa o leitor e escritor de arquivos.
2. Lê o mapa do "input.dat".
3. Descobre a posição inicial do animal, e verifica se ele é criado em uma área que já está pegando fogo.
4. Cria o animal na posição inicial.
5. Loop principal.
6. Verifica se o incêndio deve continuar.
7. Verifica se o animal está no fogo.
8. Verifica se o animal possui uma segunda chance.
9. Se sim, dá uma segunda chance para ele se mover.
10. Se não, encerra a simulação.
11. Animal olha em volta, para saber quais as possibilidades de movimento.
12. Animal decide a melhor casa possível para a qual ele deve se mover.
13. O incêndio se espalha.
14. Caso o animal encontre água, torna as árvores em volta saudáveis.
15. Mostra as informações da floresta com e sem o animal.
16. Adicionar iterações no "output.dat".
        
### Estrutura do projeto

- Os arquivos de código (.cpp) estão localizados na pasta "src".

- Os arquvios de cabeçalho (.hpp) estão localizados na pasta "include".

- Os binários do projeto são gerados na pasta "build" após a compilação do programa.

### Movimentação do animal

O animal se move a cada iteração da simulação, escolhendo a melhor posição que ele encontrar:

(a) Melhor opção: posição com valor 4 (presença de água)
(b) Opções intermediárias: posição com valor 0 (área vazia) e posição com valor 1 (árvore saudável).
(c) Pior opção: posição com valor 3 (árvore queimada)

OBS: Caso o animal precise decidir entre 2 opções para se movimentar, ele vai selecionar alguma de forma aleatoria.

Ao alcançar uma posição com valor 4, essa posição se torna uma área vazia, e as posições ortogonalmente adjascentes se tornam 1 (árvores saudáveis).

### Segunda chance

Caso o animal seja atingido pelo fogo, ele receberá uma segunda chance de movimento, ficando imune ao fogo por uma iteração.

### Representação visual do incêndio

A propagação do fogo pode acontecer de duas maneiras: com vento em todas as direções ou somente em direções específicas. Isso precisa ser definido pelo usuário no arquivo "config.cpp".

#### Sem vento em direções específicos

Na propagação em todas as direções, o fogo começa se espalhando para cima, para baixo, para esquerda e para a direta, assim como ilustrado na imagem abaixo.

![image](assets/semventoespecifico.png)

#### Com vento em uma direção específica

Na propagação com vento em direção específica, o fogo se espalha somente naquela direção inicialmente.

![image](assets/comventoespecifico.png)

## Casos de teste

input.dat:

```
5 5 1 1
1 1 1 1 4
1 2 1 1 1
1 1 1 1 4
0 0 0 1 1
1 4 1 0 4
```

#### Output sem vento:

```
Iniciando simulação. O animal é representado pelo X: 
1 1 1 1 4 
1 2 1 1 1 
1 1 1 1 4 
X 0 0 1 1 
1 4 1 0 4 


Interação 1:
1 1 1 1 4 
1 2 2 1 1 
1 2 1 1 4 
0 0 0 1 1 
1 4 1 0 4 

Posição do animal: 
1 1 1 1 4 
1 2 2 1 1 
1 2 1 1 4 
0 X 0 1 1 
1 4 1 0 4 


Interação 2:
1 2 2 1 4 
2 3 3 2 1 
2 3 2 1 4 
0 1 0 1 1 
1 0 1 0 4 

Posição do animal: 
1 2 2 1 4 
2 3 3 2 1 
2 3 2 1 4 
0 1 0 1 1 
1 X 1 0 4 


Interação 3:
2 3 3 2 4 
3 3 3 3 2 
3 3 3 2 4 
0 1 0 1 1 
1 0 1 0 4 

Posição do animal: 
2 3 3 2 4 
3 3 3 3 2 
3 3 3 2 4 
0 1 0 1 1 
X 0 1 0 4 


Interação 4:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 1 0 2 1 
1 0 1 0 4 

Posição do animal: 
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
X 1 0 2 1 
1 0 1 0 4 


Interação 5:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 1 0 3 2 
1 0 1 0 4 

Posição do animal: 
3 3 3 3 4 
3 3 3 3 3 
X 3 3 3 4 
0 1 0 3 2 
1 0 1 0 4 


Interação 6:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 1 0 3 3 
1 0 1 0 4 

Posição do animal: 
3 3 3 3 4 
X 3 3 3 3 
3 3 3 3 4 
0 1 0 3 3 
1 0 1 0 4 


A simulação parou na iteração: 6


Informações do animal: 
Número de passos: 1
Achou água 1 vezes.
```

#### Output com vento em um direção (para baixo):

```
Iniciando simulação. O animal é representado pelo X: 
1 1 1 1 4 
1 2 1 1 1 
1 1 1 1 4 
X 0 0 1 1 
1 4 1 0 4 


Interação 1:
1 1 1 1 4 
1 2 1 1 1 
1 2 1 1 4 
0 0 0 1 1 
1 4 1 0 4 

Posição do animal: 
1 1 1 1 4 
1 2 1 1 1 
X 2 1 1 4 
0 0 0 1 1 
1 4 1 0 4 


Interação 2:
1 2 1 1 4 
2 3 2 1 1 
2 3 2 1 4 
0 0 0 1 1 
1 4 1 0 4 

Posição do animal: 
1 2 1 1 4 
X 3 2 1 1 
2 3 2 1 4 
0 0 0 1 1 
1 4 1 0 4 


Interação 4:
2 3 2 1 4 
3 3 3 2 1 
3 3 3 2 4 
0 0 0 1 1 
1 4 1 0 4 

Posição do animal: 
2 3 2 1 4 
3 X 3 2 1 
3 3 3 2 4 
0 0 0 1 1 
1 4 1 0 4 


Interação 5:
3 3 3 2 4 
3 3 3 3 2 
3 3 3 3 4 
0 0 0 2 1 
1 4 1 0 4 

Posição do animal: 
3 X 3 2 4 
3 3 3 3 2 
3 3 3 3 4 
0 0 0 2 1 
1 4 1 0 4 


Interação 6:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 0 0 3 2 
1 4 1 0 4 

Posição do animal: 
X 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 0 0 3 2 
1 4 1 0 4 


Interação 7:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 0 0 3 3 
1 4 1 0 4 

Posição do animal: 
3 3 3 3 4 
X 3 3 3 3 
3 3 3 3 4 
0 0 0 3 3 
1 4 1 0 4 


A simulação parou na iteração: 7


Informações do animal: 
Número de passos: 0
Achou água 0 vezes.
```

#### Output com vento em 3 direções (esquerda, direita e para cima):

```
Iniciando simulação. O animal é representado pelo X: 
1 1 1 1 4 
1 2 1 1 1 
1 1 1 1 4 
X 0 0 1 1 
1 4 1 0 4 


Interação 1:
1 2 1 1 4 
2 2 2 1 1 
1 1 1 1 4 
0 0 0 1 1 
1 4 1 0 4 

Posição do animal: 
Passos: 1
1 2 1 1 4 
2 2 2 1 1 
1 1 1 1 4 
0 0 0 1 1 
X 4 1 0 4 


Interação 2:
2 3 2 1 4 
3 3 3 2 1 
2 2 2 1 4 
0 1 0 1 1 
1 0 1 0 4 

Posição do animal: 
Passos: 2
2 3 2 1 4 
3 3 3 2 1 
2 2 2 1 4 
0 1 0 1 1 
1 X 1 0 4 


Interação 3:
3 3 3 2 4 
3 3 3 3 2 
3 3 3 2 4 
0 2 0 1 1 
1 0 1 0 4 

Posição do animal: 
Passos: 3
3 3 3 2 4 
3 3 3 3 2 
3 3 3 2 4 
0 2 0 1 1 
1 0 X 0 4 


Interação 4:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 3 0 2 1 
1 0 1 0 4 

Posição do animal: 
Passos: 4
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 3 0 2 1 
1 0 1 X 4 


Interação 5:
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 3 0 3 1 
1 0 1 1 0 

Posição do animal: 
Passos: 5
3 3 3 3 4 
3 3 3 3 3 
3 3 3 3 4 
0 3 0 3 1 
1 0 1 1 X 


A simulação parou na iteração: 5


Informações do animal: 
Número de passos: 5
Achou água 2 vezes.
```

## Conclusão

### Sobre o projeto

O trabalho trouxe uma oportunidade para revisitar conceitos básicos da programação em C/C++, como leitura e escrita de arquivos, manipulação de elementos em matrizes, lógica de programação, entre outros. Além disso, propôs uma reflexão sobre o desempenho e eficiência do código após os resultados de execução.

### Relação entre o tamanho do incêndio e quantidade de iterações

A partir das seguintes informações:

- Tamanho da floresta

- Presença de vento

- Proximidade das árvoes

- Quantidade de áreas seguras e áres com água (não permitem que o incêndio se espalhe através delas)

É possível estimar a quantidade de iterações necessárias para a conclusão da simulação.

Por exemplo, caso existam árvores saudáveis em todas as casas da floresta, todas elas serão afetadas pelo incêndio. Entretanto, a presença de vento nessa simulação poderia diminuir a velocidade da propagação do fogo.

### Ideia de melhoria na performance

Nesse projeto, para saber quais árvores vão pegar fogo na iteração atual, o programa percorre toda a matriz que representa o estado atual da floresta, marcando em uma outra matriz as posições que começarão a queimar. Uma ideia para melhorar o desempenho seria utilizar uma fila que armazenasse as coordenadas das árvores em chamas. Dessa maneira, não seria necessário utilizar FOR loops em cadeia para encontrar as posições.

## Compilação

A compilação pode ser feita usando o comando (é necessário possuir um compilador de C/C++ e também o make instalados):

```bash
# Dentro da raiz do projeto

make clean
make
make run
```

## Autores

Arthur Batista Lage e Silva

<a href="https://github.com/arthur-lage">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
</a>


<a href="https://www.linkedin.com/in/arthur-lage/">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white">
</a>
