#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];  // Matriz 10x10 representando o tabuleiro

    // Inicializa o tabuleiro com água (valor 0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIO 1: horizontal, linha 2, coluna inicial 4
    int linha1 = 2;
    int coluna1 = 4;

    // Verifica se o navio 1 cabe no tabuleiro (horizontalmente)
    if (coluna1 + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    }

    // NAVIO 2: vertical, linha inicial 5, coluna 7
    int linha2 = 5;
    int coluna2 = 7;

    // Verifica se o navio 2 cabe no tabuleiro (verticalmente)
    if (linha2 + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já tem navio na posição (para não sobrepor)
            if (tabuleiro[linha2 + i][coluna2] == 0) {
                tabuleiro[linha2 + i][coluna2] = 3;
            } else {
                printf("Erro: Sobreposição de navios detectada.\n");
                return 1;
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
