#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura que guarda informações do jogador
typedef struct {
    char nome[50];       // Nome do jogador
    int tentativas;      // Tentativas na rodada atual
    int melhorPontuacao; // Melhor pontuação registrada
} Jogador;

// Inicializa o jogador com nome e pontuações zeradas
void iniciarJogador(Jogador *j, char nome[]) {
    strcpy(j->nome, nome);
    j->tentativas = 0;
    j->melhorPontuacao = 0;
}

// Função que executa uma rodada do jogo
int jogarRodada(Jogador *j) {
    int numeroSecreto, chute;
    j->tentativas = 0;

    srand(time(NULL));                 // Inicializa gerador de números aleatórios
    numeroSecreto = rand() % 100 + 1; // Gera número aleatório de 1 a 100

    printf("\nAdivinhe um número entre 1 e 100!\n");

    do {
        printf("Digite seu chute: ");
        scanf("%d", &chute);
        j->tentativas++;

        if (chute > numeroSecreto)
            printf("Menor!\n");
        else if (chute < numeroSecreto)
            printf("Maior!\n");
        else
            printf("Parabéns, %s! Você acertou em %d tentativas.\n", j->nome, j->tentativas);

    } while (chute != numeroSecreto);

    if (j->melhorPontuacao == 0 || j->tentativas < j->melhorPontuacao)
        j->melhorPontuacao = j->tentativas;

    return j->tentativas;
}

// Mostra a melhor pontuação do jogador
void mostrarPontuacao(Jogador *j) {
    printf("%s | Melhor pontuação: %d tentativas\n", j->nome, j->melhorPontuacao);
}

// Função principal
int main() {
    Jogador jogador;
    char nome[50];
    int opcao;

    printf("Digite seu nome: ");
    scanf("%s", nome);
    iniciarJogador(&jogador, nome);

    do {
        printf("\n=== Menu ===\n");
        printf("1. Jogar\n2. Ver pontuação\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: jogarRodada(&jogador); break;
            case 2: mostrarPontuacao(&jogador); break;
            case 3: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while(opcao != 3);

    return 0;
}
