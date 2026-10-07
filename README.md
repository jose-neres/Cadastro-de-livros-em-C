# 📚 Sistema de Cadastro e Empréstimo de Livros em C

Sistema desenvolvido em **linguagem C** para gerenciamento de uma pequena biblioteca através do terminal.

O projeto permite cadastrar livros, consultar os livros disponíveis e controlar empréstimos, utilizando conceitos fundamentais de programação estruturada, estruturas de dados e gerenciamento de memória.

---

## 📌 Sobre o Projeto

O **Cadastro de Livros em C** foi desenvolvido como um projeto prático para aplicar conceitos da linguagem C na construção de um sistema de gerenciamento de biblioteca.

A aplicação funciona através de um menu interativo no terminal, permitindo ao usuário realizar operações relacionadas ao cadastro e empréstimo de livros.

O projeto também utiliza **alocação dinâmica de memória**, estruturas (`struct`) e funções para organizar as diferentes responsabilidades do sistema.

---

## 🚀 Funcionalidades

* 📖 Cadastro de livros
* 📚 Listagem dos livros cadastrados
* 🔄 Controle da disponibilidade dos livros
* 🤝 Registro de empréstimos
* 👤 Associação do empréstimo ao usuário
* 📋 Listagem dos empréstimos realizados
* ⚠️ Validação de livros disponíveis e opções inválidas
* 🧹 Liberação da memória utilizada pelo programa

---

## 🛠️ Tecnologias e Conceitos

### Linguagem

* **C**

### Conceitos aplicados

* Estruturas (`struct`)
* Ponteiros
* Funções
* Vetores
* Strings
* Estruturas de controle
* Entrada e saída de dados
* Alocação dinâmica de memória
* `calloc()` e `free()`
* Manipulação de strings
* Organização modular do código

---

## 🧩 Estruturas de Dados

O sistema utiliza duas estruturas principais.

### `struct Livro`

Responsável por armazenar as informações dos livros:

* Título
* Autor
* Editora
* Edição
* Disponibilidade

### `struct Emprestimo`

Responsável por armazenar:

* Índice do livro emprestado
* Nome do usuário responsável pelo empréstimo

Essa organização permite relacionar os empréstimos aos livros cadastrados no sistema.

---

## 📋 Menu do Sistema

Ao executar o programa, o usuário encontra as seguintes opções:

```text
--- Menu da Biblioteca ---

1. Cadastrar Livro
2. Listar Livros
3. Realizar Empréstimo
4. Listar Empréstimos
5. Sair
```

### 1. Cadastrar Livro

Permite inserir as informações de um novo livro, incluindo título, autor, editora e edição.

### 2. Listar Livros

Exibe os livros cadastrados e informa se cada livro está disponível para empréstimo.

### 3. Realizar Empréstimo

Apresenta os livros disponíveis e permite associar um empréstimo a determinado usuário.

Após o empréstimo, o livro passa a ser marcado como **indisponível**.

### 4. Listar Empréstimos

Exibe os empréstimos realizados, mostrando o livro emprestado e o usuário responsável.

---

## 💾 Gerenciamento de Memória

Um dos principais objetivos técnicos do projeto foi praticar o **gerenciamento de memória em C**.

O programa utiliza `calloc()` para realizar a alocação dinâmica dos espaços destinados aos livros e empréstimos.

Ao finalizar a execução, a função `liberarMemoria()` utiliza `free()` para liberar os recursos alocados.

```c
struct Livro *biblioteca =
    (struct Livro*) calloc(MAX_LIVROS, sizeof(struct Livro));

struct Emprestimo *emprestimos =
    (struct Emprestimo*) calloc(MAX_EMPRESTIMOS, sizeof(struct Emprestimo));
```

Essa abordagem permite praticar conceitos importantes relacionados ao uso de memória dinâmica na linguagem C.

---

## 📊 Limites do Sistema

Atualmente, o sistema trabalha com:

| Recurso                            |        Limite |
| ---------------------------------- | ------------: |
| Livros cadastrados                 |            50 |
| Empréstimos                        |           100 |
| Tamanho máximo dos campos de texto | 99 caracteres |

Os limites são definidos através de constantes no código:

```c
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100
```

---

## ▶️ Como Executar

### 1. Clone o repositório

```bash
git clone https://github.com/jose-neres/Cadastro-de-livros-em-C.git
```

### 2. Acesse a pasta

```bash
cd Cadastro-de-livros-em-C
```

### 3. Compile o programa

Utilizando o GCC:

```bash
gcc CadastroDeLivro.c -o cadastro
```

### 4. Execute

No Linux/macOS:

```bash
./cadastro
```

No Windows:

```bash
cadastro.exe
```

---

## 🎯 Objetivos de Aprendizado

Este projeto foi desenvolvido com o objetivo de fortalecer conhecimentos em programação, especialmente nos seguintes pontos:

* Desenvolvimento em linguagem C
* Lógica de programação
* Estruturas de dados
* Manipulação de ponteiros
* Alocação dinâmica de memória
* Organização do código através de funções
* Manipulação de strings
* Desenvolvimento de aplicações executadas via terminal

---

## 📂 Estrutura do Projeto

```text
Cadastro-de-livros-em-C/
│
├── CadastroDeLivro.c
└── README.md
```

---

## 🔮 Possíveis Melhorias

Como evolução futura do projeto, algumas funcionalidades poderiam ser implementadas:

* [ ] Persistência dos dados em arquivos
* [ ] Busca de livros por título ou autor
* [ ] Devolução de livros
* [ ] Edição de livros cadastrados
* [ ] Exclusão de livros
* [ ] Histórico de empréstimos
* [ ] Validações mais robustas das entradas
* [ ] Separação do projeto em múltiplos arquivos `.c` e `.h`

---

## 👨‍💻 Desenvolvedor

**José Neres**

Projeto desenvolvido como parte da minha evolução prática em programação e desenvolvimento de software.

🔗 **GitHub:**
https://github.com/jose-neres

---

⭐ Se este projeto foi útil ou interessante, considere deixar uma estrela no repositório.
