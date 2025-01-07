#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int T, n;
string p, str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> p >> n;
		deque<int> dq;
		getline(cin, str, '[');
		for (int j = 0; j < n - 1; j++)
		{
			getline(cin, str, ',');
			dq.push_back(stoi(str));
		}
		getline(cin, str, ']');
		if (str != "")
			dq.push_back(stoi(str));

		bool isBack = false, flag = false;
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] == 'R')
				isBack = !isBack;
			else
			{
				if (dq.empty())
				{
					cout << "error\n";
					flag = true;
					break;
				}
				else
				{
					if (isBack)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}

		if (!flag && dq.empty())
			cout << "[]\n";
		else if (!flag)
		{
			cout << "[";
			if (isBack)
			{
				for (int j = dq.size() - 1; j > 0; j--)
					cout << dq[j] << ",";
				cout << dq.front() << "]\n";
			}
			else
			{
				for (int j = 0; j < dq.size() - 1; j++)
					cout << dq[j] << ",";
				cout << dq.back() << "]\n";
			}
		}
	}
}