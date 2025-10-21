# Jogo de Adivinhação em C

Este é um projeto simples de um **jogo de adivinhação** desenvolvido em C.  
O jogador precisa adivinhar um número aleatório entre 1 e 100 e o jogo registra a **melhor pontuação**.

## Funcionalidades

- Recebe o nome do jogador.
- Gera um número aleatório entre 1 e 100.
- Dá dicas se o número secreto é maior ou menor que o chute.
- Registra a melhor pontuação (menos tentativas).
- Menu interativo com opções:
  1. Jogar
  2. Ver pontuação
  3. Sair

## Conceitos usados

- Estruturas (`struct`) para armazenar dados do jogador.
- Funções para organizar o código (`iniciarJogador`, `jogarRodada`, `mostrarPontuacao`).
- Loops (`do...while`) para repetir a rodada e o menu.
- Bibliotecas padrão (`stdio.h`, `stdlib.h`, `time.h`, `string.h`).
- Manipulação de strings com `strcpy`.
- Geração de números aleatórios com `rand()` e `srand(time(NULL))`.
