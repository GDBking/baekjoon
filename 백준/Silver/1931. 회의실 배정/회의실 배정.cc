#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].second;
        cin >> A[i].first;
    }

    sort(A.begin(), A.end());

    int endTime = 0, ans = 0;
    for (pair<int, int> i : A)
    {
        if (i.second >= endTime)
        {
            ans++;
            endTime = i.first;
        }
    }

    cout << ans;

    return 0;
}