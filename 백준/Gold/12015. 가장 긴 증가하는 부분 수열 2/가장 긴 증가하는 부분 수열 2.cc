#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, temp;

int binary_search(int k);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	temp.push_back(A.front());

	for (int i = 1; i < N; i++)
	{
		if (A[i] > temp.back())
			temp.push_back(A[i]);
		else
		{
			int idx = binary_search(A[i]);
			temp[idx] = A[i];
		}
	}
	cout << temp.size();
}

int binary_search(int k)
{
	int l = 0, r = temp.size() - 1;
	while (l < r)
	{
		int pivot = (l + r) / 2;
		if (temp[pivot] >= k)
			r = pivot;
		else
			l = pivot + 1;
	}
	return r;
}