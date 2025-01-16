#include <iostream>
#include <vector>
using namespace std;

int N, d, k, c;
vector<int> type;
vector<int> belt;
int ans = 0, cnt = 0;
bool isCoupon = false;

void slidingWindow();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> d >> k >> c;
	type.resize(d + 1);
	belt.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> belt[i];
		if (i < k)
		{
			if (!type[belt[i]])
				cnt++;
			type[belt[i]]++;
		}
	}
	if (!type[c])
		isCoupon = true;
	ans = max(ans, cnt + isCoupon);

	slidingWindow();
	cout << ans;
}

void slidingWindow()
{
	int s = 0, e = k;
	while (e != N + k - 1)
	{
		isCoupon = false;

		type[belt[s]]--;
		if (!type[belt[s]])
			cnt--;
		s++;
		
		if (!type[belt[e % N]])
			cnt++;
		type[belt[e % N]]++;
		e++;

		if (!type[c])
			isCoupon = true;

		ans = max(ans, cnt + isCoupon);
	}
}