#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char buffer[101] = " ";
	while (true) {
		st = {};
		cin.getline(buffer, 100, '.');
		cin.ignore();
		if (!*buffer) break;
		char* p = buffer;
		while (*p) {
			if (*p == '(')
				st.push('(');
			else if (*p == '[')
				st.push('[');
			else if (*p == ')') {
				if (st.empty() || st.top() != '(') {
					st.push('x');
					break;
				}
				st.pop();
			}
			else if (*p == ']') {
				if (st.empty() || st.top() != '[') {
					st.push('x');
					break;
				}
				st.pop();
			}
			p++;
		}
		if (st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}