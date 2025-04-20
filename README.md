# Trabalho 1 AEDS - Simulação de Incêndio

![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

Aluno: Arthur Batista Lage e Silva

Professor: Michel Pires da Silva

Disciplina: Algoritmos e Estruturas de Dados I

## Introdução

Esse trabalho de aquecimento tem o objetivo de simular a propagação de um incêndio em uma floresta e também a movimentação de um animal que está dentro dela, além de promover a reflexão.

Funcionamento geral do programa:
    
    - Possui um arquivo de configurações chamado "config.cpp", localizado na pasta "src", em que podem ser definidas propriedades que afetam a simulação, como o número máximo de iterações e a direção do vento que empurra o fogo.

    - Lê informações da floresta e incêndio de um arquivo de entrada chamado de "input.dat", que está localizado na raiz do projeto.
    
    - Cria uma matriz que representa a floresta.

    - Possui um loop no arquivo "main.cpp", que fará com que a simulação seja executada até uma quantidade máxima de iterações. Além disso, o loop será encerrado caso: o animal tenha sido encurralado pelo fogo, e não consiga escapar com sua segunda chance; ou caso todas as árvores tenham sido queimadas

    - O incêndio só se espalha após a movimentação do animal.

    - O resultado final da simulação fica no arquivo "output.dat", que é gerado após o fim da execução do programa.

## Estrutura do projeto

- Os arquivos de código (.cpp) estão localizados na pasta "src".

- Os arquvios de cabeçalho (.hpp) estão localizados na pasta "include".

- Os binários do projeto são gerados na pasta "build" após a compilação do programa.

## Movimentação do animal

O animal se move a cada iteração da simulação, escolhendo a melhor posição que ele encontrar:

(a) Melhor opção: posição com valor 4 (presença de água)
(b) Opções intermediárias: posição com valor 0 (área vazia) e posição com valor 1 (ár-
vore saudável).
(c) Pior opção: posição com valor 3 (árvore queimada)

Ao alcançar uma posição com valor 4, essa posição se torna uma área vazia, e as posições ortogonalmente adjascentes se tornam 1 (árvores saudáveis).

### Segunda chance

Caso o animal seja atingido pelo fogo, ele receberá uma segunda chance de movimento, retornando à sua ultima posição e podendo se mover por um caminho diferente a fim de escapar da árvore em chamas.

## Compilação

A compilação pode ser feita usando o comando (é necessário possuir um compilador de C/C++ e também o make instalados):

```bash
# Dentro da raiz do projeto

make clean
make
make run
```

## Propagação do fogo

A propagação do fogo pode acontecer de duas maneiras: com vento em todas as direções ou somente em direções específicas. Isso precisa ser definido pelo usuário no arquivo "config.cpp".

### Sem vento em direções específicos

Na propagação em todas as direções, o fogo começa se espalhando para cima, para baixo, para esquerda e para a direta, assim como ilustrado na imagem abaixo.

![image](assets/semventoespecifico.png)

### Com vento em uma direção específica

Na propagação com vento em direção específica, o fogo se espalha somente naquela direção inicialmente.

![image](assets/comventoespecifico.png)

## Relação entre o tamanho do incêndio e quantidade de iterações

A partir das seguintes informações:

- Tamanho da floresta

- Presença de vento

- Proximidade das árvoes

- Quantidade de áreas seguras e áres com água (não permitem que o incêndio se espalhe através delas)

É possível estimar a quantidade de iterações necessárias para a conclusão da simulação.

## Ideia de melhoria na performance

Nesse projeto, para saber quais árvores vão pegar fogo na iteração atual, o programa percorre toda a matriz que representa o estado atual da floresta, marcando em uma outra matriz as posições que começarão a queimar. Uma ideia para melhorar o desempenho seria utilizar uma fila que armazenasse as coordenadas das árvores em chamas. Dessa maneira, não seria necessário utilizar FOR loops em cadeia para encontrar as posições.
