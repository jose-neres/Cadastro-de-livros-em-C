
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes globais ---
#define MAX_LIVROS 50  
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

// --- Estruturas ---
struct Livro {
    char titulo[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int disponivel;
    int edicao;
};

struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

// --- Protótipos das Funções ---
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(struct Livro *biblioteca, int totalLivros);
void realiazarEmprestimo(struct Livro *biblioteca, struct Emprestimo *emprestimos, int *totalEmprestimos, int totalLivros);
void listarEmprestimos(struct Emprestimo *emprestimos, int totalEmprestimos, struct Livro *biblioteca);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// --- Função Principal ---

int main() 
{
    struct Livro *biblioteca = (struct Livro*) calloc (MAX_LIVROS, sizeof(struct Livro));
    struct Emprestimo *emprestimos = (struct Emprestimo*) calloc (MAX_EMPRESTIMOS, sizeof(struct Emprestimo));
    
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do
    {
       exibirMenu();
       scanf("%d", &opcao);
         limparBufferEntrada();
         switch (opcao) {
            case 1:
                cadastrarLivro(biblioteca, &totalLivros);
                break;
            case 2:
                listarLivros(biblioteca, totalLivros);
                break;
            case 3:
                realiazarEmprestimo(biblioteca, emprestimos, &totalEmprestimos, totalLivros);
                break;
            case 4:
                listarEmprestimos(emprestimos, totalEmprestimos, biblioteca);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
            }
        } while (opcao != 5);

    // chama a função dedicada para liberar a memoria alocada

    liberarMemoria(biblioteca, emprestimos);

    return 0;
}

void limparBufferEntrada()
{
    int c;
    while ((c= getchar()) != '\n' && c != EOF); 
}

void exibirMenu() {
    printf("\n--- Menu da Biblioteca ---\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Listar Livros\n");
    printf("3. Realizar Empréstimo\n");
    printf("4. Listar Empréstimos\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

void cadastrarLivro(struct Livro *biblioteca, int *totalLivros) {
    if (*totalLivros < MAX_LIVROS) {
        int indice = *totalLivros; // Usar o valor atual como índice

        printf("Digite o nome do livro:\n");
        fgets(biblioteca[indice].titulo, TAM_STRING, stdin);
        printf("Digite o autor do livro:\n");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);
        printf("Digite a editora do livro:\n");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);

        biblioteca[indice].titulo[strcspn(biblioteca[indice].titulo, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';

        printf("Digite a edição do livro:\n");
        scanf("%d", &biblioteca[indice].edicao);
        limparBufferEntrada();

        biblioteca[indice].disponivel = 1; // Livro disponível
        (*totalLivros)++; // Incrementa o total de livros
        printf("Livro cadastrado com sucesso!\n");
    } else {
        printf("Capacidade máxima de livros atingida.\n");
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void listarLivros(struct Livro *biblioteca, int totalLivros) {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
    } else {
        for (int i = 0; i < totalLivros; i++) {
            printf("Livro %d:\n", i + 1);
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao);
            printf("Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
            printf("-------------------------------\n");
        }
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void realiazarEmprestimo(struct Livro *biblioteca, struct Emprestimo *emprestimos, int *totalEmprestimos, int totalLivros) {
    printf("--- Realizar Empréstimo ---\n");
    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Capacidade máxima de empréstimos atingida.\n");
        return;
    } else {
    printf("Lista de Livros Disponíveis:\n");
        int disponiveis = 0;
    for (int i = 0; i < totalLivros; i++) {
       if (biblioteca[i].disponivel) {
            printf("%d. %s\n", i + 1, biblioteca[i].titulo);
            disponiveis++;
            }
   
    }
    if (disponiveis == 0) {
        printf("Nenhum livro disponível para empréstimo.\n");
        
    
    } else {
        printf("\nDigite o número do livro que deseja emprestar:\n");
        int numeroLivro;
        scanf("%d", &numeroLivro);
        limparBufferEntrada();

        int indice= numeroLivro - 1;

        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
            printf("Digite o nome do usuário:\n");
            fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
            emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';
            emprestimos[*totalEmprestimos].indiceLivro = indice;

            biblioteca[indice].disponivel = 0; // Marca o livro como não disponível
            (*totalEmprestimos)++;
            printf("Empréstimo realizado com sucesso!\n");
        } else {
            printf("Número de livro inválido ou livro não disponível.\n");
    }
    }
}
    printf("Pressione enter para continuar...");
    getchar();
}

void listarEmprestimos(struct Emprestimo *emprestimos, int totalEmprestimos, struct Livro *biblioteca) {
    printf("--- Lista de Empréstimos ---\n");
    if (totalEmprestimos == 0) {
        printf("Nenhum empréstimo realizado.\n");
    } else {
        for (int i = 0; i < totalEmprestimos; i++) {
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("Empréstimo %d:\n", i + 1);
            printf("Livro: %s\n", biblioteca[indiceLivro].titulo);
            printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
            printf("-------------------------------\n");
        }
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos) {
    free(biblioteca);
    free(emprestimos);
    printf("Memória liberada com sucesso.\n");
}

