#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numArr1;
vector<pair<int, int>> numArr2;
vector<int> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	numArr1.resize(N);
	for (int i = 0; i < N; i++)
		cin >> numArr1[i];
	cin >> M;
	numArr2.resize(M);
	result.resize(M);
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		numArr2[i] = make_pair(temp, i);
	}

	sort(numArr1.begin(), numArr1.end());
	sort(numArr2.begin(), numArr2.end());

	int j = 0;
	for (int i = 0; i < M; i++) {
		if (j == N) break;
		while (j < N) {
			if (numArr1[j] == numArr2[i].first) {
				result[numArr2[i].second] = 1;
				break;
			}
			else if (numArr1[j] > numArr2[i].first)
				break;
			else
				j++;
		}
	}

	for (int i : result)
		cout << i << "\n";
}