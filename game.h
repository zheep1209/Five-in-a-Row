//
// Created by zheep on 2024/6/3.
//
#pragma once
#define ROW 15
#define COL 15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROW][COL]);
bool PlayerMove(char board[ROW][COL]);
bool ComputerMove (char board[ROW][COL]);
bool Victory(char board[ROW][COL],int x,int y,int role);
bool draw(char board[ROW][COL]);
