#include <iostream>
#include <vector>
using namespace std;

int M;
vector<bool> A(21);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;
	for (int i = 0; i < M; i++) {
		string cmd;
		int x;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			A[x] = true;
		}
		else if (cmd == "remove") {
			cin >> x;
			A[x] = false;
		}
		else if (cmd == "check") {
			cin >> x;
			if (A[x]) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			A[x] = !A[x];
		}
		else if (cmd == "all")
			fill(A.begin(), A.end(), true);
		else
			fill(A.begin(), A.end(), false);
	}
}