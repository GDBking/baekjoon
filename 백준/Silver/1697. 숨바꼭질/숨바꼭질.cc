#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, K;
vector<int> visited;

void BFS();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	visited.resize(200001, INT_MAX);

	BFS();
	cout << visited[K];
}

void BFS() {
	visited[N] = 0;
	queue<int> q;
	q.push(N);
	while (visited[K] == INT_MAX) {
		int now = q.front();
		q.pop();
		if (now + 1 < K * 2 && visited[now + 1] == INT_MAX) {
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}
		if (now - 1 >= 0 && visited[now - 1] == INT_MAX) {
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}
		if (now < K && visited[now * 2] == INT_MAX) {
			visited[now * 2] = visited[now] + 1;
			q.push(now * 2);
		}
	}
}