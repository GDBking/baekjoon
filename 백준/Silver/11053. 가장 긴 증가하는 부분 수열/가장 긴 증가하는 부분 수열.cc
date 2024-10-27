#include <iostream>
#include <vector>
using namespace std;

int A;
vector<int> numArr;
vector<int> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A;
	numArr.resize(A);
	result.resize(A, 1);
	for (int i = 0; i < A; i++)
		cin >> numArr[i];

	for (int i = 1; i < A; i++)
		for (int j = i - 1; j >= 0; j--)
			if (numArr[i] > numArr[j])
				result[i] = max(result[i], result[j] + 1);

	int maxCnt = 0;
	for (int i : result)
		maxCnt = max(maxCnt, i);

	cout << maxCnt;
}