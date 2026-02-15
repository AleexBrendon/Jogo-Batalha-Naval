#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    printf("\n======= TABULEIRO BATALHA NAVAL =======\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Agua | 3 = Navio\n");
}

bool dentroLimite(int linha, int coluna)
{
    return (linha >= 0 && linha < TAM_TABULEIRO &&
            coluna >= 0 && coluna < TAM_TABULEIRO);
}

bool verificaSobreposicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                          int linha, int coluna)
{
    return tabuleiro[linha][coluna] != 0;
}

bool posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                     int linhaInicial,
                     int colunaInicial,
                     char tipo)
{

    int linha, coluna;

    for (int i = 0; i < TAM_NAVIO; i++)
    {

        linha = linhaInicial;
        coluna = colunaInicial;

        if (tipo == 'H')
            coluna += i;
        else if (tipo == 'V')
            linha += i;
        else if (tipo == 'D')
        {
            linha += i;
            coluna += i;
        }
        else if (tipo == 'A')
        {
            linha += i;
            coluna -= i;
        }

        if (!dentroLimite(linha, coluna))
            return false;

        if (verificaSobreposicao(tabuleiro, linha, coluna))
            return false;
    }

    for (int i = 0; i < TAM_NAVIO; i++)
    {

        linha = linhaInicial;
        coluna = colunaInicial;

        if (tipo == 'H')
            coluna += i;
        else if (tipo == 'V')
            linha += i;
        else if (tipo == 'D')
        {
            linha += i;
            coluna += i;
        }
        else if (tipo == 'A')
        {
            linha += i;
            coluna -= i;
        }

        tabuleiro[linha][coluna] = 3;
    }

    return true;
}

int main()
{

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    inicializarTabuleiro(tabuleiro);
    if (!posicionarNavio(tabuleiro, 1, 1, 'H'))
    {
        printf("Erro ao posicionar navio horizontal.\n");
        return 1;
    }

    if (!posicionarNavio(tabuleiro, 4, 6, 'V'))
    {
        printf("Erro ao posicionar navio vertical.\n");
        return 1;
    }

    if (!posicionarNavio(tabuleiro, 0, 7, 'D'))
    {
        printf("Erro ao posicionar navio diagonal principal.\n");
        return 1;
    }

    if (!posicionarNavio(tabuleiro, 7, 9, 'A'))
    {
        printf("Erro ao posicionar navio diagonal secundaria.\n");
        return 1;
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
