//
// Created by zheep on 2024/6/3.
//
//      井字棋
//┌─────┬─────┬─────┐
//│  O  │  X  │  X  │
//├─────┼─────┼─────│
//│  X  │  O  │  O  │
//├─────┼─────┼─────│
//│  X  │  O  │  x  │
//└─────┴─────┴─────┘
#include <stdio.h>
#include "game.h"

void menu() {
    printf("┌──────────────┬──────────────┐\n");
    printf("│    1.Play    │    0.Exit    │\n");
    printf("└──────────────┴──────────────┘\n");
}
void game(){
//    初始化数据
    char boardArr [ROW][COL] = {" "};
//    打印棋盘
    DisplayBoard(boardArr);
//    下棋
    while (1){
        if (PlayerMove(boardArr))
            break;
        if (ComputerMove(boardArr))
            break;
        if(draw(boardArr))
            break;
    }
}
int main() {
    int input = 0;
    do {
        menu();
        printf("请选择>：");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    } while (input);
}