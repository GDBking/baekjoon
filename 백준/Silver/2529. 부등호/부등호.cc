#include <iostream>
#include <vector>
using namespace std;

int k;
bool visited[10];
vector<int> result;
vector<char> inequality;
bool flag = false;

void descendingBacktracking(int depth);
void ascendingBacktracking(int depth);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	result.resize(k + 1);
	inequality.resize(k);
	for (int i = 0; i < k; i++)
		cin >> inequality[i];

	descendingBacktracking(0);
	flag = false;
	fill(visited, &visited[10], false);
	ascendingBacktracking(0);
}

void descendingBacktracking(int depth)
{
	if (depth == k + 1)
	{
		for (int i : result)
			cout << i;
		cout << "\n";
		flag = true;
		return;
	}

	if (depth == 0)
		for (int i = 9; i >= 0; i--)
		{
			result[0] = i;
			visited[i] = true;
			descendingBacktracking(depth + 1);
			if (flag) return;
			visited[i] = false;
		}
	else
		for (int i = 9; i >= 0; i--)
			if (!visited[i])
			{
				char ine = inequality[depth - 1];
				if ((ine == '<' && result[depth - 1] < i) || (ine == '>' && result[depth - 1] > i))
				{
					result[depth] = i;
					visited[i] = true;
					descendingBacktracking(depth + 1);
					if (flag) return;
					visited[i] = false;
				}
			}
}

void ascendingBacktracking(int depth)
{
	if (depth == k + 1)
	{
		for (int i : result)
			cout << i;
		flag = true;
		return;
	}

	if (depth == 0)
		for (int i = 0; i <= 9; i++)
		{
			result[0] = i;
			visited[i] = true;
			ascendingBacktracking(depth + 1);
			if (flag)
				return;
			visited[i] = false;
		}
	else
		for (int i = 0; i <= 9; i++)
			if (!visited[i])
			{
				char ine = inequality[depth - 1];
				if ((ine == '<' && result[depth - 1] < i) || (ine == '>' && result[depth - 1] > i))
				{
					result[depth] = i;
					visited[i] = true;
					ascendingBacktracking(depth + 1);
					if (flag) 
						return;
					visited[i] = false;
				}
			}
}