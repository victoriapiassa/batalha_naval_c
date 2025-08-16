#include <stdio.h>

#define TAMANHO 10   // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3      // Valor que representa uma parte do navio
#define TAMANHO_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Matriz que representa o tabuleiro
    int i, j;

    // Inicializando todas as posições com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ------------------- Definição dos navios -------------------
    // Coordenadas iniciais do navio horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Coordenadas iniciais do navio vertical
    int linha_vertical = 5;
    int coluna_vertical = 7;

    // ------------------- Validação simples -------------------
    // Garantir que o navio horizontal caiba no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO) {
        for (j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[linha_horizontal][coluna_horizontal + j] = NAVIO;
        }
    } else {
        printf("Erro: navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // Garantir que o navio vertical caiba no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se não está sobrepondo outro navio
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            } else {
                printf("Erro: sobreposição de navios detectada!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ------------------- Exibição do tabuleiro -------------------
    printf("Tabuleiro Batalha Naval (0 = Agua, 3 = Navio):\n\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//finalizado