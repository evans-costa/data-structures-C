<h1 align="center">
  <br>
   Estrutura Abstrata de Dados em C
  <br>
</h1>
<h4 align="center">Um repositório que implementa as estrututas abstratas de dados básicas escritas em linguagem C</h4>

<p align="center">
  <a href="#descrição">Descrição</a> •
  <a href="#motivações">Motivações</a> •
  <a href="#estrutura-de-arquivos">Estrutura de Arquivos</a> •
  <a href="#entendendo-o-arquivo-makefile">Entendendo o arquivo Makefile</a> •
  <a href="#como-usar">Como Usar</a> •
  <a href="#licença">Licença</a>
</p>

## Descrição

Este projeto consiste em uma biblioteca de estruturas de dados em C, acompanhada por aplicativos de teste para cada estrutura. As estruturas de dados suportadas incluem vetores (arrays), listas encadeadas (linked lists), listas duplamente encadeadas (double linked lists), listas circulares (circular linked lists), pilhas (stacks), filas (queues), tabelas de hash (hash tables) e tabelas de hash com encadeamento separado.

## Motivações

Em meus estudos, vi a necessidade de aprender melhor a base da programação, em especial, estruturas de dados abstratas (abstract data structures). Para isso, acompanhado de vídeos (em especial [essa playlist aqui do Prof. Samuka](https://www.youtube.com/playlist?list=PL3ZslI15yo2r-gHJtjORRMRKMSNRpf7u5)), decidi transfomar esse projeto em um repositório, para ajudar quem precisar e também servir de consulta rápida para estudo.

O uso da linguagem C também me propiciou aprender como linguagens de mais baixo nível se comportam em comparação com outras como JavaScript, Python. Em especial, aprendi como funciona manejar ponteiros, alocação e desalocação de memória com `calloc` e `malloc`.

## Estrutura de Arquivos

O projeto está organizado conforme a seguinte estrutura:

```
📦root/
├── 📂apps/
│   ├── 📜test_cicular_list.c
│   ├── 📜test_double_linked_list.c
│   ├── 📜test_linked_list.c
│   ├── 📜test_linked_list_exercise.c
│   ├── 📜test_hash_table_sc.c
│   ├── 📜test_hash_table.c
│   ├── 📜test_queue.c
│   └── 📜test_stacks.c
├── 📂bin
├── 📂include/
│   ├── 📜circular_list.h
│   ├── 📜double_linked_list.h
│   ├── 📜float_vector.h
│   ├── 📜hash_table_sc.h
│   ├── 📜hash_table.h
│   ├── 📜linked_list_exercise.h
│   ├── 📜linked_list.h
│   ├── 📜stacks.h
│   └── 📜queue.h
├── 📂lib
├── 📂obj
├── 📂src/
│   ├── 📜cicular_list.c
│   ├── 📜double_linked_list.c
│   ├── 📜linked_list.c
│   ├── 📜linked_list_exercise.c
│   ├── 📜hash_table_sc.c
│   ├── 📜hash_table.c
│   ├── 📜queue.c
│   └── 📜stacks.c
└── ⚙️Makefile
```

- `src`: Contém os arquivos de código-fonte (.c) para as estruturas de dados.
- `include:` Contém os arquivos de cabeçalho (.h) para as estruturas de dados.
- `bin:` Os arquivos executáveis dos aplicativos de teste serão gerados aqui.
- `apps:` Arquivos de código-fonte (.c) para os aplicativos de teste.
- `obj:` Arquivos de objeto (.o) gerados durante a compilação.
- `lib:` O arquivo de biblioteca (libds.a) será gerado aqui.

> **📌 Nota:** </br>
> Se você quiser saber mais sobre como o processo de compilação ocorre [recomendo esse link](https://www.alura.com.br/artigos/o-que-e-compilacao) (ou um ChatGPT também funciona 😏)

## Entendendo o arquivo Makefile

O arquivo `Makefile` contém um conjunto de diretivas que são usadas pelo comando `make` para automatizar a compilação dos arquivos. Ele irá chamar o compilador para criar os arquivos executáveis.

Algumas variáveis que estão nesse arquivo:

- `SRC`: Diretório para os arquivos de código-fonte.
- `INCLUDE`: Diretório para os arquivos de cabeçalho.
- `BIN`: Diretório para os arquivos executáveis.
- `APPS`: Diretório para os arquivos de código-fonte dos aplicativos.
- `OBJ`: Diretório para os arquivos de objeto.
- `LIB`: Diretório para o arquivo de biblioteca.
- `CC`: Comando do compilador (gcc).
- `FLAGS`: Sinalizadores de compilação, incluindo avisos, erros e informações de depuração.
- `LIBS`: Bibliotecas a serem vinculadas (matemática e a biblioteca personalizada 'libds' com o caminho especificado).

Os targets:

- `all`: Constrói a biblioteca e os aplicativos de teste.
- `libds`: Compila os arquivos de origem da estrutura de dados em arquivos de objeto e cria a biblioteca (libds.a).
- `myapps`: Compila os aplicativos de teste e os vincula à biblioteca.
- `re`: Limpa o projeto e reconstrói tudo.
- `clean`: Remove todos os arquivos e diretórios gerados.

> **📌 Nota:** </br>
> Algumas flags utilizadas no Makefile são:
>
> - A flag `-I` é usada para especificar o diretório de inclusão durante a compilação.
> - A flag `-lm` vincula a biblioteca de matemática, e `-lds` vincula a biblioteca personalizada de estruturas de dados.
> - O alvo `PHONY` garante que os alvos `clean` e `all` sejam sempre executados, mesmo que existam arquivos com os mesmos nomes.

O arquivo Makefile tem uma extensa documentação, que você pode encontrar na [documentaçao oficial do GNU](https://www.gnu.org/software/make/manual/make.html#Makefile-Contents).

## Como Usar

Para clonar e rodar essa aplicação, você precisará do [Git](https://git-scm.com) e do compilador [GCC](https://gcc.gnu.org/). Na maioria das distribuições Linux e em Mac, o GCC já vem instalado. Se não tiver instalado, você pode instalá-lo utilizando o gerenciador de pacotes do seu sistema operacional. Da sua linha de comando:

```bash
# Clone este repositório
$ git clone https://github.com/evans-costa/data-structures-C.git

# Vá para o diretório do repositório
$ cd data-structures-C
```

Se você desejar, poderá modificar as entradas de dados da estrutura desejada nos arquivos na pasta `apps`.

Depois, use os comandos para compilar e executar os arquivos gerados:

```bash
# Compile o projeto
$ make

# Executar o arquivo
$ ./bin/test_nome-da-estrutura-de-dados
```

Substitua `"nome-da-estrutura-de-dados"` pelo nome da estrutura que você deseja testar, por exemplo: `test_linked_list`.

Depois de rodar a estrutura desejada, você pode limpar os arquivos gerados durante a compilação usando:

```bash
# Limpe os arquivos
$ make clean
```

## Licença

The MIT License (MIT) 2023 - Evandro Costa. Por favor, dê uma olhada na LICENSE para mais detalhes.

---

> GitHub [@evans-costa](https://github.com/evans-costa) &nbsp;&middot;&nbsp;
> LinkedIn [@evandro-souzac](https://www.linkedin.com/in/evandro-souzac/)
