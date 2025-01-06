#include <iostream>
#include <vector>
using namespace std;

int N, cnt = 0;
vector<vector<int>> visited;

void backtracking(int row);
void check(int row, int col, int sum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	visited.resize(N + 1, vector<int>(N + 1));
	backtracking(1);
	
	cout << cnt;
}

void backtracking(int row)
{
	if (row == N)
	{
		for (int i = 1; i <= N; i++)
			if (!visited[row][i])
				cnt++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[row][i])
		{
			check(row, i, 1);
			backtracking(row + 1);
			check(row, i, -1);
		}
	}
}

void check(int row, int col, int sum)
{
	int cnt = 1;
	for (int i = row + 1; i <= N; i++, cnt++)
	{
		visited[i][col] += sum;
		if (col - cnt > 0)
			visited[i][col - cnt] += sum;
		if (col + cnt <= N)
			visited[i][col + cnt] += sum;
	}
}