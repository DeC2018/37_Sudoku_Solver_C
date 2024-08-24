#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char** board, int row, int col, char c) {
    // row check
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) {
            return false;
        }
    }
    // col check
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) {
            return false;
        }
    }
    // box check
    int x0 = (row / 3) * 3;
    int y0 = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[x0 + i][y0 + j] == c) {
                return false;
            }
        }
    }
    return true;
}

bool helper(char** board, int row, int col) {
    // done
    if (row == 9) {
        return true;
    }
    // time for next row
    if (col == 9) {
        return helper(board, row + 1, 0);
    }
    // already marked
    if (board[row][col] != '.') {
        return helper(board, row, col + 1);
    }
    for (char c = '1'; c <= '9'; c++) {
        if (isValid(board, row, col, c)) {
            board[row][col] = c;
            // without return here, the board reverts to initial state
            if (helper(board, row, col + 1)) {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(char** board) {
    helper(board, 0, 0);
}

int main() {
    char** board = (char**)malloc(9 * sizeof(char*));
    for (int i = 0; i < 9; i++) {
        board[i] = (char*)malloc(9 * sizeof(char));
    }

    board[0][0] = '5';
    board[0][1] = '3';
    board[0][2] = '.';
    board[0][3] = '.';
    board[0][4] = '7';
    board[0][5] = '.';
    board[0][6] = '.';
    board[0][7] = '.';
    board[0][8] = '.';

    board[1][0] = '6';
    board[1][1] = '.';
    board[1][2] = '.';
    board[1][3] = '1';
    board[1][4] = '9';
    board[1][5] = '5';
    board[1][6] = '.';
    board[1][7] = '.';
    board[1][8] = '.';

    board[2][0] = '.';
    board[2][1] = '9';
    board[2][2] = '8';
    board[2][3] = '.';
    board[2][4] = '.';
    board[2][5] = '.';
    board[2][6] = '.';
    board[2][7] = '6';
    board[2][8] = '.';

    board[3][0] = '8';
    board[3][1] = '.';
    board[3][2] = '.';
    board[3][3] = '.';
    board[3][4] = '6';
    board[3][5] = '.';
    board[3][6] = '.';
    board[3][7] = '.';
    board[3][8] = '3';

    board[4][0] = '4';
    board[4][1] = '.';
    board[4][2] = '.';
    board[4][3] = '8';
    board[4][4] = '.';
    board[4][5] = '3';
    board[4][6] = '.';
    board[4][7] = '.';
    board[4][8] = '1';

    board[5][0] = '7';
    board[5][1] = '.';
    board[5][2] = '.';
    board[5][3] = '.';
    board[5][4] = '2';
    board[5][5] = '.';
    board[5][6] = '.';
    board[5][7] = '.';
    board[5][8] = '6';

    board[6][0] = '.';
    board[6][1] = '6';
    board[6][2] = '.';
    board[6][3] = '.';
    board[6][4] = '.';
    board[6][5] = '.';
    board[6][6] = '2';
    board[6][7] = '8';
    board[6][8] = '.';

    board[7][0] = '.';
    board[7][1] = '.';
    board[7][2] = '.';
    board[7][3] = '4';
    board[7][4] = '1';
    board[7][5] = '9';
    board[7][6] = '.';
    board[7][7] = '.';
    board[7][8] = '5';

    board[8][0] = '.';
    board[8][1] = '.';
    board[8][2] = '.';
    board[8][3] = '.';
    board[8][4] = '8';
    board[8][5] = '.';
    board[8][6] = '.';
    board[8][7] = '7';
    board[8][8] = '9';

    solveSudoku(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 9; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}