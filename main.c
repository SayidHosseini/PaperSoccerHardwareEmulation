#include "main.h"
#include "stack.h"
#include <stdio.h>

void initMap(void);
void printMap(void);

void main(void)
{
    printf("Starting the GAME!\n\n");

    initMap();
    currentStack = sInit(10 * row * col);
    doneStack = sInit(10 * row * col);
    // printMap();
}

void initMap(void)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            map[i][j] = 0x00;
    
    for(int j = 0; j < col; j++)
    {
        map[0][j] = 0xFF;
        map[row - 1][j] = 0xFF;
    }

    for(int i = 1; i < row - 1; i++)
        map[i][0] = 0x0E; // 0000 1110

    for(int i = 1; i < row - 1; i++)
        map[i][col - 1] = 0xE0; // 1110 0000

    for(int j = 0; j < col; j++)
    {
        map[1][j] = 0x38; // 0011 1000
        map[row - 2][j] = 0x83; // 1000 0011
    }

    map[1][0] = 0x08; // 0000 1000
    map[1][col - 1] = 0x20; // 0010 0000
    map[row - 2][0] = 0x02; // 0000 0010
    map[row - 2][col - 1] = 0x80; // 1000 0000
    
    map[0][(col / 2) - 1] = 0x08; // 0000 1000
    map[0][(col / 2)] = 0x38; // 0011 1000
    map[0][(col / 2) + 1] = 0x20; // 0010 0000

    map[1][(col / 2) - 1] = 0x3E; // 0011 1110
    map[1][(col / 2)] = 0x00; // 0000 0000
    map[1][(col / 2) + 1] = 0xF8; // 1111 1000

    map[row - 1][(col / 2) - 1] = 0x02; // 0000 0010
    map[row - 1][(col / 2)] = 0x83; // 1000 0011
    map[row - 1][(col / 2) + 1] = 0x80; // 1000 0000

    map[row - 2][(col / 2) - 1] = 0x8F; // 1000 1111
    map[row - 2][(col / 2)] = 0x00; // 0000 0000
    map[row - 2][(col / 2) + 1] = 0xE3; // 1110 0011
}

void printMap(void)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            printf("0x%02X  ", map[i][j]);

            if(j == col - 1)
                printf("\n");
        }
}
