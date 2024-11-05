#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, y;
vector<vector<int>> A;
vector<int> visited;

void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x >> y >> m;
    A.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    bfs();
    if (visited[y])
        cout << visited[y] - 1;
    else
        cout << "-1";
}

void bfs() {
    visited[x] = 1;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : A[now]) {
            if (!visited[next]) {
                visited[next] = visited[now] + 1;
                if (next == y)
                    break;
                q.push(next);
            }
        }
    }
}