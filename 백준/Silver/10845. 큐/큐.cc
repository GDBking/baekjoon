#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;
		if (!cmd.compare("push"))
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (!cmd.compare("pop"))
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (!cmd.compare("size"))
		{
			cout << q.size() << "\n";
		}
		else if (!cmd.compare("empty"))
		{
			cout << q.empty() << "\n";
		}
		else if (!cmd.compare("front"))
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}

	return 0;
}