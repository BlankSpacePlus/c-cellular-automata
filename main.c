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
    printf("��������һ���ϸ��������λ�ã�����(-1,1)�������\n");
    while (1) {
        printf("������һ����ϸ��������λ�ã�");
        scanf("%d %d", &row, &col);
        if (0 <= row && row < ROWLEN && 0 <= col && col < COLLEN) {
            cell[row][col] = ALIVE;
        } else if (row == -1 || col == -1) {
            break;
        } else {
            printf("����Խ�磡\n");
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
    printf("\nϸ��״̬\n��-");
    for (col = 0; col < COLLEN-1; col++) {
        printf("---��-");
    }
    printf("---��\n");
    for (row = 0; row < ROWLEN; row++) {
        printf("��");
        for (col = 0; col < COLLEN; col++) {
            switch (cell[row][col]) {
                case ALIVE:
                    printf(" �� ��");
                    break;
                case DEAD:
                    printf(" �� ��");
                    break;
            }
        }
        printf("\n");
        if (row < ROWLEN-1) {
            printf("��");
            for (col = 0; col < COLLEN-1; col++) {
                printf("----��");
            }
            printf("----��\n");
        }
    }
    printf("��");
    for (col = 0; col < COLLEN-1; col++) {
        printf("----��");
    }
    printf("----��\n");
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
    printf("��ǰ״̬�£�����%d����ϸ��\n", sum);
}

int main() {
    char again;
    printf("Ԫ���Զ���\n");
    initCell();
    printCell();
    printf("���������ʼ��Ϸ������ϸ��ת��\n");
    getch();
    cellFunction();
    printf("\n����������һ��ϸ����״̬(y/n)?");
    while (1) {
        fflush(stdin);
        scanf("%c", &again);
        if (again == 'y' || again == 'Y') {
            cellFunction();
            printf("\n����������һ��ϸ����״̬(y/n)?");
        } else if (again == 'n' || again == 'N') {
            break;
        } else {
            printf("����������������룡\n����������һ��ϸ����״̬(y/n)?");
        }
    }
    printf("��Ϸ����");
    return 0;
}
