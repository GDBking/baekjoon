#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	
	for (int i : A)
		cout << i << "\n";
}