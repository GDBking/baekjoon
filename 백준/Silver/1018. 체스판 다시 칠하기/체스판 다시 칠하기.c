#include <stdio.h>

int main() 
{
    int caseW[50][50] = { 0, }, caseB[50][50] = { 0, };
    char board[51][51] = { 0, };
    int n, m, min, ans = 63;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", board[i]);
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (board[i][j] == 'W')
                {
                    caseB[i][j] = 1;
                }
                else
                {
                    caseW[i][j] = 1;
                }
            }
            else
            {
                if (board[i][j] == 'W')
                {
                    caseW[i][j] = 1;
                }
                else
                {
                    caseB[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int sumW = 0, sumB = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    sumW += caseW[k][l];
                    sumB += caseB[k][l];
                }
            }
            min = sumW < sumB ? sumW : sumB;
            ans = ans < min ? ans : min;
        }
    }
    printf("%d", ans);
    
    return 0;
}