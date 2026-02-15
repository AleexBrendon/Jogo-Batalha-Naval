#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    bool podePosicionarH = true;

    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        podePosicionarH = false;
    }

    if (podePosicionarH) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podePosicionarH = false;
            }
        }
    }

    if (podePosicionarH) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }

    bool podePosicionarV = true;

    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        podePosicionarV = false;
    }

    if (podePosicionarV) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podePosicionarV = false;
            }
        }
    }

    if (podePosicionarV) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    } else {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }

    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");

    return 0;
}
