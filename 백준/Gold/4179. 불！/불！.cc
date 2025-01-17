#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int R, C;
char maze[1000][1001];
int direction[4][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
int ans = 0;

void BFS(int JR, int JC, vector<pair<int, int>> FPlaces);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> maze[i];

	int JPlace[2];
	vector<pair<int, int>> FPlaces;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (maze[i][j] == 'F')
				FPlaces.push_back(make_pair(i, j));
			else if (maze[i][j] == 'J')
			{
				if (i == 0 || j == 0)
				{
					cout << 1;
					return 0;
				}
				JPlace[0] = i;
				JPlace[1] = j;
			}
		}

	BFS(JPlace[0], JPlace[1], FPlaces);

	cout << (ans == 0 ? "IMPOSSIBLE" : to_string(ans));
}

void BFS(int JR, int JC, vector<pair<int, int>> FPlaces)
{
	queue<tuple<int, int, int>> JQ;
	queue<tuple<int, int, int>> FQ;
	JQ.push(make_tuple(JR, JC, 0));
	for (int i = 0; i < FPlaces.size(); i++)
		FQ.push(make_tuple(FPlaces[i].first, FPlaces[i].second, 0));
	int minute = 0;
	while (true)
	{
		while (!JQ.empty())
		{
			auto [nowR, nowC, nowM] = JQ.front();
			if (minute != nowM)
				break;
			if (maze[nowR][nowC] != 'J')
			{
				JQ.pop();
				continue;
			}
			JQ.pop();
			for (auto next : direction)
			{
				int nr = nowR + next[0];
				int nc = nowC + next[1];
				if (maze[nr][nc] == '.')
				{
					maze[nr][nc] = 'J';
					JQ.push(make_tuple(nr, nc, nowM + 1));
				}
			}
		}
		if (JQ.empty())
			return;

		while (!FQ.empty())
		{
			auto [nowR, nowC, nowM] = FQ.front();
			if (minute != nowM)
				break;
			FQ.pop();
			for (auto next : direction)
			{
				int nr = nowR + next[0];
				int nc = nowC + next[1];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || maze[nr][nc] == '#' || maze[nr][nc] == 'F')
					continue;
				maze[nr][nc] = 'F';
				FQ.push(make_tuple(nr, nc, nowM + 1));
			}
		}
		minute++;
		for (int i = 0; i < C; i++)
			if (maze[0][i] == 'J' || maze[R - 1][i] == 'J')
			{
				ans = minute + 1;
				return;
			}
		for (int i = 0; i < R; i++)
			if (maze[i][0] == 'J' || maze[i][C - 1] == 'J')
			{
				ans = minute + 1;
				return;
			}
	}
}