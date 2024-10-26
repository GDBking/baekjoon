#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[27][27];
bool visited[27][27];
int order[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
vector<int> result;

int DFS(int y, int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= N; j++) {
			map[i][j] = temp[j - 1] - 48;
		}
	}
	
	int address = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (map[i][j] && !visited[i][j]) {
				result.push_back(DFS(i, j));
				address++;
			}
		}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i : result)
		cout << i << "\n";
}

int DFS(int y, int x) {
	visited[y][x] = true;
	int cnt = 1;
	for (int* next : order) {
		int nextY = y + next[0];
		int nextX = x + next[1];
		if (!visited[nextY][nextX] && map[nextY][nextX]) {
			cnt += DFS(nextY, nextX);
		}
	}
	return cnt;
}