#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> wine;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    wine.resize(n + 2);
    dp.resize(n + 2);
    for (int i = 0; i < n; i++)
        cin >> wine[i];

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(max(wine[0] + wine[2], wine[1] + wine[2]), dp[1]);
    for (int i = 3; i < n; i++)
        dp[i] = max(max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]), dp[i - 1]);

    cout << dp[n - 1];
}