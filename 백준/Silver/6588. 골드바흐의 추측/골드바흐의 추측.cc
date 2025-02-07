#include <iostream>
#include <vector>
using namespace std;

#define MAXNUM 1000000

vector<int> prime;
bool isPrime[MAXNUM];

void Eratosthenes();

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
		for (int i = 0; i < prime.size(); i++)
			if (isPrime[temp - prime[i]])
			{
				cout << temp << " = " << prime[i] << " + " << temp - prime[i] << "\n";
				break;
			}
		cin >> temp;
	}
}

void Eratosthenes()
{
	for (int i = 2; i * i < MAXNUM; i++)
		if (isPrime[i])
			for (int j = i << 1; j < MAXNUM; j += i)
				isPrime[j] = false;

	for (int i = 3; i < MAXNUM; i++)
	{
		if (isPrime[i])
			prime.push_back(i);
	}
}