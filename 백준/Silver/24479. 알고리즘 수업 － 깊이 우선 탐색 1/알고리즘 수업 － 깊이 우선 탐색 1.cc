#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> A;
vector<int> visited;

void dfs(int s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    A.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    for (int i = 1; i <= N; i++)
        sort(A[i].begin(), A[i].end());

    dfs(R);

    for (int i = 1; i <= N; i++)
        cout << visited[i] << "\n";
}

int cnt = 1;
void dfs(int s) {
    visited[s] = cnt++;
    for (int i : A[s])
        if (!visited[i])
            dfs(i);
}