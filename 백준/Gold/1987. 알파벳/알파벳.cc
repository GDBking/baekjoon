#include <iostream>
#include <vector>
using namespace std;

int R, C;
char board[20][21];
bool visitedAlpha[26];
int order[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
int ans = 0;

void DFS(int row, int col, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> board[i];
    DFS(0, 0, 1);

    cout << ans;
}

void DFS(int row, int col, int depth)
{
    ans = max(ans, depth);
    visitedAlpha[board[row][col] - 'A'] = true;
    for (int* next : order)
    {
        int nextR = row + next[0];
        int nextC = col + next[1];
        if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && !visitedAlpha[board[nextR][nextC] - 'A'])
        {
            DFS(nextR, nextC, depth + 1);
            visitedAlpha[board[nextR][nextC] - 'A'] = false;
        }
    }
}