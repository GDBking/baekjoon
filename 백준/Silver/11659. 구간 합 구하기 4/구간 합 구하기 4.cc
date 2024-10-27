#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	A.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 2; i <= N; i++)
		A[i] += A[i - 1];

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		int result = A[e] - A[s - 1];
		cout << result << "\n";
	}
}