#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void munion(int a, int b);
int find(int a);
static vector<int> parent;

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	parent.resize(V + 1);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(Edge{a, b, c});
	}

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	int cnt = 0, ans = 0;
	while (cnt < V - 1)
	{
		Edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e))
		{
			munion(now.s, now.e);
			cnt++;
			ans += now.v;
		}
	}

	cout << ans;

	return 0;
}


void munion(int a, int b)
{
	int fa = find(a);
	int fb = find(b);

	if (fa != fb)
		parent[fb] = fa;
}

int find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}