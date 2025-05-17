#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define TAMANHO_HABILIDADE 5  // Tamanho fixo das áreas de habilidade (5x5)
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = AGUA;
}

// Posiciona navios fixos para exemplo
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Horizontal (linha 1, coluna 1 a 3)
    for (int j = 1; j <= 3; j++)
        tabuleiro[1][j] = NAVIO;

    // Vertical (linha 4 a 6, coluna 6)
    for (int i = 4; i <= 6; i++)
        tabuleiro[i][6] = NAVIO;
}

// Aplica matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origem_linha - offset + i;
            int coluna = origem_coluna - offset + j;

            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (matriz[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Constrói matriz de habilidade tipo CONE
void construirCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE/2 - i && j <= TAMANHO_HABILIDADE/2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Constrói matriz de habilidade tipo CRUZ
void construirCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE/2 || j == TAMANHO_HABILIDADE/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Constrói matriz de habilidade tipo OCTAEDRO (losango)
void construirOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE/2) + abs(j - TAMANHO_HABILIDADE/2) <= TAMANHO_HABILIDADE/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Mostra o tabuleiro com símbolos
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n--- TABULEIRO ---\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf(". ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone com centro em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 6);       // Cruz com centro em (6,6)
    aplicarHabilidade(tabuleiro, octaedro, 4, 4);   // Octaedro com centro em (4,4)

    exibirTabuleiro(tabuleiro);

    return 0;
}