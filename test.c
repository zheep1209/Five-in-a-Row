//
// Created by zheep on 2024/6/3.
//
//      ������
//�������������Щ����������Щ�����������
//��  O  ��  X  ��  X  ��
//�������������੤���������੤����������
//��  X  ��  O  ��  O  ��
//�������������੤���������੤����������
//��  X  ��  O  ��  x  ��
//�������������ة����������ة�����������
#include <stdio.h>
#include "game.h"

void menu() {
    printf("�������������������������������Щ�����������������������������\n");
    printf("��    1.Play    ��    0.Exit    ��\n");
    printf("�������������������������������ة�����������������������������\n");
}
void game(){
//    ��ʼ������
    char boardArr [ROW][COL] = {" "};
//    ��ӡ����
    DisplayBoard(boardArr);
//    ����
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
        printf("��ѡ��>��");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("�˳���Ϸ\n");
                break;
            default:
                printf("ѡ�����\n");
                break;
        }
    } while (input);
}