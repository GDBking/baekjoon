#include <iostream>
#include <vector>
using namespace std;

int R, C;
char board[20][25];
bool visited[20][20];
vector<bool> visitedAlpha(26);
int order[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
int ans = 0;

void DFS(int row, int col, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            visited[i][j] = false;

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> board[i];
    DFS(0, 0, 1);

    cout << ans;
}

void DFS(int row, int col, int depth)
{
    ans = max(ans, depth);
    visited[row][col] = true;
    visitedAlpha[board[row][col] - 'A'] = true;
    for (int* next : order)
    {
        int nextR = row + next[0];
        int nextC = col + next[1];
        if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && !visited[nextR][nextC] && !visitedAlpha[board[nextR][nextC] - 'A'])
        {
            DFS(nextR, nextC, depth + 1);
            visited[nextR][nextC] = false;
            visitedAlpha[board[nextR][nextC] - 'A'] = false;
        }
    }
}