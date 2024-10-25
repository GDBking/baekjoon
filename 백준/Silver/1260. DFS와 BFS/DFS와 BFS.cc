#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> node;
static vector<bool> visit;
void DFS(int s);
void BFS(int s);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    node.resize(N + 1);
    visit = vector<bool>(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(node[i].begin(), node[i].end());
    }

    DFS(V);
    cout << '\n';
    fill(visit.begin(), visit.end(), false);
    BFS(V);

    return 0;
}

void DFS(int s)
{
    visit[s] = true;
    cout << s << ' ';

    for (int i : node[s])
    {
        if (!visit[i])
            DFS(i);
    }
}


void BFS(int s)
{
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty())
    {
        int temp = q.front();
        cout << temp << ' ';
        q.pop();
        for (int i : node[temp])
        {
            if (!visit[i])
            {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}