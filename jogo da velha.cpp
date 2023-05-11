#include <stdio.h>

char board[3][3]; // Matriz para armazenar o tabuleiro

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("-----------\n");
        }
    }
}

int check_win(char player) {
    int i;
    // Checar linhas
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Checar colunas
    for (i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Checar diagonais
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    int row, col;
    char player = 'X';
    initialize_board();
    printf("Jogo da Velha!\n");
    printf("Player 1 = X\nPlayer 2 = O\n");
    printf("-------------\n");
    print_board();
    printf("-------------\n");
    // Loop principal do jogo
    while (1) {
        printf("Player %c, faça sua jogada (linha, coluna): ", player);
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }
        if (board[row][col] != ' ') {
            printf("Esse espaço já está ocupado. Tente novamente.\n");
            continue;
        }
        board[row][col] = player;
        print_board();
        if (check_win(player)) {
            printf("Player %c venceu!\n", player);
            break;
        }
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    return 0;
}

