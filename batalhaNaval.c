#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Definição de cores do texto do console
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

int main() {
    int erro = 0;
    const int TAB_V = 10, TAB_H = 10;   // Dimensões do tabuleiro
    int tabuleiro[10][10][2];

    // Inicializa tabuleiro
    for(int i = 0; i < TAB_H; i++) {
        for(int j = 0; j < TAB_V; j++)
        {
            tabuleiro[i][j][0] = 0;
            tabuleiro[i][j][1] = 37;
        }
    }

    // Declaração e inicialização dos vetores dos navios
    // Navio: {Tamanho, 0=Horizontal/1=Vertical/2=DiagonalCrescente/3=DiagonalDecrescente, Linha_Início[0..9], Coluna_Início[0..9]}
    int navios[4][4] = {
        {3, 0, 2, 4},
        {3, 1, 3, 2},
        {5, 3, 4, 4},
        {3, 2, 7, 2},
        
    };


    printf(GREEN"\n\n    .:: BATALHA NAVAL ::.\n\n"RESET);
    // Insere navios no tabuleiro
    for(int i = 0; i < sizeof(navios) / sizeof(navios[0]); i++) {    // Percorre o vetor de navios
        switch (navios[i][1])
        {
        case 0: // Seleciona navios na horizontal
            if ((navios[i][2] >= 0) &&
                (navios[i][3] >= 0) &&
                (navios[i][3] < TAB_V) &&
                (TAB_H - navios[i][3] - navios[i][0] >= 0)) { // Verifica se o navio cabe no tabuleiro
                for(int j = 0; j < navios[i][0]; j++) {
                    if(tabuleiro[navios[i][2]][navios[i][3] + j][0] == 3) {    // Verifica conicidências entre navios
                        printf(RED"Erro! O navio %d coincide com outro navio na casa %c%02d.\n"RESET, i + 1, navios[i][3] + j + 65, navios[i][2] + 1);
                        tabuleiro[navios[i][2]][navios[i][3] + j][1] = 31;
                    } else {
                        tabuleiro[navios[i][2]][navios[i][3] + j][0] = 3;
                        tabuleiro[navios[i][2]][navios[i][3] + j][1] = 34;
                        
                    }
                }
            }
            else {
                printf(RED"Erro! O navio %d ultrapassa os limites do tabuleiro.\n"RESET, i + 1);
                erro = 1;
            }
            break;
        
        case 1: // Seleciona navios na vertical
            if ((navios[i][2] >= 0) &&
                (navios[i][3] >= 0) &&
                (navios[i][2] < TAB_H) &&
                (TAB_V - navios[i][2] - navios[i][0] >= 0)) { // Verifica se o navio cabe no tabuleiro
                for(int j = 0; j < navios[i][0]; j++) {
                    if(tabuleiro[navios[i][2] + j][navios[i][3]][0] == 3) {    // Verifica conicidências entre navios
                        printf(RED"Erro! O navio %d coincide com outro navio na casa %c%02d.\n"RESET, i + 1, navios[i][3] + 65, navios[i][2] + j + 1);
                        tabuleiro[navios[i][2] + j][navios[i][3]][1] = 31;
                    } else {
                        tabuleiro[navios[i][2] + j][navios[i][3]][0] = 3;
                        tabuleiro[navios[i][2] + j][navios[i][3]][1] = 34;
                    }
                }
            }
            else {
                printf(RED"Erro! O navio %d ultrapassa os limites do tabuleiro.\n"RESET, i + 1);
                erro = 1;
            }
            break;
        
        case 2: // Seleciona navios na diagonal crescente
            if ((navios[i][3] >= 0) &&
                (navios[i][2] < TAB_H) &&
                (navios[i][2] - navios[i][0] - 1 >= 0) &&
                (navios[i][3] + navios[i][0] - 1 < TAB_V)) { // Verifica se o navio cabe no tabuleiro
                for(int j = 0; j < navios[i][0]; j++) {
                    if(tabuleiro[navios[i][2] + j][navios[i][3] - j][0] == 3) {    // Verifica conicidências entre navios
                        printf(RED"Erro! O navio %d coincide com outro navio na casa %c%02d.\n"RESET, i + 1, navios[i][3] + j + 65, navios[i][2] + 1);
                        tabuleiro[navios[i][2] + j][navios[i][3] - j][1] = 31;
                    } else {
                        tabuleiro[navios[i][2] + j][navios[i][3] - j][0] = 3;
                        tabuleiro[navios[i][2] + j][navios[i][3] - j][1] = 34;
                        
                    }
                }
            }
            else {
                printf(RED"Erro! O navio %d ultrapassa os limites do tabuleiro.\n"RESET, i + 1);
                erro = 1;
            }
            break;
        
        case 3: // Seleciona navios na diagonal decrecrescente
            if ((navios[i][2] >= 0) &&
                (navios[i][3] >= 0) &&
                (navios[i][2] + navios[i][0] - 1 < TAB_H) &&
                (navios[i][3] + navios[i][0] - 1 < TAB_V)) { // Verifica se o navio cabe no tabuleiro
                for(int j = 0; j < navios[i][0]; j++) {
                    if(tabuleiro[navios[i][2] + j][navios[i][3] + j][0] == 3) {    // Verifica conicidências entre navios
                        printf(RED"Erro! O navio %d coincide com outro navio na casa %c%02d.\n"RESET, i + 1, navios[i][3] + j + 65, navios[i][2] + 1);
                        tabuleiro[navios[i][2] + j][navios[i][3] + j][1] = 31;
                    } else {
                        tabuleiro[navios[i][2] + j][navios[i][3] + j][0] = 3;
                        tabuleiro[navios[i][2] + j][navios[i][3] + j][1] = 34;
                        
                    }
                }
            }
            else {
                printf(RED"Erro! O navio %d ultrapassa os limites do tabuleiro.\n"RESET, i + 1);
                erro = 1;
            }
            break;
        }
    }

    // Imprime tabuleiro com os navios
    if(!erro) { // Imprime o tabuleiro se não houver erros
        printf(WHITE"     ");
        for(int i = 65; i < 65 + TAB_H; i++) {
            printf("%c ", i);
        }
        printf("\n");
        printf("   ┌");
        for (int i = 0; i < TAB_H * 2 + 1; i++)
        {
            printf("─");
        }
        printf("┐\n");

        for (int i = 0; i < TAB_H; i++)
        {
            printf("%02d │ ", i+1);
            for (int j = 0; j < TAB_V; j++)
            {
                printf("\033[0;%dm%d \033[0m", tabuleiro[i][j][1] , tabuleiro[i][j][0]);
            }
            printf("│\n");
        }

        printf("   └");
        for (int i = 0; i < TAB_H * 2 + 1; i++)
        {
            printf("─");
        }
        printf("┘\n");

        printf("\n\n"RESET);
    }

    return 0;
}
