#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define ROWLEN 10
#define COLLEN 10
#define DEAD 0
#define ALIVE 1

int cell[ROWLEN][COLLEN];
int cellTemp[ROWLEN][COLLEN];

void initCell() {
    int row, col;
    for (row = 0; row < ROWLEN; row++) {
        for (col = 0; col < COLLEN; col++) {
            cell[row][col] = DEAD;
        }
    }
    printf("请先输入一组活细胞的坐标位置，输入(-1,1)则结束：\n");
    while (1) {
        printf("请输入一个活细胞的坐标位置：");
        scanf("%d %d", &row, &col);
        if (0 <= row && row < ROWLEN && 0 <= col && col < COLLEN) {
            cell[row][col] = ALIVE;
        } else if (row == -1 || col == -1) {
            break;
        } else {
            printf("坐标越界！\n");
        }
    }
}

int countAlive(int row, int col) {
    int count = 0, i, j;
    for (i = row-1; i <= row+1; i++) {
        for (j = col-1; j <= col+1; j++) {
            if (i < 0 || i >= ROWLEN || j < 0 || j >= COLLEN) {
                continue;
            }
            if (cell[i][j] == ALIVE) {
                count++;
            }
        }
    }
    if (cell[row][col] == ALIVE) {
        count--;
    }
    return count;
}

void printCell() {
    int row, col;
    printf("\n细胞状态\n┌-");
    for (col = 0; col < COLLEN-1; col++) {
        printf("---┐-");
    }
    printf("---┐\n");
    for (row = 0; row < ROWLEN; row++) {
        printf("│");
        for (col = 0; col < COLLEN; col++) {
            switch (cell[row][col]) {
                case ALIVE:
                    printf(" ● │");
                    break;
                case DEAD:
                    printf(" ○ │");
                    break;
            }
        }
        printf("\n");
        if (row < ROWLEN-1) {
            printf("├");
            for (col = 0; col < COLLEN-1; col++) {
                printf("----┼");
            }
            printf("----┤\n");
        }
    }
    printf("└");
    for (col = 0; col < COLLEN-1; col++) {
        printf("----┴");
    }
    printf("----┘\n");
}

void cellFunction() {
    int row, col, sum;
    int count = 0;
    for (row = 0; row < ROWLEN; row++) {
        for (col = 0; col < COLLEN; col++) {
            switch (countAlive(row, col)) {
                case 2:
                    cellTemp[row][col] = cell[row][col];
                    break;
                case 3:
                    cellTemp[row][col] = ALIVE;
                    break;
                default:
                    cellTemp[row][col] = DEAD;
                    break;
            }
        }
    }
    for (row = 0; row < ROWLEN; row++) {
        for (col = 0; col < COLLEN; col++) {
            cell[row][col] = cellTemp[row][col];
        }
    }
    for (row = 0; row < ROWLEN; row++) {
        for (col = 0; col < COLLEN; col++) {
            if (cell[row][col] == ALIVE) {
                count++;
            }
        }
    }
    sum = count;
    printCell();
    printf("当前状态下，共有%d个活细胞\n", sum);
}

int main() {
    char again;
    printf("元胞自动机\n");
    initCell();
    printCell();
    printf("按任意键开始游戏，进行细胞转换\n");
    getch();
    cellFunction();
    printf("\n继续生成下一次细胞的状态(y/n)?");
    while (1) {
        fflush(stdin);
        scanf("%c", &again);
        if (again == 'y' || again == 'Y') {
            cellFunction();
            printf("\n继续生成下一次细胞的状态(y/n)?");
        } else if (again == 'n' || again == 'N') {
            break;
        } else {
            printf("输入错误，请重新输入！\n继续生成下一次细胞的状态(y/n)?");
        }
    }
    printf("游戏结束");
    return 0;
}
