//
// Created by zheep on 2024/6/3.
//
#include "game.h"

void DisplayBoard(char board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        if (i == 0) {
            for (int j = 0; j < COL; j++) {
                if (j == 0)
                    printf("┌─────");
                else if (j != COL - 1)
                    printf("┬─────");
                else printf("┬─────┐\n");
            }
        }
        for (int j = 0; j < COL; j++) {
            if (j == 0)
                printf("│  %c  │", board[i][j]);
            else if (j != COL - 1)
                printf("  %c  │", board[i][j]);
            else printf("  %c  │\n", board[i][j]);
        }

        if (i != ROW - 1) {
            for (int j = 0; j < COL; j++) {
                if (j == 0)
                    printf("│─────┼");
                else if (j != COL - 1)
                    printf("─────┼");
                else printf("─────│\n");
            }
        }
        if (i == ROW - 1) {
            for (int j = 0; j < COL; j++) {
                if (j == 0)
                    printf("└─────");
                else if (j != COL - 1)
                    printf("┴─────");
                else printf("┴─────┘\n");
            }
        }
    }
}

bool PlayerMove(char board[ROW][COL]) {
    while (1) {
        int x = 0, y = 0;
        printf("    请输入坐标(例: 1 1 )>>>\n");
        printf("        :");
        scanf("%d %d", &y, &x);
        x--;
        y--;
        if (x < 0 || x > COL - 1 || y < 0 || y > ROW - 1) {
            printf("你的坐标在棋盘之外,请重下>>>\n");
            continue;
        } else if (board[x][y] == 'X' || board[x][y] == 'O') {
            printf("当前位置有棋子,请重下>>>\n");
            continue;
        } else {
            board[x][y] = 'X';
            DisplayBoard(board);
            return Victory(board, x, y, 1);
        }
    }
}

bool ComputerMove(char board[ROW][COL]) {
    printf("电脑>>>\n");
    int x = 0;
    int y = 0;
    srand(time(NULL));
    while (1) {
        x = rand() % ROW;
        y = rand() % COL;
        if (board[x][y] == 'X' || board[x][y] == 'O') {
            continue;
        }
        Victory(board, x, y, 0);
        board[x][y] = 'O';
        DisplayBoard(board);
        return Victory(board, x, y, 0);
        break;
    }
}

bool draw(char board[ROW][COL]) {
    int isDraw = 1;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != 'X' & board[i][j] != 'O') {
                isDraw = 0;
            }
        }
    }
    return isDraw;
}

bool Victory(char board[ROW][COL], int x, int y, int role) {
    int mode = 5;
    char kiko = role ? 'X' : 'O';
    for (int j = 0; j < mode-1; j++) {
        int sum = 1;
        for (int i = 1; i < mode; i++) {
            if (board[x][y + i] == kiko && x >= 0 && x < COL && y + i >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        for (int i = 1; i < mode; i++) {
            if (board[x][y - i] == kiko && x >= 0 && x < COL && y - i >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        if (sum >= 5) {
            printf("%s胜利\n", role ? "玩家" : "电脑");
            DisplayBoard(board);
            return true;
        }
    }
    for (int j = 0; j <  mode-1; j++) {
        int sum = 1;
        for (int i = 1; i < mode; i++) {
            if (board[x + i][y] == kiko && x >= 0 && x + i < COL && y >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        for (int i = 1; i <mode; i++) {
            if (board[x - i][y] == kiko && x >= 0 && x - i < COL && y >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        if (sum >= 5) {
            printf("%s胜利\n", role ? "玩家" : "电脑");
            DisplayBoard(board);
            return true;
        }
    }
    for (int j = 0; j <  mode-1; j++) {
        int sum = 1;
        for (int i = 1; i < mode; i++) {
            if (board[x + i][y + i] == kiko && x >= 0 && x + i < COL && y + i >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        for (int i = 1; i < mode; i++) {
            if (board[x - i][y - i] == kiko && x >= 0 && x - i < COL && y - i >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        if (sum >= 5) {
            printf("%s胜利\n", role ? "玩家" : "电脑");
            DisplayBoard(board);
            return true;
        }
    }
    for (int j = 0; j <  mode-1; j++) {
        int sum = 1;
        for (int i = 1; i < mode; i++) {
            if (board[x + i][y - i] == kiko && x >= 0 && x + i < COL && y - i >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        for (int i = 1; i < mode; i++) {
            if (board[x - i][y + i] == kiko && x >= 0 && x - i < COL && y + i >= 0 && y < ROW) {
                sum++;
            } else break;
        }
        if (sum >= mode) {
            DisplayBoard(board);
            printf("***%s胜利***\n", role ? "玩家" : "电脑");
            return true;
        }
    }
    return false;
}