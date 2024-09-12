#include <iostream>
#include <stack>
using namespace std;

stack<char> st, buffer;

void cursorLeft()
{
	if (!st.empty())
	{
		buffer.push(st.top());
		st.pop();
	}
}

void cursorRight()
{
	if (!buffer.empty())
	{
		st.push(buffer.top());
		buffer.pop();
	}
}

void deleteChar()
{
	if (!st.empty())
		st.pop();
}

void insertChar()
{
	char temp;
	cin >> temp;
	st.push(temp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	for (int i = 0; str[i]; i++)
		st.push(str[i]);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		char c;
		cin >> c;
		switch (c)
		{
		case 'L':
			cursorLeft();
			break;
		case 'D':
			cursorRight();
			break;
		case 'B':
			deleteChar();
			break;
		case 'P':
			insertChar();
		}
	}

	while (!st.empty())
	{
		buffer.push(st.top());
		st.pop();
	}

	while (!buffer.empty())
	{
		cout << buffer.top();
		buffer.pop();
	}

	return 0;
}