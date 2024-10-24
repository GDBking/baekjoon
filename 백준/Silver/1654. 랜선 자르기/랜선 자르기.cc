#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> LAN;

int binarySearch(int r);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	LAN.resize(K);
	for (int i = 0; i < K; i++)
		cin >> LAN[i];

	int maxLen = 0;
	for (int i : LAN)
		maxLen = max(maxLen, i);

	cout << binarySearch(maxLen);
}

int binarySearch(int r) {
	long long left = 1, right = r;
	int result = 0;
	while (left <= right) {
		long long pivot = left + (right - left) / 2;
		int cnt = 0;
		for (int i : LAN)
			cnt += i / pivot;

		if (cnt >= N) {
			result = pivot;
			left = pivot + 1;
		}
		else
			right = pivot - 1;
	}
	return result;
}