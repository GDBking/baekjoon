#include <iostream>
using namespace std;

static int n, D[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= n; i++)
		D[i] = (D[i - 2] + D[i - 1]) % 10007;

	cout << D[n];

	return 0;
}