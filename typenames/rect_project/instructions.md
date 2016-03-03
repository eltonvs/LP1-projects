# Apresentação

Estas intruções descrevem os passos que você deve seguir antes de iniciar
o exercício.

Em linhas gerais você primeiramente vai gerar uma biblioteca compilada a partir
da classe `MyRectangle::Rect` desenvolvida por outro programador.

Em seguida você vai compilar a aplicação alvo do exercício, a qual depende
da biblioteca gerada no passo anterior.

O objetivo aqui é simular que a aplicação final foi desenvolvido por 2 programadores
diferentes, um que desenvolveu a classe `MyRectangle::Rect` e outro
programador do módulo principal que vai utilizar `MyRectangle::Rect` para resolver
um certo problema.

Neste cenário, a classe `MyRectangle::Rect` estará disponível para a aplicação apenas
na forma de um **arquivo de biblioteca** `libRect.a` e seu correspondente
**cabeçalho** `rect.h`.
Em outras palavras, vamos simular uma situação bastante comum: você **não tem acesso ao código fonte** de
`MyRectangle::Rect`, isto é, não é capaz de alterar o código fonte para
adaptá-lo às suas necessidades.

# Organização

A pasta `Projeto_retangulo` possui duas subpastas: `External` e `App`.

* A pasta `External`:  corresponde ao projeto de programação do programador
externo, ou seja, o programador que desenvolveu uma classe que simula
retângulos simples com suporte a algumas operações de manipulação.

* A pasta `App`: corresponde ao projeto de programação da aplicação
real, ou seja, o programa que vai criar retângulos e realizar algumas
operações básica como buscas.
O objetivo é testar o conceito de *data abstraction* através de funções
template e ponteiros para função.

`

    Projeto_retangulo
        |---- External
        |        |------ bin
        |        |------ docs
        |        |------ include
        |        |------ lib
        |        |------ src
        |---- App
                 |------ bin
                 |------ include
                 |------ lib
                 |------ src

# Intruções sobre o que fazer

Para iniciar o exercício você vai seguir 2 conjuntos de instruções,
apresentadas nas subseções a seguir.

Estas intruções assumem o uso de *terminal* onde serão inseridos os
comandos indicados.
Parte-se do princípio que você se encontra em uma pasta
**imediatamente acima** da pasta `Projeto_retangulo`.

## Para compilar a classe `MyRectangle::Rect` em uma biblioteca

1.  Gere primeiramente o código objeto da classe `MyRectangle::Rect`: 

    `$ cd Projeto_retangulo/External`

    `$ g++ -Wall -std=c++11 -c -I include/ src/rect.cpp -o bin/rect.o`

    Este comando gera um arquivo `rect.o` na pasta `bin`.

2. Agora gere a biblioteca estática a partir do codigo objeto.

    `$ ar rvs lib/libRect.a bin/rect.o`

    se não der certo utilize o comando abaixo

    `$ ar cr lib/libRect.a bin/rect.o`

    Este comando gera o arquivo `libRect.a`, que será distribuído para o
    "cliente" juntamente com o cabeçalho `rect.h`.

## Para gerar a aplicação principal

1. Primeiramente copie a biblioteca recém criada `libRect.a` para a pasta `lib` da aplicação.

    `$ cd ../App`

    `$ cp ../External/lib/libRect.a lib/`

2. Copie agora o cabeçalho que descreve a classe `MyRectangle::Rect`.

    `$ cp ../External/include/rect.h include/`

3. Compilando o programa principal.

    `$ g++ -Wall -std=c++11 src/buscaRect.cpp -I include -L lib -l Rect -o bin/buscaRect`

    Este comando compila e liga o código objeto da aplicação com a biblioteca
    desenvolvida por outro programador.
    
    O argumento `-I` indica em qual caminho procurar por cabeçalhos (além do `PATH`).
    O argumento `-L` indica em qual caminho procurar por bibliotecas (alen do `PATH`).
    O argumento `-l <biblioteca>` indica qual biblioteca deve ser *ligada* ao programa.

# Considerações finais

Agora você já pode alterar o programa `buscaRect.cpp` de maneira a realizar o que
foi pedido no exercício.
