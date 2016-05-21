# Tabela de Dispersão
Nesse código, foi feita a implementação de uma Tabela de Dispersão genérica (utilizando a tag `template`) e desenvolvida uma aplicação simples que mantém um cadastro de contas corrente.

## Variações
Esse programa foi implementado em 3 versões diferentes. Sendo elas:

#### Versão 1
Uma chave composta por um inteiro correspondente ao número da conta corrente.
```cpp
using AcctKey = int;
```

#### Versão 2
Uma chave composta de dois campos definidos por um std::pair , que contém o nome
do cliente e o número da conta.
```cpp
using AcctKey = std::pair<std::string, int>;
```

#### Versão 3
Uma chave composta por meio de 4 campos definidos por uma std::tuple, que contém o nome do cliente, o código do banco, o número da agência e o número da conta.
```cpp
using AcctKey = std::tuple<std::string, int, int, int>;
```

## Como compilar
Para compilar, você só precisa digitar:
```shell
make clean
make V=[versão a ser executada] # make V=1
```

Caso nenhuma versão seja informada, o compilador utilizará a versão 3.

E para executar:
```shell
./bin/hash_table
```

## Autor
Elton de Souza Vieira
 - [GitHub](https://github.com/eltonvs)
 - [Webpage](http://www.eltonviana.com)
