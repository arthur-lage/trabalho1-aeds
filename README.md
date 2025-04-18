# Trabalho 1 AEDS

Aluno: Arthur Batista Lage e Silva

Professor: Michel Pires da Silva

Disciplina: Algoritmos e Estruturas de Dados I

## Introdução

Esse trabalho de aquecimento tem o objetivo de simular  a propagação de um incêndio em uma floresta e também a movimentação de um animal que está dentro dela, além de promover a reflexão.

Funcionamento geral do programa:
    
    - Possui um arquivo de configurações chamado "config.cpp", localizado na pasta "src", em que podem ser definidas propriedades que afetam a simulação, como o número máximo de iterações e a direção do vento que empurra o fogo.

    - Lê informações da floresta e incêndio de um arquivo de entrada chamado de "input.dat", que está localizado na raiz do projeto.
    
    - Cria uma matriz que representa a floresta.

    - Possui um loop no arquivo "main.cpp", que fará com que a simulação seja executada até uma quantidade máxima de iterações. Além disso, o loop será encerrado caso: o animal tenha sido encurralado pelo fogo, e não consiga escapar com sua segunda chance; ou caso todas as árvores tenham sido queimadas

    - O incêndio só se espalha após a movimentação do animal.

## Compilação

A compilação pode ser feita usando o comando (é necessário possuir um compilador de C/C++ e também o make instalados):

```bash
# Dentro da raiz do projeto

make clean
make
make run
```

Inclusão, na documentação (README.md), de uma análise sobre padrões de propa-
gação do fogo. Para isso, apresentar exemplos visuais que ilustrem esses padrões, uti-
lizando imagens. Elabore como parte dessa discussão o comportamento de ambas as
simulações, sem a consideração do vento e com sua influência.

•Discussão sobre a capacidade da solução de simulação em prever o tamanho de um
incêndio, considerando que cada interação pode ser interpretada como uma unidade de
tempo.

•Discussão sobre possíveis algoritmos emergentes que poderiam contribuir com esse
cenário, apresentando suas principais características e motivos que o levam a uma pos-
sível melhoria de desempenho.