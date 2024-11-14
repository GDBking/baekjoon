#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> A;
vector<int> result;

void dijkstra();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    A.resize(V + 1);
    result.resize(V + 1, 200000);
    for (int i = 1; i <= E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(make_pair(v, w));
    }

    dijkstra();

    for (int i = 1; i <= V; i++) {
        if (result[i] == 200000)
            cout << "INF\n";
        else
            cout << result[i] << "\n";
    }
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, K));
    result[K] = 0;
    while (!pq.empty()) {
        pair<int, int> now = pq.top();
        pq.pop();

        if (now.first > result[now.second])
            continue;

        for (auto next : A[now.second]) {
            if (result[next.first] > now.first + next.second) {
                result[next.first] = now.first + next.second;
                pq.push(make_pair(result[next.first], next.first));
            }
        }
    }
}