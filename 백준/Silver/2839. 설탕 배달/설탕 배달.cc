#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	if (N % 5 == 0)
		cout << N / 5;
	else if (N % 5 == 1)
		cout << N / 5 + 1;
	else if (N % 5 == 2 && N >= 12)
		cout << N / 5 + 2;
	else if (N % 5 == 3)
		cout << N / 5 + 1;
	else if (N % 5 == 4 && N != 4)
		cout << N / 5 + 2;
	else
		cout << -1;
}