#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> coordinate;
vector<vector<int>> maze;
vector<vector<bool>> visited;
void BFS(int N, int M);


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    maze = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = str[j] - '0';
        }
    }

    BFS(N - 1, M - 1);

    cout << maze[N - 1][M - 1];

    return 0;
}

void BFS(int N, int M)
{
    int x[4] = { 0, -1, 1, 0 };
    int y[4] = { -1, 0, 0, 1 };
    queue<coordinate> q;
    q.push(coordinate(0, 0));

    while (!q.empty())
    {
        int x1 = q.front().second;
        int y1 = q.front().first;
        q.pop();
        visited[y1][x1] = true;
        for (int i = 0; i < 4; i++)
        {
            int x2 = x1 + x[i];
            int y2 = y1 + y[i];
            if (x2 >= 0 and y2 >= 0 and x2 <= M and y2 <= N and !visited[y2][x2] and maze[y2][x2])
            {
                visited[y2][x2] = true;
                maze[y2][x2] = maze[y1][x1] + 1;
                q.push(coordinate(y2, x2));
                if (y2 == N and x2 == M)
                    return;
            }
        }
    }
}