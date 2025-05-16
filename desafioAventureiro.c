#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com 0 (agua)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se é possível posicionar o navio
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcaoLinha;
        int c = coluna + i * direcaoColuna;

        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO)
            return 0;
        if (tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * direcaoLinha][coluna + i * direcaoColuna] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Navio horizontal (linha 0, coluna 0)
    if (podePosicionar(tabuleiro, 0, 0, 0, 1)) {
        posicionarNavio(tabuleiro, 0, 0, 0, 1);
    }

    // Navio vertical (linha 5, coluna 5)
    if (podePosicionar(tabuleiro, 5, 5, 1, 0)) {
        posicionarNavio(tabuleiro, 5, 5, 1, 0);
    }

    // Navio diagonal principal (linha 2, coluna 2)
    if (podePosicionar(tabuleiro, 2, 2, 1, 1)) {
        posicionarNavio(tabuleiro, 2, 2, 1, 1);
    }

    // Navio diagonal secundária (linha 0, coluna 9)
    if (podePosicionar(tabuleiro, 0, 9, 1, -1)) {
        posicionarNavio(tabuleiro, 0, 9, 1, -1);
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
