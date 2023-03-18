#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void main()
{
    int gd = DETECT, gm;
    int op[3][3], ob[3][3], ob2[3][3];
    int x1, y1, x2, y2, x3, y3, i, j, k, tx, ty;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    scanf("%d%d", &tx , &ty);
    op[0][0] = op[1][1] = op[2][2] = 1;
    op[0][1] = op[1][0] = op[2][0] = op[2][1] = 0;
    op[0][2] = tx;
    op[1][2] = ty;
    ob[0][0] = x1;
    ob[1][0] = y1;
    ob[0][1] = x2;
    ob[1][1] = y2;
    ob[0][2] = x3;cvbn
    ob[1][2] = y3;
    ob[2][0] = ob[2][1] = ob[2][2] = 1;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ob2[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                ob2[i][j] = ob2[i][j] + op[i][k] * ob[k][j];
            }
        }
    }
    line(ob2[0][0], ob2[1][0], ob2[0][1], ob2[1][1]);
    line(ob2[0][1], ob2[1][1], ob2[0][2], ob2[1][2]);
    line(ob2[0][0], ob2[1][0], ob2[0][2], ob2[1][2]);
    getch();
}