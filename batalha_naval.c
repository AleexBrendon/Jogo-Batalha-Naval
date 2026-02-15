#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n======= TABULEIRO =======\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0=Agua | 3=Navio | 5=Habilidade\n");
}

void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int centro = TAM_HAB / 2;
            if (i >= centro && abs(j - centro) <= (i - centro)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
    int habilidade[TAM_HAB][TAM_HAB],
    int origemLinha,
    int origemColuna
) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {

                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;

    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;
    tabuleiro[8][6] = NAVIO;

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 1, 7);
    aplicarHabilidade(tabuleiro, cruz, 5, 2);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    exibirTabuleiro(tabuleiro);

    return 0;
}
