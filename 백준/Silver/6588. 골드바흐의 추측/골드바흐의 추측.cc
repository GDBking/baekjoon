#include <iostream>
#include <vector>
using namespace std;

#define MAXNUM 1000000

vector<int> prime;
bool isPrime[MAXNUM];

void Eratosthenes();
void twoPointer(int k);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(isPrime, &isPrime[MAXNUM], true);
	Eratosthenes();

	int temp;
	cin >> temp;
	while (temp)
	{
		twoPointer(temp);
		cin >> temp;
	}
}

void Eratosthenes()
{
	for (int i = 2; i * i < MAXNUM; i++)
		if (isPrime[i])
			for (int j = i << 1; j < MAXNUM; j += i)
				isPrime[j] = false;
}

void twoPointer(int k)
{
	int l = 3, r = k - 3;
	while (!isPrime[r])
		r++;
	while (l <= r)
	{
		int sum = l + r;
		if (sum < k)
			while (!isPrime[++l]) {}
		else if (sum > k)
			while (!isPrime[--r]) {}
		else
		{
			cout << k << " = " << l << " + " << r << "\n";
			break;
		}
	}
}