#include <iostream>
#include <stack>
using namespace std;

int K;
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		if (temp) st.push(temp);
		else st.pop();
	}

	int ans = 0;
	while (!st.empty()) {
		int temp = st.top();
		st.pop();
		ans += temp;
	}

	cout << ans;
}